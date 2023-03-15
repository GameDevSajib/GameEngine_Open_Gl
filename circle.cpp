///circle akar code:

#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <GL/glu.h>


// Set up the window and projection
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Set background color to black and opaque
    glMatrixMode(GL_PROJECTION);      // Set projection matrix as the current matrix
    glLoadIdentity();                 // Load identity matrix to reset previous transformations
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);  // Set up an orthographic projection with a square viewing volume
}

// Draw the circle
void drawCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 100; // The number of triangles used to draw the circle
    GLfloat twicePi = 2.0f * 3.14159265358979323846f;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // Center of the circle
    for (i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i * twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}

// Draw the scene
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    glColor3f(1.0, 0.0, 0.0); // Set the color to red
    drawCircle(0.0, 0.0, 0.5); // Draw a circle centered at the origin with radius 0.5
    glFlush(); // Send the drawing commands to the graphics card
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set up a basic display buffer
    glutInitWindowSize(500, 500); // Set the window size
    glutCreateWindow("Circle"); // Create the window
    init(); // Set up the window and projection
    glutDisplayFunc(display); // Register the display function
    glutMainLoop(); // Enter the event loop
    return 0;
}
