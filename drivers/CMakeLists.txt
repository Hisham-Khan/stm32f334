cmake_minimum_required(VERSION 3.12)
project(stm32_bare_metal C)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_LINKER arm-none-eabi-ld)
set(CMAKE_OBJCOPY arm-none-eabi-objcopy)

set(CMAKE_C_FLAGS "-mcpu=cortex-m3 -mthumb -O0 -g -Wall")
set(CMAKE_EXE_LINKER_FLAGS "-T ${CMAKE_SOURCE_DIR}/../essentials/linker/stm32f334.ld -nostdlib")

set(SOURCES
    ${CMAKE_SOURCE_DIR}/../essentials/startup/startup.c
    ${CMAKE_SOURCE_DIR}/main.c
    ${CMAKE_SOURCE_DIR}/gpio/src/gpio.c
)

include_directories(${CMAKE_SOURCE_DIR}/inc)
include_directories(${CMAKE_SOURCE_DIR}/gpio/inc)
include_directories(${CMAKE_SOURCE_DIR}/../essentials/types/inc)

add_executable(stm32f334.elf ${SOURCES})

add_custom_command(
    OUTPUT stm32f334.bin
    COMMAND ${CMAKE_OBJCOPY} -O binary stm32f334.elf stm32f334.bin
    DEPENDS stm32f334.elf
    COMMENT "Generating binary file"
)

add_custom_target(bin ALL DEPENDS stm32f334.bin)

add_custom_target(flash
    COMMAND openocd -f interface/stlink-v2.cfg -f target/stm32f3x.cfg -c "program stm32f334.bin 0x08000000 verify reset exit"
    DEPENDS stm32f334.bin
    COMMENT "Flashing binary to STM32"
)

add_custom_target(openocd
    COMMAND openocd -f interface/stlink-v2.cfg -f target/stm32f3x.cfg
    COMMENT "Starting OpenOCD"
)
