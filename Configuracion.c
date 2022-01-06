/********************************************************************************/
/*                     Configuracion.c                                          */
/*..............................................................................*/
/*		Revisi?n:               	1.00										*/
/*		PIC family:                	PIC18F46J50.     							*/
/*		Compilador:             	MPLAB X IDE V5.10 - XC8 V2.00   			*/
/*		Fecha de creaci?n:      	09/01/2019.									*/
/*		Autor:                  	Mariano Ariel Deville.						*/
/********************************************************************************/

#include <stdio.h>
#include "Configuracion.h"
#include "Dependencias/Leds.h"
#include "Dependencias/DRV_USART.h"
#include "Dependencias/DRV_MSSP.h"
//#include "Dependencias/DRV_ADC.h"
//#include "Dependencias/DRV_CCS811.h"
//#include "Dependencias/DRV_RN2903.h"

void Inicializo_Placa(void)
{
/*-------------------  Configuraci?n de las interrupciones.  -------------------*/
    GIE=0;      // Interrupcion global.
    IPEN=0;     // Prioridades en las interrupciones.
    TMR0IE=0;
    TMR1IE=0;
    TMR2IE=0;
    INT0IE=0;
    INT1IE=0;
    INT2IE=0;
    INT3IE=0;
    RBIE=0;
    TMR0IP=0;
    INT3IP=0;
    RBIP=0;
    ADIE=0;
    RC1IE=0;
    
    RTCEN=0;    // M?dulo Real Time Clock.
/*----------------  Por defecto todos los pines como entrada.  -----------------*/
    TRISA=0XFF; 
    TRISB=0XFF;
    TRISC=0XFF;
/*------------------  Configuraci?n de los pines utilizados.  ------------------*/
    RNCTS=PIN_INPUT;
    RNRTS=PIN_INPUT;
    Inicializo_Led();
    Inicializo_UART();
    MSSP_Setup(I2C,200000); // i2c configurado a 200 kHz ok
//    (void)ADC_SetConfiguration(ADC_CONFIGURATION_DEFAULT);
//    (void)RN2903_Init();
    return;
}

