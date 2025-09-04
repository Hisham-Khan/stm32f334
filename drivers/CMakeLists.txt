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
    ${CMAKE_SOURCE_DIR}/../essentials/helpers/src/helpers.c
)

include_directories(${CMAKE_SOURCE_DIR}/inc)
include_directories(${CMAKE_SOURCE_DIR}/gpio/inc)
include_directories(${CMAKE_SOURCE_DIR}/../essentials/types/inc)
include_directories(${CMAKE_SOURCE_DIR}/../essentials/helpers/inc)

add_executable(stm32f334.elf ${SOURCES})

add_custom_command(
    OUTPUT stm32f334.bin
    COMMAND ${CMAKE_OBJCOPY} -O binary stm32f334.elf stm32f334.bin
    DEPENDS stm32f334.elf
    COMMENT "Generating binary file"
)

add_custom_target(bin ALL DEPENDS stm32f334.bin)
