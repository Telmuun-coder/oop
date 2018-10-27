#include <iostream>
#include "matrix.cpp"

int main() {
    float a1[] = {3, 3};
    float a2[] = {4, 4};
    float *arr[2] = {a1, a2};
    Matrix a(2, 2, arr, 2, 2);

    return 0;
}