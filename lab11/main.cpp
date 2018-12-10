#include <math.h>
#include <iostream>
#include "Universe.h"

int main() {
    // Compile with:
    // g++ Body.cpp -c && g++ Universe.cpp -c && g++ main.cpp -o main.exe Universe.o Body.o && ./main.exe
    Universe uni = Universe("./files/nbodys.txt");

    uni.update_universe(0.5);

    return 0;
}