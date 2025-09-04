MEMORY
{
    FLASH(rx) : ORIGIN = 0x10000000, LENGTH = 2048k /* 2MB Flash */
    RAM(rwx)  : ORIGIN = 0x20000000, LENGTH = 264k  /* 264KB SRAM */
}

SECTIONS
{
    .text : {
        KEEP(*(.vectors)) /* Interrupt vector table */
        *(.text*)         /* Program code */
        *(.rodata*)       /* Read-only data */
        . = ALIGN(4);
    } > FLASH

    .data : {
        _sdata = .;       /* Start of .data in RAM */
        *(.data*)         /* Initialized data */
        . = ALIGN(4);
        _edata = .;       /* End of .data in RAM */
    } > RAM AT > FLASH

    .bss : {
        _sbss = .;        /* Start of .bss */
        *(.bss*)          /* Uninitialized data */
        *(COMMON)
        . = ALIGN(4);
        _ebss = .;        /* End of .bss */
    } > RAM

    _stacktop = ORIGIN(RAM) + LENGTH(RAM);
    _etext = LOADADDR(.data); /* End of code in Flash, start of .data in Flash */

    /DISCARD/ : {
        *(*)              /* Discard all other sections */
    }
}
