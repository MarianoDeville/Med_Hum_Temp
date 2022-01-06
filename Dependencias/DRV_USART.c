/****************************************************************************/
/*         DRV_USART.h - Utilización del módulo USART del PIC18F46J50       */
/*..........................................................................*/
/*		Revisión:               	1.00									*/
/*		PIC family:                	PIC18F46J50.     						*/
/*		Compilador:             	MPLAB X IDE V5.10 - XC8 V2.00   		*/
/*		Fecha de creación:      	09/01/2019.								*/
/*		Autor:                  	Mariano Ariel Deville.					*/
/****************************************************************************/

#include "../Configuracion.h"
#include "DRV_USART.h"
#include <stdbool.h>
#include <xc.h>

/****************************************************************************/
/*                                    */
/*--------------------------------------------------------------------------*/
void Inicializo_UART(void)
{
    unsigned char c;
    RNRTS=PIN_OUTPUT;
    RNCTS=PIN_INPUT;
    UART_TRISRx=1;			// RX
    UART_TRISTx=0;			// TX
    TXSTA = 0x24;       	// TX enable BRGH=1
    RCSTA = 0x90;       	// Single Character RX
    SPBRG = 0xE1;
    SPBRGH = 0x04;      	// 0x04E1 for 48MHz -> 9600 baud.
    BAUDCON = 0x08;     	// BRG16 = 1
    c=RCREG;				// read
    return;
}


/****************************************************************************/
/*                                    */
/*--------------------------------------------------------------------------*/
void PutcUSART(char c)
{
    TXREG = c;
    return;
}

/****************************************************************************/
/*                                    */
/*--------------------------------------------------------------------------*/
unsigned char GetcUSART(void)
{
	char  c;
	if (RCSTAbits.OERR)     // in case of overrun error
	{                       // we should never see an overrun error, but if we do,
		RCSTAbits.CREN = 0; // reset the port
		c = RCREG;
		RCSTAbits.CREN = 1; // and keep going.
	}
	else
		c = RCREG;
	return c;
}

/****************************************************************************/
/*                                    */
/*--------------------------------------------------------------------------*/
void PutsUSART(char * data)
{
    if(!*data)
        return;
    do
    {
        PutcUSART( *data );
        while(TXSTAbits.TRMT); //espera a enviar el dato);
        __delay_ms(10);
        data++;
    }while(*data != 0);
    return;
}
