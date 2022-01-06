/****************************************************************************/
/*          Driver para el manejo del sensor de temperatura y humedad.      */
/*..........................................................................*/
/*      Archivo:                    DRV_ENS210.c                            */
/*		Revisi?n:               	1.00									*/
/*		Sensor de temp. y humedad:  ENS210. 								*/
/*		Comunicaci?n:             	I2C.                                    */
/*		Compilador:             	MPLAB X IDE V5.10 - XC8 V2.00   		*/
/*		Fecha de creaci?n:      	21/01/2019.								*/
/*		Autor:                  	Mariano Ariel Deville.					*/
/****************************************************************************/

#include "../Configuracion.h"
#include "DRV_MSSP.h"
#include "DRV_ENS210.h"

unsigned char bufferENS210[6];

/****************************************************************************/
/*                                                */
/*--------------------------------------------------------------------------*/
void ENS210StartSens(unsigned char sensores)
{
    I2C_Start();                            // Start condition
    (void)I2C_Write(ENS210_ADR_W);          // 7 bit address + Write
    (void)I2C_Write(ENS210_SENS_START);     // Write data
    (void)I2C_Write(sensores);              // Write data
    I2C_Stop();                             // Stop condition
    return;
}

/****************************************************************************/
/*                                                */
/*--------------------------------------------------------------------------*/
void ENS210ReadResults(void)
{
    char i;
    I2C_Start();                        // Start condition
    (void)I2C_Write(ENS210_ADR_W);      // 7 bit address + Write
    (void)I2C_Write(ENS210_T_VAL);      // Registro de resultados (Temperatura y Humedad est?n a continuaci?n)
    I2C_RepStart();                     // Repeated Start condition
    (void)I2C_Write(ENS210_ADR_R);      // 7 bit address + Read
    // Leo los 6 bytes (3 de Temp + 3 de Humidity)
    for(i=0;i<5;i++)
    {
        bufferENS210[i] = I2C_Read(1);  // Read Byte + ACK
    }
    bufferENS210[5]=I2C_Read(0);        // Read Byte + NACK
    I2C_Stop();                         // Stop condition
    return;
}

/****************************************************************************/
/*                                                */
/*--------------------------------------------------------------------------*/
float ENS210GetTempBuffer(void)
{
    unsigned long tData = ((bufferENS210[1] << 8) + bufferENS210[0]);
    float tInK = (float) tData / 64.0;
    return tInK - 273.15;
}

/****************************************************************************/
/*                                                */
/*--------------------------------------------------------------------------*/
float ENS210GetHumidityBuffer(void)
{
    unsigned long hData = ((bufferENS210[4] << 8) + bufferENS210[3]);
    float humidity = hData / 512.0;
    return humidity;
}
