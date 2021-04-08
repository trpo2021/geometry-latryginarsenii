#include "function.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float calculate(char* object, int m_string)
{
    int i, j;
    char rad[m_string];
    float r = 0;

    for (i = 0; i < m_string; i++) {
        if ((object[i] == ',') && (object[i + 1] == ' ')) {
            for (j = i; object[j + 1] != ')'; j++) {
                rad[j - i] = object[j + 1];
            }
        }
    }
    r = atof(rad);
    return r;
}