#ifndef GPIO_TYPES_H
#define GPIO_TYPES_H

// GPIO port definitions
typedef enum
{
    BM_GPIO_PORTA = 0U,
    BM_GPIO_PORTB,
    BM_GPIO_PORTC,
    BM_GPIO_PORTD
} gpio_port_t;

// GPIO pin modes
typedef enum
{
    BM_GPIO_MODE_INPUT = 0U,
    BM_GPIO_MODE_OUTPUT,
    BM_GPIO_MODE_AF,
    BM_GPIO_MODE_ANALOG
} gpio_mode_t;

// GPIO configuration enum
typedef enum
{
    // For MODE = 00 (Input)
    BM_GPIO_CFG_ANALOG         = 0x0U, // 00: Analog input
    BM_GPIO_CFG_INPUT          = 0x1U, // 01: Floating input
    BM_GPIO_CFG_PULL           = 0x2U, // 10: Pull-up/pull-down
    // For MODE != 00 (Output or Alternate Function)
    BM_GPIO_CFG_PUSHPULL       = 0x0U, // 00: Push-pull output
    BM_GPIO_CFG_OUT            = 0x1U, // 0x: Pull-up/pull-down output
    BM_GPIO_CFG_AF_PUSHPULL    = 0x2U, // 10: Alternate function push-pull
    BM_GPIO_CFG_AF_OUT         = 0x3U  // 11: Alternate function open-drain
} gpio_cfg_t;

// Pull-up/pull-down enum
typedef enum
{
    BM_GPIO_PULL_NONE = 0U,
    BM_GPIO_PULL_UP,
    BM_GPIO_PULL_DOWN
} gpio_pull_t;

#endif // GPIO_TYPES_H
