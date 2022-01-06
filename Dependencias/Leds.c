/****************************************************************************/
/*                               Leds.c                                     */
/*..........................................................................*/
/*		Revisión:               	1.00									*/
/*		PIC family:                	PIC18F46J50.                            */
/*		Compilador:             	MPLAB X IDE V5.50 - XC8 V2.20   		*/
/*		Fecha de creación:      	09/01/2019.								*/
/*		Autor:                  	Mariano Ariel Deville.					*/
/****************************************************************************/

#include "../Configuracion.h"
#include "Leds.h"

/****************************************************************************/
/*               Cofiguro los pines como salida                             */
/*--------------------------------------------------------------------------*/
void Inicializo_Led(void)
{
    LED_D1_TRIS=PIN_OUTPUT;
    LED_D2_TRIS=PIN_OUTPUT;
}

/****************************************************************************/
/*                                                */
/*--------------------------------------------------------------------------*/
bool Estado_Led(LED led)
{
    switch(led)
    {
        case LED_D1:
            return ( (LED_D1_LAT == LED_ON) ? true : false );

        case LED_D2:
            return ( (LED_D2_LAT == LED_ON) ? true : false );

        default:
            return false;
    }
    
    return false;
}

/****************************************************************************/
/*                                                */
/*--------------------------------------------------------------------------*/
void LED_On(LED led)
{
        switch(led)
    {
        case LED_D1:
            LED_D1_LAT = LED_ON;
            break;

        case LED_D2:
            LED_D2_LAT = LED_ON;
            break;

        default:
            break;
    }
    return;
}

/****************************************************************************/
/*                                                */
/*--------------------------------------------------------------------------*/
void LED_Off(LED led)
{
    switch(led)
    {
        case LED_D1:
            LED_D1_LAT = LED_OFF;
            break;

        case LED_D2:
            LED_D2_LAT = LED_OFF;
            break;

        default:
            break;
    }
    return;
}

/****************************************************************************/
/*                                                */
/*--------------------------------------------------------------------------*/
void Toggle_Led(LED led)
{
    switch(led)
    {
        case LED_D1:
            LED_D1_LAT ^= 1;
            break;

        case LED_D2:
            LED_D2_LAT ^= 1;
            break;

        default:
            break;
    }
    return;
}
