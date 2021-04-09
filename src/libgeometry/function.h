#pragma once
struct object {
    float r;
    float x;
    float y;
    int object_interesection_1;
    int object_interesection_2;
};
float calculate(char* object, int m_string);
void check_object(char* object, int m_string);
float coordinates_x(char* object, int m_string);
float coordinates_y(char* object, int m_string);
void output_object(struct object* circle);
void object_interesection(struct object* circle);