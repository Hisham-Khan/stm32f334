#include "stm32f334.h"
#include "gpio.h"
#include "helpers.h"

#define ONBOARD_LED_PIN             13U

int main(void)
{
    // Enable HSI oscillator
    RCC_CR |= RCC_CR_HSION;
    
    // Wait for HSI to be ready
    while (!(RCC_CR & RCC_CR_HSIRDY))
    {
        // Wait for HSI ready flag
    }

    // Select HSI as system clock (FIXED - use correct bits)
    RCC_CFGR &= ~(0x3U << 0);        // Clear SW[1:0] bits (bits 0-1, not using HSI_CLEAR)
    RCC_CFGR |= RCC_SYSCLK_HSI;      // Set HSI as system clock source

    // Initialize GPIOA5
    gpio_init(GPIO_PORTA, 5, GPIO_MODE_OUTPUT);

    // Blink LED forever
    while (1)
    {
        gpio_toggle(GPIO_PORTA, 5);  // Toggle LED state
        delay_ms(1000);
    }
    return 0; // Never reached
}