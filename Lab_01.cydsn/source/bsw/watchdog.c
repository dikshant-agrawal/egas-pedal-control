/**
* \file watchdog.h
* \author Dikshant Agrawal
* \date 03.06.2026
*
* \brief Drivers to check if the system is running in issues using watchdog.
*
* \copyright Copyright ©2016
* Department of electrical engineering and information technology, Hochschule Darmstadt - University of applied sciences (h_da). All Rights Reserved.
* Permission to use, copy, modify, and distribute this software and its documentation for educational, and research purposes in the context of non-commercial
* (unless permitted by h_da) and official h_da projects, is hereby granted for enrolled students of h_da, provided that the above copyright notice,
* this paragraph and the following paragraph appear in all copies, modifications, and distributions.
* Contact Prof.Dr.-Ing. Peter Fromm, peter.fromm@h-da.de, Birkenweg 8 64295 Darmstadt - GERMANY for commercial requests.
*
* \warning This software is a PROTOTYPE version and is not designed or intended for use in production, especially not for safety-critical applications!
* The user represents and warrants that it will NOT use or redistribute the Software for such purposes.
* This prototype is for research purposes only. This software is provided "AS IS," without a warranty of any kind.
*/

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/

#include "watchdog.h"

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/



/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/


/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/


// Reference Manual
// https://www.infineon.com/assets/row/public/documents/30/57/infineon-psoc5lp-architecture-trm-additionaltechnicalinformation-en.pdf?fileId=8ac78c8c7d0d8da4017d0f905e3e7ce9



/**
 * Activate the watchdog trigger
 * \param WDT_TimeOut_t timeout - [IN] timeout period 
* \param lpMode: Low power mode configuration. This parameter is ignored for PSoC 5.
*          The WDT always acts as if CYWDT_LPMODE_NOCHANGE is passed.
 * \return RC_SUCCESS
 */
RC_t WD_Start(WDT_TimeOut_t timeout){
    
    CyWdtStart(timeout, CYWDT_LPMODE_NOCHANGE);
    
    return RC_SUCCESS;

}

/**
 * Service the watchdog trigger
 * \return RC_SUCCESS
 */
RC_t WD_Trigger(){
    
    WDT_bitField = 0b00000000;
    CyWdtClear();
    
    return RC_SUCCESS;

}

/**
 * Checks the watchdog bit
 * \return TRUE if watchdog reset bit was set
 * Reset register fields of RESET_SR0 (CyResetStatus) 
#define CY_RESET_LVID               (0x01u)
#define CY_RESET_LVIA               (0x02u)
#define CY_RESET_HVIA               (0x04u)
#define CY_RESET_WD                 (0x08u)
#define CY_RESET_SW                 (0x20u)
#define CY_RESET_GPIO0              (0x40u)
#define CY_RESET_GPIO1              (0x80u)
 */
boolean_t WD_CheckResetBit(){

    if(CyResetStatus == 0x08u){
        return TRUE;
    }
    
    return FALSE;
    
}



/**
 * Set the bit position by the runnables
 * \return RC_SUCCESS
 */
RC_t WD_Alive(uint8_t myBitPosition){

    WDT_bitField |= (1 << myBitPosition);
    
    return RC_SUCCESS;

}

