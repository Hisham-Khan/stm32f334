#ifndef GPIO_H
#define GPIO_H

#include "gpio_types.h"

// Number of GPIO ports
#define NUM_GPIO_PORTS              0x5U

// GPIO port reset values
#define GPIOA_RESET                 0xA8000000U
#define GPIOB_RESET                 0x00000280U
#define GPIOx_RESET                 0x00000000U

// RCC AHBENR GPIO enable bits
#define RCC_AHBENR_GPIOAEN_BIT      17U
#define RCC_AHBENR_GPIOBEN_BIT      18U
#define RCC_AHBENR_GPIOCEN_BIT      19U
#define RCC_AHBENR_GPIODEN_BIT      20U
#define RCC_AHBENR_GPIOFEN_BIT      22U

#define GPIOA   ((gpio_reg_t *)AHB2_GPIOA_BASE)
#define GPIOB   ((gpio_reg_t *)AHB2_GPIOB_BASE)
#define GPIOC   ((gpio_reg_t *)AHB2_GPIOC_BASE)
#define GPIOD   ((gpio_reg_t *)AHB2_GPIOD_BASE)
#define GPIOF   ((gpio_reg_t *)AHB2_GPIOF_BASE)

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
