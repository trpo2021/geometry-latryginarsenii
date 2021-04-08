#include "function.h"
#include <stdio.h>
#include <stdlib.h>

float coordinates_x(char* object, int m_string)
{
    int i, j;
    char search_x[m_string];
    float x;
    for (i = 0; i < m_string; i++) {
        search_x[i] = '\0';
    }
    for (i = 0; i < m_string; i++) {
        if (object[i] == '(') {
            for (j = i; object[j + 1] != ' '; j++) {
                search_x[j - i] = object[j + 1];
            }
        }
    }
    x = atof(search_x);
    return x;
}