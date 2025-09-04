#ifndef GPIO_H
#define GPIO_H

#include "gpio_types.h"

// APB2 peripheral clock enable
#define BM_RCC_APB2ENR     *(volatile unsigned int *)(RCC_BASE + 0x18)

// GPIO register offsets
#define BM_GPIO_CRL    0x00 // Configuration low (pins 0-7)
#define BM_GPIO_CRH    0x04 // Configuration high (pins 8-15)
#define BM_GPIO_IDR    0x08 // Input data register
#define BM_GPIO_ODR    0x0C // Output data register

// Initialize GPIO pin as output
void gpio_init(gpio_port_t port, unsigned int pin, gpio_mode_t mode, gpio_cfg_t cnf, gpio_pull_t pull);

// Set GPIO pin high (e.g., turn LED on)
void gpio_set(gpio_port_t port, unsigned int pin);

// Clear GPIO pin (e.g., turn LED off)
void gpio_clear(gpio_port_t port, unsigned int pin);

// Toggle GPIO pin state
void gpio_toggle(gpio_port_t port, unsigned int pin);

// Simple delay loop (approximate, for demonstration)
void delay_ms(unsigned int ms);

#endif // GPIO_H
