#include <iostream>
#include "matrix.cpp"

int main() {
    float m1r0[] = {3, 3};
    float m1r1[] = {4, 4};
    float *m1[2] = {m1r0, m1r1};

    float m2r0[] = {75, 12};
    float m2r1[] = {-8, 3};
    float *m2[2] = {m2r0, m2r1};

    Matrix a(2, 2, m1, 2, 2);
    Matrix b(2, 2, m2, 2, 2);

    a *= b;

    std::cout
        << std::endl;

    return 0;
}