#include <chrono>
#include <future>
#include <iostream>

const std::string DELIMITER = "->";

bool is_even(unsigned long input) {
    bool is_even;
    if (input % 2 == 0) {
        is_even = true;
    } else {
        is_even = false;
    }
    return is_even;
}

unsigned long collatz_iteration(unsigned long input) {
    unsigned long output;
    if (is_even(input)) {
        output = input / 2;
    } else {
        output = (input * 3) + 1;
    }
    return output;
}

void print_orbit(unsigned long start) {
    std::cout << start;
    unsigned long current = start;
    while (current != 1) {
        current = collatz_iteration(current);
        std::cout << DELIMITER << current;
    }
    std::cout << std::endl;
}

int main() {
    unsigned long current_start = 1;
    while (true) {
        print_orbit(current_start);
        current_start++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}