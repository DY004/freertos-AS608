/*
 * FreeModbus Libary: BARE Demo Application
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id$
 */

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"

/* ----------------------- Defines ------------------------------------------*/
#define REG_INPUT_START 1
#define REG_INPUT_NREGS 10

#define REG_HOLDING_START 1
#define REG_HOLDING_NREGS 100

/* ----------------------- Static variables ---------------------------------*/
static USHORT   usRegInputStart = REG_INPUT_START;
//static USHORT   usRegInputBuf[REG_INPUT_NREGS];

static USHORT   usRegHoldingStart = REG_HOLDING_START;
//static USHORT   usRegHoldingBuf[REG_HOLDING_NREGS];
uint16_t usRegHoldingBuf[REG_HOLDING_NREGS];

uint16_t   usRegInputBuf[REG_INPUT_NREGS];
uint16_t   InputBuff[5];

/* ----------------------- Start implementation -----------------------------*/
//int
//host( void )
//{
//    eMBErrorCode    eStatus;

//    eStatus = eMBInit( MB_RTU, 0x0A, 0, 38400, MB_PAR_EVEN );

//    /* Enable the Modbus Protocol Stack. */
//    eStatus = eMBEnable(  );

//    for( ;; )
//    {
//        ( void )eMBPoll(  );

//        /* Here we simply count the number of poll cycles. */
//        usRegInputBuf[0]++;
//    }
//}

eMBErrorCode
eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs )
{
	
    eMBErrorCode    eStatus = MB_ENOERR;
    int             iRegIndex;
	
		int             i;
		InputBuff[0] = 0x11;
		InputBuff[1] = 0x22;
		InputBuff[2] = 0x33;
		InputBuff[3] = 0x44;
	
    if( ( usAddress >= REG_INPUT_START )
        && ( usAddress + usNRegs <= REG_INPUT_START + REG_INPUT_NREGS ) )
    {
        iRegIndex = ( int )( usAddress - usRegInputStart );
//        while( usNRegs > 0 )
//        {
//            *pucRegBuffer++ =
//                ( unsigned char )( usRegInputBuf[iRegIndex] >> 8 );
//            *pucRegBuffer++ =
//                ( unsigned char )( usRegInputBuf[iRegIndex] & 0xFF );
//            iRegIndex++;
//            usNRegs--;
//        }
				for(i=0;i<usNRegs;i++)
				{
					*pucRegBuffer=InputBuff[i+usAddress-1]>>8;
					pucRegBuffer++;
					*pucRegBuffer=InputBuff[i+usAddress-1]&0xff;
					pucRegBuffer++;
				}
    }
    else
    {
        eStatus = MB_ENOREG;
    }
 
    return eStatus;
}

eMBErrorCode
eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs,
                 eMBRegisterMode eMode )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    int             iRegIndex;

    if( ( usAddress >= REG_HOLDING_START ) && ( usAddress + usNRegs <= REG_HOLDING_START + REG_HOLDING_NREGS ) )
    {
        iRegIndex = ( int )( usAddress - usRegHoldingStart );
        switch ( eMode )
        {
        case MB_REG_READ:
            while( usNRegs > 0 )
            {
                *pucRegBuffer++ = ( unsigned char )( usRegHoldingBuf[iRegIndex] >> 8 );
                *pucRegBuffer++ = ( unsigned char )( usRegHoldingBuf[iRegIndex] & 0xFF );
                iRegIndex++;
                usNRegs--;
            }
            break;

        case MB_REG_WRITE:
            while( usNRegs > 0 )
            {
                usRegHoldingBuf[iRegIndex] = *pucRegBuffer++ << 8;
                usRegHoldingBuf[iRegIndex] |= *pucRegBuffer++;
                iRegIndex++;
                usNRegs--;
            }
        }
    }
    else
    {
        eStatus = MB_ENOREG;
    }
    return eStatus;
//		return MB_ENOREG;
}


eMBErrorCode
eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils,
               eMBRegisterMode eMode )
{
    return MB_ENOREG;
}

eMBErrorCode
eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )
{
    return MB_ENOREG;
}
