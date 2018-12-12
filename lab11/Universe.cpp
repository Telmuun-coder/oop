#if !defined(UNIVERSE_CPP)
#define UNIVERSE_CPP

#include "Universe.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Body.h"

Universe::Universe() {}

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

void Universe::update_universe(double t) {
  for (Body &body : this->bodies) {
    // draw(current position of bodies)
    // std::cout << "BEFORE CHANGE: " << std::endl;
    // body.print_body();
    // std::cout << "+++++++++++++++" << std::endl;

    double force_x = find_horizontal_force(body.name);
    double force_y = find_vertical_force(body.name);
    body.update_horizontal_position(force_x, t);
    body.update_vertical_position(force_y, t);
    body.update_velocity_by_acceleration(force_x, force_y, t);

    // std::cout << "AFTER CHANGE: " << std::endl;
    // std::cout << "FORCE X: " << force_x << " FORCE Y:" << force_y <<
    // std::endl; body.print_body(); std::cout << "--------------" << std::endl
    //           << std::endl;
  }
}

double Universe::find_horizontal_force(std::string name) {
  double force = 0.0;
  double cos_angle = 0.0;
  double horizontal_force = 0.0;
  for (Body const &main_body : this->bodies) {
    if (main_body.name == name) {
      for (Body const &other_body : this->bodies) {
        if (other_body.name == main_body.name) {
          continue;
        }
        force = find_gravitational_force(main_body, other_body);
        // cos_angle = find_angle(main_body, other_body);
        cos_angle = (other_body.position.x - main_body.position.x) /
                    find_distance(main_body, other_body);

        horizontal_force += force * cos_angle;
      }
      return horizontal_force;
    }
  }
  return horizontal_force;
}
double Universe::find_vertical_force(std::string name) {
  double force = 0.0;
  double sin_angle = 0.0;
  double vertical_force = 0.0;
  for (Body const &main_body : this->bodies) {
    if (main_body.name == name) {
      for (Body const &other_body : this->bodies) {
        if (other_body.name == main_body.name) {
          continue;
        }
        force = find_gravitational_force(main_body, other_body);
        sin_angle = (other_body.position.y - main_body.position.y) /
                    find_distance(main_body, other_body);

        vertical_force += force * sin_angle;
      }
      return vertical_force;
    }
  }
  return vertical_force;
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