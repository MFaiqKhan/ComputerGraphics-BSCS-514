#include <GL/glut.h>
#include <cstdlib>
#include <ctime>

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200.0, 200.0, -200.0, 150.0);
}

void drawTree(int x, int y) {
    // Draw the trunk
    glColor3f(0.65, 0.16, 0.16); // Brown color
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + 10, y);
    glVertex2f(x + 10, y + 30);
    glVertex2f(x, y + 30);
    glEnd();

    // Draw the leaves
    glColor3f(0.0, 0.5, 0.0); // Green color
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 15, y + 30);
    glVertex2f(x + 25, y + 30);
    glVertex2f(x + 5, y + 60);
    glEnd();
}

void drawHouse() {
    // Draw the base
    glColor3f(1.0, 1.0, 1.0); // White color
    glBegin(GL_POLYGON);
    glVertex2f(100, 0);
    glVertex2f(150, 0);
    glVertex2f(150, 50);
    glVertex2f(100, 50);
    glEnd();

    // Draw the roof
    glColor3f(0.65, 0.16, 0.16); // Brown color
    glBegin(GL_TRIANGLES);
    glVertex2f(90, 50);
    glVertex2f(160, 50);
    glVertex2f(125, 80);
    glEnd();

    // Draw the windows
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_POLYGON);
    glVertex2f(110, 10);
    glVertex2f(120, 10);
    glVertex2f(120, 20);
    glVertex2f(110, 20);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(130, 10);
    glVertex2f(140, 10);
    glVertex2f(140, 20);
    glVertex2f(130, 20);
    glEnd();
}

void drawRiver() {
    glBegin(GL_POLYGON);
    glColor3ub(30, 144, 255);
    glVertex2i(-200, -50);
    glVertex2i(200, -30);
    glColor3ub(0, 0, 128);
    glVertex2i(200, -200);
    glVertex2i(-200, -200);
    glVertex2i(-200, -50);
    glEnd();
    glBegin(GL_POLYGON); // border
    glColor3ub(128, 128, 0);
    glVertex2i(-200, -45);
    glVertex2i(200, -25);
    glVertex2i(200, -30);
    glVertex2i(-200, -50);
    glVertex2i(-200, -45);
    glEnd();
}

void drawFish(int x, int y) {
    glColor3f(1.0, 0.0, 0.0); // Red color

    // Draw the body
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + 10, y + 5);
    glVertex2f(x, y + 10);
    glVertex2f(x - 10, y + 5);
    glEnd();

    // Draw the tail
    glBegin(GL_TRIANGLES);
    glVertex2f(x + 10, y + 5);
    glVertex2f(x + 15, y + 7);
    glVertex2f(x + 15, y + 3);
    glEnd();
}


void drawLand() {
    glColor3ub(139, 69, 19); // Brown color
    glBegin(GL_POLYGON);
    glVertex2i(-200, 0);
    glVertex2i(200, 0);
    glVertex2i(200, -50);
    glVertex2i(-200, -50);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

    drawRiver();
    for (int i = 0; i < 5; i++) {
        drawFish(rand() % 400 - 200, rand() % 50 - 200); // Randomly place fish within the river
    }
    drawLand();
    drawHouse();
    for (int i = 0; i < 5; i++) {
        drawTree(rand() % 400 - 200, 0); // Randomly place trees on the land
    }

    // Draw stars
    glColor3f(1.0, 1.0, 1.0); // Set color to white
    glBegin(GL_POINTS);
    for (int i = 0; i < 50; i++) {
        int x = rand() % 400 - 200;
        int y = rand() % 350;
        if (y > 0) { // Only draw stars above the land
            glVertex2i(x, y);
        }
    }
    glEnd();

    glFlush(); // Force execution of GL commands
}

int main(int argc, char** argv) {
    srand(time(0)); // Initialize random seed

    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowPosition(50, 50); // Set top-left display-window position
    glutInitWindowSize(400, 300); // Set display-window width and height
    glutCreateWindow("Night Scene with Stars"); // Create display window

    init(); // Execute initialization procedure
    glutDisplayFunc(display); // Send graphics to display window
    glutMainLoop(); // Display everything and wait

    return 0;
}



































//Sure, I'd be happy to explain the code in detail.

//#include <GL/glut.h>: This line includes the GLUT (OpenGL Utility Toolkit) library, which provides functions for creating windows and handling user input in a window system independent manner.
//#include <cstdlib> and #include <ctime>: These lines include the standard library and time library, which are used for generating random numbers.
//void init() : This function initializes the OpenGL rendering context.It sets the background color to black and sets up an orthographic projection.
//void drawTree(int x, int y) : This function draws a tree at the specified x and y coordinates.It first draws the trunk as a brown rectangle, then draws the leaves as a green triangle.
//void drawHouse() : This function draws a house.It first draws the base as a white rectangle, then draws the roof as a brown triangle, and finally draws two windows as blue rectangles.
//void drawRiver() : This function draws a river as a blue polygon and its border as a brown polygon.
//void drawFish(int x, int y) : This function draws a fish at the specified x and y coordinates.It first draws the body as a red polygon, then draws the tail as a red triangle.
//void drawLand() : This function draws the land as a brown rectangle.
//void display() : This function is the main display callback.It clears the color buffer, draws the river, fish, land, house, trees, and stars, and then flushes the OpenGL commands to the screen.
//int main(int argc, char** argv) : This is the main function.It initializes the random number generator, initializes GLUT, sets the display mode, creates a window, sets up the initial OpenGL state, registers the display callback, and enters the GLUT event loop.
//The glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); line sets the initial display mode.GLUT_SINGLE specifies that a single buffered window is to be created, and GLUT_RGB specifies that an RGB color model is to be used.

//The glutInitWindowPosition(50, 50); line sets the initial window position, which is the top - left corner of the window in screen coordinates.

//The glutInitWindowSize(400, 300); line sets the initial window size in screen coordinates.

//The glutCreateWindow("Night Scene with Stars"); line creates a top - level window with the title "Night Scene with Stars".

//The glutDisplayFunc(display); line sets the display callback for the current window.The display callback is the function that GLUT will call whenever the window needs to be redrawn.

//The glutMainLoop(); line enters the GLUT event processing loop.This function does not return until the program is terminated.It processes events from the window system, such as redraw events and mouse events.