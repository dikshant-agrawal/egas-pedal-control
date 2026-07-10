/*******************************************************************************
* File Name: Direction_control_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Direction_control.h"

/* Check for removal by optimization */
#if !defined(Direction_control_Sync_ctrl_reg__REMOVED)

static Direction_control_BACKUP_STRUCT  Direction_control_backup = {0u};

    
/*******************************************************************************
* Function Name: Direction_control_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Direction_control_SaveConfig(void) 
{
    Direction_control_backup.controlState = Direction_control_Control;
}


/*******************************************************************************
* Function Name: Direction_control_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void Direction_control_RestoreConfig(void) 
{
     Direction_control_Control = Direction_control_backup.controlState;
}


/*******************************************************************************
* Function Name: Direction_control_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Direction_control_Sleep(void) 
{
    Direction_control_SaveConfig();
}


/*******************************************************************************
* Function Name: Direction_control_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Direction_control_Wakeup(void)  
{
    Direction_control_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
