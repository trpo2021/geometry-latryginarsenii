#include <libgeometry/function.h>

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m_string = 60;
    char object[m_string];
    struct object circle[3];
    char test_c;
    int result_char;

    //Вводим объекты
    for (int i = 0; i < 3; i++) {
        result_char = 0;
        printf("\nEnter your Object:\n");
        for (int j = 0; j < m_string; j++) {
            test_c = getchar();
            if (test_c == '\n') {
                break;
            }
            object[j] = test_c;
            result_char++;
        }
        for (int k = result_char; k < m_string; k++) {
            object[result_char] = '\0';
        }

        check_object(object, m_string);
        circle[i].r = calculate(object, m_string);
        circle[i].x = coordinates_x(object, m_string);
        circle[i].y = coordinates_y(object, m_string);

        for (int j = 0; j < m_string; j++) {
            object[j] = '\0';
        }
    }
    for (int i = 0; i < 3; i++) {
        printf("circle(%.2f %.2f, %.2f)\n",
               circle[i].x,
               circle[i].y,
               circle[i].r);
    }

    object_interesection(circle);
    output_object(circle);
}