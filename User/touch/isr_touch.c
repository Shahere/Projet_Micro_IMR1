#include "touch_panel.h"
#include "LPC17xx.h"
#include "global.h"

void EINT3_IRQHandler(void)
{
        
    if (((LPC_GPIO0->FIOPIN)&(1<<19))==0)  {appui=1;  GPIO_IntCmd (0,(1<<19),0); } /*P0.19 Risign edge interrupt      */
     else  {appui=0;  GPIO_IntCmd (0,(1<<19),1);  /*P0.19 Falling edge interrupt      */}
	  flagtacheclavier=1; // réveil de la tache clavier
	  GPIO_ClearInt (0,(1<<19));/* clear pending interrupt on P0.19*/
    
}
