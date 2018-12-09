#if !defined(UNIVERSE_H)
#define UNIVERSE_H

#include <vector>
#include "Body.h"

class Universe {
   public:
    std::vector<Body> bodies;
    double g_constant;

    Universe();
    Universe(std::string file);

    void update_universe();
};

#endif  // UNIVERSE_H