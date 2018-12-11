#if !defined(BODY_CPP)
#define BODY_CPP

#include "Body.h"
#include <iostream>
#include <string>
#include <vector>

Body::Body() {
}

Body::Body(std::string name, double px, double py, double vx, double vy, double mass) {
    this->name = name;
    this->position.x = px;
    this->position.y = py;
    this->velocity.x = vx;
    this->velocity.y = vy;
    this->mass = mass;
}

void Body::update_velocity_by_acceleration(double horizontal_force, double vertical_force, double t) {
    // v = u + at
    this->velocity.x = this->velocity.x + horizontal_force / this->mass * t;
    this->velocity.y = this->velocity.y + vertical_force / this->mass * t;
}

void Body::update_horizontal_position(double horizontal_force, double t) {
    // s = vt + 0.5at^2
    double a = horizontal_force / this->mass;
    this->position.x = this->position.x + (this->velocity.x * t + 0.5 * a * std::pow(t, 2));
}

void Body::update_vertical_position(double vertical_force, double t) {
    // s = vt + 0.5at^2
    double a = vertical_force / this->mass;
    this->position.y = this->position.y + (this->velocity.y * t + 0.5 * a * std::pow(t, 2));
}

void Body::print_body() {
    std::cout << name << "    px: " << position.x << "    py: " << position.y << "    vx: " << velocity.x << "    vy: " << velocity.y << "    m: " << mass << std::endl;
}

#endif  // BODY_CPP