#include "systick.h"

// Simple blocking delay using the 1 ms tick if available; falls back to loop
void delay_ms(uint32 ms)
{
    if (*((volatile uint32 *)0xE000E010U) & 1U) // SysTick enabled?
    {
        uint32 start = millis();
        while ((millis() - start) < ms) { }
        return;
    }

    // Fallback: rough busy wait (~1 ms per 1000 iterations @ 8 MHz with -O0..-O1)
    volatile uint32 i;
    for (i = 0U; i < ms * 1000U; i++) { }
}
