cmake_minimum_required(VERSION 3.13)
project(embeddedProject)

include(CTest)
enable_testing()

add_subdirectory(common)
add_subdirectory(i2c)
add_subdirectory(uart)
add_subdirectory(connectionManager)
add_subdirectory(system)

include(CPack)
