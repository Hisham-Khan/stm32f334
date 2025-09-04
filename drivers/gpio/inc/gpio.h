#ifndef GPIO_H
#define GPIO_H

#include "gpio_types.h"

// AHB1 peripheral clock enable
#define RCC_AHB1ENR     *(volatile uint8 *)(AHB1_RCC_BASE + 0x18)

// GPIO register offsets
#define GPIO_CRL    0x00 // Configuration low (pins 0-7)
#define GPIO_CRH    0x04 // Configuration high (pins 8-15)
#define GPIO_IDR    0x08 // Input data register
#define GPIO_ODR    0x0C // Output data register

// Initialize GPIO pin as output
void gpio_init(gpio_port_e port, uint8 pin, gpio_mode_e mode, gpio_cfg_e cnf, gpio_pull_e pull);

// Set GPIO pin high (e.g., turn LED on)
void gpio_set(gpio_port_e port, uint8 pin);

// Clear GPIO pin (e.g., turn LED off)
void gpio_clear(gpio_port_e port, uint8 pin);

// Toggle GPIO pin state
void gpio_toggle(gpio_port_e port, uint8 pin);

// Simple delay loop (approximate, for demonstration)
void delay_ms(uint16 ms);

#endif // GPIO_H
