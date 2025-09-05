#include "stm32f334.h"
#include "gpio.h"

// Get GPIO base address for a port
static volatile uint32 *get_gpio_base(gpio_port_e port);

// Track initialization status of GPIO ports
static boolean gpio_initialized[NUM_GPIO_PORTS] = {FALSE, FALSE, FALSE, FALSE, FALSE};

// GPIO RCC bits lookup table:
static const uint8 gpio_rcc_bits[] = 
{
    RCC_AHBENR_GPIOAEN_BIT,  // GPIO_PORTA = 0
    RCC_AHBENR_GPIOBEN_BIT,  // GPIO_PORTB = 1
    RCC_AHBENR_GPIOCEN_BIT,  // GPIO_PORTC = 2
    RCC_AHBENR_GPIODEN_BIT,  // GPIO_PORTD = 3
    RCC_AHBENR_GPIOFEN_BIT   // GPIO_PORTF = 4
};

// Initialize GPIO pin
void gpio_init(gpio_port_e port, gpio_pin_t pin, gpio_mode_e mode)
{
    if (pin > 15 || mode > GPIO_MODE_ANALOG)
    {
        return; // Invalid parameters
    }

    // Get GPIO base address
    volatile uint32 *base = get_gpio_base(port);
    if (base == (volatile uint32 *)0xFFFFFFFF)
    {
        return; // Invalid port
    }

    // Enable GPIO clock
    if (port < NUM_GPIO_PORTS)
    {
        RCC_AHBENR |= (1 << gpio_rcc_bits[port]);
    }

    // Access MODER register (offset 0x00)
    volatile uint32 *moder = base;
    
    // Clear the mode bits for this pin (2 bits per pin)
    *moder &= ~(0x3U << (pin * 2));
    
    // Set the new mode
    *moder |= ((uint32)mode << (pin * 2));

    gpio_initialized[port] = TRUE;
}

// Set GPIO pin (output high)
uint8 gpio_set(gpio_port_e port, gpio_pin_t pin)
{
    if(gpio_initialized[port] == FALSE) return 1;
    volatile uint32 *base = get_gpio_base(port);
    if (base == (volatile uint32 *)0xFFFFFFFF)
    {
        return 1; // Invalid port
    }
    return 0;
}

// Clear GPIO pin (output low)
uint8 gpio_clear(gpio_port_e port, gpio_pin_t pin)
{
    if(gpio_initialized[port] == FALSE) return 1;
    volatile uint32 *base = get_gpio_base(port);
    if (base == (volatile uint32 *)0xFFFFFFFF)
    {
        return 1; // Invalid port
    }
    return 0;
}

// Toggle GPIO pin
uint8 gpio_toggle(gpio_port_e port, gpio_pin_t pin)
{
    if(gpio_initialized[port] == FALSE) return 1;
    volatile uint32 *base = get_gpio_base(port);
    if (base == (volatile uint32 *)0xFFFFFFFF)
    {
        return 1; // Invalid port
    }
    return 0;
}

// Read GPIO pin (for input modes)
uint8 gpio_read(gpio_port_e port, gpio_pin_t pin)
{
    if(gpio_initialized[port] == FALSE) return 1;
    volatile uint32 *base = get_gpio_base(port);
    if (base == (volatile uint32 *)0xFFFFFFFF)
    {
        return 1; // Invalid port
    }
    return 0;
}

// Get GPIO base address for a port
static volatile uint32 *get_gpio_base(gpio_port_e port)
{
    switch (port)
    {
        case GPIO_PORTA:
            return (volatile uint32 *)AHB2_GPIOA_BASE;
        case GPIO_PORTB:
            return (volatile uint32 *)AHB2_GPIOB_BASE;
        case GPIO_PORTC:
            return (volatile uint32 *)AHB2_GPIOC_BASE;
        case GPIO_PORTD:
            return (volatile uint32 *)AHB2_GPIOD_BASE;
        case GPIO_PORTF:
            return (volatile uint32 *)AHB2_GPIOF_BASE;
        default:
            return (volatile uint32 *)0xFFFFFFFF; // Invalid port
    }
}
