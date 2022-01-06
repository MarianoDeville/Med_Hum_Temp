/****************************************************************************/
/*                               Leds.h                                     */
/*..........................................................................*/
/*		Revisión:               	1.00									*/
/*		PIC family:                	PIC18F46J50.     						*/
/*		Compilador:             	MPLAB X IDE V5.50 - XC8 V2.20   		*/
/*		Fecha de creación:      	09/01/2019.								*/
/*		Autor:                  	Mariano Ariel Deville.					*/
/****************************************************************************/

#ifndef LEDSH
#define LEDSH

#include <stdbool.h>

/****************************************************************************/
/*                             Macros.                                      */
/*--------------------------------------------------------------------------*/
#define LED_ON 1
#define LED_OFF 0
#define LED_COUNT 2

typedef enum
{
    LED_NONE,
    LED_D1,
    LED_D2,
} LED;

/****************************************************************************/
/*                  Prototipo de funciones.                                 */
/*--------------------------------------------------------------------------*/
void Inicializo_Led(void);
bool Estado_Led(LED led);
void LED_On(LED led);
void LED_Off(LED led);
void Toggle_Led(LED led);
        
#endif