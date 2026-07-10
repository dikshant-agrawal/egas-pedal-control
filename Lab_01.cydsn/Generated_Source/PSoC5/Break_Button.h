/*******************************************************************************
* File Name: Break_Button.h  
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

#if !defined(CY_PINS_Break_Button_H) /* Pins Break_Button_H */
#define CY_PINS_Break_Button_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Break_Button_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Break_Button__PORT == 15 && ((Break_Button__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Break_Button_Write(uint8 value);
void    Break_Button_SetDriveMode(uint8 mode);
uint8   Break_Button_ReadDataReg(void);
uint8   Break_Button_Read(void);
void    Break_Button_SetInterruptMode(uint16 position, uint16 mode);
uint8   Break_Button_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Break_Button_SetDriveMode() function.
     *  @{
     */
        #define Break_Button_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Break_Button_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Break_Button_DM_RES_UP          PIN_DM_RES_UP
        #define Break_Button_DM_RES_DWN         PIN_DM_RES_DWN
        #define Break_Button_DM_OD_LO           PIN_DM_OD_LO
        #define Break_Button_DM_OD_HI           PIN_DM_OD_HI
        #define Break_Button_DM_STRONG          PIN_DM_STRONG
        #define Break_Button_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Break_Button_MASK               Break_Button__MASK
#define Break_Button_SHIFT              Break_Button__SHIFT
#define Break_Button_WIDTH              1u

/* Interrupt constants */
#if defined(Break_Button__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Break_Button_SetInterruptMode() function.
     *  @{
     */
        #define Break_Button_INTR_NONE      (uint16)(0x0000u)
        #define Break_Button_INTR_RISING    (uint16)(0x0001u)
        #define Break_Button_INTR_FALLING   (uint16)(0x0002u)
        #define Break_Button_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Break_Button_INTR_MASK      (0x01u) 
#endif /* (Break_Button__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Break_Button_PS                     (* (reg8 *) Break_Button__PS)
/* Data Register */
#define Break_Button_DR                     (* (reg8 *) Break_Button__DR)
/* Port Number */
#define Break_Button_PRT_NUM                (* (reg8 *) Break_Button__PRT) 
/* Connect to Analog Globals */                                                  
#define Break_Button_AG                     (* (reg8 *) Break_Button__AG)                       
/* Analog MUX bux enable */
#define Break_Button_AMUX                   (* (reg8 *) Break_Button__AMUX) 
/* Bidirectional Enable */                                                        
#define Break_Button_BIE                    (* (reg8 *) Break_Button__BIE)
/* Bit-mask for Aliased Register Access */
#define Break_Button_BIT_MASK               (* (reg8 *) Break_Button__BIT_MASK)
/* Bypass Enable */
#define Break_Button_BYP                    (* (reg8 *) Break_Button__BYP)
/* Port wide control signals */                                                   
#define Break_Button_CTL                    (* (reg8 *) Break_Button__CTL)
/* Drive Modes */
#define Break_Button_DM0                    (* (reg8 *) Break_Button__DM0) 
#define Break_Button_DM1                    (* (reg8 *) Break_Button__DM1)
#define Break_Button_DM2                    (* (reg8 *) Break_Button__DM2) 
/* Input Buffer Disable Override */
#define Break_Button_INP_DIS                (* (reg8 *) Break_Button__INP_DIS)
/* LCD Common or Segment Drive */
#define Break_Button_LCD_COM_SEG            (* (reg8 *) Break_Button__LCD_COM_SEG)
/* Enable Segment LCD */
#define Break_Button_LCD_EN                 (* (reg8 *) Break_Button__LCD_EN)
/* Slew Rate Control */
#define Break_Button_SLW                    (* (reg8 *) Break_Button__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Break_Button_PRTDSI__CAPS_SEL       (* (reg8 *) Break_Button__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Break_Button_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Break_Button__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Break_Button_PRTDSI__OE_SEL0        (* (reg8 *) Break_Button__PRTDSI__OE_SEL0) 
#define Break_Button_PRTDSI__OE_SEL1        (* (reg8 *) Break_Button__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Break_Button_PRTDSI__OUT_SEL0       (* (reg8 *) Break_Button__PRTDSI__OUT_SEL0) 
#define Break_Button_PRTDSI__OUT_SEL1       (* (reg8 *) Break_Button__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Break_Button_PRTDSI__SYNC_OUT       (* (reg8 *) Break_Button__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Break_Button__SIO_CFG)
    #define Break_Button_SIO_HYST_EN        (* (reg8 *) Break_Button__SIO_HYST_EN)
    #define Break_Button_SIO_REG_HIFREQ     (* (reg8 *) Break_Button__SIO_REG_HIFREQ)
    #define Break_Button_SIO_CFG            (* (reg8 *) Break_Button__SIO_CFG)
    #define Break_Button_SIO_DIFF           (* (reg8 *) Break_Button__SIO_DIFF)
#endif /* (Break_Button__SIO_CFG) */

/* Interrupt Registers */
#if defined(Break_Button__INTSTAT)
    #define Break_Button_INTSTAT            (* (reg8 *) Break_Button__INTSTAT)
    #define Break_Button_SNAP               (* (reg8 *) Break_Button__SNAP)
    
	#define Break_Button_0_INTTYPE_REG 		(* (reg8 *) Break_Button__0__INTTYPE)
#endif /* (Break_Button__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Break_Button_H */


/* [] END OF FILE */
