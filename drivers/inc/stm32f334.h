#ifndef STM32F334_H
#define STM32F334_H

// Base addresses for key peripherals
#define APB1_BASE           0x40000000  // APB1 peripheral base address
#define APB2_BASE           0x40010000  // APB2 peripheral base address
#define AHB1_BASE           0x40020000  // AHB1 peripheral base address
#define AHB2_BASE           0x48000000  // AHB2 peripheral base address
#define AHB3_BASE           0x50000000  // AHB3 peripheral base address

#define APB1_TIMER2_BASE    (APB1_BASE + 0x0000) // Timer 2 base address
#define APB1_TIMER3_BASE    (APB1_BASE + 0x0400) // Timer 3 base address
#define APB1_TIMER6_BASE    (APB1_BASE + 0x1000) // Timer 6 base address
#define APB1_TIMER7_BASE    (APB1_BASE + 0x1400) // Timer 7 base address
#define APB1_RTC_BASE       (APB1_BASE + 0x2800) // RTC base address
#define APB1_WWDG_BASE      (APB1_BASE + 0x2C00) // Window Watchdog base address
#define APB1_IWDG_BASE      (APB1_BASE + 0x3000) // Independent Watchdog base address
#define APB1_USART2_BASE    (APB1_BASE + 0x4400) // USART2 base address
#define APB1_USART3_BASE    (APB1_BASE + 0x4800) // USART3 base address
#define APB1_I2C_BASE       (APB1_BASE + 0x5400) // I2C base address
#define APB1_BXCAN_BASE     (APB1_BASE + 0x6400) // BXCAN base address
#define APB1_PWR_BASE       (APB1_BASE + 0x7000) // Power control base address
#define APB1_DAC1_BASE      (APB1_BASE + 0x7400) // Digital-to-Analog Converter 1 base address
#define APB1_DAC2_BASE      (APB1_BASE + 0x9800) // Digital-to-Analog Converter 2 base address

#define APB2_EXTI_BASE      (APB2_BASE + 0x0400) // External Interrupt base address
#define APB2_TIMER1_BASE    (APB2_BASE + 0x2C00) // Timer 1 base address
#define APB2_SPI1_BASE      (APB2_BASE + 0x3000) // SPI1 base address
#define APB2_USART1_BASE    (APB2_BASE + 0x3800) // USART1 base address
#define APB2_TIMER15_BASE   (APB2_BASE + 0x4000) // Timer 15 base address
#define APB2_TIMER16_BASE   (APB2_BASE + 0x4400) // Timer 16 base address
#define APB2_TIMER17_BASE   (APB2_BASE + 0x4800) // Timer 17 base address
#define APB2_HRTIM1_BASE    (APB2_BASE + 0x7400) // High-resolution Timer 1 base address

#define AHB1_DMA1_BASE      (AHB1_BASE + 0x0000) // DMA1 base address
#define AHB1_RCC_BASE       (AHB1_BASE + 0x1000) // RCC base address
#define AHB1_FLASH_BASE     (AHB1_BASE + 0x2000) // Flash base address
#define AHB1_CRC_BASE       (AHB1_BASE + 0x3000) // CRC base address
#define AHB1_TSC_BASE       (AHB1_BASE + 0x4000) // TSC base address

#define AHB2_GPIOA_BASE     (AHB2_BASE + 0x0000) // GPIOA base address
#define AHB2_GPIOB_BASE     (AHB2_BASE + 0x0400) // GPIOB base address
#define AHB2_GPIOC_BASE     (AHB2_BASE + 0x0800) // GPIOC base address
#define AHB2_GPIOD_BASE     (AHB2_BASE + 0x0C00) // GPIOD base address
#define AHB2_GPIOF_BASE     (AHB2_BASE + 0x1400) // GPIOF base address

#define AHB3_ADC_BASE       (AHB3_BASE + 0x0000) // Analog-to-Digital Converter base address

// System clock frequency (default)
#define SYSTEM_CLOCK    72000000  // 72 MHz

#endif // STM32F334_H
