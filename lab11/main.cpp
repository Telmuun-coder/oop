#include <iostream>
#include "Universe.h"

int main() {
    Universe a = Universe("./files/nbodys.txt");

    std::cout << a.g_constant << std::endl;
    a.bodies[0].print_body();

    return 0;
}