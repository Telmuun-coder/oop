#if !defined(BODY_H)
#define BODY_H

#include <math.h>
#include <iostream>
#include <string>

class Body {
    class Pair {
       public:
        double x;
        double y;
    };

   public:
    std::string name;
    Pair position;
    Pair velocity;
    double mass;

    // Contructor
    Body() {
    }

    Body(std::string name, double px, double py, double vx, double vy, double mass) {
        this->name = name;
        this->position.x = px;
        this->position.y = py;
        this->velocity.x = vx;
        this->velocity.y = vy;
        this->mass = mass;
    }

    void update_velocity_by_acceleration(double horizontal_force, double vertical_force, double t) {
        // v = u + at
        this->velocity.x = this->velocity.x + horizontal_force / this->mass * t;
        this->velocity.y = this->velocity.y + vertical_force / this->mass * t;
    }

    double calculate_horizontal_position(double horizontal_force, double t) {
        // s = vt + 0.5at^2
        double a = horizontal_force / this->mass;
        return this->velocity.x * t + 0.5 * a * std::pow(t, 2);
    }

    // double calculate_horizontal_position(double horizontal_force, double t) {
    //     // s = vt + 0.5at^2
    //     double a = horizontal_force / this->mass;
    //     return this->velocity.x * t + 0.5 * a * std::pow(t, 2);
    // }

    void print_body() {
        std::cout << name << ", " << position.x << ", " << position.y << ", " << velocity.x << ", " << velocity.y << ", " << mass << std::endl;
    }
};

#endif  // BODY_H