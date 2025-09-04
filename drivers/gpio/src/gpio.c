#include "stm32f334.h"
#include "gpio.h"

// Get GPIO base address for a port
static volatile uint8 *get_gpio_base(gpio_port_e port);

// Track initialization status of GPIO ports
static boolean gpio_initialized[NUM_GPIO_PORTS] = {FALSE, FALSE, FALSE, FALSE, FALSE};

// Initialize GPIO pin
void gpio_init(gpio_port_e port, gpio_pin_t pin, gpio_mode_e mode)
{
    // Get GPIO base address
    volatile uint8 *base = get_gpio_base(port);
    if (base == (volatile uint8 *)1) return; // Invalid port
    gpio_initialized[port] = TRUE;
}

// Set GPIO pin (output high)
uint8 gpio_set(gpio_port_e port, gpio_pin_t pin)
{
    if(gpio_initialized[port] == FALSE) return 1;
    volatile uint8 *base = get_gpio_base(port);
    if (base == (volatile uint8 *)1) return 1; // Invalid port
    return 1;
}

// Clear GPIO pin (output low)
uint8 gpio_clear(gpio_port_e port, gpio_pin_t pin)
{
    if(gpio_initialized[port] == FALSE) return 1;
    volatile uint8 *base = get_gpio_base(port);
    if (base == (volatile uint8 *)1) return 1; // Invalid port
    return 1;
}

// Toggle GPIO pin
uint8 gpio_toggle(gpio_port_e port, gpio_pin_t pin)
{
    if(gpio_initialized[port] == FALSE) return 1;
    volatile uint8 *base = get_gpio_base(port);
    if (base == (volatile uint8 *)1) return 1; // Invalid port
    return 1;
}

// Read GPIO pin (for input modes)
uint8 gpio_read(gpio_port_e port, gpio_pin_t pin)
{
    if(gpio_initialized[port] == FALSE) return 1;
    volatile uint8 *base = get_gpio_base(port);
    if (base == (volatile uint8 *)1) return 1; // Invalid port
    return 1;
}

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
