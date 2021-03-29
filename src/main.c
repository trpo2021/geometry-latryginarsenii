#include "calculate.c"
#include "check_object.c"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m_string = 60;
    char object[m_string];
    printf("Enter your Object:\n");
    scanf("%[^\n]s", object);
    check_object(object, m_string);
    calculate(object, m_string);
}