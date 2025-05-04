#include <chrono>
#include <future>
#include <iostream>

int main() {
    unsigned long current_start = 1;
    while (true) {
        unsigned long current = current_start;
        std::cout << current_start;
        while (current != 1) {
            if (current % 2 == 0) {
                current /= 2;
            } else {
                current = (3 * current) + 1;
            }
            std::cout << "  -> " << current;
        }
        std::cout << std::endl;
        current_start++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}