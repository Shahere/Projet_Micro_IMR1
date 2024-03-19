//===========================================================//
// Projet Micro - INFO1 - ENSSAT - S2 2018							 //
//===========================================================//
// File                : Programme de départ
// Hardware Environment: Open1768	
// Build Environment   : Keil µVision
//===========================================================//

#include "touch\ili_lcd_general.h"
#include "touch\lcd_api.h"
#include "affichagelcd.h"
#include "touch\touch_panel.h"

#include "global.h"

#include "gestion_I2C.h"
#include "gestion_Timer.h" // include globaldec.h
#include "gestion_Pinsel.h"
#include "gestion_I2C.h"

char chaine_print[30];

#include <stdio.h>


//===========================================================//
// Function: when som1 tap the screen
//===========================================================//
void screenPat(){
	touch_read();
	if(touch_x >= 1000 && touch_x <= 2500 && touch_y >= 1000 && touch_y <= 4000){ //restart the count !
		
		restartCount();
	} else if(touch_x >= 2500 && touch_x <= 4000 && touch_y >= 1000 && touch_y <= 4000){ //stop the count !
		stopCount();
	}
	
	// parfois les ecrans sont inversées il faut configurer quand l'écran est dans l'autre sen
	/*if(touch_x >= 2500 && touch_x <= 4000 && touch_y >= 0 && touch_y <= 2000){ //stop the count !
		stopCount();
	}
	
	if(touch_x >= 2500 && touch_x <= 4000 && touch_y >= 0 && touch_y <= 2000){ //stop the count !
		stopCount();
	}*/

}

//===========================================================//
// Function: Main
//===========================================================//
int main(void)
{	   
		uint16_t slaveAddr = 81;
		int data = 0x0070;
		int data_recup = 0x70;
	  // Init(); // init variables globales et pinsel pour IR => à faire
	
	  lcd_Initializtion(); // init pinsel ecran et init LCD
		touch_init(); // init pavé tactile
		pin_Configuration(); // initialisation des broches
		initTimer();
		init_i2c_eeprom();
	
		//i2c_eeprom_read(slaveAddr, &data_recup, 2);
	
		//printf("%s", data_recup);
		
		sprintf(chaine_print,"%s", "Yellow : Play");
		LCD_write_english_string (10,10,chaine_print,White,Blue);
		sprintf(chaine_print,"%s", "Red : Pause");
		LCD_write_english_string (10,30,chaine_print,White,Blue);
    dessiner_rect(10,170,110,110,2,1,Black,Yellow);
    dessiner_rect(120,170,110,110,2,1,Black,Red);
	
	
    while(1) {
			touch_debug();
			if(TP_DOWN() && lcdPress == 0){
				lcdPress = 1; // ecran est appuyé
				screenPat();
			} else if (!TP_DOWN() && lcdPress == 1) {
				lcdPress = 0;
			}
		};
	};
//---------------------------------------------------------------------------------------------	
#ifdef  DEBUG
void check_failed(uint8_t *file, uint32_t line) {while(1);}
#endif
