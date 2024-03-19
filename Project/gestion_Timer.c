#include "gestion_Timer.h"

#include "lpc17xx_gpio.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_libcfg_default.h"
#include "lpc17xx_timer.h"

#include "affichagelcd.h"
#include "touch\ili_lcd_general.h"
#include "touch\lcd_api.h"

#include <stdio.h>
#include <stdlib.h>
#include "globaldec.h"


#define precision 2500;
#define demie_periode 100;

uint8_t compteur = 0;
uint32_t port0 = 0;

uint16_t slaveAddr = 0x81;
uint8_t data_recup;
int nombre = 0x00;
uint8_t nombreAddr = 0;
uint8_t process = 1;
int i2c_processing = 0;

void i2c_eeprom_write(uint16_t addr, void* data, int length);
void i2c_eeprom_read(uint16_t addr, void* data_recup, int length);

//==========================================
//Affiche ecran
//==========================================
void afficher_ecran() {
		i2c_eeprom_read(slaveAddr, &data_recup, sizeof(data_recup));
		sprintf(chaine,"val mem : %d    ", data_recup);
		LCD_write_english_string (100,100,chaine,White,Blue);
		
		sprintf(chaine,"timer : %d    ", nombre);
		LCD_write_english_string (100,120,chaine,White,Blue);
}

//================================================
// Timer handler, pas besoin d'appel fonction
//================================================
void TIMER0_IRQHandler(void) {
    if(compteur == 100) {
        if(process == 1 && i2c_processing == 0) {	
					uint16_t data = 0x0081;
					i2c_processing = 1;
					nombre = nombre+1;
			
					data |= (nombre << 8);
					/*sprintf(chaine,"0x%x       ", data);
					LCD_write_english_string (20,80,chaine,White,Blue);*/
					i2c_eeprom_write(slaveAddr,&data,sizeof(data));
					
					/*sprintf(chaine,"0x%x       ", nombre);
					LCD_write_english_string (20,100,chaine,White,Blue);*/
			
					afficher_ecran();
					i2c_processing = 0;
				}
				compteur = 0;
				
    } else {
        compteur++;
    }
		
    TIM_ClearIntPending(LPC_TIM0, TIM_MR0_INT);
}

 
//==========================================
//Initialisation du timer
//==========================================
void initTimer() {
	PINSEL_CFG_Type configPinsel; // pour pin connect bloc 
	TIM_TIMERCFG_Type configTimer ; // pour timer mode et precision
	TIM_MATCHCFG_Type maconfigmatch ; // pour timer match
  // remplissage pour P1.28 sur MAT0.0
  configPinsel.Portnum=PINSEL_PORT_1;
  configPinsel.Pinnum=PINSEL_PIN_28;
  configPinsel.Funcnum=PINSEL_FUNC_3;
  configPinsel.Pinmode=0;
  configPinsel.OpenDrain=PINSEL_PINMODE_NORMAL;
  // appel de la fonction qui va initialiser les registres
  PINSEL_ConfigPin(&configPinsel);
	
	
  // remplissage pour choisir le mode timer et la precision
  configTimer.PrescaleOption = TIM_PRESCALE_TICKVAL; // valeur donnee en tick
  configTimer.PrescaleValue = 2500; //Précision
  // appel de la fonction qui va initialiser les registres
  TIM_Init(LPC_TIM0,TIM_TIMER_MODE,&configTimer);
  // remplissage pour choisir les actions quand ça match
	

  maconfigmatch.ExtMatchOutputType= TIM_EXTMATCH_TOGGLE; // inverse la sortie a chaque match
  maconfigmatch.IntOnMatch = ENABLE; // pas d'interruption generee quand ca match
  maconfigmatch.StopOnMatch = DISABLE ;
  maconfigmatch.MatchChannel = 0; // on utilise MR0
  maconfigmatch.MatchValue = 100; // correspond a la duree d'une demie-periode 
  maconfigmatch.ResetOnMatch = ENABLE; // remet TC a 0 quand ca match
  // appel de la fonction qui va initialiser les registres
  TIM_ConfigMatch(LPC_TIM0,&maconfigmatch);
    
  NVIC_EnableIRQ(TIMER0_IRQn);
    
  // lancement du timer-compteur 
  TIM_Cmd(LPC_TIM0,ENABLE);
}

void restartCount() {
	process = 1;
	sprintf(chaine,"%s                ", "restart");
	LCD_write_english_string (100,80,chaine,White,Blue);
}

void stopCount() {
		if(process == 0) { // timer is not running
			uint16_t dataEc = 0x0081;
			nombre = 0; //reinit
			i2c_eeprom_write(slaveAddr,&dataEc,sizeof(dataEc));
			sprintf(chaine,"%s               ", "press yellow");
			LCD_write_english_string (100,80,chaine,White,Blue);
			afficher_ecran();
		} else {  //timer is running
			process = 0;
			sprintf(chaine,"%s                ", "stop");
			LCD_write_english_string (100,80,chaine,White,Blue);
		}

}



