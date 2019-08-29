add_library(common INTERFACE)

target_include_directories(common INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
        )

set_target_properties(common PROPERTIES
        PUBLIC_HEADER "CommonTypes.h;ReceivingInterface.h;SendingInterface.h")

install(TARGETS common EXPORT commonConfig
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include
        PUBLIC_HEADER DESTINATION include
        )

install(EXPORT commonConfig DESTINATION lib/common)

