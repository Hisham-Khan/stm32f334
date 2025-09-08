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
    // Validate inputs first
    if (port >= NUM_GPIO_PORTS)
    {
        return;
    }
    else if ((pin > 15U || mode > GPIO_MODE_ANALOG))
    {
        return; // Invalid parameters
    }
    else
    {
        // Get GPIO base address
        volatile uint32 *base = get_gpio_base(port);
        if (base == (volatile uint32 *)0xFFFFFFFFU)
        {
            return; // Invalid port
        }
        // Enable GPIO clock
        RCC_AHBENR |= (1U << gpio_rcc_bits[port]);

        // Access MODER register (offset 0x00)
        volatile uint32 *moder = base + (GPIOx_MODER / 4U);
        
        // Clear the mode bits for this pin (2 bits per pin)
        *moder &= ~(0x3U << (pin * 2U));
        
        // Set the new mode
        *moder |= ((uint32)mode << (pin * 2U));

        gpio_initialized[port] = TRUE;
    }
}

// Set GPIO pin (output high)
uint8 gpio_set(gpio_port_e port, gpio_pin_t pin)
{
    uint8 retval = 0U;
    volatile uint32 *base = get_gpio_base(port);

    if (base == (volatile uint32 *)0xFFFFFFFFU)
    {
        retval = 1U; // Invalid port
    }
    else if(!gpio_initialized[port])
    {
        retval = 1U; // Not initialized
    }
    else if(pin > 15U)
    {
        retval = 1U; // Invalid pin
    }
    else
    {
        // Use BSRR register for atomic set operation (offset 0x18)
        volatile uint32 *bsrr = base + (GPIOx_BSRR / 4U);
        *bsrr = (1U << pin); // Set pin (lower 16 bits)
        retval = 0U;
    }

    return retval;
}

// Clear GPIO pin (output low)
uint8 gpio_clear(gpio_port_e port, gpio_pin_t pin)
{
    uint8 retval = 0U;
    volatile uint32 *base = get_gpio_base(port);

    if (base == (volatile uint32 *)0xFFFFFFFFU)
    {
        retval = 1U; // Invalid port
    }
    else if(!gpio_initialized[port])
    {
        retval = 1U; // Not initialized
    }
    else if(pin > 15U)
    {
        retval = 1U; // Invalid pin
    }
    else
    {
        // Use BSRR register for atomic clear operation (offset 0x18)
        volatile uint32 *bsrr = base + (GPIOx_BSRR / 4U);
        *bsrr = (1U << (pin + 16U)); // Reset pin (upper 16 bits)
        retval = 0U;
    }

    return retval;
}

// Read GPIO pin (for input modes)
uint8 gpio_read(gpio_port_e port, gpio_pin_t pin)
{
    uint8 retval = 0U;
    volatile uint32 *base = get_gpio_base(port);

    if (base == (volatile uint32 *)0xFFFFFFFFU)
    {
        retval = 1U; // Invalid port
    }
    else if(!gpio_initialized[port])
    {
        retval = 1U; // Not initialized
    }
    else if(pin > 15U)
    {
        retval = 1U; // Invalid pin
    }
    else
    {
        // Access IDR register (offset 0x10)
        volatile uint32 *idr = base + (GPIOx_IDR / 4U);
        
        // Read the pin state
        retval = (*idr & (1U << pin)) ? 1U : 0U;
    }

    return retval;    
}

// Toggle GPIO pin
uint8 gpio_toggle(gpio_port_e port, gpio_pin_t pin)
{
    uint8 retval = 0U;
    volatile uint32 *base = get_gpio_base(port);

    if (base == (volatile uint32 *)0xFFFFFFFFU)
    {
        retval = 1U; // Invalid port
    }
    else if(!gpio_initialized[port])
    {
        retval = 1U; // Not initialized
    }
    else if(pin > 15U)
    {
        retval = 1U; // Invalid pin
    }
    else
    {
        // Access ODR register (offset 0x14U)
        volatile uint32 *odr = base + (GPIOx_ODR / 4U);

        // Toggle the pin
        *odr ^= (1U << pin);

        retval = 0U;
    }

    return retval;
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
            return (volatile uint32 *)0xFFFFFFFFU; // Invalid port
    }
}
