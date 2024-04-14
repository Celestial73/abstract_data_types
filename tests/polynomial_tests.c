#include "polynomial_tests.h"

void testComplex()
{
    test_createComplexPolynomial();
    test_createComplexTypeInfo();
    test_getComplexTypeInfo();
    test_complexMultiplication();
    test_complexAddition();
    test_complexPower();
    printf("Complex tests passed. \n\n");
}

void testInteger()
{
    test_createIntegerPolynomial();
    test_createIntegerTypeInfo();
    test_getIntegerTypeInfo();
    test_integerMultiplication();
    test_integerAddition();
    test_integerPower();
    printf("Integer tests passed. \n\n");
}

void testReal()
{
    test_realAddition();
    test_realMultiplication();
    test_realPower();
    test_createRealTypeInfo();
    test_createRealPolynomial();
    test_getRealTypeInfo();
    printf("Real tests passed. \n\n");
}

void test_calculatePolynomial()
{
    Polynomial tester = createIntegerPolynomial(3);
    int value;
    int *value_ptr = &value;
    for (int i = 0; i < 3; i++)
    {
        value = (i) * 2;
        setValue(&tester, i, (void *)(value_ptr));
    }
    value = 3;
    void *res = calculatePolynomial(&tester, value_ptr);
    int expected_res = 42;
    int *expected_res_ptr = &expected_res;
    assert(!memcmp(res, expected_res_ptr, tester.element_size));
    printf("Test Passed: calculatePolynomial\n");
}

void test_composePolynomials()
{
    int value;
    int *value_ptr = &value;
    Polynomial p1 = createIntegerPolynomial(3);
    for (int i = 0; i < 3; i++)
    {
        value = i + 1;
        setValue(&p1, i, (void *)(value_ptr));
    }
    Polynomial p2 = createIntegerPolynomial(3);
    for (int i = 0; i < 3; i++)
    {
        value = i + 1;
        setValue(&p2, i, (void *)(value_ptr));
    }
    void *res = composePolynomials(&p1, &p2);
    int expected_res = 32;
    int *expected_res_ptr = &expected_res;
    assert(!memcmp(res, expected_res_ptr, p2.element_size));
    printf("Test Passed: composePolynomials\n");
}

void test_addPolynomials()
{
    Polynomial tester = createIntegerPolynomial(3);
    int value;
    int *value_ptr = &value;
    for (int i = 0; i < 3; i++)
    {
        value = (i) * 2;
        setValue(&tester, i, (void *)(value_ptr));
    }
    Polynomial p1 = createIntegerPolynomial(3);
    for (int i = 0; i < 3; i++)
    {
        value = i;
        setValue(&p1, i, (void *)(value_ptr));
    }
    Polynomial p2 = createIntegerPolynomial(3);
    for (int i = 0; i < 3; i++)
    {
        value = i;
        setValue(&p2, i, (void *)(value_ptr));
    }
    Polynomial *addedPolynomial = addPolynomials(&p1, &p2);
    assert(comparePolynomials(&tester, addedPolynomial));
    printf("Test Passed: addPolynomials\n");
}

void test_multiplyPolynomials()
{
    Polynomial tester = createIntegerPolynomial(3);
    int value;
    int *value_ptr = &value;
    for (int i = 0; i < 3; i++)
    {
        value = i * i;
        setValue(&tester, i, (void *)(value_ptr));
    }
    Polynomial p1 = createIntegerPolynomial(3);
    for (int i = 0; i < 3; i++)
    {
        value = i;
        setValue(&p1, i, (void *)(value_ptr));
    }
    Polynomial p2 = createIntegerPolynomial(3);
    for (int i = 0; i < 3; i++)
    {
        value = i;
        setValue(&p2, i, (void *)(value_ptr));
    }
    Polynomial *multipliedPolynomial = multiplyPolynomials(&p1, &p2);
    assert(comparePolynomials(&tester, multipliedPolynomial));
    printf("Test Passed: multiplyPolynomials\n");
}
