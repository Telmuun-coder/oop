#if !defined(UNIVERSE_H)
#define UNIVERSE_H

#include <math.h>
#include <vector>
#include "Body.h"

class Universe {
   public:
    std::vector<Body> bodies;
    double g_constant;

    Universe();
    Universe(std::string file);

    void update_universe(double t);
    double find_horizontal_force(std::string name);
    double find_vertical_force(std::string name);
    double find_gravitational_force(Body main, Body with);
    double find_distance(Body main, Body with);
    double find_angle(Body main, Body with);
};

#endif  // UNIVERSE_H