#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.2f, 0.2f);
        glVertex2f(0.0f, 0.7f);
        glColor3f(0.2f, 1.0f, 0.2f);
        glVertex2f(-0.7f, -0.6f);
        glColor3f(0.2f, 0.3f, 1.0f);
        glVertex2f(0.7f, -0.6f);
    glEnd();

    glutSwapBuffers();
}

void init() {
    glClearColor(0.08f, 0.09f, 0.12f, 1.0f);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(900, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Lab - First Test");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
