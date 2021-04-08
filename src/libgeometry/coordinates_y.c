#include "function.h"
#include <stdio.h>
#include <stdlib.h>

float coordinates_y(char* object, int m_string)
{
    int i, j;
    char search_y[m_string];
    float y;
    for (i = 0; i < m_string; i++) {
        search_y[i] = '\0';
    }
    for (i = 0; i < m_string; i++) {
        if ((object[i] == ' ') && (object[i - 1] != ',')) {
            for (j = i; object[j + 1] != ','; j++) {
                search_y[j - i] = object[j + 1];
            }
        }
    }
    y = atof(search_y);
    return y;
}