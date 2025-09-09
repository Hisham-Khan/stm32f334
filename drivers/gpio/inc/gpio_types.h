#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

#include "std_types.h"

// GPIO Register Structure
typedef struct
{
    volatile uint32 MODER;    // 0x00
    volatile uint32 OTYPER;   // 0x04
    volatile uint32 OSPEEDR;  // 0x08
    volatile uint32 PUPDR;    // 0x0C
    volatile uint32 IDR;      // 0x10
    volatile uint32 ODR;      // 0x14
    volatile uint32 BSRR;     // 0x18
    volatile uint32 LCKR;     // 0x1C
    volatile uint32 AFRL;     // 0x20
    volatile uint32 AFRH;     // 0x24
    volatile uint32 BRR;      // 0x28
} gpio_reg_t;

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

#endif // GPIO_TYPES_H
