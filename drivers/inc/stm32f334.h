#ifndef STM32F334_H
#define STM32F334_H

#include "std_types.h"

// Base addresses for key peripherals
#define APB1_BASE           0x40000000U // APB1 peripheral base address
#define APB2_BASE           0x40010000U // APB2 peripheral base address
#define AHB1_BASE           0x40020000U // AHB1 peripheral base address
#define AHB2_BASE           0x48000000U // AHB2 peripheral base address
#define AHB3_BASE           0x50000000U // AHB3 peripheral base address

// APB1 peripherals
#define APB1_TIMER2_BASE    (APB1_BASE + 0x0000U)   // Timer 2 base address
#define APB1_TIMER3_BASE    (APB1_BASE + 0x0400U)   // Timer 3 base address
#define APB1_TIMER6_BASE    (APB1_BASE + 0x1000U)   // Timer 6 base address
#define APB1_TIMER7_BASE    (APB1_BASE + 0x1400U)   // Timer 7 base address
#define APB1_RTC_BASE       (APB1_BASE + 0x2800U)   // RTC base address
#define APB1_WWDG_BASE      (APB1_BASE + 0x2C00U)   // Window Watchdog base address
#define APB1_IWDG_BASE      (APB1_BASE + 0x3000U)   // Independent Watchdog base address
#define APB1_USART2_BASE    (APB1_BASE + 0x4400U)   // USART2 base address
#define APB1_USART3_BASE    (APB1_BASE + 0x4800U)   // USART3 base address
#define APB1_I2C_BASE       (APB1_BASE + 0x5400U)   // I2C base address
#define APB1_BXCAN_BASE     (APB1_BASE + 0x6400U)   // BXCAN base address
#define APB1_PWR_BASE       (APB1_BASE + 0x7000U)   // Power control base address
#define APB1_DAC1_BASE      (APB1_BASE + 0x7400U)   // Digital-to-Analog Converter 1 base address
#define APB1_DAC2_BASE      (APB1_BASE + 0x9800U)   // Digital-to-Analog Converter 2 base address

// APB2 peripherals
#define APB2_EXTI_BASE      (APB2_BASE + 0x0400U)   // External Interrupt base address
#define APB2_TIMER1_BASE    (APB2_BASE + 0x2C00U)   // Timer 1 base address
#define APB2_SPI1_BASE      (APB2_BASE + 0x3000U)   // SPI1 base address
#define APB2_USART1_BASE    (APB2_BASE + 0x3800U)   // USART1 base address
#define APB2_TIMER15_BASE   (APB2_BASE + 0x4000U)   // Timer 15 base address
#define APB2_TIMER16_BASE   (APB2_BASE + 0x4400U)   // Timer 16 base address
#define APB2_TIMER17_BASE   (APB2_BASE + 0x4800U)   // Timer 17 base address
#define APB2_HRTIM1_BASE    (APB2_BASE + 0x7400U)   // High-resolution Timer 1 base address

// AHB1 peripherals
#define AHB1_DMA1_BASE      (AHB1_BASE + 0x0000U)   // DMA1 base address
#define AHB1_RCC_BASE       (AHB1_BASE + 0x1000U)   // RCC base address
#define AHB1_FLASH_BASE     (AHB1_BASE + 0x2000U)   // Flash base address
#define AHB1_CRC_BASE       (AHB1_BASE + 0x3000U)   // CRC base address
#define AHB1_TSC_BASE       (AHB1_BASE + 0x4000U)   // TSC base address

// AHB1 RCC registers offsets
#define RCC_CR              *(volatile uint32 *)(AHB1_RCC_BASE + 0x00U) // RCC Clock Control
#define RCC_CFGR            *(volatile uint32 *)(AHB1_RCC_BASE + 0x04U) // RCC Clock Configuration
#define RCC_AHBENR          *(volatile uint32 *)(AHB1_RCC_BASE + 0x14U) // AHB Peripheral Clock Enable

// RCC_CR bit definitions
#define RCC_CR_HSION        (0x1U << 0U)    // HSI oscillator enable
#define RCC_CR_HSIRDY       (0x1U << 1U)    // HSI oscillator ready flag

// RCC SYSCLK options (for RCC_CFGR)
#define RCC_SYSCLK_HSI      0x00000000U // High-Speed Internal (HSI selected as system clock)
#define RCC_SYSCLK_HSE      0x00000001U // High-Speed External
#define RCC_SYSCLK_PLL      0x00000002U // PLL selected as system clock

// AHB2 peripherals
#define AHB2_GPIOA_BASE     (AHB2_BASE + 0x0000U)   // GPIOA base address
#define AHB2_GPIOB_BASE     (AHB2_BASE + 0x0400U)   // GPIOB base address
#define AHB2_GPIOC_BASE     (AHB2_BASE + 0x0800U)   // GPIOC base address
#define AHB2_GPIOD_BASE     (AHB2_BASE + 0x0C00U)   // GPIOD base address
#define AHB2_GPIOF_BASE     (AHB2_BASE + 0x1400U)   // GPIOF base address

// AHB3 peripherals
#define AHB3_ADC_BASE       (AHB3_BASE + 0x0000U)   // Analog-to-Digital Converter base address

// Flash Memory interface register
#define FLASH_ACR           (AHB1_FLASH_BASE + 0x00U)    // Flash access control register
#define FLASH_KEYR          (AHB1_FLASH_BASE + 0x04U)    // Flash key register
#define FLASH_OPTKEYR       (AHB1_FLASH_BASE + 0x08U)    // Flash option key register
#define FLASH_SR            (AHB1_FLASH_BASE + 0x0CU)    // Flash status register
#define FLASH_CR            (AHB1_FLASH_BASE + 0x10U)    // Flash control register
#define FLASH_AR            (AHB1_FLASH_BASE + 0x14U)    // Flash address register
#define FLASH_OBR           (AHB1_FLASH_BASE + 0x1CU)    // Flash option byte register
#define FLASH_WRPR          (AHB1_FLASH_BASE + 0x20U)    // Flash write protection register

// System clock frequency (default)
#define SYSTEM_CLOCK        8000000U    // 8 MHz if HSI is used

#endif // STM32F334_H
