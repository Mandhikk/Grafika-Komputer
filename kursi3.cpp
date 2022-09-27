#include <GL/glew.h>
#include<GL/freeglut.h>
#include<math.h>
#define phi 3.14

static float x = 0.0;
static float XKA = -1.0;
static float XKI = -1.0;
static float y = 0.0;
static float tumpu = 0.5;
static float kursi = 1.0;
static float z = -12.0;


void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glLoadIdentity();

//kanan
glPushMatrix();
glTranslatef(XKA, tumpu, z);
glRotatef(80.0, 1.0, 0.0, 0.0);
glRotatef(-30.0, 0.0, 1.0, 1.0);
glColor3f(1.0, 0, 0);
glutSolidCylinder(1.0, 11.0, 10.0, 2.0);
glPopMatrix();

//tengah
glPushMatrix();
glTranslatef(x, y, z);
glRotatef(80.0, 1.0, 0.0, 0.0);
glColor3f(1.0, 0, 0.0);
glutSolidCylinder(1.0, 11.0, 10.0, 2.0);
glPopMatrix();

//kiri
glPushMatrix();
glTranslatef(XKI, tumpu, z);
glRotatef(80.0, 1.0, 0.0, 0.0);
glRotatef(30.0, 0.0, 1.0, 1.0);
glColor3f(1.0, 0.0, 0.0);
glutSolidCylinder(1.0, 11.0, 10.0, 2.0);
glPopMatrix();

glPushMatrix();

    glTranslatef(x, kursi, z);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 370; ++i)
    {
        glColor3f(0.82, 0.4086, 0.1148);
        // glColor3f(0.62, 0.3633, 0.0496);
        glVertex2f(2.0f * cos(phi * i / 180) * 3.5, sin(phi * i / 180) * 3.5);
    }

    glEnd();

    glPopMatrix();
    
    glFlush();
}

// Initialization routine.
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // glOrtho(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case 'a':
        x += 0.5;
        XKI += 0.5;
        XKA += 0.5;
        glutPostRedisplay();
        break;
    case 'd':
        x -= 0.5;
        XKI -= 0.5;
        XKA -= 0.5;
        glutPostRedisplay();
        break;
    case 's':
        y -= 0.5;
        tumpu -= 0.5;
        kursi -= 0.5;
        glutPostRedisplay();
        break;
    case 'w':
        y += 0.5;
        tumpu += 0.5;
        kursi += 0.5;
        glutPostRedisplay();
        break;
    case 'q':
        z -= 0.5;
        glutPostRedisplay();
        break;
    case 'e':
        z += 0.5;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

// Main routine.
int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitContextVersion(4, 3);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("chair.cpp");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);

    glewExperimental = GL_TRUE;
    glewInit();

    setup();

    glutMainLoop();
}
