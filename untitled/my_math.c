//
// Created by yura on 21.03.17.
//

#include <malloc.h>
#include <memory.h>
#include <tgmath.h>
#include "my_math.h"

void my_math_elips_init(struct elips **elips_out)
{
    struct elips *elips = malloc(sizeof(struct elips));

    memset(elips, 0, sizeof(struct elips));

    *elips_out = elips;
}

void my_math_paral_init(struct paral **paral_out)
{
    struct paral *paral = malloc(sizeof(struct paral));

    memset(paral, 0, sizeof(struct elips));

    *paral_out = paral;
}

void my_math_elips_set_default(struct elips *elips)
{
    elips->a = 14;
    elips->b = 12.5;
}

void my_math_paral_set_default(struct paral *paral)
{
     const float points[4][3] =
            {
                    { -5, -2, -50 },
                    { 3, -2, -50},
                    { 5, 2, -50},
                    { -3, 2, -50 }
            };

        memcpy(paral->point, points, sizeof(float) * 12);
}

void my_math_elips_close(struct elips *elips)
{
    free(elips);
}

void my_math_paral_close(struct paral *paral)
{
    free(paral);
}

void my_math_elips_get(struct elips* elips, float angle, float *x, float *y)
{
    *x = elips->a * cos(angle);
    *y = elips->b * sin(angle);
}
