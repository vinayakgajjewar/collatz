#include <iostream>

bool is_even(unsigned long input) {
    bool is_even;
    if (input % 2 == 0) {
        is_even = true;
    } else {
        is_even = false;
    }
    return is_even;
}

unsigned long even_collatz_operation(unsigned long input) {
    unsigned long output = input / 2;
    return output;
}

unsigned long odd_collatz_operation(unsigned long input) {
    unsigned long output = (input * 3) + 1;
    return output;
}

unsigned long collatz_iteration(unsigned long input) {
    unsigned long output;
    if (is_even(input)) {
        output = even_collatz_operation(input);
    } else {
        output = odd_collatz_operation(input);
    }
    return output;
}

std::vector<unsigned long> get_orbit(unsigned long start) {
    std::vector<unsigned long> orbit;
    orbit.push_back(start);
    unsigned long current = start;
    while (current != 1) {
        current = collatz_iteration(current);
        orbit.push_back(current);
    }
    return orbit;
}

int main() {
    unsigned long current_start = 1;
    while (true) {
        std::vector<unsigned long> orbit = get_orbit(current_start);
        size_t orbit_length = orbit.size();
        std::cout << "Starting at " << current_start << ", length is " << orbit_length << std::endl;
        current_start++;
    }
}