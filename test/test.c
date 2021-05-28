#include <../src/libgeometry/function.h>
#include <ctest.h>

CTEST(check_object, correct_input)
{
    char test_source[50] = "circle(1 2, 3)\0";
    const int expect = 0;

    const int result = check_object(test_source, 50);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_object, incorrect_input_1)
{
    char test_source[50] = "circle(1 2, 3)5\0";
    const int expect = 1;

    const int result = check_object(test_source, 50);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_object, incorrect_input_2)
{
    char test_source[50] = "circle(1 2, 3)shhhfgs\0";
    const int expect = 1;

    const int result = check_object(test_source, 50);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_object, incorrect_input_3)
{
    char test_source[50] = "circrtrtr(1 2, 3)\0";
    const int expect = 1;

    const int result = check_object(test_source, 50);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_object, incorrect_input_4)
{
    char test_source[50] = "(1 2, 3)\0";
    const int expect = 1;

    const int result = check_object(test_source, 50);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_object, incorrect_input_5)
{
    char test_source[50] = "circle(1 2, 3ааа\0";
    const int expect = 1;

    const int result = check_object(test_source, 50);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_object, incorrect_input_6)
{
    char test_source[50] = "circle(1 2, 3333\0";
    const int expect = 1;

    const int result = check_object(test_source, 50);
    ASSERT_EQUAL(expect, result);
}

CTEST(check_object, incorrect_input_7)
{
    char test_source[50] = "circle(1 2, 3      \0";
    const int expect = 1;

    const int result = check_object(test_source, 50);
    ASSERT_EQUAL(expect, result);
}