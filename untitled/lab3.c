#include <GL/glut.h>
#include <memory.h>
#include "lab3.h"
#include "my_math.h"

struct lab3_ctx {
    struct paral *paral;
    struct elips *elips;
    float paral_angle;
    float elips_angle;
    float step;
    struct point center;
};

static struct lab3_ctx *_self;

static void display();

static void key_pressed(unsigned char, int, int);

static void reshape(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void GL_init(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (900, 700);
    glutCreateWindow("Lab3 ");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key_pressed);
}

void lab3_init(int argc, char **argv)
{
    GL_init(argc, argv);

    struct lab3_ctx *lab3_ctx = malloc(sizeof(lab3_ctx));
    my_math_elips_init(&lab3_ctx->elips);
    my_math_paral_init(&lab3_ctx->paral);
    my_math_paral_set_default(lab3_ctx->paral);
    my_math_elips_set_default(lab3_ctx->elips);

    lab3_ctx->paral_angle = 0;
    lab3_ctx->elips_angle = 0;
    memset(lab3_ctx->center.arr, 0, sizeof(float)* 3);
    _self = lab3_ctx;
}

void lab3_show()
{
    glClearColor(0,0,0,0);
    glutMainLoop();
}

void lab3_close()
{
    my_math_elips_close(_self->elips);
    my_math_paral_close(_self->paral);
    free(_self);
}

static void move(float *x, float *y)
{
    _self->elips_angle += _self->step;
    my_math_elips_get(_self->elips, _self->elips_angle, x, y);
}

static void draw_paral()
{
    glBegin(GL_POLYGON);
    float x, y;
    move(&x,&y);

    glColor3d(0, 1, 0);
    struct lab3_ctx *self = _self;
    for (int i = 0; i < 4; i++) {
        glColor3d(0, 1, 0);

        glVertex3f(self->paral->point[i].x + x, self->paral->point[i].y + y, self->paral->point[i].z);
    }

    glEnd();
}

static void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    _self->paral_angle += _self->step * (-15);
    glRotatef(_self->paral_angle,0.0,0.0, 1.0); // Rotate on x

    glTranslatef(_self->center.x, _self->center.y, _self->center.z);
    draw_paral();
    glPopMatrix();

    glutSwapBuffers();
}

static void key_pressed(unsigned char key, int x, int y)
{
    switch (key) {
        case 'e':
            lab3_close();
            break;
        case 'm':
            _self->step += 0.005;
            break;
        case 'l':
            _self->step -= 0.005;
            break;
        case 'x':
            _self->elips->a += 0.1;
            break;
        case 'c':
            _self->elips->b += 0.1;
            break;
        case 'w':
            _self->center.y += 0.5;
            break;
        case 'a':
            _self->center.x -= 0.5;
            break;
        case 'd':
            _self->center.x += 0.5;
            break;
        case 's':
            _self->center.y -= 0.5;
            break;

        default:
            return;
    }
}
