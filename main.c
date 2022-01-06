/****************************************************************************/
/*				DETECTOR DE CALIDAD DE AIRE, TEMPERATURA Y HUMEDAD.			*/
/*..........................................................................*/
/*		Revisi�n:               	1.00									*/
/*		PIC:                    	PIC18F26J50-I/ML						*/
/*		PCB:                    	SMARTHUMAN.      						*/
/*		Comunicaci�n:             	USB, I2C, RS232.						*/
/*		M�dulo LoRa:            	RN2903-I/RM.							*/
/*		Sensor de calidad de aire:	CCS811. 								*/
/*		Sensor de humedad y temp.: 	ENS210.									*/
/*		Compilador:             	MPLAB X IDE V5.50 - XC8 V2.20   		*/
/*		Checksum:               	0xa6ea.             					*/
/*		Fecha de creaci�n:      	04/01/2022.								*/
/*		Autor:                  	Mariano Ariel Deville.					*/
/****************************************************************************/

#include "Configuracion.h"
#include "Dependencias/DRV_ENS210.h"

/****************************************************************************/
/*                  	Variables globales.                            		*/
/****************************************************************************/
 float temperatura,humedad;

void main(void) {
    
    int temp=0;
    Inicializo_Placa();
    
    while(1)
    {
        CLRWDT();
        __delay_ms(100);
        Toggle_Led(1);

        // Sensado de la calidad del aire.
        if(temp==25)
        {
            // Sensado de temperatura y humedad.
            ENS210StartSens(ENS210_SENS_START_TEMPERATURE | ENS210_SENS_START_HUMIDITY);
            Toggle_Led(2);
        }
        if(temp>150)
        {
            
            // Obtengo los valores del sensor.
            ENS210ReadResults();
            // Proceso los valores de temperatura y humedad
            temperatura=ENS210GetTempBuffer();
            humedad=ENS210GetHumidityBuffer();
            temp=0;
            Toggle_Led(2);
        }
        temp++;
    }
}
