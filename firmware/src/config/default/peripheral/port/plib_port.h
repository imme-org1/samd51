/*******************************************************************************
  PORT PLIB

  Company:
    Microchip Technology Inc.

  File Name:
    plib_port.h

  Summary:
    PORT PLIB Header File

  Description:
    This file provides an interface to control and interact with PORT-I/O
    Pin controller module.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#ifndef PLIB_PORT_H
#define PLIB_PORT_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "device.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
    extern "C" {
#endif
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Data types and constants
// *****************************************************************************
// *****************************************************************************

/*** Macros for VDD_MIC_EN pin ***/
#define VDD_MIC_EN_Set()               (PORT_REGS->GROUP[0].PORT_OUTSET = ((uint32_t)1U << 0U))
#define VDD_MIC_EN_Clear()             (PORT_REGS->GROUP[0].PORT_OUTCLR = ((uint32_t)1U << 0U))
#define VDD_MIC_EN_Toggle()            (PORT_REGS->GROUP[0].PORT_OUTTGL = ((uint32_t)1U << 0U))
#define VDD_MIC_EN_OutputEnable()      (PORT_REGS->GROUP[0].PORT_DIRSET = ((uint32_t)1U << 0U))
#define VDD_MIC_EN_InputEnable()       (PORT_REGS->GROUP[0].PORT_DIRCLR = ((uint32_t)1U << 0U))
#define VDD_MIC_EN_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 0U)) & 0x01U)
#define VDD_MIC_EN_PIN                  PORT_PIN_PA00

/*** Macros for ENCODER_L_KEY pin ***/
#define ENCODER_L_KEY_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 2U)) & 0x01U)
#define ENCODER_L_KEY_PIN                  PORT_PIN_PC02

/*** Macros for MFB_L pin ***/
#define MFB_L_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 3U)) & 0x01U)
#define MFB_L_PIN                  PORT_PIN_PC03

/*** Macros for U5V_DET pin ***/
#define U5V_DET_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 4U)) & 0x01U)
#define U5V_DET_PIN                  PORT_PIN_PB04

/*** Macros for USB_SEL pin ***/
#define USB_SEL_Set()               (PORT_REGS->GROUP[1].PORT_OUTSET = ((uint32_t)1U << 5U))
#define USB_SEL_Clear()             (PORT_REGS->GROUP[1].PORT_OUTCLR = ((uint32_t)1U << 5U))
#define USB_SEL_Toggle()            (PORT_REGS->GROUP[1].PORT_OUTTGL = ((uint32_t)1U << 5U))
#define USB_SEL_OutputEnable()      (PORT_REGS->GROUP[1].PORT_DIRSET = ((uint32_t)1U << 5U))
#define USB_SEL_InputEnable()       (PORT_REGS->GROUP[1].PORT_DIRCLR = ((uint32_t)1U << 5U))
#define USB_SEL_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 5U)) & 0x01U)
#define USB_SEL_PIN                  PORT_PIN_PB05

/*** Macros for U5V_DC_DC_EN pin ***/
#define U5V_DC_DC_EN_Set()               (PORT_REGS->GROUP[1].PORT_OUTSET = ((uint32_t)1U << 8U))
#define U5V_DC_DC_EN_Clear()             (PORT_REGS->GROUP[1].PORT_OUTCLR = ((uint32_t)1U << 8U))
#define U5V_DC_DC_EN_Toggle()            (PORT_REGS->GROUP[1].PORT_OUTTGL = ((uint32_t)1U << 8U))
#define U5V_DC_DC_EN_OutputEnable()      (PORT_REGS->GROUP[1].PORT_DIRSET = ((uint32_t)1U << 8U))
#define U5V_DC_DC_EN_InputEnable()       (PORT_REGS->GROUP[1].PORT_DIRCLR = ((uint32_t)1U << 8U))
#define U5V_DC_DC_EN_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 8U)) & 0x01U)
#define U5V_DC_DC_EN_PIN                  PORT_PIN_PB08

/*** Macros for LED_L_G pin ***/
#define LED_L_G_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 9U)) & 0x01U)
#define LED_L_G_PIN                  PORT_PIN_PB09

/*** Macros for CC1_DET pin ***/
#define CC1_DET_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 4U)) & 0x01U)
#define CC1_DET_PIN                  PORT_PIN_PA04

/*** Macros for CC2_DET pin ***/
#define CC2_DET_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 5U)) & 0x01U)
#define CC2_DET_PIN                  PORT_PIN_PA05

/*** Macros for INT_MCU pin ***/
#define INT_MCU_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 6U)) & 0x01U)
#define INT_MCU_PIN                  PORT_PIN_PC06

/*** Macros for SPI_SI_SDI0 pin ***/
#define SPI_SI_SDI0_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 8U)) & 0x01U)
#define SPI_SI_SDI0_PIN                  PORT_PIN_PA08

/*** Macros for SPI_SO_SIO1 pin ***/
#define SPI_SO_SIO1_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 9U)) & 0x01U)
#define SPI_SO_SIO1_PIN                  PORT_PIN_PA09

/*** Macros for SPI_WP pin ***/
#define SPI_WP_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 10U)) & 0x01U)
#define SPI_WP_PIN                  PORT_PIN_PA10

/*** Macros for SPI_SIO3 pin ***/
#define SPI_SIO3_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 11U)) & 0x01U)
#define SPI_SIO3_PIN                  PORT_PIN_PA11

/*** Macros for SPI_SCLK pin ***/
#define SPI_SCLK_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 10U)) & 0x01U)
#define SPI_SCLK_PIN                  PORT_PIN_PB10

/*** Macros for SPI_CS pin ***/
#define SPI_CS_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 11U)) & 0x01U)
#define SPI_CS_PIN                  PORT_PIN_PB11

/*** Macros for U3V3_VDD_EN pin ***/
#define U3V3_VDD_EN_Set()               (PORT_REGS->GROUP[1].PORT_OUTSET = ((uint32_t)1U << 12U))
#define U3V3_VDD_EN_Clear()             (PORT_REGS->GROUP[1].PORT_OUTCLR = ((uint32_t)1U << 12U))
#define U3V3_VDD_EN_Toggle()            (PORT_REGS->GROUP[1].PORT_OUTTGL = ((uint32_t)1U << 12U))
#define U3V3_VDD_EN_OutputEnable()      (PORT_REGS->GROUP[1].PORT_DIRSET = ((uint32_t)1U << 12U))
#define U3V3_VDD_EN_InputEnable()       (PORT_REGS->GROUP[1].PORT_DIRCLR = ((uint32_t)1U << 12U))
#define U3V3_VDD_EN_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 12U)) & 0x01U)
#define U3V3_VDD_EN_PIN                  PORT_PIN_PB12

/*** Macros for DSP_PWR_EN pin ***/
#define DSP_PWR_EN_Set()               (PORT_REGS->GROUP[1].PORT_OUTSET = ((uint32_t)1U << 13U))
#define DSP_PWR_EN_Clear()             (PORT_REGS->GROUP[1].PORT_OUTCLR = ((uint32_t)1U << 13U))
#define DSP_PWR_EN_Toggle()            (PORT_REGS->GROUP[1].PORT_OUTTGL = ((uint32_t)1U << 13U))
#define DSP_PWR_EN_OutputEnable()      (PORT_REGS->GROUP[1].PORT_DIRSET = ((uint32_t)1U << 13U))
#define DSP_PWR_EN_InputEnable()       (PORT_REGS->GROUP[1].PORT_DIRCLR = ((uint32_t)1U << 13U))
#define DSP_PWR_EN_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 13U)) & 0x01U)
#define DSP_PWR_EN_PIN                  PORT_PIN_PB13

/*** Macros for INT_G pin ***/
#define INT_G_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 14U)) & 0x01U)
#define INT_G_PIN                  PORT_PIN_PB14

/*** Macros for INT_IR pin ***/
#define INT_IR_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 15U)) & 0x01U)
#define INT_IR_PIN                  PORT_PIN_PB15

/*** Macros for SPI_DC_L pin ***/
#define SPI_DC_L_Set()               (PORT_REGS->GROUP[2].PORT_OUTSET = ((uint32_t)1U << 11U))
#define SPI_DC_L_Clear()             (PORT_REGS->GROUP[2].PORT_OUTCLR = ((uint32_t)1U << 11U))
#define SPI_DC_L_Toggle()            (PORT_REGS->GROUP[2].PORT_OUTTGL = ((uint32_t)1U << 11U))
#define SPI_DC_L_OutputEnable()      (PORT_REGS->GROUP[2].PORT_DIRSET = ((uint32_t)1U << 11U))
#define SPI_DC_L_InputEnable()       (PORT_REGS->GROUP[2].PORT_DIRCLR = ((uint32_t)1U << 11U))
#define SPI_DC_L_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 11U)) & 0x01U)
#define SPI_DC_L_PIN                  PORT_PIN_PC11

/*** Macros for SPI_SDA_L pin ***/
#define SPI_SDA_L_Set()               (PORT_REGS->GROUP[2].PORT_OUTSET = ((uint32_t)1U << 12U))
#define SPI_SDA_L_Clear()             (PORT_REGS->GROUP[2].PORT_OUTCLR = ((uint32_t)1U << 12U))
#define SPI_SDA_L_Toggle()            (PORT_REGS->GROUP[2].PORT_OUTTGL = ((uint32_t)1U << 12U))
#define SPI_SDA_L_OutputEnable()      (PORT_REGS->GROUP[2].PORT_DIRSET = ((uint32_t)1U << 12U))
#define SPI_SDA_L_InputEnable()       (PORT_REGS->GROUP[2].PORT_DIRCLR = ((uint32_t)1U << 12U))
#define SPI_SDA_L_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 12U)) & 0x01U)
#define SPI_SDA_L_PIN                  PORT_PIN_PC12

/*** Macros for SPI_SCL_L pin ***/
#define SPI_SCL_L_Set()               (PORT_REGS->GROUP[2].PORT_OUTSET = ((uint32_t)1U << 13U))
#define SPI_SCL_L_Clear()             (PORT_REGS->GROUP[2].PORT_OUTCLR = ((uint32_t)1U << 13U))
#define SPI_SCL_L_Toggle()            (PORT_REGS->GROUP[2].PORT_OUTTGL = ((uint32_t)1U << 13U))
#define SPI_SCL_L_OutputEnable()      (PORT_REGS->GROUP[2].PORT_DIRSET = ((uint32_t)1U << 13U))
#define SPI_SCL_L_InputEnable()       (PORT_REGS->GROUP[2].PORT_DIRCLR = ((uint32_t)1U << 13U))
#define SPI_SCL_L_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 13U)) & 0x01U)
#define SPI_SCL_L_PIN                  PORT_PIN_PC13

/*** Macros for SPI_CS_L pin ***/
#define SPI_CS_L_Set()               (PORT_REGS->GROUP[2].PORT_OUTSET = ((uint32_t)1U << 14U))
#define SPI_CS_L_Clear()             (PORT_REGS->GROUP[2].PORT_OUTCLR = ((uint32_t)1U << 14U))
#define SPI_CS_L_Toggle()            (PORT_REGS->GROUP[2].PORT_OUTTGL = ((uint32_t)1U << 14U))
#define SPI_CS_L_OutputEnable()      (PORT_REGS->GROUP[2].PORT_DIRSET = ((uint32_t)1U << 14U))
#define SPI_CS_L_InputEnable()       (PORT_REGS->GROUP[2].PORT_DIRCLR = ((uint32_t)1U << 14U))
#define SPI_CS_L_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 14U)) & 0x01U)
#define SPI_CS_L_PIN                  PORT_PIN_PC14

/*** Macros for I2C_SCL_G pin ***/
#define I2C_SCL_G_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 12U)) & 0x01U)
#define I2C_SCL_G_PIN                  PORT_PIN_PA12

/*** Macros for I2C_SDA_G pin ***/
#define I2C_SDA_G_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 13U)) & 0x01U)
#define I2C_SDA_G_PIN                  PORT_PIN_PA13

/*** Macros for I2C_SCL pin ***/
#define I2C_SCL_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 16U)) & 0x01U)
#define I2C_SCL_PIN                  PORT_PIN_PA16

/*** Macros for I2C_SDA pin ***/
#define I2C_SDA_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 17U)) & 0x01U)
#define I2C_SDA_PIN                  PORT_PIN_PA17

/*** Macros for RST_TOUCH_L pin ***/
#define RST_TOUCH_L_Set()               (PORT_REGS->GROUP[0].PORT_OUTSET = ((uint32_t)1U << 18U))
#define RST_TOUCH_L_Clear()             (PORT_REGS->GROUP[0].PORT_OUTCLR = ((uint32_t)1U << 18U))
#define RST_TOUCH_L_Toggle()            (PORT_REGS->GROUP[0].PORT_OUTTGL = ((uint32_t)1U << 18U))
#define RST_TOUCH_L_OutputEnable()      (PORT_REGS->GROUP[0].PORT_DIRSET = ((uint32_t)1U << 18U))
#define RST_TOUCH_L_InputEnable()       (PORT_REGS->GROUP[0].PORT_DIRCLR = ((uint32_t)1U << 18U))
#define RST_TOUCH_L_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 18U)) & 0x01U)
#define RST_TOUCH_L_PIN                  PORT_PIN_PA18

/*** Macros for RST_DIS_L1 pin ***/
#define RST_DIS_L1_Set()               (PORT_REGS->GROUP[0].PORT_OUTSET = ((uint32_t)1U << 19U))
#define RST_DIS_L1_Clear()             (PORT_REGS->GROUP[0].PORT_OUTCLR = ((uint32_t)1U << 19U))
#define RST_DIS_L1_Toggle()            (PORT_REGS->GROUP[0].PORT_OUTTGL = ((uint32_t)1U << 19U))
#define RST_DIS_L1_OutputEnable()      (PORT_REGS->GROUP[0].PORT_DIRSET = ((uint32_t)1U << 19U))
#define RST_DIS_L1_InputEnable()       (PORT_REGS->GROUP[0].PORT_DIRCLR = ((uint32_t)1U << 19U))
#define RST_DIS_L1_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 19U)) & 0x01U)
#define RST_DIS_L1_PIN                  PORT_PIN_PA19

/*** Macros for INT_CHG pin ***/
#define INT_CHG_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 16U)) & 0x01U)
#define INT_CHG_PIN                  PORT_PIN_PC16

/*** Macros for INT_TOUCH_L pin ***/
#define INT_TOUCH_L_Set()               (PORT_REGS->GROUP[2].PORT_OUTSET = ((uint32_t)1U << 17U))
#define INT_TOUCH_L_Clear()             (PORT_REGS->GROUP[2].PORT_OUTCLR = ((uint32_t)1U << 17U))
#define INT_TOUCH_L_Toggle()            (PORT_REGS->GROUP[2].PORT_OUTTGL = ((uint32_t)1U << 17U))
#define INT_TOUCH_L_OutputEnable()      (PORT_REGS->GROUP[2].PORT_DIRSET = ((uint32_t)1U << 17U))
#define INT_TOUCH_L_InputEnable()       (PORT_REGS->GROUP[2].PORT_DIRCLR = ((uint32_t)1U << 17U))
#define INT_TOUCH_L_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 17U)) & 0x01U)
#define INT_TOUCH_L_PIN                  PORT_PIN_PC17

/*** Macros for BUSY_L pin ***/
#define BUSY_L_Set()               (PORT_REGS->GROUP[2].PORT_OUTSET = ((uint32_t)1U << 18U))
#define BUSY_L_Clear()             (PORT_REGS->GROUP[2].PORT_OUTCLR = ((uint32_t)1U << 18U))
#define BUSY_L_Toggle()            (PORT_REGS->GROUP[2].PORT_OUTTGL = ((uint32_t)1U << 18U))
#define BUSY_L_OutputEnable()      (PORT_REGS->GROUP[2].PORT_DIRSET = ((uint32_t)1U << 18U))
#define BUSY_L_InputEnable()       (PORT_REGS->GROUP[2].PORT_DIRCLR = ((uint32_t)1U << 18U))
#define BUSY_L_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 18U)) & 0x01U)
#define BUSY_L_PIN                  PORT_PIN_PC18

/*** Macros for LCD_LED_L pin ***/
#define LCD_LED_L_Set()               (PORT_REGS->GROUP[2].PORT_OUTSET = ((uint32_t)1U << 19U))
#define LCD_LED_L_Clear()             (PORT_REGS->GROUP[2].PORT_OUTCLR = ((uint32_t)1U << 19U))
#define LCD_LED_L_Toggle()            (PORT_REGS->GROUP[2].PORT_OUTTGL = ((uint32_t)1U << 19U))
#define LCD_LED_L_OutputEnable()      (PORT_REGS->GROUP[2].PORT_DIRSET = ((uint32_t)1U << 19U))
#define LCD_LED_L_InputEnable()       (PORT_REGS->GROUP[2].PORT_DIRCLR = ((uint32_t)1U << 19U))
#define LCD_LED_L_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 19U)) & 0x01U)
#define LCD_LED_L_PIN                  PORT_PIN_PC19

/*** Macros for RS553_EN pin ***/
#define RS553_EN_Set()               (PORT_REGS->GROUP[2].PORT_OUTSET = ((uint32_t)1U << 20U))
#define RS553_EN_Clear()             (PORT_REGS->GROUP[2].PORT_OUTCLR = ((uint32_t)1U << 20U))
#define RS553_EN_Toggle()            (PORT_REGS->GROUP[2].PORT_OUTTGL = ((uint32_t)1U << 20U))
#define RS553_EN_OutputEnable()      (PORT_REGS->GROUP[2].PORT_DIRSET = ((uint32_t)1U << 20U))
#define RS553_EN_InputEnable()       (PORT_REGS->GROUP[2].PORT_DIRCLR = ((uint32_t)1U << 20U))
#define RS553_EN_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 20U)) & 0x01U)
#define RS553_EN_PIN                  PORT_PIN_PC20

/*** Macros for CC_PULL_UP pin ***/
#define CC_PULL_UP_Set()               (PORT_REGS->GROUP[2].PORT_OUTSET = ((uint32_t)1U << 21U))
#define CC_PULL_UP_Clear()             (PORT_REGS->GROUP[2].PORT_OUTCLR = ((uint32_t)1U << 21U))
#define CC_PULL_UP_Toggle()            (PORT_REGS->GROUP[2].PORT_OUTTGL = ((uint32_t)1U << 21U))
#define CC_PULL_UP_OutputEnable()      (PORT_REGS->GROUP[2].PORT_DIRSET = ((uint32_t)1U << 21U))
#define CC_PULL_UP_InputEnable()       (PORT_REGS->GROUP[2].PORT_DIRCLR = ((uint32_t)1U << 21U))
#define CC_PULL_UP_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 21U)) & 0x01U)
#define CC_PULL_UP_PIN                  PORT_PIN_PC21

/*** Macros for MCU_PB16_1V8_EN pin ***/
#define MCU_PB16_1V8_EN_Set()               (PORT_REGS->GROUP[1].PORT_OUTSET = ((uint32_t)1U << 16U))
#define MCU_PB16_1V8_EN_Clear()             (PORT_REGS->GROUP[1].PORT_OUTCLR = ((uint32_t)1U << 16U))
#define MCU_PB16_1V8_EN_Toggle()            (PORT_REGS->GROUP[1].PORT_OUTTGL = ((uint32_t)1U << 16U))
#define MCU_PB16_1V8_EN_OutputEnable()      (PORT_REGS->GROUP[1].PORT_DIRSET = ((uint32_t)1U << 16U))
#define MCU_PB16_1V8_EN_InputEnable()       (PORT_REGS->GROUP[1].PORT_DIRCLR = ((uint32_t)1U << 16U))
#define MCU_PB16_1V8_EN_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 16U)) & 0x01U)
#define MCU_PB16_1V8_EN_PIN                  PORT_PIN_PB16

/*** Macros for MCU_RESET_U6 pin ***/
#define MCU_RESET_U6_Set()               (PORT_REGS->GROUP[0].PORT_OUTSET = ((uint32_t)1U << 20U))
#define MCU_RESET_U6_Clear()             (PORT_REGS->GROUP[0].PORT_OUTCLR = ((uint32_t)1U << 20U))
#define MCU_RESET_U6_Toggle()            (PORT_REGS->GROUP[0].PORT_OUTTGL = ((uint32_t)1U << 20U))
#define MCU_RESET_U6_OutputEnable()      (PORT_REGS->GROUP[0].PORT_DIRSET = ((uint32_t)1U << 20U))
#define MCU_RESET_U6_InputEnable()       (PORT_REGS->GROUP[0].PORT_DIRCLR = ((uint32_t)1U << 20U))
#define MCU_RESET_U6_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 20U)) & 0x01U)
#define MCU_RESET_U6_PIN                  PORT_PIN_PA20

/*** Macros for REGEN_77 pin ***/
#define REGEN_77_Set()               (PORT_REGS->GROUP[0].PORT_OUTSET = ((uint32_t)1U << 21U))
#define REGEN_77_Clear()             (PORT_REGS->GROUP[0].PORT_OUTCLR = ((uint32_t)1U << 21U))
#define REGEN_77_Toggle()            (PORT_REGS->GROUP[0].PORT_OUTTGL = ((uint32_t)1U << 21U))
#define REGEN_77_OutputEnable()      (PORT_REGS->GROUP[0].PORT_DIRSET = ((uint32_t)1U << 21U))
#define REGEN_77_InputEnable()       (PORT_REGS->GROUP[0].PORT_DIRCLR = ((uint32_t)1U << 21U))
#define REGEN_77_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 21U)) & 0x01U)
#define REGEN_77_PIN                  PORT_PIN_PA21

/*** Macros for UART1_TX_MCU_77 pin ***/
#define UART1_TX_MCU_77_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 22U)) & 0x01U)
#define UART1_TX_MCU_77_PIN                  PORT_PIN_PA22

/*** Macros for UART1_RX_MCU_77 pin ***/
#define UART1_RX_MCU_77_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 23U)) & 0x01U)
#define UART1_RX_MCU_77_PIN                  PORT_PIN_PA23

/*** Macros for ENCODER_L_A pin ***/
#define ENCODER_L_A_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 24U)) & 0x01U)
#define ENCODER_L_A_PIN                  PORT_PIN_PA24

/*** Macros for ENCODER_L_B pin ***/
#define ENCODER_L_B_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 25U)) & 0x01U)
#define ENCODER_L_B_PIN                  PORT_PIN_PA25

/*** Macros for RESET_77 pin ***/
#define RESET_77_Set()               (PORT_REGS->GROUP[1].PORT_OUTSET = ((uint32_t)1U << 22U))
#define RESET_77_Clear()             (PORT_REGS->GROUP[1].PORT_OUTCLR = ((uint32_t)1U << 22U))
#define RESET_77_Toggle()            (PORT_REGS->GROUP[1].PORT_OUTTGL = ((uint32_t)1U << 22U))
#define RESET_77_OutputEnable()      (PORT_REGS->GROUP[1].PORT_DIRSET = ((uint32_t)1U << 22U))
#define RESET_77_InputEnable()       (PORT_REGS->GROUP[1].PORT_DIRCLR = ((uint32_t)1U << 22U))
#define RESET_77_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 22U)) & 0x01U)
#define RESET_77_PIN                  PORT_PIN_PB22

/*** Macros for MIC_DET pin ***/
#define MIC_DET_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 23U)) & 0x01U)
#define MIC_DET_PIN                  PORT_PIN_PB23

/*** Macros for SPI_MOSI pin ***/
#define SPI_MOSI_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 24U)) & 0x01U)
#define SPI_MOSI_PIN                  PORT_PIN_PB24

/*** Macros for SP_SCLK pin ***/
#define SP_SCLK_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 25U)) & 0x01U)
#define SP_SCLK_PIN                  PORT_PIN_PB25

/*** Macros for SPI_SS pin ***/
#define SPI_SS_Set()               (PORT_REGS->GROUP[2].PORT_OUTSET = ((uint32_t)1U << 24U))
#define SPI_SS_Clear()             (PORT_REGS->GROUP[2].PORT_OUTCLR = ((uint32_t)1U << 24U))
#define SPI_SS_Toggle()            (PORT_REGS->GROUP[2].PORT_OUTTGL = ((uint32_t)1U << 24U))
#define SPI_SS_OutputEnable()      (PORT_REGS->GROUP[2].PORT_DIRSET = ((uint32_t)1U << 24U))
#define SPI_SS_InputEnable()       (PORT_REGS->GROUP[2].PORT_DIRCLR = ((uint32_t)1U << 24U))
#define SPI_SS_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 24U)) & 0x01U)
#define SPI_SS_PIN                  PORT_PIN_PC24

/*** Macros for SPI_MISO pin ***/
#define SPI_MISO_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 25U)) & 0x01U)
#define SPI_MISO_PIN                  PORT_PIN_PC25

/*** Macros for UART_RX pin ***/
#define UART_RX_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 27U)) & 0x01U)
#define UART_RX_PIN                  PORT_PIN_PC27

/*** Macros for UART_TX pin ***/
#define UART_TX_Get()               (((PORT_REGS->GROUP[2].PORT_IN >> 28U)) & 0x01U)
#define UART_TX_PIN                  PORT_PIN_PC28

/*** Macros for ADAU1860_IRQ pin ***/
#define ADAU1860_IRQ_Get()               (((PORT_REGS->GROUP[0].PORT_IN >> 27U)) & 0x01U)
#define ADAU1860_IRQ_PIN                  PORT_PIN_PA27

/*** Macros for ADAU1860_BOOT pin ***/
#define ADAU1860_BOOT_Set()               (PORT_REGS->GROUP[1].PORT_OUTSET = ((uint32_t)1U << 30U))
#define ADAU1860_BOOT_Clear()             (PORT_REGS->GROUP[1].PORT_OUTCLR = ((uint32_t)1U << 30U))
#define ADAU1860_BOOT_Toggle()            (PORT_REGS->GROUP[1].PORT_OUTTGL = ((uint32_t)1U << 30U))
#define ADAU1860_BOOT_OutputEnable()      (PORT_REGS->GROUP[1].PORT_DIRSET = ((uint32_t)1U << 30U))
#define ADAU1860_BOOT_InputEnable()       (PORT_REGS->GROUP[1].PORT_DIRCLR = ((uint32_t)1U << 30U))
#define ADAU1860_BOOT_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 30U)) & 0x01U)
#define ADAU1860_BOOT_PIN                  PORT_PIN_PB30

/*** Macros for LED_MIC pin ***/
#define LED_MIC_Set()               (PORT_REGS->GROUP[1].PORT_OUTSET = ((uint32_t)1U << 31U))
#define LED_MIC_Clear()             (PORT_REGS->GROUP[1].PORT_OUTCLR = ((uint32_t)1U << 31U))
#define LED_MIC_Toggle()            (PORT_REGS->GROUP[1].PORT_OUTTGL = ((uint32_t)1U << 31U))
#define LED_MIC_OutputEnable()      (PORT_REGS->GROUP[1].PORT_DIRSET = ((uint32_t)1U << 31U))
#define LED_MIC_InputEnable()       (PORT_REGS->GROUP[1].PORT_DIRCLR = ((uint32_t)1U << 31U))
#define LED_MIC_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 31U)) & 0x01U)
#define LED_MIC_PIN                  PORT_PIN_PB31

/*** Macros for ADAU1860_PD pin ***/
#define ADAU1860_PD_Set()               (PORT_REGS->GROUP[1].PORT_OUTSET = ((uint32_t)1U << 0U))
#define ADAU1860_PD_Clear()             (PORT_REGS->GROUP[1].PORT_OUTCLR = ((uint32_t)1U << 0U))
#define ADAU1860_PD_Toggle()            (PORT_REGS->GROUP[1].PORT_OUTTGL = ((uint32_t)1U << 0U))
#define ADAU1860_PD_OutputEnable()      (PORT_REGS->GROUP[1].PORT_DIRSET = ((uint32_t)1U << 0U))
#define ADAU1860_PD_InputEnable()       (PORT_REGS->GROUP[1].PORT_DIRCLR = ((uint32_t)1U << 0U))
#define ADAU1860_PD_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 0U)) & 0x01U)
#define ADAU1860_PD_PIN                  PORT_PIN_PB00

/*** Macros for LED_L_R pin ***/
#define LED_L_R_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 1U)) & 0x01U)
#define LED_L_R_PIN                  PORT_PIN_PB01

/*** Macros for VDD_1V8_EN pin ***/
#define VDD_1V8_EN_Set()               (PORT_REGS->GROUP[1].PORT_OUTSET = ((uint32_t)1U << 2U))
#define VDD_1V8_EN_Clear()             (PORT_REGS->GROUP[1].PORT_OUTCLR = ((uint32_t)1U << 2U))
#define VDD_1V8_EN_Toggle()            (PORT_REGS->GROUP[1].PORT_OUTTGL = ((uint32_t)1U << 2U))
#define VDD_1V8_EN_OutputEnable()      (PORT_REGS->GROUP[1].PORT_DIRSET = ((uint32_t)1U << 2U))
#define VDD_1V8_EN_InputEnable()       (PORT_REGS->GROUP[1].PORT_DIRCLR = ((uint32_t)1U << 2U))
#define VDD_1V8_EN_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 2U)) & 0x01U)
#define VDD_1V8_EN_PIN                  PORT_PIN_PB02

/*** Macros for ADC0_AIN15 pin ***/
#define ADC0_AIN15_Get()               (((PORT_REGS->GROUP[1].PORT_IN >> 3U)) & 0x01U)
#define ADC0_AIN15_PIN                  PORT_PIN_PB03

// *****************************************************************************
/* PORT Group

  Summary:
    Identifies the port groups available on the device.

  Description:
    These macros identifies all the ports groups that are available on this
    device.

  Remarks:
    The caller should not use the constant expressions assigned to any of
    the preprocessor macros as these may vary between devices.

    Port groups shown here are the ones available on the selected device. Not
    all ports groups are implemented. Refer to the device specific datasheet
    for more details. The MHC will generate these macros with the port
    groups that are available on the device.
*/

/* Group 0 */
#define PORT_GROUP_0 (PORT_BASE_ADDRESS + (0U * 0x80U))

/* Group 1 */
#define PORT_GROUP_1 (PORT_BASE_ADDRESS + (1U * 0x80U))

/* Group 2 */
#define PORT_GROUP_2 (PORT_BASE_ADDRESS + (2U * 0x80U))


/* Helper macros to get port information from the pin */
#define GET_PORT_GROUP(pin)  ((PORT_GROUP)(PORT_BASE_ADDRESS + (0x80U * (((uint32_t)pin) >> 5U))))
#define GET_PIN_MASK(pin)   (((uint32_t)(0x1U)) << (((uint32_t)pin) & 0x1FU))

/* Named type for port group */
typedef uint32_t PORT_GROUP;


typedef enum
{
PERIPHERAL_FUNCTION_A = 0x0,
PERIPHERAL_FUNCTION_B = 0x1,
PERIPHERAL_FUNCTION_C = 0x2,
PERIPHERAL_FUNCTION_D = 0x3,
PERIPHERAL_FUNCTION_E = 0x4,
PERIPHERAL_FUNCTION_F = 0x5,
PERIPHERAL_FUNCTION_G = 0x6,
PERIPHERAL_FUNCTION_H = 0x7,
PERIPHERAL_FUNCTION_I = 0x8,
PERIPHERAL_FUNCTION_J = 0x9,
PERIPHERAL_FUNCTION_K = 0xA,
PERIPHERAL_FUNCTION_L = 0xB,
PERIPHERAL_FUNCTION_M = 0xC,
PERIPHERAL_FUNCTION_N = 0xD,

}PERIPHERAL_FUNCTION;

// *****************************************************************************
/* PORT Pins

  Summary:
    Identifies the available Ports pins.

  Description:
    This enumeration identifies all the ports pins that are available on this
    device.

  Remarks:
    The caller should not use the constant expressions assigned to any of
    the enumeration constants as these may vary between devices.

    Port pins shown here are the ones available on the selected device. Not
    all ports pins within a port group are implemented. Refer to the device
    specific datasheet for more details.
*/

typedef enum
{
    /* PA00 pin */
    PORT_PIN_PA00 = 0U,

    /* PA01 pin */
    PORT_PIN_PA01 = 1U,

    /* PA02 pin */
    PORT_PIN_PA02 = 2U,

    /* PA03 pin */
    PORT_PIN_PA03 = 3U,

    /* PA04 pin */
    PORT_PIN_PA04 = 4U,

    /* PA05 pin */
    PORT_PIN_PA05 = 5U,

    /* PA06 pin */
    PORT_PIN_PA06 = 6U,

    /* PA07 pin */
    PORT_PIN_PA07 = 7U,

    /* PA08 pin */
    PORT_PIN_PA08 = 8U,

    /* PA09 pin */
    PORT_PIN_PA09 = 9U,

    /* PA10 pin */
    PORT_PIN_PA10 = 10U,

    /* PA11 pin */
    PORT_PIN_PA11 = 11U,

    /* PA12 pin */
    PORT_PIN_PA12 = 12U,

    /* PA13 pin */
    PORT_PIN_PA13 = 13U,

    /* PA14 pin */
    PORT_PIN_PA14 = 14U,

    /* PA15 pin */
    PORT_PIN_PA15 = 15U,

    /* PA16 pin */
    PORT_PIN_PA16 = 16U,

    /* PA17 pin */
    PORT_PIN_PA17 = 17U,

    /* PA18 pin */
    PORT_PIN_PA18 = 18U,

    /* PA19 pin */
    PORT_PIN_PA19 = 19U,

    /* PA20 pin */
    PORT_PIN_PA20 = 20U,

    /* PA21 pin */
    PORT_PIN_PA21 = 21U,

    /* PA22 pin */
    PORT_PIN_PA22 = 22U,

    /* PA23 pin */
    PORT_PIN_PA23 = 23U,

    /* PA24 pin */
    PORT_PIN_PA24 = 24U,

    /* PA25 pin */
    PORT_PIN_PA25 = 25U,

    /* PA27 pin */
    PORT_PIN_PA27 = 27U,

    /* PA30 pin */
    PORT_PIN_PA30 = 30U,

    /* PA31 pin */
    PORT_PIN_PA31 = 31U,

    /* PB00 pin */
    PORT_PIN_PB00 = 32U,

    /* PB01 pin */
    PORT_PIN_PB01 = 33U,

    /* PB02 pin */
    PORT_PIN_PB02 = 34U,

    /* PB03 pin */
    PORT_PIN_PB03 = 35U,

    /* PB04 pin */
    PORT_PIN_PB04 = 36U,

    /* PB05 pin */
    PORT_PIN_PB05 = 37U,

    /* PB06 pin */
    PORT_PIN_PB06 = 38U,

    /* PB07 pin */
    PORT_PIN_PB07 = 39U,

    /* PB08 pin */
    PORT_PIN_PB08 = 40U,

    /* PB09 pin */
    PORT_PIN_PB09 = 41U,

    /* PB10 pin */
    PORT_PIN_PB10 = 42U,

    /* PB11 pin */
    PORT_PIN_PB11 = 43U,

    /* PB12 pin */
    PORT_PIN_PB12 = 44U,

    /* PB13 pin */
    PORT_PIN_PB13 = 45U,

    /* PB14 pin */
    PORT_PIN_PB14 = 46U,

    /* PB15 pin */
    PORT_PIN_PB15 = 47U,

    /* PB16 pin */
    PORT_PIN_PB16 = 48U,

    /* PB17 pin */
    PORT_PIN_PB17 = 49U,

    /* PB18 pin */
    PORT_PIN_PB18 = 50U,

    /* PB19 pin */
    PORT_PIN_PB19 = 51U,

    /* PB20 pin */
    PORT_PIN_PB20 = 52U,

    /* PB21 pin */
    PORT_PIN_PB21 = 53U,

    /* PB22 pin */
    PORT_PIN_PB22 = 54U,

    /* PB23 pin */
    PORT_PIN_PB23 = 55U,

    /* PB24 pin */
    PORT_PIN_PB24 = 56U,

    /* PB25 pin */
    PORT_PIN_PB25 = 57U,

    /* PB30 pin */
    PORT_PIN_PB30 = 62U,

    /* PB31 pin */
    PORT_PIN_PB31 = 63U,

    /* PC00 pin */
    PORT_PIN_PC00 = 64U,

    /* PC01 pin */
    PORT_PIN_PC01 = 65U,

    /* PC02 pin */
    PORT_PIN_PC02 = 66U,

    /* PC03 pin */
    PORT_PIN_PC03 = 67U,

    /* PC05 pin */
    PORT_PIN_PC05 = 69U,

    /* PC06 pin */
    PORT_PIN_PC06 = 70U,

    /* PC07 pin */
    PORT_PIN_PC07 = 71U,

    /* PC10 pin */
    PORT_PIN_PC10 = 74U,

    /* PC11 pin */
    PORT_PIN_PC11 = 75U,

    /* PC12 pin */
    PORT_PIN_PC12 = 76U,

    /* PC13 pin */
    PORT_PIN_PC13 = 77U,

    /* PC14 pin */
    PORT_PIN_PC14 = 78U,

    /* PC15 pin */
    PORT_PIN_PC15 = 79U,

    /* PC16 pin */
    PORT_PIN_PC16 = 80U,

    /* PC17 pin */
    PORT_PIN_PC17 = 81U,

    /* PC18 pin */
    PORT_PIN_PC18 = 82U,

    /* PC19 pin */
    PORT_PIN_PC19 = 83U,

    /* PC20 pin */
    PORT_PIN_PC20 = 84U,

    /* PC21 pin */
    PORT_PIN_PC21 = 85U,

    /* PC24 pin */
    PORT_PIN_PC24 = 88U,

    /* PC25 pin */
    PORT_PIN_PC25 = 89U,

    /* PC26 pin */
    PORT_PIN_PC26 = 90U,

    /* PC27 pin */
    PORT_PIN_PC27 = 91U,

    /* PC28 pin */
    PORT_PIN_PC28 = 92U,

    /* This element should not be used in any of the PORT APIs.
     * It will be used by other modules or application to denote that none of
     * the PORT Pin is used */
    PORT_PIN_NONE = 65535U,

} PORT_PIN;

// *****************************************************************************
// *****************************************************************************
// Section: Generated API based on pin configurations done in Pin Manager
// *****************************************************************************
// *****************************************************************************
// *****************************************************************************
/* Function:
    void PORT_Initialize(void)

  Summary:
    Initializes the PORT Library.

  Description:
    This function initializes all ports and pins as configured in the
    MHC Pin Manager.

  Precondition:
    None.

  Parameters:
    None.

  Returns:
    None.

  Example:
    <code>

    PORT_Initialize();

    </code>

  Remarks:
    The function should be called once before calling any other PORTS PLIB
    functions.
*/

void PORT_Initialize(void);

// *****************************************************************************
// *****************************************************************************
// Section: PORT APIs which operates on multiple pins of a group
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    uint32_t PORT_GroupRead(PORT_GROUP group)

  Summary:
    Read all the I/O pins in the specified port group.

  Description:
    The function reads the hardware pin state of all pins in the specified group
    and returns this as a 32 bit value. Each bit in the 32 bit value represent a
    pin. For example, bit 0 in group 0 will represent pin PA0. Bit 1 will
    represent PA1 and so on. The application should only consider the value of
    the port group pins which are implemented on the device.

  Precondition:
    The PORT_Initialize() function should have been called. Input buffer
    (INEN bit in the Pin Configuration register) should be enabled in MHC.

  Parameters:
    group - One of the IO groups from the enum PORT_GROUP.

  Returns:
    A 32-bit value representing the hardware state of of all the I/O pins in the
    selected port group.

  Example:
    <code>

    uint32_t value;
    value = PORT_Read(PORT_GROUP_C);

    </code>

  Remarks:
    None.
*/

uint32_t PORT_GroupRead(PORT_GROUP group);

// *****************************************************************************
/* Function:
    uint32_t PORT_GroupLatchRead(PORT_GROUP group)

  Summary:
    Read the data driven on all the I/O pins of the selected port group.

  Description:
    The function will return a 32-bit value representing the logic levels being
    driven on the output pins within the group. The function will not sample the
    actual hardware state of the output pin. Each bit in the 32-bit return value
    will represent one of the 32 port pins within the group. The application
    should only consider the value of the pins which are available on the
    device.

  Precondition:
    The PORT_Initialize() function should have been called.

  Parameters:
    group - One of the IO groups from the enum PORT_GROUP.

  Returns:
    A 32-bit value representing the output state of of all the I/O pins in the
    selected port group.

  Example:
    <code>

    uint32_t value;
    value = PORT_GroupLatchRead(PORT_GROUP_C);

    </code>

  Remarks:
    None.
*/

uint32_t PORT_GroupLatchRead(PORT_GROUP group);

// *****************************************************************************
/* Function:
    void PORT_GroupWrite(PORT_GROUP group, uint32_t mask, uint32_t value);

  Summary:
    Write value on the masked pins of the selected port group.

  Description:
    This function writes the value contained in the value parameter to the
    port group. Port group pins which are configured for output will be updated.
    The mask parameter provides additional control on the bits in the group to
    be affected. Setting a bit to 1 in the mask will cause the corresponding
    bit in the port group to be updated. Clearing a bit in the mask will cause
    that corresponding bit in the group to stay unaffected. For example,
    setting a mask value 0xFFFFFFFF will cause all bits in the port group
    to be updated. Setting a value 0x3 will only cause port group bit 0 and
    bit 1 to be updated.

    For port pins which are not configured for output and have the pull feature
    enabled, this function will affect pull value (pull up or pull down). A bit
    value of 1 will enable the pull up. A bit value of 0 will enable the pull
    down.

  Precondition:
    The PORT_Initialize() function should have been called.

  Parameters:
    group - One of the IO groups from the enum PORT_GROUP.

    mask  - A 32 bit value in which positions of 0s and 1s decide
             which IO pins of the selected port group will be written.
             1's - Will write to corresponding IO pins.
             0's - Will remain unchanged.

    value - Value which has to be written/driven on the I/O
             lines of the selected port for which mask bits are '1'.
             Values for the corresponding mask bit '0' will be ignored.
             Refer to the function description for effect on pins
             which are not configured for output.

  Returns:
    None.

  Example:
    <code>

    PORT_GroupWrite(PORT_GROUP_C, 0x0F, 0xF563D453);

    </code>

  Remarks:
    None.
*/

void PORT_GroupWrite(PORT_GROUP group, uint32_t mask, uint32_t value);

// *****************************************************************************
/* Function:
    void PORT_GroupSet(PORT_GROUP group, uint32_t mask)

  Summary:
    Set the selected IO pins of a group.

  Description:
    This function sets (drives a logic high) on the selected output pins of a
    group. The mask parameter control the pins to be updated. A mask bit
    position with a value 1 will cause that corresponding port pin to be set. A
    mask bit position with a value 0 will cause the corresponding port pin to
    stay un-affected.

  Precondition:
    The PORT_Initialize() function should have been called.

  Parameters:
    group - One of the IO ports from the enum PORT_GROUP.
    mask - A 32 bit value in which a bit represent a pin in the group. If the
    value of the bit is 1, the corresponding port pin will driven to logic 1. If
    the value of the bit is 0. the corresponding port pin will stay un-affected.

  Returns:
    None.

  Example:
    <code>

    PORT_GroupSet(PORT_GROUP_C, 0x00A0);

    </code>

  Remarks:
    If the port pin within the the group is not configured for output and has
    the pull feature enabled, driving a logic 1 on this pin will cause the pull
    up to be enabled.
*/

void PORT_GroupSet(PORT_GROUP group, uint32_t mask);

// *****************************************************************************
/* Function:
    void PORT_GroupClear(PORT_GROUP group, uint32_t mask)

  Summary:
    Clears the selected IO pins of a group.

  Description:
    This function clears (drives a logic 0) on the selected output pins of a
    group. The mask parameter control the pins to be updated. A mask bit
    position with a value 1 will cause that corresponding port pin to be clear.
    A mask bit position with a value 0 will cause the corresponding port pin to
    stay un-affected.

  Precondition:
    The PORT_Initialize() function should have been called.

  Parameters:
    group - One of the IO ports from the enum PORT_GROUP.
    mask - A 32 bit value in which a bit represent a pin in the group. If the
    value of the bit is 1, the corresponding port pin will driven to logic 0. If
    the value of the bit is 0. the corresponding port pin will stay un-affected.

  Returns:
    None.

  Example:
    <code>

    PORT_GroupClear(PORT_GROUP_C, 0x00A0);

    </code>

  Remarks:
    If the port pin within the the group is not configured for output and has
    the pull feature enabled, driving a logic 0 on this pin will cause the pull
    down to be enabled.
*/

void PORT_GroupClear(PORT_GROUP group, uint32_t mask);

// *****************************************************************************
/* Function:
    void PORT_GroupToggle(PORT_GROUP group, uint32_t mask)

  Summary:
    Toggles the selected IO pins of a group.

  Description:
    This function toggles the selected output pins of a group. The mask
    parameter control the pins to be updated. A mask bit position with a value 1
    will cause that corresponding port pin to be toggled.  A mask bit position
    with a value 0 will cause the corresponding port pin to stay un-affected.

  Precondition:
    The PORT_Initialize() function should have been called.

  Parameters:
    group - One of the IO ports from the enum PORT_GROUP.
    mask - A 32 bit value in which a bit represent a pin in the group. If the
    value of the bit is 1, the corresponding port pin will be toggled. If the
    value of the bit is 0. the corresponding port pin will stay un-affected.

  Returns:
    None.

  Example:
    <code>

    PORT_GroupToggle(PORT_GROUP_C, 0x00A0);

    </code>

  Remarks:
    If the port pin within the the group is not configured for output and has
    the pull feature enabled, driving a logic 0 on this pin will cause the pull
    down to be enabled. Driving a logic 1 on this pin will cause the pull up to
    be enabled.
*/

void PORT_GroupToggle(PORT_GROUP group, uint32_t mask);

// *****************************************************************************
/* Function:
    void PORT_GroupInputEnable(PORT_GROUP group, uint32_t mask)

  Summary:
    Configures the selected IO pins of a group as input.

  Description:
    This function configures the selected IO pins of a group as input. The pins
    to be configured as input are selected by setting the corresponding bits in
    the mask parameter to 1.

  Precondition:
    The PORT_Initialize() function should have been called.

  Parameters:
    group - One or more of the of the IO ports from the enum PORT_GROUP.
    mask - A 32 bit value in which a bit represents a pin in the group. If the
    value of the bit is 1, the corresponding port pin will be configured as
    input. If the value of the bit is 0. the corresponding port pin will stay
    un-affected.

  Returns:
    None.

  Example:
    <code>

    PORT_GroupInputEnable(PORT_GROUP_C, 0x00A0);

    </code>

  Remarks:
   None.
*/

void PORT_GroupInputEnable(PORT_GROUP group, uint32_t mask);

// *****************************************************************************
/* Function:
    void PORT_GroupOutputEnable(PORT_GROUP group, uint32_t mask)

  Summary:
    Configures the selected IO pins of a group as output.

  Description:
    This function configures the selected IO pins of a group as output. The pins
    to be configured as output are selected by setting the corresponding bits in
    the mask parameter to 1.

  Precondition:
    The PORT_Initialize() function should have been called.

  Parameters:
    group - One or more of the of the IO ports from the enum PORT_GROUP.
    mask - A 32 bit value in which a bit represents a pin in the group. If the
    value of the bit is 1, the corresponding port pin will be configured as
    output. If the value of the bit is 0. the corresponding port pin will stay
    un-affected.

  Returns:
    None.

  Example:
    <code>

    PORT_GroupOutputEnable(PORT_GROUP_C, 0x00A0);

    </code>

  Remarks:
    None.
*/

void PORT_GroupOutputEnable(PORT_GROUP group, uint32_t mask);

// *****************************************************************************
/* Function:
    void PORT_PinPeripheralFunctionConfig(PORT_PIN pin, PERIPHERAL_FUNCTION function)

  Summary:
    Configures the peripheral function on the selected port pin

  Description:
    This function configures the selected peripheral function on the given port pin.

  Remarks:
    None
*/
void PORT_PinPeripheralFunctionConfig(PORT_PIN pin, PERIPHERAL_FUNCTION function);

// *****************************************************************************
/* Function:
    void PORT_PinGPIOConfig(PORT_PIN pin)

  Summary:
    Configures the selected pin as GPIO

  Description:
    This function configures the given pin as GPIO.

  Remarks:
    None
*/
void PORT_PinGPIOConfig(PORT_PIN pin);

// *****************************************************************************
// *****************************************************************************
// Section: PORT APIs which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void PORT_PinWrite(PORT_PIN pin, bool value)

  Summary:
    Writes the specified value to the selected pin.

  Description:
    This function writes/drives the "value" on the selected I/O line/pin.

  Precondition:
    The PORT_Initialize() function should have been called once.

  Parameters:
    pin - One of the IO pins from the enum PORT_PIN.
    value - value to be written on the selected pin.
            true  = set pin to high (1).
            false = clear pin to low (0).

  Returns:
    None.

  Example:
    <code>

    bool value = true;
    PORT_PinWrite(PORT_PIN_PB3, value);

    </code>

  Remarks:
    Calling this function with an input pin with the pull-up/pull-down feature
    enabled will affect the pull-up/pull-down configuration. If the value is
    false, the pull-down will be enabled. If the value is true, the pull-up will
    be enabled.
*/

static inline void PORT_PinWrite(PORT_PIN pin, bool value)
{
    PORT_GroupWrite(GET_PORT_GROUP(pin),
                    GET_PIN_MASK(pin),
                    (value ? GET_PIN_MASK(pin) : 0U));
}


// *****************************************************************************
/* Function:
    bool PORT_PinRead(PORT_PIN pin)

  Summary:
    Read the selected pin value.

  Description:
    This function reads the present state at the selected input pin.  The
    function can also be called to read the value of an output pin if input
    sampling on the output pin is enabled in MHC. If input synchronization on
    the pin is disabled in MHC, the function will cause a 2 PORT Clock cycles
    delay. Enabling the synchronization eliminates the delay but will increase
    power consumption.

  Precondition:
    The PORT_Initialize() function should have been called. Input buffer
    (INEN bit in the Pin Configuration register) should be enabled in MHC.

  Parameters:
    pin - the port pin whose state needs to be read.

  Returns:
    true - the state at the pin is a logic high.
    false - the state at the pin is a logic low.

  Example:
    <code>

    bool value;
    value = PORT_PinRead(PORT_PIN_PB3);

    </code>

  Remarks:
    None.
*/

static inline bool PORT_PinRead(PORT_PIN pin)
{
    return ((PORT_GroupRead(GET_PORT_GROUP(pin)) & GET_PIN_MASK(pin)) != 0U);
}


// *****************************************************************************
/* Function:
    bool PORT_PinLatchRead(PORT_PIN pin)

  Summary:
    Read the value driven on the selected pin.

  Description:
    This function reads the data driven on the selected I/O line/pin. The
    function does not sample the state of the hardware pin. It only returns the
    value that is written to output register. Refer to the PORT_PinRead()
    function if the state of the output pin needs to be read.

  Precondition:
    The PORT_Initialize() function should have been called.

  Parameters:
    pin - One of the IO pins from the enum PORT_PIN.

  Returns:
    true - the present value in the output latch is a logic high.
    false - the present value in the output latch is a logic low.

  Example:
    <code>

    bool value;
    value = PORT_PinLatchRead(PORT_PIN_PB3);

    </code>

  Remarks:
    To read actual pin value, PIN_Read API should be used.
*/

static inline bool PORT_PinLatchRead(PORT_PIN pin)
{
    return ((PORT_GroupLatchRead(GET_PORT_GROUP(pin)) & GET_PIN_MASK(pin)) != 0U);
}


// *****************************************************************************
/* Function:
    void PORT_PinToggle(PORT_PIN pin)

  Summary:
    Toggles the selected pin.

  Description:
    This function toggles/inverts the present value on the selected I/O line/pin.

  Precondition:
    The PORT_Initialize() function should have been called.

  Parameters:
    pin - One of the IO pins from the enum PORT_PIN.

  Returns:
    None.

  Example:
    <code>

    PORT_PinToggle(PORT_PIN_PB3);

    </code>

  Remarks:
    None.
*/

static inline void PORT_PinToggle(PORT_PIN pin)
{
    PORT_GroupToggle(GET_PORT_GROUP(pin), GET_PIN_MASK(pin));
}


// *****************************************************************************
/* Function:
    void PORT_PinSet(PORT_PIN pin)

  Summary:
    Sets the selected pin.

  Description:
    This function drives a logic 1 on the selected I/O line/pin.

  Precondition:
    The PORT_Initialize() function should have been called.

  Parameters:
    pin - One of the IO pins from the enum PORT_PIN.

  Returns:
    None.

  Example:
    <code>

    PORT_PinSet(PORT_PIN_PB3);

    </code>

  Remarks:
    None.
*/

static inline void PORT_PinSet(PORT_PIN pin)
{
    PORT_GroupSet(GET_PORT_GROUP(pin), GET_PIN_MASK(pin));
}


// *****************************************************************************
/* Function:
    void PORT_PinClear(PORT_PIN pin)

  Summary:
    Clears the selected pin.

  Description:
    This function drives a logic 0 on the selected I/O line/pin.

  Precondition:
    The PORT_Initialize() function should have been called.

  Parameters:
    pin - One of the IO pins from the enum PORT_PIN.

  Returns:
    None.

  Example:
    <code>

    PORT_PinClear(PORT_PIN_PB3);

    </code>

  Remarks:
    None.
*/

static inline void PORT_PinClear(PORT_PIN pin)
{
    PORT_GroupClear(GET_PORT_GROUP(pin), GET_PIN_MASK(pin));
}


// *****************************************************************************
/* Function:
    void PORT_PinInputEnable(PORT_PIN pin)

  Summary:
    Configures the selected IO pin as input.

  Description:
    This function configures the selected IO pin as input. This function
    override the MHC input output pin settings.

  Precondition:
    The PORT_Initialize() function should have been called.

  Parameters:
    pin - One of the IO pins from the enum PORT_PIN.

  Returns:
    None.

  Example:
    <code>

    PORT_PinInputEnable(PORT_PIN_PB3);

    </code>

  Remarks:
    None.
*/

static inline void PORT_PinInputEnable(PORT_PIN pin)
{
    PORT_GroupInputEnable(GET_PORT_GROUP(pin), GET_PIN_MASK(pin));
}


// *****************************************************************************
/* Function:
    void PORT_PinOutputEnable(PORT_PIN pin)

  Summary:
    Enables selected IO pin as output.

  Description:
    This function enables selected IO pin as output. Calling this function will
    override the MHC input output pin configuration.

  Precondition:
    The PORT_Initialize() function should have been called.

  Parameters:
    pin - One of the IO pins from the enum PORT_PIN.

  Returns:
    None.

  Example:
    <code>

    PORT_PinOutputEnable(PORT_PIN_PB3);

    </code>

  Remarks:
    None.
*/

static inline void PORT_PinOutputEnable(PORT_PIN pin)
{
    PORT_GroupOutputEnable(GET_PORT_GROUP(pin), GET_PIN_MASK(pin));
}

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

}

#endif
// DOM-IGNORE-END
#endif // PLIB_PORT_H
