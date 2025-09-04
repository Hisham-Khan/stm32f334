#include "stm32f103.h"
#include "gpio.h"

#define ONBOARD_LED_PIN             13U

int main(void)
{
    // Initialize GPIOA5
    gpio_init(BM_GPIO_PORTA, 5, BM_GPIO_MODE_OUTPUT, BM_GPIO_CFG_PUSHPULL, BM_GPIO_PULL_NONE);
    
    // Blink LED forever
    while (1)
    {
        gpio_toggle(BM_GPIO_PORTA, 5);  // Toggle LED state
        delay_ms(1000);
    }
    return 0; // Never reached
}
