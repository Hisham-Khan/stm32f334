typedef void (*handler_t)(void);

extern int main(void);

// Reset handler that calls main
void reset_handler(void) {
    main();
    while (1); // Trap if main returns
}

__attribute__((section(".vectors")))
handler_t vectors[] = {
    (handler_t) 0x20001800, // Stack pointer (6 KB SRAM)
    reset_handler,          // Reset handler
    0,                      // NMI handler
    0                       // HardFault handler
};
