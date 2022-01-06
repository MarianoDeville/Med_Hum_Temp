/****************************************************************************/
/*        DRV_MSSP.h - Utilizaci?n del m?dulo MSSP del PIC18F46J50          */
/*..........................................................................*/
/*		Revisi?n:               	1.00									*/
/*		PIC family:                	PIC18F46J50.     						*/
/*		Compilador:             	MPLAB X IDE V5.10 - XC8 V2.00   		*/
/*		Fecha de creaci?n:      	09/01/2019.								*/
/*		Autor:                  	Mariano Ariel Deville.					*/
/****************************************************************************/

#ifndef DRVMSSP_H
#define DRVMSSP_H

/****************************************************************************/
/*                             Macros.                                      */
/*--------------------------------------------------------------------------*/
#define I2C 1
#define SPI 2

/****************************************************************************/
/*                  Prototipo de funciones.                                 */
/*--------------------------------------------------------------------------*/
void MSSP_Setup(char modo,const unsigned long velocidad);
void I2C_Wait_Idle(void);
void I2C_Start(void);
void I2C_RepStart(void);
void I2C_Stop(void);
unsigned char I2C_Read(unsigned char ack);
unsigned char I2C_Write(unsigned char i2cWriteData);

#endif	// DRVMSSP_H

