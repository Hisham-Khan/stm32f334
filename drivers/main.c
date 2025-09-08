#include "stm32f334.h"
#include "gpio.h"
#include "helpers.h"

#define ONBOARD_LED_PIN             5U

#define USER_BUTTON_PIN             13U

#define BUTTON_PRESSED              0U
#define BUTTON_UNPRESSED            1U

int main(void)
{
    volatile uint8 button_status = BUTTON_UNPRESSED;
    volatile uint8 last_button_status = BUTTON_UNPRESSED;
    volatile uint8 button_count = 0U;
    // Enable HSI oscillator
    RCC_CR |= RCC_CR_HSION;
    
    // Wait for HSI to be ready
    while (!(RCC_CR & RCC_CR_HSIRDY))
    {
        // Wait for HSI ready flag
    }

    // Select HSI as system clock (FIXED - use correct bits)
    RCC_CFGR &= ~(0x3U << 0U);  // Clear SW[1:0] bits (bits 0-1, not using HSI_CLEAR)
    RCC_CFGR |= RCC_SYSCLK_HSI; // Set HSI as system clock source

    // Initialize GPIOA5 as output for onboard LED
    gpio_init(GPIO_PORTA, ONBOARD_LED_PIN, GPIO_MODE_OUTPUT);

    // Initialize GPIOC13 as input for user button
    gpio_init(GPIO_PORTC, USER_BUTTON_PIN, GPIO_MODE_INPUT);

    // Infinite loop
    while (TRUE)
    {
        button_status = gpio_read(GPIO_PORTC, USER_BUTTON_PIN);

        // Edge detect: count only on press (1 -> 0)
        if ((button_status == BUTTON_PRESSED) && (last_button_status == BUTTON_UNPRESSED))
        {
            button_count++;
            if (button_count >= 3U)
            {
                button_count = 0U;
            }
            // Debounce delay
            delay_ms(50U);
        }
        last_button_status = button_status;

        switch (button_count)
        {
            case 0U:
                (void)gpio_clear(GPIO_PORTA, ONBOARD_LED_PIN);  // LED off
                break;
            case 1U:
                (void)gpio_set(GPIO_PORTA, ONBOARD_LED_PIN);    // LED on
                break;
            case 2U:
                (void)gpio_toggle(GPIO_PORTA, ONBOARD_LED_PIN); // Blink
                delay_ms(500U);
                break;
            default:
                button_count = 0U;
                break;
        }
    }
    return 0; // Never reached
}
