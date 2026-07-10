/*******************************************************************************
* File Name: decoder.h  
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

#if !defined(CY_PINS_decoder_H) /* Pins decoder_H */
#define CY_PINS_decoder_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "decoder_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 decoder__PORT == 15 && ((decoder__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    decoder_Write(uint8 value);
void    decoder_SetDriveMode(uint8 mode);
uint8   decoder_ReadDataReg(void);
uint8   decoder_Read(void);
void    decoder_SetInterruptMode(uint16 position, uint16 mode);
uint8   decoder_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the decoder_SetDriveMode() function.
     *  @{
     */
        #define decoder_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define decoder_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define decoder_DM_RES_UP          PIN_DM_RES_UP
        #define decoder_DM_RES_DWN         PIN_DM_RES_DWN
        #define decoder_DM_OD_LO           PIN_DM_OD_LO
        #define decoder_DM_OD_HI           PIN_DM_OD_HI
        #define decoder_DM_STRONG          PIN_DM_STRONG
        #define decoder_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define decoder_MASK               decoder__MASK
#define decoder_SHIFT              decoder__SHIFT
#define decoder_WIDTH              1u

/* Interrupt constants */
#if defined(decoder__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in decoder_SetInterruptMode() function.
     *  @{
     */
        #define decoder_INTR_NONE      (uint16)(0x0000u)
        #define decoder_INTR_RISING    (uint16)(0x0001u)
        #define decoder_INTR_FALLING   (uint16)(0x0002u)
        #define decoder_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define decoder_INTR_MASK      (0x01u) 
#endif /* (decoder__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define decoder_PS                     (* (reg8 *) decoder__PS)
/* Data Register */
#define decoder_DR                     (* (reg8 *) decoder__DR)
/* Port Number */
#define decoder_PRT_NUM                (* (reg8 *) decoder__PRT) 
/* Connect to Analog Globals */                                                  
#define decoder_AG                     (* (reg8 *) decoder__AG)                       
/* Analog MUX bux enable */
#define decoder_AMUX                   (* (reg8 *) decoder__AMUX) 
/* Bidirectional Enable */                                                        
#define decoder_BIE                    (* (reg8 *) decoder__BIE)
/* Bit-mask for Aliased Register Access */
#define decoder_BIT_MASK               (* (reg8 *) decoder__BIT_MASK)
/* Bypass Enable */
#define decoder_BYP                    (* (reg8 *) decoder__BYP)
/* Port wide control signals */                                                   
#define decoder_CTL                    (* (reg8 *) decoder__CTL)
/* Drive Modes */
#define decoder_DM0                    (* (reg8 *) decoder__DM0) 
#define decoder_DM1                    (* (reg8 *) decoder__DM1)
#define decoder_DM2                    (* (reg8 *) decoder__DM2) 
/* Input Buffer Disable Override */
#define decoder_INP_DIS                (* (reg8 *) decoder__INP_DIS)
/* LCD Common or Segment Drive */
#define decoder_LCD_COM_SEG            (* (reg8 *) decoder__LCD_COM_SEG)
/* Enable Segment LCD */
#define decoder_LCD_EN                 (* (reg8 *) decoder__LCD_EN)
/* Slew Rate Control */
#define decoder_SLW                    (* (reg8 *) decoder__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define decoder_PRTDSI__CAPS_SEL       (* (reg8 *) decoder__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define decoder_PRTDSI__DBL_SYNC_IN    (* (reg8 *) decoder__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define decoder_PRTDSI__OE_SEL0        (* (reg8 *) decoder__PRTDSI__OE_SEL0) 
#define decoder_PRTDSI__OE_SEL1        (* (reg8 *) decoder__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define decoder_PRTDSI__OUT_SEL0       (* (reg8 *) decoder__PRTDSI__OUT_SEL0) 
#define decoder_PRTDSI__OUT_SEL1       (* (reg8 *) decoder__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define decoder_PRTDSI__SYNC_OUT       (* (reg8 *) decoder__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(decoder__SIO_CFG)
    #define decoder_SIO_HYST_EN        (* (reg8 *) decoder__SIO_HYST_EN)
    #define decoder_SIO_REG_HIFREQ     (* (reg8 *) decoder__SIO_REG_HIFREQ)
    #define decoder_SIO_CFG            (* (reg8 *) decoder__SIO_CFG)
    #define decoder_SIO_DIFF           (* (reg8 *) decoder__SIO_DIFF)
#endif /* (decoder__SIO_CFG) */

/* Interrupt Registers */
#if defined(decoder__INTSTAT)
    #define decoder_INTSTAT            (* (reg8 *) decoder__INTSTAT)
    #define decoder_SNAP               (* (reg8 *) decoder__SNAP)
    
	#define decoder_0_INTTYPE_REG 		(* (reg8 *) decoder__0__INTTYPE)
#endif /* (decoder__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_decoder_H */


/* [] END OF FILE */
