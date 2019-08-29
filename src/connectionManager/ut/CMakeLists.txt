find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

add_executable(ut_connectionMgr
        TestSuite.cpp)

target_link_libraries(ut_connectionMgr
        PRIVATE connectionManager
        PRIVATE CONAN_PKG::gtest
        PRIVATE Threads::Threads
)

include(GoogleTest)
gtest_discover_tests(ut_connectionMgr)
