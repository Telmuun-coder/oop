#include <math.h>
#include <iostream>
#include "Universe.h"

int main() {
    // Compile with:
    // g++ Body.cpp -c && g++ Universe.cpp -c && g++ main.cpp -o main.exe Universe.o Body.o && ./main.exe
    Universe uni = Universe("./files/nbodys.txt");

    double distance = uni.find_distance(uni.bodies[0], uni.bodies[1]);
    double force = uni.find_gravitational_force(uni.bodies[0], uni.bodies[1]);
    double angle = uni.find_angle(uni.bodies[0], uni.bodies[1]);

    std::cout << "Distance: " << distance << " "
              << "Force: " << force << " "
              << "Angle: " << angle << std::endl;

    double dy = uni.bodies[1].position.y - uni.bodies[0].position.y;
    double dx = uni.bodies[1].position.x - uni.bodies[0].position.x;

    std::cout << dy << " " << dx << " " << 2 * M_PI + atan2(dy, dx) << std::endl;

    return 0;
}