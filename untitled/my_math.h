#pragma once

struct elips {
    float a;
    float b;
};

struct point {
    union {
        struct {
            float x;
            float y;
            float z;
        };
        float arr[3];
    };
};


struct paral {
    struct point point[4];
};


void my_math_elips_init(struct elips **elips_out);
void my_math_elips_set_default(struct elips *elips);
void my_math_elips_close(struct elips *elips);

void my_math_elips_get(struct elips* elips, float angle, float *x, float *y);

void my_math_paral_init(struct paral **paral_out);
void my_math_paral_set_default(struct paral *paral);
void my_math_paral_close(struct paral *paral);