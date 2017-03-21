#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "lab3.h"


int main(int argc, char *argv[])
{
    lab3_init(argc, argv);
    lab3_show();
    lab3_close();

    return 0;
}