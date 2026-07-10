/*******************************************************************************
* File Name: Run1.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Run1_H) /* Pins Run1_H */
#define CY_PINS_Run1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Run1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Run1__PORT == 15 && ((Run1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Run1_Write(uint8 value);
void    Run1_SetDriveMode(uint8 mode);
uint8   Run1_ReadDataReg(void);
uint8   Run1_Read(void);
void    Run1_SetInterruptMode(uint16 position, uint16 mode);
uint8   Run1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Run1_SetDriveMode() function.
     *  @{
     */
        #define Run1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Run1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Run1_DM_RES_UP          PIN_DM_RES_UP
        #define Run1_DM_RES_DWN         PIN_DM_RES_DWN
        #define Run1_DM_OD_LO           PIN_DM_OD_LO
        #define Run1_DM_OD_HI           PIN_DM_OD_HI
        #define Run1_DM_STRONG          PIN_DM_STRONG
        #define Run1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Run1_MASK               Run1__MASK
#define Run1_SHIFT              Run1__SHIFT
#define Run1_WIDTH              1u

/* Interrupt constants */
#if defined(Run1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Run1_SetInterruptMode() function.
     *  @{
     */
        #define Run1_INTR_NONE      (uint16)(0x0000u)
        #define Run1_INTR_RISING    (uint16)(0x0001u)
        #define Run1_INTR_FALLING   (uint16)(0x0002u)
        #define Run1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Run1_INTR_MASK      (0x01u) 
#endif /* (Run1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Run1_PS                     (* (reg8 *) Run1__PS)
/* Data Register */
#define Run1_DR                     (* (reg8 *) Run1__DR)
/* Port Number */
#define Run1_PRT_NUM                (* (reg8 *) Run1__PRT) 
/* Connect to Analog Globals */                                                  
#define Run1_AG                     (* (reg8 *) Run1__AG)                       
/* Analog MUX bux enable */
#define Run1_AMUX                   (* (reg8 *) Run1__AMUX) 
/* Bidirectional Enable */                                                        
#define Run1_BIE                    (* (reg8 *) Run1__BIE)
/* Bit-mask for Aliased Register Access */
#define Run1_BIT_MASK               (* (reg8 *) Run1__BIT_MASK)
/* Bypass Enable */
#define Run1_BYP                    (* (reg8 *) Run1__BYP)
/* Port wide control signals */                                                   
#define Run1_CTL                    (* (reg8 *) Run1__CTL)
/* Drive Modes */
#define Run1_DM0                    (* (reg8 *) Run1__DM0) 
#define Run1_DM1                    (* (reg8 *) Run1__DM1)
#define Run1_DM2                    (* (reg8 *) Run1__DM2) 
/* Input Buffer Disable Override */
#define Run1_INP_DIS                (* (reg8 *) Run1__INP_DIS)
/* LCD Common or Segment Drive */
#define Run1_LCD_COM_SEG            (* (reg8 *) Run1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Run1_LCD_EN                 (* (reg8 *) Run1__LCD_EN)
/* Slew Rate Control */
#define Run1_SLW                    (* (reg8 *) Run1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Run1_PRTDSI__CAPS_SEL       (* (reg8 *) Run1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Run1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Run1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Run1_PRTDSI__OE_SEL0        (* (reg8 *) Run1__PRTDSI__OE_SEL0) 
#define Run1_PRTDSI__OE_SEL1        (* (reg8 *) Run1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Run1_PRTDSI__OUT_SEL0       (* (reg8 *) Run1__PRTDSI__OUT_SEL0) 
#define Run1_PRTDSI__OUT_SEL1       (* (reg8 *) Run1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Run1_PRTDSI__SYNC_OUT       (* (reg8 *) Run1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Run1__SIO_CFG)
    #define Run1_SIO_HYST_EN        (* (reg8 *) Run1__SIO_HYST_EN)
    #define Run1_SIO_REG_HIFREQ     (* (reg8 *) Run1__SIO_REG_HIFREQ)
    #define Run1_SIO_CFG            (* (reg8 *) Run1__SIO_CFG)
    #define Run1_SIO_DIFF           (* (reg8 *) Run1__SIO_DIFF)
#endif /* (Run1__SIO_CFG) */

/* Interrupt Registers */
#if defined(Run1__INTSTAT)
    #define Run1_INTSTAT            (* (reg8 *) Run1__INTSTAT)
    #define Run1_SNAP               (* (reg8 *) Run1__SNAP)
    
	#define Run1_0_INTTYPE_REG 		(* (reg8 *) Run1__0__INTTYPE)
#endif /* (Run1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Run1_H */


/* [] END OF FILE */
