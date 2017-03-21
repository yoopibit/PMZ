#pragma once

#include <GL/gl.h>

struct point {
    union {
        struct {
            GLfloat x;
            GLfloat y;
            GLfloat z;
        };
        GLfloat arr[3];
    };
};


struct paral {
    struct point point[4];
};

struct elips {
    GLfloat a;
    GLfloat b;
};

static struct lab3_ctx {
    struct paral paral;
    struct elips elips;
};



