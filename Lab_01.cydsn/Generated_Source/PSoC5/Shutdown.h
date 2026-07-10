/*******************************************************************************
* File Name: Shutdown.h  
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

#if !defined(CY_PINS_Shutdown_H) /* Pins Shutdown_H */
#define CY_PINS_Shutdown_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Shutdown_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Shutdown__PORT == 15 && ((Shutdown__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Shutdown_Write(uint8 value);
void    Shutdown_SetDriveMode(uint8 mode);
uint8   Shutdown_ReadDataReg(void);
uint8   Shutdown_Read(void);
void    Shutdown_SetInterruptMode(uint16 position, uint16 mode);
uint8   Shutdown_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Shutdown_SetDriveMode() function.
     *  @{
     */
        #define Shutdown_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Shutdown_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Shutdown_DM_RES_UP          PIN_DM_RES_UP
        #define Shutdown_DM_RES_DWN         PIN_DM_RES_DWN
        #define Shutdown_DM_OD_LO           PIN_DM_OD_LO
        #define Shutdown_DM_OD_HI           PIN_DM_OD_HI
        #define Shutdown_DM_STRONG          PIN_DM_STRONG
        #define Shutdown_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Shutdown_MASK               Shutdown__MASK
#define Shutdown_SHIFT              Shutdown__SHIFT
#define Shutdown_WIDTH              1u

/* Interrupt constants */
#if defined(Shutdown__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Shutdown_SetInterruptMode() function.
     *  @{
     */
        #define Shutdown_INTR_NONE      (uint16)(0x0000u)
        #define Shutdown_INTR_RISING    (uint16)(0x0001u)
        #define Shutdown_INTR_FALLING   (uint16)(0x0002u)
        #define Shutdown_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Shutdown_INTR_MASK      (0x01u) 
#endif /* (Shutdown__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Shutdown_PS                     (* (reg8 *) Shutdown__PS)
/* Data Register */
#define Shutdown_DR                     (* (reg8 *) Shutdown__DR)
/* Port Number */
#define Shutdown_PRT_NUM                (* (reg8 *) Shutdown__PRT) 
/* Connect to Analog Globals */                                                  
#define Shutdown_AG                     (* (reg8 *) Shutdown__AG)                       
/* Analog MUX bux enable */
#define Shutdown_AMUX                   (* (reg8 *) Shutdown__AMUX) 
/* Bidirectional Enable */                                                        
#define Shutdown_BIE                    (* (reg8 *) Shutdown__BIE)
/* Bit-mask for Aliased Register Access */
#define Shutdown_BIT_MASK               (* (reg8 *) Shutdown__BIT_MASK)
/* Bypass Enable */
#define Shutdown_BYP                    (* (reg8 *) Shutdown__BYP)
/* Port wide control signals */                                                   
#define Shutdown_CTL                    (* (reg8 *) Shutdown__CTL)
/* Drive Modes */
#define Shutdown_DM0                    (* (reg8 *) Shutdown__DM0) 
#define Shutdown_DM1                    (* (reg8 *) Shutdown__DM1)
#define Shutdown_DM2                    (* (reg8 *) Shutdown__DM2) 
/* Input Buffer Disable Override */
#define Shutdown_INP_DIS                (* (reg8 *) Shutdown__INP_DIS)
/* LCD Common or Segment Drive */
#define Shutdown_LCD_COM_SEG            (* (reg8 *) Shutdown__LCD_COM_SEG)
/* Enable Segment LCD */
#define Shutdown_LCD_EN                 (* (reg8 *) Shutdown__LCD_EN)
/* Slew Rate Control */
#define Shutdown_SLW                    (* (reg8 *) Shutdown__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Shutdown_PRTDSI__CAPS_SEL       (* (reg8 *) Shutdown__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Shutdown_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Shutdown__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Shutdown_PRTDSI__OE_SEL0        (* (reg8 *) Shutdown__PRTDSI__OE_SEL0) 
#define Shutdown_PRTDSI__OE_SEL1        (* (reg8 *) Shutdown__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Shutdown_PRTDSI__OUT_SEL0       (* (reg8 *) Shutdown__PRTDSI__OUT_SEL0) 
#define Shutdown_PRTDSI__OUT_SEL1       (* (reg8 *) Shutdown__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Shutdown_PRTDSI__SYNC_OUT       (* (reg8 *) Shutdown__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Shutdown__SIO_CFG)
    #define Shutdown_SIO_HYST_EN        (* (reg8 *) Shutdown__SIO_HYST_EN)
    #define Shutdown_SIO_REG_HIFREQ     (* (reg8 *) Shutdown__SIO_REG_HIFREQ)
    #define Shutdown_SIO_CFG            (* (reg8 *) Shutdown__SIO_CFG)
    #define Shutdown_SIO_DIFF           (* (reg8 *) Shutdown__SIO_DIFF)
#endif /* (Shutdown__SIO_CFG) */

/* Interrupt Registers */
#if defined(Shutdown__INTSTAT)
    #define Shutdown_INTSTAT            (* (reg8 *) Shutdown__INTSTAT)
    #define Shutdown_SNAP               (* (reg8 *) Shutdown__SNAP)
    
	#define Shutdown_0_INTTYPE_REG 		(* (reg8 *) Shutdown__0__INTTYPE)
#endif /* (Shutdown__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Shutdown_H */


/* [] END OF FILE */
