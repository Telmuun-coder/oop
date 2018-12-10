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

    // Contructors
    Body();
    Body(std::string name, double px, double py, double vx, double vy, double mass);

    // Methods
    void update_velocity_by_acceleration(double horizontal_force, double vertical_force, double t);
    void update_horizontal_position(double horizontal_force, double t);
    void update_vertical_position(double vertical_force, double t);
    void print_body();
};

#endif  // BODY_H