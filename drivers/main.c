#include "stm32f334.h"
#include "gpio.h"

#define ONBOARD_LED_PIN             13U

int main(void)
{
    // Initialize GPIOA5
    gpio_init(GPIO_PORTA, 5, GPIO_MODE_OUTPUT, GPIO_CFG_PUSHPULL, GPIO_PULL_NONE);
    
    // Blink LED forever
    while (1)
    {
        gpio_toggle(GPIO_PORTA, 5);  // Toggle LED state
        delay_ms(1000);
    }
    return 0; // Never reached
}
