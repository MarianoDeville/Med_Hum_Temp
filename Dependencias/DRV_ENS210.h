/****************************************************************************/
/*          Driver para el manejo del sensor de temperatura y humedad.      */
/*..........................................................................*/
/*      Archivo:                    DRV_ENS210.h                            */
/*		Revisi?n:               	1.00									*/
/*		Sensor de temp. y humedad:  ENS210. 								*/
/*		Comunicaci?n:             	I2C.                                    */
/*		Compilador:             	MPLAB X IDE V5.10 - XC8 V2.00   		*/
/*		Fecha de creaci?n:      	21/01/2019.								*/
/*		Autor:                  	Mariano Ariel Deville.					*/
/****************************************************************************/

#ifndef DRVENS210H
#define DRVENS210H

#include "DRV_MSSP.h"

/****************************************************************************/
/*                             Macros.                                      */
/*--------------------------------------------------------------------------*/
#define ENS210_ADR_W          0x86
#define ENS210_ADR_R          0x87
// Register addresses
#define ENS210_PART_ID      0x00
#define ENS210_UID          0x04
#define ENS210_SYS_CTRL     0x10
#define ENS210_SYS_STAT     0x11
#define ENS210_SENS_RUN     0x21
#define ENS210_SENS_START   0x22
#define ENS210_SENS_START_TEMPERATURE 0b00000001
#define ENS210_SENS_START_HUMIDITY 0b00000010
#define ENS210_SENS_STOP    0x23
#define ENS210_SENS_STAT    0x24
#define ENS210_T_VAL        0x30
#define ENS210_H_VAL        0x33

/****************************************************************************/
/*                  Prototipo de funciones.                                 */
/*--------------------------------------------------------------------------*/
void ENS210StartSens(unsigned char sensores);
void ENS210ReadResults(void);
float ENS210GetTempBuffer(void);
float ENS210GetHumidityBuffer(void);
        
#endif