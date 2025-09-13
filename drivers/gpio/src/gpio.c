#include "gpio.h"
#include "stm32f334.h"

// Map enum -> typed GPIO pointer
static gpio_reg_t *get_gpio(gpio_port_e port)
{
    switch (port)
    {
        case GPIO_PORTA: return GPIOA;
        case GPIO_PORTB: return GPIOB;
        case GPIO_PORTC: return GPIOC;
        case GPIO_PORTD: return GPIOD;
        case GPIO_PORTF: return GPIOF;
        default:         return (gpio_reg_t *)0;
    }
}

// Track initialization status of GPIO ports
static boolean gpio_initialized[NUM_GPIO_PORTS] = {FALSE, FALSE, FALSE, FALSE, FALSE};

// GPIO RCC bits lookup table
static const uint8 gpio_rcc_bits[] =
{
    RCC_AHBENR_GPIOAEN_BIT,
    RCC_AHBENR_GPIOBEN_BIT,
    RCC_AHBENR_GPIOCEN_BIT,
    RCC_AHBENR_GPIODEN_BIT,
    RCC_AHBENR_GPIOFEN_BIT
};

void gpio_init(gpio_port_e port, gpio_pin_t pin, gpio_mode_e mode)
{
    if (port >= NUM_GPIO_PORTS) return;
    if (pin > 15U || mode > GPIO_MODE_ANALOG) return;

    gpio_reg_t *gpio = get_gpio(port);
    if (!gpio) return;

    // Enable GPIO clock
    RCC->AHBENR |= (1U << gpio_rcc_bits[port]);
    (void)RCC->AHBENR;

    // Configure MODER
    gpio->MODER &= ~(0x3U << (pin * 2U));
    gpio->MODER |= ((uint32)mode << (pin * 2U));

    gpio_initialized[port] = TRUE;
}

uint8 gpio_set(gpio_port_e port, gpio_pin_t pin)
{
    if (port >= NUM_GPIO_PORTS || pin > 15U) return 1U;
    if (!gpio_initialized[port]) return 1U;

    gpio_reg_t *gpio = get_gpio(port);
    if (!gpio) return 1U;

    gpio->BSRR = (1U << pin);
    return 0U;
}

uint8 gpio_clear(gpio_port_e port, gpio_pin_t pin)
{
    if (port >= NUM_GPIO_PORTS || pin > 15U) return 1U;
    if (!gpio_initialized[port]) return 1U;

    gpio_reg_t *gpio = get_gpio(port);
    if (!gpio) return 1U;

    gpio->BSRR = (1U << (pin + 16U));
    return 0U;
}

uint8 gpio_read(gpio_port_e port, gpio_pin_t pin)
{
    if (port >= NUM_GPIO_PORTS || pin > 15U) return 0xFFU;
    if (!gpio_initialized[port]) return 0xFFU;

    gpio_reg_t *gpio = get_gpio(port);
    if (!gpio) return 0xFFU;

    return ((gpio->IDR & (1U << pin)) ? 1U : 0U);
}

uint8 gpio_toggle(gpio_port_e port, gpio_pin_t pin)
{
    if (port >= NUM_GPIO_PORTS || pin > 15U) return 1U;
    if (!gpio_initialized[port]) return 1U;

    gpio_reg_t *gpio = get_gpio(port);
    if (!gpio) return 1U;

    gpio->ODR ^= (1U << pin);
    return 0U;
}
