#if !defined(UNIVERSE_CPP)
#define UNIVERSE_CPP

#include "Universe.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Body.h"

Universe::Universe() {
}

Universe::Universe(std::string file) {
    std::ifstream input(file);

    if (input.is_open()) {
        input >> this->g_constant;

        std::string name;
        double px;
        double py;
        double vx;
        double vy;
        double mass;
        while (input >> name >> px >> py >> vx >> vy >> mass) {
            std::cout << vx << " " << vy << " " << mass << std::endl;
            this->bodies.push_back(Body(name, px, py, vx, vy, mass));
        }

        input.close();
    }
}

#endif  // UNIVERSE_CPP