#ifndef SYSTICK_H
#define SYSTICK_H

#include "std_types.h"

#define SYSTICK_BASE           0xE000E010U // SysTick Timer Base Address

// System Timer Registers
typedef struct
{
    volatile uint32 CTRL;   // 0x10
    volatile uint32 LOAD;   // 0x14
    volatile uint32 VAL;    // 0x18
    volatile uint32 CALIB;  // 0x1C
} systick_reg_t;

#define SYSTICK                 ((systick_reg_t  *)SYSTICK_BASE)

void systick_init(uint32 sysclk_hz);
uint32 millis(void);

#endif // SYSTICK_H
