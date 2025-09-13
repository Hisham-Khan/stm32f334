#include "systick.h"

static volatile uint32 s_ticks_ms = 0U;

void systick_init(uint32 sysclk_hz)
{
    // Configure SysTick for 1 kHz tick
    // Reload = (Fcpu / 1000) - 1; HSI default = 8 MHz -> 8000 - 1
    SYSTICK->LOAD = (sysclk_hz / 1000U) - 1U; // STK_LOAD
    SYSTICK->VAL = 0U; // STK_VAL
    SYSTICK->CTRL = 0x7U; // STK_CTRL: ENABLE|TICKINT|CLKSOURCE
}

uint32 millis(void)
{
    return s_ticks_ms;
}

// Called by the core every 1 ms
void systick_handler(void)
{
    s_ticks_ms++;
}
