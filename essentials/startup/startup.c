#include "std_types.h"
#include "stm32f334.h"

typedef void (*handler_t)(void);

extern int main(void);

// Forward-declare the vector table so reset_handler can reference it
extern const handler_t vectors[];

// Linker symbols
extern uint32 _sdata, _edata;   // .data in RAM
extern uint32 _etext;           // .data load address in FLASH
extern uint32 _sbss, _ebss;     // .bss in RAM
extern uint32 _stacktop;        // top of stack from linker

static void default_handler(void)
{
    while (1)
    {

    }
}

void nmi_handler(void)       __attribute__((weak, alias("default_handler")));
void hardfault_handler(void) __attribute__((weak, alias("default_handler")));

void reset_handler(void)
{
    // Copy .data from FLASH to RAM
    uint32 *src = &_etext;
    uint32 *dst = &_sdata;
    while (dst < &_edata) { *dst++ = *src++; }

    // Zero .bss
    for (uint32 *b = &_sbss; b < &_ebss; ) 
    {
        *b++ = 0U;
    }

    // Point VTOR to our vector table
    SCB->VTOR = (uint32)&vectors[0];

    main();
    while (1)
    {
        // If main returns, loop forever
    }
}

__attribute__((section(".vectors"), used, aligned(256)))
const handler_t vectors[] = 
{
    (handler_t)(&_stacktop), // Initial MSP
    reset_handler,           // Reset
    nmi_handler,             // NMI
    hardfault_handler        // HardFault
};
