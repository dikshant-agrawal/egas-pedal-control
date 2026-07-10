/*******************************************************************************
* File Name: Run4.h  
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

#if !defined(CY_PINS_Run4_H) /* Pins Run4_H */
#define CY_PINS_Run4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Run4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Run4__PORT == 15 && ((Run4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Run4_Write(uint8 value);
void    Run4_SetDriveMode(uint8 mode);
uint8   Run4_ReadDataReg(void);
uint8   Run4_Read(void);
void    Run4_SetInterruptMode(uint16 position, uint16 mode);
uint8   Run4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Run4_SetDriveMode() function.
     *  @{
     */
        #define Run4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Run4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Run4_DM_RES_UP          PIN_DM_RES_UP
        #define Run4_DM_RES_DWN         PIN_DM_RES_DWN
        #define Run4_DM_OD_LO           PIN_DM_OD_LO
        #define Run4_DM_OD_HI           PIN_DM_OD_HI
        #define Run4_DM_STRONG          PIN_DM_STRONG
        #define Run4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Run4_MASK               Run4__MASK
#define Run4_SHIFT              Run4__SHIFT
#define Run4_WIDTH              1u

/* Interrupt constants */
#if defined(Run4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Run4_SetInterruptMode() function.
     *  @{
     */
        #define Run4_INTR_NONE      (uint16)(0x0000u)
        #define Run4_INTR_RISING    (uint16)(0x0001u)
        #define Run4_INTR_FALLING   (uint16)(0x0002u)
        #define Run4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Run4_INTR_MASK      (0x01u) 
#endif /* (Run4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Run4_PS                     (* (reg8 *) Run4__PS)
/* Data Register */
#define Run4_DR                     (* (reg8 *) Run4__DR)
/* Port Number */
#define Run4_PRT_NUM                (* (reg8 *) Run4__PRT) 
/* Connect to Analog Globals */                                                  
#define Run4_AG                     (* (reg8 *) Run4__AG)                       
/* Analog MUX bux enable */
#define Run4_AMUX                   (* (reg8 *) Run4__AMUX) 
/* Bidirectional Enable */                                                        
#define Run4_BIE                    (* (reg8 *) Run4__BIE)
/* Bit-mask for Aliased Register Access */
#define Run4_BIT_MASK               (* (reg8 *) Run4__BIT_MASK)
/* Bypass Enable */
#define Run4_BYP                    (* (reg8 *) Run4__BYP)
/* Port wide control signals */                                                   
#define Run4_CTL                    (* (reg8 *) Run4__CTL)
/* Drive Modes */
#define Run4_DM0                    (* (reg8 *) Run4__DM0) 
#define Run4_DM1                    (* (reg8 *) Run4__DM1)
#define Run4_DM2                    (* (reg8 *) Run4__DM2) 
/* Input Buffer Disable Override */
#define Run4_INP_DIS                (* (reg8 *) Run4__INP_DIS)
/* LCD Common or Segment Drive */
#define Run4_LCD_COM_SEG            (* (reg8 *) Run4__LCD_COM_SEG)
/* Enable Segment LCD */
#define Run4_LCD_EN                 (* (reg8 *) Run4__LCD_EN)
/* Slew Rate Control */
#define Run4_SLW                    (* (reg8 *) Run4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Run4_PRTDSI__CAPS_SEL       (* (reg8 *) Run4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Run4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Run4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Run4_PRTDSI__OE_SEL0        (* (reg8 *) Run4__PRTDSI__OE_SEL0) 
#define Run4_PRTDSI__OE_SEL1        (* (reg8 *) Run4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Run4_PRTDSI__OUT_SEL0       (* (reg8 *) Run4__PRTDSI__OUT_SEL0) 
#define Run4_PRTDSI__OUT_SEL1       (* (reg8 *) Run4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Run4_PRTDSI__SYNC_OUT       (* (reg8 *) Run4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Run4__SIO_CFG)
    #define Run4_SIO_HYST_EN        (* (reg8 *) Run4__SIO_HYST_EN)
    #define Run4_SIO_REG_HIFREQ     (* (reg8 *) Run4__SIO_REG_HIFREQ)
    #define Run4_SIO_CFG            (* (reg8 *) Run4__SIO_CFG)
    #define Run4_SIO_DIFF           (* (reg8 *) Run4__SIO_DIFF)
#endif /* (Run4__SIO_CFG) */

/* Interrupt Registers */
#if defined(Run4__INTSTAT)
    #define Run4_INTSTAT            (* (reg8 *) Run4__INTSTAT)
    #define Run4_SNAP               (* (reg8 *) Run4__SNAP)
    
	#define Run4_0_INTTYPE_REG 		(* (reg8 *) Run4__0__INTTYPE)
#endif /* (Run4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Run4_H */


/* [] END OF FILE */
