/****************************************************************************/
/*                     Configuracion.h                                      */
/*..........................................................................*/
/*		Revisión:               	1.00									*/
/*		PIC family:                	PIC18F46J50.     						*/
/*		Compilador:             	MPLAB X IDE V5.50 - XC8 V2.20   		*/
/*		Fecha de creación:      	04/01/2022.								*/
/*		Autor:                  	Mariano Ariel Deville.					*/
/****************************************************************************/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef CONFIGURACION_H
#define	CONFIGURACION_H

/********************************************************************************/
/*                  Bits de configuración.                                      */
/*------------------------------------------------------------------------------*/
#pragma config WDTEN = OFF          //WDT disabled (enabled by SWDTEN bit)
#pragma config PLLDIV = 3           //Divide by 3 (12 MHz oscillator input)
#pragma config STVREN = ON          //stack overflow/underflow reset enabled
#pragma config XINST = OFF          //Extended instruction set disabled
#pragma config CPUDIV = OSC1        //No CPU system clock divide
#pragma config CP0 = OFF            //Program memory is not code-protected
#pragma config OSC = HSPLL          //HS oscillator, PLL enabled, HSPLL used by USB
#pragma config FCMEN = OFF          //Fail-Safe Clock Monitor disabled
#pragma config IESO = OFF           //Two-Speed Start-up disabled
#pragma config WDTPS = 32768        //1:32768
#pragma config DSWDTOSC = INTOSCREF //DSWDT uses INTOSC/INTRC as clock
#pragma config RTCOSC = T1OSCREF    //RTCC uses T1OSC/T1CKI as clock
#pragma config DSBOREN = OFF        //Zero-Power BOR disabled in Deep Sleep
#pragma config DSWDTEN = OFF        //Disabled
#pragma config DSWDTPS = 8192       //1:8,192 (8.5 seconds)
#pragma config IOL1WAY = OFF        //IOLOCK bit can be set and cleared
#pragma config MSSP7B_EN = MSK7     //7 Bit address masking
#pragma config WPFP = PAGE_1        //Write Protect Program Flash Page 0
#pragma config WPEND = PAGE_0       //Start protection at page 0
#pragma config WPCFG = OFF          //Write/Erase last page protect Disabled
#pragma config WPDIS = OFF          //WPFP[5:0], WPEND, and WPCFG bits ignored
#pragma config T1DIG = ON           //Sec Osc clock source may be selected
#pragma config LPT1OSC = OFF        //high power Timer1 mode
/********************************************************************************/

#include <xc.h> // include processor files - each processor file is guarded.
#include "Dependencias/Leds.h"

/********************************************************************************/
/*                             Macros.                                          */
/*------------------------------------------------------------------------------*/
#define _XTAL_FREQ      12000000

#define PIN_INPUT       1
#define PIN_OUTPUT      0

#define PIN_ANALOG      1
#define PIN_DIGITAL     0

/********************************************************************************/
/*                  Defino los pines que utilizo.                               */
/*------------------------------------------------------------------------------*/
#define CCS811_WAKEUP   LATCbits.LATC0
#define LED_D1_LAT      LATCbits.LATC2
#define LED_D2_LAT      LATAbits.LATA0
#define NINT_LAT        LATCbits.LATC1

#define LED_D2_TRIS     TRISAbits.TRISA0
#define LED_D1_TRIS     TRISCbits.TRISC2
#define RNRTS           TRISBbits.TRISB1
#define RNCTS           TRISBbits.TRISB2
#define NWAKE           TRISCbits.TRISC0
#define NINT            TRISCbits.TRISC1

/********************************************************************************/
/*                  Prototipo de funciones.                                     */
/*------------------------------------------------------------------------------*/
void Inicializo_Placa(void);


#endif	/* CONFIGURACION_H */

