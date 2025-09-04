#include "stm32f334.h"
#include "gpio.h"

// Get GPIO base address for a port
static volatile uint8 *get_gpio_base(gpio_port_e port);

// Get GPIO base address for a port
static volatile uint8 *get_gpio_base(gpio_port_e port)
{
    switch (port)
    {
        case GPIO_PORTA:
            return (volatile uint8 *)AHB2_GPIOA_BASE;
        case GPIO_PORTB:
            return (volatile uint8 *)AHB2_GPIOB_BASE;
        case GPIO_PORTC:
            return (volatile uint8 *)AHB2_GPIOC_BASE;
        case GPIO_PORTD:
            return (volatile uint8 *)AHB2_GPIOD_BASE;
        case GPIO_PORTF:
            return (volatile uint8 *)AHB2_GPIOF_BASE;
        default:
            return (volatile uint8 *)1; // Invalid port
    }
}

// Initialize GPIO pin
void gpio_init(gpio_port_e port, uint8 pin, gpio_mode_e mode, gpio_cfg_e cnf, gpio_pull_e pull)
{
    // Get GPIO base address
    volatile uint8 *base = get_gpio_base(port);
    if ((base == (volatile uint8 *)1) || (pin > 15))
    {
        return; // Invalid port or pin
    }

    // Enable port clock (RCC_AHB1ENR bits 2-5 for GPIOA-D)
    RCC_AHB1ENR |= (1 << (2 + port));

    // Calculate configuration value: MODE[1:0], CNF[1:0]
    uint8 config = (mode & 0x3) | ((cnf & 0x3) << 2);

    // Configure pin in CRL (pins 0-7) or CRH (pins 8-15)
    if (pin < 8)
    {
        uint8 shift = pin * 4;
        *(base + GPIO_CRL / 4) &= ~(0xF << shift); // Clear 4 bits
        *(base + GPIO_CRL / 4) |= (config << shift); // Set MODE, CNF
    }
    else
    {
        uint8 shift = (pin - 8) * 4;
        *(base + GPIO_CRH / 4) &= ~(0xF << shift); // Clear 4 bits
        *(base + GPIO_CRH / 4) |= (config << shift); // Set MODE, CNF
    }

    // Set pull-up/pull-down for input mode with pull
    if (mode == GPIO_MODE_INPUT && cnf == GPIO_CFG_PULL)
    {
        if (pull == GPIO_PULL_UP)
        {
            *(base + GPIO_ODR / 4) |= (1 << pin); // Set ODR for pull-up
        }
        else if (pull == GPIO_PULL_DOWN)
        {
            *(base + GPIO_ODR / 4) &= ~(1 << pin); // Clear ODR for pull-down
        }
    }
}

// Set GPIO pin (output high)
void gpio_set(gpio_port_e port, uint8 pin)
{
    volatile uint8 *base = get_gpio_base(port);
    if ((base == (volatile uint8 *)1) || (pin > 15))
    {
        return; // Invalid port or pin
    }
    *(base + GPIO_ODR / 4) |= (1 << pin); // Set pin high
}

// Clear GPIO pin (output low)
void gpio_clear(gpio_port_e port, uint8 pin)
{
    volatile uint8 *base = get_gpio_base(port);
    if ((base == (volatile uint8 *)1) || (pin > 15))
    {
        return; // Invalid port or pin
    }
    *(base + GPIO_ODR / 4) &= ~(1 << pin); // Set pin low
}

// Toggle GPIO pin
void gpio_toggle(gpio_port_e port, uint8 pin)
{
    volatile uint8 *base = get_gpio_base(port);
    if ((base == (volatile uint8 *)1) || (pin > 15))
    {
        return; // Invalid port or pin
    }
    *(base + GPIO_ODR / 4) ^= (1 << pin);
}

// Read GPIO pin (for input modes)
uint8 gpio_read(gpio_port_e port, uint8 pin)
{
    volatile uint8 *base = get_gpio_base(port);
    if ((base == (volatile uint8 *)1) || (pin > 15))
    {
        return 0; // Invalid port or pin - return 0 instead of 1
    }
    return (*(base + GPIO_IDR / 4) >> pin) & 0x1;
}

// Simple delay
void delay_ms(uint16 ms)
{
    volatile uint16 i;
    for (i = 0; i < ms * 10000; i++)
    {
        
    }
}
