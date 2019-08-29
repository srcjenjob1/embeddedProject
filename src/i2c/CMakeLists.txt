add_library(i2c
        I2cInterface.cpp
        I2cInterface.h)

target_link_libraries(i2c
        PUBLIC common)

target_include_directories(i2c
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        PUBLIC $<INSTALL_INTERFACE:include>)

set_target_properties(i2c PROPERTIES
        PUBLIC_HEADER "I2cInterface.h")

target_compile_features(i2c
        PUBLIC cxx_std_14)

install(TARGETS i2c EXPORT i2cConfig
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include
        )

install(EXPORT i2cConfig DESTINATION lib/i2c)

