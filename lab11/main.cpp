#include <GL/glut.h>
#include <math.h>
#include <math.h> /* sin cos */
#include <iostream>
#include "Universe.h"
#include "graph.cpp"

// int main() {
//     // Compile with:
//     g++ Body.cpp -c && g++ Universe.cpp -c && g++ main.cpp -o main.exe Universe.o Body.o && ./main.exe
//     g++ Body.cpp -c && g++ Universe.cpp -c && g++ main.cpp -o main.exe -lglut -lGLU -lGL Universe.o Body.o && ./main.exe
//     g++ Body.cpp -c && g++ Universe.cpp -c && openglc main.cpp main.exe Universe.o Body.o && ./main.exe
//     Universe uni = Universe("./files/nbodys.txt");

//     uni.update_universe(0.5);

//     return 0;
// }

#define PI 3.14159265
Universe uni;

int CIRCLE_POINTS = 360;
int i = 0;

void displayMe(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    for (Body const &body : uni.bodies) {
        draw_circle(body.position.x, 1000 - body.position.y);
    }

    glutSwapBuffers();
}

void timer(int value) {
    uni.update_universe(0.2);
    glutPostRedisplay();
    glutTimerFunc(1, timer, 1);
}

void resize(int w, int h) {
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(0, 1000, 0, 1000);
    // glOrtho(0, w, 0, h, 5.0, -5.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void setup() {
    uni = Universe("./files/nbodys.txt");
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(800, 100);
    glutCreateWindow("Universe");
    glutReshapeFunc(resize);
    glutDisplayFunc(displayMe);
    setup();
    glutTimerFunc(1, timer, 1);
    // Keyborad func
    glutMainLoop();
    return 0;
}