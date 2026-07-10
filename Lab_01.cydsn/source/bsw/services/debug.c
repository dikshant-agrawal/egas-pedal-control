/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "debug.h"

void Debug_Start(){

    UART_LOG_Start();
    
}


//Put String on Console
void Debug_Print(const char *msg)
{
    UART_LOG_PutString(msg);
}

//Put Hex Byte on Console
void Debug_Print_HexByte(uint8_t byte)
{
    char hex[3];
    const char hexChars[] = "0123456789ABCDEF";

    hex[0] = hexChars[(byte >> 4) & 0x0F];
    hex[1] = hexChars[byte & 0x0F];
    hex[2] = '\0';

    UART_LOG_PutString(hex);
}


/* [] END OF FILE */
