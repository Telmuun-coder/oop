#include <iostream>
#include "Universe.h"

int main() {
    // Compile with:
    // g++ Body.cpp -c && g++ Universe.cpp -c && g++ main.cpp -o main.exe Universe.o Body.o && ./main.exe
    Universe uni = Universe("./files/nbodys.txt");

    double distance = uni.find_distance(uni.bodies[0], uni.bodies[1]);
    double force = uni.find_gravitational_force(uni.bodies[0], uni.bodies[1]);

    std::cout << "Distance: " << distance << " "
              << "Force: " << force << std::endl;
    return 0;
}