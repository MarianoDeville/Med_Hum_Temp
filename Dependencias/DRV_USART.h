/****************************************************************************/
/*         DRV_USART.h - Utilización del módulo USART del PIC18F46J50       */
/*..........................................................................*/
/*		Revisión:               	1.00									*/
/*		PIC family:                	PIC18F46J50.     						*/
/*		Compilador:             	MPLAB X IDE V5.10 - XC8 V2.00   		*/
/*		Fecha de creación:      	09/01/2019.								*/
/*		Autor:                  	Mariano Ariel Deville.					*/
/****************************************************************************/

#ifndef DRVUARTH
#define DRVUARTH

/****************************************************************************/
/*                             Macros.                                      */
/*--------------------------------------------------------------------------*/
#define GetSystemClock() _XTAL_FREQ

#define UART_ENABLE RCSTAbits.SPEN

#define UART_TRISTx TRISCbits.TRISC6
#define UART_TRISRx TRISCbits.TRISC7
#define UART_Tx     PORTCbits.RC6
#define UART_Rx     PORTCbits.RC7

#define UART_CTS    LATBbits.LATB2
#define UART_RTS    PORTBbits.RB1

/****************************************************************************/
/*                  Prototipo de funciones.                                 */
/*--------------------------------------------------------------------------*/
void Inicializo_UART(void);
void PutcUSART(char c);
unsigned char GetcUSART(void);
void PutsUSART(char * data);

#endif