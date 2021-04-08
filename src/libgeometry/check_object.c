#include "function.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_object(char* object, int m_string)
{
    char check_string[] = {'c', 'i', 'r', 'c', 'l', 'e', '('};
    int is_true = 1;
    int i, j, n, g;
    for (i = 0; i < 7; ++i) {
        if (tolower(object[i]) != check_string[i]) {
            is_true = 0;
        }
    }
    if (is_true != 1) {
        printf("\nError: expected 'circle': ");
        exit(0);
    }

    for (i = 0; i < m_string; i++) {
        if (object[i] == ')') {
            if (object[i + 1] != '\0') {
                for (j = 0; j != (i + 1); j++) {
                    printf(" ");
                }
                printf("^");
                printf("\nError: unexpected token");
                exit(0);
            }
        }
    }

    for (i = 0; i < m_string; i++) {
        if (object[i] == '(') {
            for (j = i; object[j + 1] != ' '; j++) {
                if (((object[j + 1] <= '9') && (object[j + 1] >= '1'))
                    || (object[j + 1] == '.') || (object[j + 1] == '-')) {
                } else {
                    for (n = 0; n != (j + 1); n++) {
                        printf(" ");
                    }
                    printf("\nError: expected x '<double>'");
                    exit(0);
                }
            }
        }
    }

    for (i = 0; i < m_string; i++) {
        if (object[i] == ' ') {
            for (g = i; g < m_string; g++) {
                if (object[g] == ',') {
                    for (j = i; object[j + 1] != ','; j++) {
                        if (((object[j + 1] <= '9') && (object[j + 1] >= '1'))
                            || (object[j + 1] == '.')
                            || (object[j + 1] == '-')) {
                        } else {
                            for (n = 0; n != (j + 1); n++) {
                                printf(" ");
                            }
                            printf("\nError: expected y '<double>'");

                            exit(0);
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < m_string; i++) {
        if ((object[i] == ',') && (object[i + 1] == ' ')) {
            for (j = (i + 1); object[j + 1] != ')'; j++) {
                if (((object[j + 1] <= '9') && (object[j + 1] >= '1'))
                    || (object[j + 1] == '.')) {
                } else {
                    for (n = 0; n != (j + 1); n++) {
                        printf(" ");
                    }
                    printf("\nError: expected r '<double>'");
                    exit(0);
                }
            }
        }
    }
}