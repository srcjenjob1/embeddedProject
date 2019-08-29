cmake_minimum_required(VERSION 3.13)
project(embeddedProject)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

include(CTest)
enable_testing()

add_subdirectory(common)
add_subdirectory(i2c)
add_subdirectory(uart)
add_subdirectory(connectionManager)
add_subdirectory(roundtrip)
add_subdirectory(it)
#add_subdirectory(tempPredictor)

include(CPack)
