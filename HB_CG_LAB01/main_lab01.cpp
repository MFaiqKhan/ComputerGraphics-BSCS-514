#include <iostream>
#include <fstream>
#include <string>
#include <GL/glut.h>
#include <Windows.h>

using namespace std;

void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.9f, 0.9f, 0.9f, 0.0);
	glColor3f(1, 0, 0);
	glFlush();
}

int screenWidth = 640;
int screenHeight = 480;

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(30, 30);
	glutCreateWindow("HB First OGL Program, Muhammad Faiq Khan - B20102084");
	glutDisplayFunc(myDisplay);

	PlaySound("backmusic.wav",NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

	glutMainLoop();

	return 0;
}
