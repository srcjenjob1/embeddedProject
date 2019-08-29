
add_library(uart # SHARED or STATIC determined by conan
        UARTInterface.cpp
        UARTInterface.h)

target_link_libraries(uart
        PUBLIC serial
        PUBLIC common)

target_include_directories(uart
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        PUBLIC $<INSTALL_INTERFACE:include>)

target_compile_features(uart
        PUBLIC cxx_std_14)

set_target_properties(uart PROPERTIES
        PUBLIC_HEADER "UARTInterface.h")


install(TARGETS uart EXPORT uartConfig
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include
        )

install(EXPORT uartConfig DESTINATION lib/uart)
