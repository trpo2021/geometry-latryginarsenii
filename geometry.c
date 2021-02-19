#include <stdio.h>
#include <string.h>
#define M_PI 3.14159265358979323846

int main()
{
    //Объявление переменных ----------------------------------

    char s1[7] = "";
    char ts1[7] = "circle"; //circle
    char s2[2] = "";
    char ts2[2] = "("; //(
    float x1;          //x1
    char s3[2] = "";
    char ts3[2] = " "; //
    float x2;          //x2
    char s4[2] = "";
    char ts4[2] = ","; //,
    char s5[2] = "";
    char ts5[2] = " "; //
    float y1;          //y1
    char s6[2] = "";
    char ts6[2] = ")"; //)
    float perimeter;
    float area;

    //Ввод данных--------------------------------------------

    for (int i = 0; i < 6; i++) //Ввод circle
    {
        scanf("%c", &s1[i]);
    }

    for (int i = 0; i < 1; i++) //Ввод "("
    {
        scanf("%c", &s2[i]);
    }

    for (int i = 0; i < 1; i++) // Ввод x1
    {
        scanf("%f", &x1);
    }

    for (int i = 0; i < 1; i++) // Ввод пробела
    {
        scanf("%c", &s3[i]);
    }

    for (int i = 0; i < 1; i++) // Ввод x2
    {
        scanf("%f", &x2);
    }

    for (int i = 0; i < 1; i++) // Ввод ,
    {
        scanf("%c", &s4[i]);
    }

    for (int i = 0; i < 1; i++) // Ввод пробела
    {
        scanf("%c", &s5[i]);
    }

    for (int i = 0; i < 1; i++) // Ввод y1
    {
        scanf("%f", &y1);
    }

    for (int i = 0; i < 1; i++) // Ввод )
    {
        scanf("%c", &s6[i]);
    }

    if (strcmp(s1, ts1) == 0 && strcmp(s2, ts2) == 0 && strcmp(s3, ts3) == 0 && strcmp(s4, ts4) == 0 && strcmp(s5, ts5) == 0 && strcmp(s6, ts6) == 0)
    {
        perimeter = 2 * M_PI * y1;
        area = M_PI * y1 * y1;
        printf("perimeter = %.4f\n", perimeter);
        printf("area = %.4f\n", area);
    }
    else if (strcmp(s1, ts1) != 0)
    {
        puts("^\n");
        puts("Error: expected 'circle', 'triangle' or 'polygon'\n");
    }
    else if (strcmp(s2, ts2) != 0)
    {
        puts("      ^\n");
        puts("Error: expected '('\n");
    }
    else if (strcmp(s3, ts3) != 0)
    {
        puts("        ^\n");
        puts("Error: expected '<double>'\n");
    }
    else if (strcmp(s4, ts4) != 0)
    {
        puts("          ^\n");
        puts("Error: expected '<double>'\n");
    }
    else if (strcmp(s5, ts5) != 0)
    {
        puts("           ^\n");
        puts("Error: expected '<double>'\n");
    }
    else if (strcmp(s6, ts6) != 0)
    {
        puts("               ^\n");
        puts("Error: expected ')'\n");
    }
}