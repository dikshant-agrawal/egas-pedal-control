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

#ifndef DEBUG_H
#define DEBUG_H
    
#include "project.h"

    
void Debug_Start();    
void Debug_Print(const char *msg);
void Debug_Print_HexByte(uint8_t byte);

#endif
/* [] END OF FILE */
