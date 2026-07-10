/*******************************************************************************
* File Name: engine_out1.h  
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

#if !defined(CY_PINS_engine_out1_H) /* Pins engine_out1_H */
#define CY_PINS_engine_out1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "engine_out1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 engine_out1__PORT == 15 && ((engine_out1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    engine_out1_Write(uint8 value);
void    engine_out1_SetDriveMode(uint8 mode);
uint8   engine_out1_ReadDataReg(void);
uint8   engine_out1_Read(void);
void    engine_out1_SetInterruptMode(uint16 position, uint16 mode);
uint8   engine_out1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the engine_out1_SetDriveMode() function.
     *  @{
     */
        #define engine_out1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define engine_out1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define engine_out1_DM_RES_UP          PIN_DM_RES_UP
        #define engine_out1_DM_RES_DWN         PIN_DM_RES_DWN
        #define engine_out1_DM_OD_LO           PIN_DM_OD_LO
        #define engine_out1_DM_OD_HI           PIN_DM_OD_HI
        #define engine_out1_DM_STRONG          PIN_DM_STRONG
        #define engine_out1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define engine_out1_MASK               engine_out1__MASK
#define engine_out1_SHIFT              engine_out1__SHIFT
#define engine_out1_WIDTH              1u

/* Interrupt constants */
#if defined(engine_out1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in engine_out1_SetInterruptMode() function.
     *  @{
     */
        #define engine_out1_INTR_NONE      (uint16)(0x0000u)
        #define engine_out1_INTR_RISING    (uint16)(0x0001u)
        #define engine_out1_INTR_FALLING   (uint16)(0x0002u)
        #define engine_out1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define engine_out1_INTR_MASK      (0x01u) 
#endif /* (engine_out1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define engine_out1_PS                     (* (reg8 *) engine_out1__PS)
/* Data Register */
#define engine_out1_DR                     (* (reg8 *) engine_out1__DR)
/* Port Number */
#define engine_out1_PRT_NUM                (* (reg8 *) engine_out1__PRT) 
/* Connect to Analog Globals */                                                  
#define engine_out1_AG                     (* (reg8 *) engine_out1__AG)                       
/* Analog MUX bux enable */
#define engine_out1_AMUX                   (* (reg8 *) engine_out1__AMUX) 
/* Bidirectional Enable */                                                        
#define engine_out1_BIE                    (* (reg8 *) engine_out1__BIE)
/* Bit-mask for Aliased Register Access */
#define engine_out1_BIT_MASK               (* (reg8 *) engine_out1__BIT_MASK)
/* Bypass Enable */
#define engine_out1_BYP                    (* (reg8 *) engine_out1__BYP)
/* Port wide control signals */                                                   
#define engine_out1_CTL                    (* (reg8 *) engine_out1__CTL)
/* Drive Modes */
#define engine_out1_DM0                    (* (reg8 *) engine_out1__DM0) 
#define engine_out1_DM1                    (* (reg8 *) engine_out1__DM1)
#define engine_out1_DM2                    (* (reg8 *) engine_out1__DM2) 
/* Input Buffer Disable Override */
#define engine_out1_INP_DIS                (* (reg8 *) engine_out1__INP_DIS)
/* LCD Common or Segment Drive */
#define engine_out1_LCD_COM_SEG            (* (reg8 *) engine_out1__LCD_COM_SEG)
/* Enable Segment LCD */
#define engine_out1_LCD_EN                 (* (reg8 *) engine_out1__LCD_EN)
/* Slew Rate Control */
#define engine_out1_SLW                    (* (reg8 *) engine_out1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define engine_out1_PRTDSI__CAPS_SEL       (* (reg8 *) engine_out1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define engine_out1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) engine_out1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define engine_out1_PRTDSI__OE_SEL0        (* (reg8 *) engine_out1__PRTDSI__OE_SEL0) 
#define engine_out1_PRTDSI__OE_SEL1        (* (reg8 *) engine_out1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define engine_out1_PRTDSI__OUT_SEL0       (* (reg8 *) engine_out1__PRTDSI__OUT_SEL0) 
#define engine_out1_PRTDSI__OUT_SEL1       (* (reg8 *) engine_out1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define engine_out1_PRTDSI__SYNC_OUT       (* (reg8 *) engine_out1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(engine_out1__SIO_CFG)
    #define engine_out1_SIO_HYST_EN        (* (reg8 *) engine_out1__SIO_HYST_EN)
    #define engine_out1_SIO_REG_HIFREQ     (* (reg8 *) engine_out1__SIO_REG_HIFREQ)
    #define engine_out1_SIO_CFG            (* (reg8 *) engine_out1__SIO_CFG)
    #define engine_out1_SIO_DIFF           (* (reg8 *) engine_out1__SIO_DIFF)
#endif /* (engine_out1__SIO_CFG) */

/* Interrupt Registers */
#if defined(engine_out1__INTSTAT)
    #define engine_out1_INTSTAT            (* (reg8 *) engine_out1__INTSTAT)
    #define engine_out1_SNAP               (* (reg8 *) engine_out1__SNAP)
    
	#define engine_out1_0_INTTYPE_REG 		(* (reg8 *) engine_out1__0__INTTYPE)
#endif /* (engine_out1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_engine_out1_H */


/* [] END OF FILE */
