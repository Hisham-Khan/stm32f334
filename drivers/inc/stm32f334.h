#ifndef STM32F334_H
#define STM32F334_H

#include "std_types.h"

// Base Addresses for Key Peripherals
#define APB1_BASE           0x40000000U // APB1 Peripheral Base Address
#define APB2_BASE           0x40010000U // APB2 Peripheral Base Address
#define AHB1_BASE           0x40020000U // AHB1 Peripheral Base Address
#define AHB2_BASE           0x48000000U // AHB2 Peripheral Base Address
#define AHB3_BASE           0x50000000U // AHB3 Peripheral Base Address

// System Control Block (SCB)
#define SCB_BASE            0xE000ED00U

// APB1 Peripherals
#define APB1_TIMER2_BASE    (APB1_BASE + 0x0000U) // Timer 2 Base Address
#define APB1_TIMER3_BASE    (APB1_BASE + 0x0400U) // Timer 3 Base Address
#define APB1_TIMER6_BASE    (APB1_BASE + 0x1000U) // Timer 6 Base Address
#define APB1_TIMER7_BASE    (APB1_BASE + 0x1400U) // Timer 7 Base Address
#define APB1_RTC_BASE       (APB1_BASE + 0x2800U) // RTC Base Address
#define APB1_WWDG_BASE      (APB1_BASE + 0x2C00U) // Window Watchdog Base Address
#define APB1_IWDG_BASE      (APB1_BASE + 0x3000U) // Independent Watchdog Base Address
#define APB1_USART2_BASE    (APB1_BASE + 0x4400U) // USART2 Base Address
#define APB1_USART3_BASE    (APB1_BASE + 0x4800U) // USART3 Base Address
#define APB1_I2C_BASE       (APB1_BASE + 0x5400U) // I2C Base Address
#define APB1_BXCAN_BASE     (APB1_BASE + 0x6400U) // BXCAN Base Address
#define APB1_PWR_BASE       (APB1_BASE + 0x7000U) // Power control Base Address
#define APB1_DAC1_BASE      (APB1_BASE + 0x7400U) // Digital-to-Analog Converter 1 Base Address
#define APB1_DAC2_BASE      (APB1_BASE + 0x9800U) // Digital-to-Analog Converter 2 Base Address

// APB2 Peripherals
#define APB2_EXTI_BASE      (APB2_BASE + 0x0400U) // External Interrupt Base Address
#define APB2_TIMER1_BASE    (APB2_BASE + 0x2C00U) // Timer 1 Base Address
#define APB2_SPI1_BASE      (APB2_BASE + 0x3000U) // SPI1 Base Address
#define APB2_USART1_BASE    (APB2_BASE + 0x3800U) // USART1 Base Address
#define APB2_TIMER15_BASE   (APB2_BASE + 0x4000U) // Timer 15 Base Address
#define APB2_TIMER16_BASE   (APB2_BASE + 0x4400U) // Timer 16 Base Address
#define APB2_TIMER17_BASE   (APB2_BASE + 0x4800U) // Timer 17 Base Address
#define APB2_HRTIM1_BASE    (APB2_BASE + 0x7400U) // High-resolution Timer 1 Base Address

// AHB1 Peripherals
#define AHB1_DMA1_BASE      (AHB1_BASE + 0x0000U) // DMA1 Base Address
#define AHB1_RCC_BASE       (AHB1_BASE + 0x1000U) // RCC Base Address
#define AHB1_FLASH_BASE     (AHB1_BASE + 0x2000U) // Flash Base Address
#define AHB1_CRC_BASE       (AHB1_BASE + 0x3000U) // CRC Base Address
#define AHB1_TSC_BASE       (AHB1_BASE + 0x4000U) // TSC Base Address

// AHB2 Peripherals
#define AHB2_GPIOA_BASE     (AHB2_BASE + 0x0000U) // GPIOA Base Address
#define AHB2_GPIOB_BASE     (AHB2_BASE + 0x0400U) // GPIOB Base Address
#define AHB2_GPIOC_BASE     (AHB2_BASE + 0x0800U) // GPIOC Base Address
#define AHB2_GPIOD_BASE     (AHB2_BASE + 0x0C00U) // GPIOD Base Address
#define AHB2_GPIOF_BASE     (AHB2_BASE + 0x1400U) // GPIOF Base Address

// AHB3 Peripherals
#define AHB3_ADC_BASE       (AHB3_BASE + 0x0000U) // Analog-to-Digital Converter Base Address

// RCC SYSCLK options (for RCC_CFGR)
#define RCC_SYSCLK_HSI      0x00000000U // High-Speed Internal (HSI selected as system clock)
#define RCC_SYSCLK_HSE      0x00000001U // High-Speed External
#define RCC_SYSCLK_PLL      0x00000002U // PLL

// AHB1 RCC registers
typedef struct
{
    volatile uint32 CR;        // 0x00 - Clock Control
    volatile uint32 CFGR;      // 0x04 - Clock Configuration
    volatile uint32 CIR;       // 0x08 - Clock Interrupt
    volatile uint32 APB2RSTR;  // 0x0C - APB2 Peripheral Reset
    volatile uint32 APB1RSTR;  // 0x10 - APB1 Peripheral Reset
    volatile uint32 AHBENR;    // 0x14 - AHB Peripheral Clock Enable
    volatile uint32 APB2ENR;   // 0x18 - APB2 Peripheral Clock Enable
    volatile uint32 APB1ENR;   // 0x1C - APB1 Peripheral Clock Enable
    volatile uint32 BDCR;      // 0x20 - Backup Domain Control
    volatile uint32 CSR;       // 0x24 - Control/Status Register
    volatile uint32 AHBRSTR;   // 0x28 - AHB Peripheral Reset
    volatile uint32 CFGR2;     // 0x2C - Clock Configuration 2
    volatile uint32 CFGR3;     // 0x30 - Clock Configuration 3
    volatile uint32 CR2;       // 0x34 - Control Register 2
} rcc_reg_t;

// Flash Memory Interface Registers
typedef struct
{
    volatile uint32 ACR;       // 0x00 - Flash Access Control
    volatile uint32 KEYR;      // 0x04 - Flash Key
    volatile uint32 OPTKEYR;   // 0x08 - Flash Option Key
    volatile uint32 SR;        // 0x0C - Flash Status
    volatile uint32 CR;        // 0x10 - Flash Control
    volatile uint32 AR;        // 0x14 - Flash Address
    uint32 RESERVED0;          // 0x18 - Reserved
    volatile uint32 OBR;       // 0x1C - Flash Option Byte
    volatile uint32 WRPR;      // 0x20 - Flash Write Protection
} flash_reg_t;

// System Control Block (SCB)
typedef struct
{
    volatile uint32 CPUID;   // 0x00 - CPU ID Base
    volatile uint32 ICSR;    // 0x04 - Interrupt Control and State Register
    volatile uint32 VTOR;    // 0x08 - Vector Table Offset Register
    volatile uint32 AIRCR;   // 0x0C - Application Interrupt and Reset Control Register
    volatile uint32 SCR;     // 0x10 - System Control Register
    volatile uint32 CCR;     // 0x14 - Configuration Control Register
    volatile uint8  SHP[12]; // 0x18 - System Handlers Priority
    volatile uint32 SHCSR;   // 0x24 - System Handler Control and State Register
} scb_reg_t;

// Peripheral Base Pointers
#define RCC                 ((rcc_reg_t  *)AHB1_RCC_BASE)
#define FLASH               ((flash_reg_t*)AHB1_FLASH_BASE)
#define SCB                 ((scb_reg_t  *)SCB_BASE)

// System clock frequency (default)
#define SYSTEM_CLOCK        8000000U // 8 MHz if HSI is used

#endif // STM32F334_H
