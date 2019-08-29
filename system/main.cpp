#include "RoundTrip.h"
#include <chrono>
#include <iostream>

int main() {
    RoundTrip roundTrip;
    Msg msg = {5, 1, 2, 3, 4};

    for (int i = 80; i < 85; i++) {
        std::cout << "Sending msg of size " << msg.size() << "\n";
        if (!roundTrip.sendMsg(msg))
            std::cout << "Sending failed\n";
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    if(roundTrip.testResult()) {
        std::cout<<"TEST PASSED\n";
    }
    else {
        std::cout<<"TEST FAILED\n";
    }
    return 0;
}
