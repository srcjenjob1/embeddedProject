
set(GTEST_ROOT ${CONAN_GTEST_ROOT})
find_package(Threads REQUIRED)
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)

add_executable(it_connection_subsystem
        TestSuite.cpp)

target_link_libraries(it_connection_subsystem
        PRIVATE i2c
        PRIVATE uart
        PRIVATE connectionManager
        PRIVATE Threads::Threads
        PRIVATE GTest::Main
        PRIVATE GTest::GTest
        PRIVATE GMock::GMock
        )

target_compile_features(it_connection_subsystem
        PUBLIC cxx_std_14)

include(GoogleTest)
gtest_discover_tests(it_connection_subsystem)
