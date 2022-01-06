/****************************************************************************/
/*          DRV_MSSP.c - Utilizaci?n del m?dulo MSSP del PIC18F46J50        */
/*..........................................................................*/
/*		Revisi?n:               	1.00									*/
/*		PIC family:                	PIC18F46J50.     						*/
/*		Compilador:             	MPLAB X IDE V5.10 - XC8 V2.00   		*/
/*		Fecha de creaci?n:      	09/01/2019.								*/
/*		Autor:                  	Mariano Ariel Deville.					*/
/****************************************************************************/

#include "../Configuracion.h"
#include "DRV_MSSP.h"


/****************************************************************************/
/*               Configuraci?n e inicializaci?n del m?dulo.                 */
/*--------------------------------------------------------------------------*/
void MSSP_Setup(char modo,const unsigned long velocidad)
{
    if(modo==I2C)
    {
        TRISBbits.TRISB4=PIN_INPUT;
        TRISBbits.TRISB5=PIN_INPUT;
        SSP1STAT=0;
//SSP1STAT=0b11000000;
        SSP1CON1=0b00101000;                    // Set I2C master mode.
        SSP1CON2=0b00000000;
        SSP1ADD=(_XTAL_FREQ/(4*velocidad))-1;   //Setting Clock Speed
        BCLIF=0;                                // Clear bus collision flag.
    }
    return;
}

/****************************************************************************/
/*                        Espero que el puerto se libere.                   */
/*--------------------------------------------------------------------------*/
void I2C_Wait_Idle(void)
{
    long timeout=65000;
	while(((SSP1CON2&0x1F)|RW) && (timeout-- > 0))
		continue;
}

/****************************************************************************/
/*                      Comienzo la transmisi?n.                            */
/*--------------------------------------------------------------------------*/
void I2C_Start(void)
{
	I2C_Wait_Idle();
	SSP1CON2bits.SEN=1;
}

/****************************************************************************/
/*                      Reinicio la transmisi?n.                            */
/*--------------------------------------------------------------------------*/
void I2C_RepStart(void)
{
	I2C_Wait_Idle();
	SSP1CON2bits.RSEN=1;
}

/****************************************************************************/
/*						Termino la transmisi?n.								*/
/*--------------------------------------------------------------------------*/
void I2C_Stop(void)
{
	I2C_Wait_Idle();
	SSP1CON2bits.PEN=1;
}

/****************************************************************************/
/*						Leo un caracter.                    				*/
/*--------------------------------------------------------------------------*/
unsigned char I2C_Read(unsigned char ack)
{
	unsigned char i2cReadData;
	I2C_Wait_Idle();
	SSP1CON2bits.RCEN=1;
	I2C_Wait_Idle();
	i2cReadData=SSPBUF;
	I2C_Wait_Idle();
	if(ack)
		SSP1CON2bits.ACKDT=0;
	else
		SSP1CON2bits.ACKDT=1;
	SSP1CON2bits.ACKEN=1;               // send acknowledge sequence
	return(i2cReadData);
}

/****************************************************************************/
/*				Escribo un caracter y devuelvo el ACK.             			*/
/*--------------------------------------------------------------------------*/
unsigned char I2C_Write(unsigned char i2cWriteData)
{
	I2C_Wait_Idle();
	SSPBUF=i2cWriteData;
	return(!SSP1CON2bits.ACKSTAT);		// function returns '1' if transmission is acknowledged.
}
