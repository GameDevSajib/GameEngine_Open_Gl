
///Line draw korer code

#include <windows.h>
#include <GL/glut.h>

void init() {
    // Set a black background color
    glClearColor(0.0, 0.0, 0.0, 0.0);
    // Set up the viewing volume: 500 x 500 window with origin lower left
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 500.0, 0.0, 500.0, 0.0, 1.0);
}

void display() {
    // Set every pixel in the frame buffer to the current clear color
    glClear(GL_COLOR_BUFFER_BIT);

    // Set line color to red
    glColor3f(1.0, 0.0, 0.0);

    // Draw a line from (100, 100) to (400, 400)
    glBegin(GL_LINES);
    glVertex2i(100, 100);
    glVertex2i(400, 400);
    glEnd();

    // Flush drawing command buffer to make drawing happen as soon as possible
    glFlush();
}

int main(int argc, char** argv) {
    // Initialize GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line Drawing");

    // Set callback functions and start the main loop
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;
}
