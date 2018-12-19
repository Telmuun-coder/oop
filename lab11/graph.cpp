#include <GL/glut.h>

#include <iostream>

#include <math.h> /* sin cos */

void draw_circle(double x, double y) {
  double radius = 10.0;
  glBegin(GL_LINE_LOOP);
  glColor3f(1, 1, 1);
  for (int i = 0; i < 360; i++) {
    glVertex2f(x + radius * cos(i * M_PI / 180),
               y + radius * sin(i * M_PI / 180));
  }
  glEnd();
}