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
            this->bodies.push_back(Body(name, px, py, vx, vy, mass));
        }

        input.close();
    }
}

void Universe::update_universe() {
}
double Universe::find_horizontal_force(std::string name) {
    for (Body const &main_body : this->bodies) {
        if (main_body.name == name) {
            double horizontal_force = 0.0;

            for (Body const &other_body : this->bodies) {
            }
        }
    }
}
double Universe::find_gravitational_force(Body main, Body with) {
    // F = G * M1 * M2 / distance^2
    double distance = find_distance(main, with);
    return this->g_constant * main.mass * with.mass / pow(distance, 2);
}
double Universe::find_distance(Body main, Body with) {
    double x = main.position.x - with.position.x;
    double y = main.position.y - with.position.y;
    return sqrt(pow(x, 2) + pow(y, 2));
}

double Universe::find_angle(Body main, Body with) {
    double delta_y = with.position.y - main.position.y;
    double delta_x = with.position.x - main.position.x;

    double in_radius = atan2(delta_y, delta_x);
    return (in_radius > 0) ? in_radius : 2 * M_PI + in_radius;
}

#endif  // UNIVERSE_CPP