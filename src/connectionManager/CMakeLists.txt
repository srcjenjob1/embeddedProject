
find_package(Threads)

add_library(connectionManager
        ConnectionManager.cpp
        MsgMerger.cpp
        MsgHelper.cpp
        )

target_link_libraries(connectionManager
        PUBLIC serial
        PUBLIC common
        PUBLIC Threads::Threads)

target_include_directories(connectionManager INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>)

target_compile_features(connectionManager
        PUBLIC cxx_std_14)

set_target_properties(connectionManager PROPERTIES
        PUBLIC_HEADER "ConnectionManager.h")


install(TARGETS connectionManager EXPORT connectionManagerConfig
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include
        )

install(EXPORT connectionManagerConfig DESTINATION lib/connectionManager)

add_subdirectory(ut)