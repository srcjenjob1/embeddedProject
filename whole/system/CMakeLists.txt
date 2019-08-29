add_executable(roundtrip
        main.cpp
        RoundTrip.cpp)

target_link_libraries(roundtrip
        PUBLIC connectionManager
        PUBLIC uart
        PUBLIC i2c
        )
