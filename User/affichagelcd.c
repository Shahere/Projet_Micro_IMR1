#include "touch/ili_lcd_general.h"
#include "touch/lcd_api.h"
#include "touch/touch_panel.h"

void dessiner_ligne(unsigned int x, unsigned int y, unsigned int l,unsigned int e, char orientation, unsigned short color)
{
	int i,j;
	if(orientation=='v')
	{
		for(j=y;j<=y+l;j++)
		{
			lcd_SetCursor(x,j);//on place le curseur à la bonne position
			rw_data_prepare();
			for(i=0;i<=e;i++)
			{
				write_data(color);//on trace un point et on passe à la position suivante
			}
		}
	}
	else//orientation='h'
	{
		for(j=y;j<=y+e;j++)
		{
			lcd_SetCursor(x,j);//on place le curseur à la bonne position
			rw_data_prepare();
			for(i=0;i<=l;i++)
			{
				write_data(color);//on trace un point et on passe à la position suivante
			}
		}
	}
}

void dessiner_rect(unsigned int x, unsigned int y, unsigned int lng, unsigned int lrg, unsigned int e, unsigned short plein, unsigned short e_color, unsigned short bg_color)
{
	//dessiner fond
	if(plein==1)
	{
		dessiner_ligne(x,y,lng,lrg,'h',bg_color);
	}
	
	//dessiner bordures
	dessiner_ligne(x,y,lng,e,'h',e_color);
	dessiner_ligne(x+lng-e,y,lrg,e,'v',e_color);
	dessiner_ligne(x,y+lrg-e,lng,e,'h',e_color);
	dessiner_ligne(x,y,lrg,e,'v',e_color);
}

