#include "function.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void output_object(struct object* circle)
{
    float perimeter, area;
    //Выводим объекты
    for (int i = 0; i < 3; i++) {
        perimeter = M_PI * 2 * circle[i].r;
        area = M_PI * circle[i].r * circle[i].r;
        printf("%d. circle(%.2f %.2f, %.2f)\n",
               i + 1,
               circle[i].x,
               circle[i].y,
               circle[i].r);
        printf("\tperimeter = %.2f\n", perimeter);
        printf("\tarea = %.2f\n", area);
        if ((circle[i].object_interesection_1 != -1)
            && (circle[i].object_interesection_2 != -1)) {
            printf("intersects:\n\t %d. circle\n\t%d. circle\n",
                   circle[i].object_interesection_1,
                   circle[i].object_interesection_2);
        } else if (circle[i].object_interesection_1 != -1) {
            printf("intersects:\n\t %d. circle\n",
                   circle[i].object_interesection_1);
        } else if (circle[i].object_interesection_2 != -1) {
            printf("intersects:\n\t %d. circle\n",
                   circle[i].object_interesection_2);
        }
    }
}