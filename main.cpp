#include "include/my_vector.hpp"
#include <iostream>

int main() {
    my::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);

    std::cout << "Vector elements: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
