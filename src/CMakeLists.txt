# based on pico-examples

cmake_minimum_required(VERSION 3.12)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

project(tsuji C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_executable(uart_usb)
add_executable(talker)

target_sources(uart_usb PRIVATE uart_usb.c)
target_sources(talker PRIVATE talker.c)

target_link_libraries(uart_usb
    pico_stdlib hardware_uart )

target_link_libraries(talker
pico_stdlib pico_time)

# enable usb output, disable uart output
pico_enable_stdio_usb(uart_usb 1)
pico_enable_stdio_uart(uart_usb 0)

pico_enable_stdio_usb(talker 0)
pico_enable_stdio_uart(talker 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(uart_usb)
pico_add_extra_outputs(talker)
