#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

#include "std_types.h"

typedef struct
{
    volatile uint32 MODER;    // GPIO port mode register
    volatile uint32 OTYPER;   // GPIO port output type register
    volatile uint32 OSPEEDR;  // GPIO port output speed register
    volatile uint32 PUPDR;    // GPIO port pull-up/pull-down register
    volatile uint32 IDR;      // GPIO port input data register
    volatile uint32 ODR;      // GPIO port output data register
    volatile uint32 BSRR;     // GPIO port bit set/reset register
    volatile uint32 LCKR;     // GPIO port configuration lock register
    volatile uint32 AFR[2];   // GPIO alternate function registers (AFR[0]: AFRL, AFR[1]: AFRH)
} gpio_reg_t;

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

// GPIO configuration enum
typedef enum
{
    // For MODE = 00 (Input)
    GPIO_CFG_ANALOG         = 0x0U, // 00: Analog input
    GPIO_CFG_INPUT          = 0x1U, // 01: Floating input
    GPIO_CFG_PULL           = 0x2U, // 10: Pull-up/pull-down
    // For MODE != 00 (Output or Alternate Function)
    GPIO_CFG_PUSHPULL       = 0x0U, // 00: Push-pull output
    GPIO_CFG_OUT            = 0x1U, // 0x: Pull-up/pull-down output
    GPIO_CFG_AF_PUSHPULL    = 0x2U, // 10: Alternate function push-pull
    GPIO_CFG_AF_OUT         = 0x3U  // 11: Alternate function open-drain
} gpio_cfg_e;

// Pull-up/pull-down enum
typedef enum
{
    GPIO_PULL_NONE = 0U,
    GPIO_PULL_UP,
    GPIO_PULL_DOWN
} gpio_pull_e;

#endif // GPIO_TYPES_H
