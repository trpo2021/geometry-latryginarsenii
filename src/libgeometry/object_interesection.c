#include "function.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void object_interesection(struct object* circle)
{
    float circle1_circle2, circle1_circle3, circle2_circle3, r1_r2, r1_r3,
            r2_r3;
    circle1_circle2
            = sqrt((circle[0].x - circle[1].x) * (circle[0].x - circle[1].x)
                   + (circle[0].y - circle[1].y) * (circle[0].y - circle[1].y));
    circle1_circle3
            = sqrt((circle[0].x - circle[2].x) * (circle[0].x - circle[2].x)
                   + (circle[0].y - circle[2].y) * (circle[0].y - circle[2].y));
    circle2_circle3
            = sqrt((circle[1].x - circle[2].x) * (circle[1].x - circle[2].x)
                   + (circle[1].y - circle[2].y) * (circle[1].y - circle[2].y));
    r1_r2 = circle[0].r + circle[1].r;
    r1_r3 = circle[0].r + circle[2].r;
    r2_r3 = circle[1].r + circle[2].r;

    for (int i = 0; i < 3; i++) {
        circle[i].object_interesection_1 = -1;
        circle[i].object_interesection_2 = -1;
    }

    if ((circle1_circle2 > r1_r2) && (circle1_circle3 > r1_r3)
        && (circle2_circle3 > r2_r3)) // 000
    {
    } else if (
            (circle1_circle2 > r1_r2) && (circle1_circle3 > r1_r3)
            && (circle2_circle3 <= r2_r3)) // 001
    {
        circle[1].object_interesection_1 = 3;
        circle[2].object_interesection_1 = 2;
    } else if (
            (circle1_circle2 > r1_r2) && (circle1_circle3 <= r1_r3)
            && (circle2_circle3 > r2_r3)) // 010
    {
        circle[0].object_interesection_1 = 3;
        circle[2].object_interesection_1 = 1;
    } else if (
            (circle1_circle2 > r1_r2) && (circle1_circle3 <= r1_r3)
            && (circle2_circle3 <= r2_r3)) // 011
    {
        circle[0].object_interesection_1 = 3;
        circle[1].object_interesection_1 = 3;
        circle[2].object_interesection_1 = 1;
        circle[2].object_interesection_2 = 2;
    } else if (
            (circle1_circle2 <= r1_r2) && (circle1_circle3 > r1_r3)
            && (circle2_circle3 > r2_r3)) // 100
    {
        circle[0].object_interesection_1 = 2;
        circle[1].object_interesection_1 = 1;
    } else if (
            (circle1_circle2 <= r1_r2) && (circle1_circle3 > r1_r3)
            && (circle2_circle3 <= r2_r3)) // 101
    {
        circle[0].object_interesection_1 = 2;
        circle[2].object_interesection_1 = 2;
        circle[1].object_interesection_1 = 1;
        circle[1].object_interesection_2 = 3;
    } else if (
            (circle1_circle2 <= r1_r2) && (circle1_circle3 <= r1_r3)
            && (circle2_circle3 > r2_r3)) // 110
    {
        circle[2].object_interesection_1 = 1;
        circle[1].object_interesection_1 = 1;
        circle[0].object_interesection_1 = 2;
        circle[0].object_interesection_2 = 3;
    } else if (
            (circle1_circle2 <= r1_r2) && (circle1_circle3 <= r1_r3)
            && (circle2_circle3 <= r2_r3)) // 111
    {
        circle[0].object_interesection_1 = 2;
        circle[0].object_interesection_2 = 3;
        circle[1].object_interesection_1 = 1;
        circle[1].object_interesection_2 = 3;
        circle[2].object_interesection_1 = 1;
        circle[2].object_interesection_2 = 2;
    }
}