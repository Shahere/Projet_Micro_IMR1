#include "gestion_Pinsel.h"

#include "lpc17xx_pinsel.h"
#include "lpc17xx_gpio.h"



// initialise les autres broches pour la gestion de la mémoire par l’I2C0 et les boutons poussoirs
void pin_Configuration(void) {
	//La reset value des pinsels sont à 00, qui correspond à l'initialisation 
	//des pin au GPIO
		
	// Broches gestion de la mémoire
	
	PINSEL_CFG_Type configPinsel1;
	configPinsel1.Portnum = PINSEL_PORT_0;
	configPinsel1.Pinnum = PINSEL_PIN_27;
	configPinsel1.Funcnum = PINSEL_FUNC_1;
	configPinsel1.Pinmode = 1;
	configPinsel1.OpenDrain = PINSEL_PINMODE_OPENDRAIN;
	PINSEL_ConfigPin(&configPinsel1);
	
	configPinsel1.Portnum = PINSEL_PORT_0;
	configPinsel1.Pinnum = PINSEL_PIN_28;
	configPinsel1.Funcnum = PINSEL_FUNC_1;
	configPinsel1.Pinmode = 1; // deja une resistance de pull up dans les circuits
	configPinsel1.OpenDrain = PINSEL_PINMODE_OPENDRAIN;
	PINSEL_ConfigPin(&configPinsel1);
	
	// Boutons
	
	GPIO_SetDir (2,(1<<10),0);  /* PORT2.10 defined as input        */
	GPIO_SetDir (2,(1<<11),0);  /* PORT2.11 defined as input        */

}


