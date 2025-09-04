#include "stm32f103.h"
#include "gpio.h"

// Get GPIO base address for a port
static volatile unsigned int *get_gpio_base(gpio_port_t port);

// Get GPIO base address for a port
static volatile unsigned int *get_gpio_base(gpio_port_t port)
{
    switch (port)
    {
        case BM_GPIO_PORTA:
            return (volatile unsigned int *)GPIOA_BASE;
        case BM_GPIO_PORTB:
            return (volatile unsigned int *)GPIOB_BASE;
        case BM_GPIO_PORTC:
            return (volatile unsigned int *)GPIOC_BASE;
        case BM_GPIO_PORTD:
            return (volatile unsigned int *)GPIOD_BASE;
        default:
            return (volatile unsigned int *)1; // Invalid port
    }
}

// Initialize GPIO pin
void gpio_init(gpio_port_t port, unsigned int pin, gpio_mode_t mode, gpio_cfg_t cnf, gpio_pull_t pull)
{
    // Get GPIO base address
    volatile unsigned int *base = get_gpio_base(port);
    if ((base == (volatile unsigned int *)1) || (pin > 15))
    {
        return; // Invalid port or pin
    }

    // Enable port clock (RCC_APB2ENR bits 2-5 for GPIOA-D)
    BM_RCC_APB2ENR |= (1 << (2 + port));

    // Calculate configuration value: MODE[1:0], CNF[1:0]
    unsigned int config = (mode & 0x3) | ((cnf & 0x3) << 2);

    // Configure pin in CRL (pins 0-7) or CRH (pins 8-15)
    if (pin < 8)
    {
        unsigned int shift = pin * 4;
        *(base + BM_GPIO_CRL / 4) &= ~(0xF << shift); // Clear 4 bits
        *(base + BM_GPIO_CRL / 4) |= (config << shift); // Set MODE, CNF
    }
    else
    {
        unsigned int shift = (pin - 8) * 4;
        *(base + BM_GPIO_CRH / 4) &= ~(0xF << shift); // Clear 4 bits
        *(base + BM_GPIO_CRH / 4) |= (config << shift); // Set MODE, CNF
    }

    // Set pull-up/pull-down for input mode with pull
    if (mode == BM_GPIO_MODE_INPUT && cnf == BM_GPIO_CFG_PULL)
    {
        if (pull == BM_GPIO_PULL_UP)
        {
            *(base + BM_GPIO_ODR / 4) |= (1 << pin); // Set ODR for pull-up
        }
        else if (pull == BM_GPIO_PULL_DOWN)
        {
            *(base + BM_GPIO_ODR / 4) &= ~(1 << pin); // Clear ODR for pull-down
        }
    }
}

// Set GPIO pin (output high)
void gpio_set(gpio_port_t port, unsigned int pin)
{
    volatile unsigned int *base = get_gpio_base(port);
    if ((base == (volatile unsigned int *)1) || (pin > 15))
    {
        return; // Invalid port or pin
    }
    *(base + BM_GPIO_ODR / 4) |= (1 << pin); // Set pin high
}

// Clear GPIO pin (output low)
void gpio_clear(gpio_port_t port, unsigned int pin)
{
    volatile unsigned int *base = get_gpio_base(port);
    if ((base == (volatile unsigned int *)1) || (pin > 15))
    {
        return; // Invalid port or pin
    }
    *(base + BM_GPIO_ODR / 4) &= ~(1 << pin); // Set pin low
}

// Toggle GPIO pin
void gpio_toggle(gpio_port_t port, unsigned int pin)
{
    volatile unsigned int *base = get_gpio_base(port);
    if ((base == (volatile unsigned int *)1) || (pin > 15))
    {
        return; // Invalid port or pin
    }
    *(base + BM_GPIO_ODR / 4) ^= (1 << pin);
}

// Read GPIO pin (for input modes)
unsigned int gpio_read(gpio_port_t port, unsigned int pin)
{
    volatile unsigned int *base = get_gpio_base(port);
    if ((base == (volatile unsigned int *)1) || (pin > 15))
    {
        return 0; // Invalid port or pin - return 0 instead of 1
    }
    return (*(base + BM_GPIO_IDR / 4) >> pin) & 0x1;
}

// Simple delay
void delay_ms(unsigned int ms)
{
    volatile unsigned long i;
    for (i = 0; i < ms * 10000; i++)
    {
        
    }
}
