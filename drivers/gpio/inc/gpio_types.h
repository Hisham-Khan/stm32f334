#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

#include "std_types.h"

// GPIO pin type (0-15)
typedef uint8 gpio_pin_t; 

// GPIO port definitions
typedef enum
{
    GPIO_PORTA = 0U,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTF
} gpio_port_e;

// GPIO pin modes
typedef enum
{
    GPIO_MODE_INPUT = 0U,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_AF,
    GPIO_MODE_ANALOG
} gpio_mode_e;

// Pull-up/pull-down enum
typedef enum
{
    GPIO_PULL_NONE = 0U,
    GPIO_PULL_UP,
    GPIO_PULL_DOWN
} gpio_pull_e;

#endif // GPIO_TYPES_H
