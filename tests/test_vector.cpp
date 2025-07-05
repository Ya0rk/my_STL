#include "../include/my_vector.hpp"
#include <cassert>
#include <cstdio>

void test_vector_basic() {
    my::vector<int> v;
    assert(v.size() == 0);

    v.push_back(42);
    assert(v.size() == 1);
    assert(v[0] == 42);

    v.push_back(100);
    assert(v.size() == 2);
    assert(v[1] == 100);
    printf("test_vector finished\n");
}

int main() {
    test_vector_basic();
    return 0;
}
