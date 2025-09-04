#ifndef GPIO_H
#define GPIO_H

#include "gpio_types.h"

// AHB1 peripheral clock enable
#define RCC_AHB1ENR         *(volatile uint8 *)(AHB1_RCC_BASE + 0x14)

// Number of GPIO ports
#define NUM_GPIO_PORTS      0x5U

// GPIO port reset values
#define GPIOA_RESET         0xA8000000U
#define GPIOB_RESET         0x00000280U
#define GPIOx_RESET         0x00000000U

// GPIO register offsets
#define GPIOx_MODER         0x00U
#define GPIOx_OTYPER        0x04U
#define GPIOx_OSPEEDR       0x08U
#define GPIOx_PUPDR         0x0CU
#define GPIOx_IDR           0x10U
#define GPIOx_ODR           0x14U
#define GPIOx_BSRR          0x18U
#define GPIOx_LCKR          0x1CU
#define GPIOx_AFR           0x20U
#define GPIOx_AFH           0x24U
#define GPIOx_BRR           0x28U

// Initialize GPIO pin as output
void gpio_init(gpio_port_e port, gpio_pin_t pin, gpio_mode_e mode);

// Set GPIO pin high (e.g., turn LED on)
uint8 gpio_set(gpio_port_e port, gpio_pin_t pin);

// Clear GPIO pin (e.g., turn LED off)
uint8 gpio_clear(gpio_port_e port, gpio_pin_t pin);

// Toggle GPIO pin state
uint8 gpio_toggle(gpio_port_e port, gpio_pin_t pin);

// Read GPIO pin (for input modes)
uint8 gpio_read(gpio_port_e port, gpio_pin_t pin);

#endif // GPIO_H
