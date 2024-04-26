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
    Polynomial *tester = malloc(sizeof(Polynomial));
    createPolynomial(getIntegerTypeInfo(), 3, tester);
    int value;
    int *value_ptr = &value;
    for (int i = 0; i < 3; i++)
    {
        value = (i) * 2;
        setValue(tester, i, (void *)(value_ptr));
    }
    value = 3;
    void *res = malloc(tester->type_info->element_size);
    calculatePolynomial(tester, value_ptr, res);
    int expected_res = 42;
    int *expected_res_ptr = &expected_res;
    assert(!memcmp(res, expected_res_ptr, tester->type_info->element_size));
    printf("Test Passed: calculatePolynomial\n");
    deletePolynomial(tester);
    free(res);
}

void test_composePolynomials()
{
    int value;
    int *value_ptr = &value;
    Polynomial *p1 = malloc(sizeof(Polynomial));
    createPolynomial(getIntegerTypeInfo(), 3, p1);
    for (int i = 0; i < 3; i++)
    {
        value = i + 1;
        setValue(p1, i, (void *)(value_ptr));
    }
    Polynomial *p2 = malloc(sizeof(Polynomial));
    createPolynomial(getIntegerTypeInfo(), 3, p2);
    for (int i = 0; i < 3; i++)
    {
        value = i + 1;
        setValue(p2, i, (void *)(value_ptr));
    }
    void *res = malloc(p1->type_info->element_size);
    composePolynomials(p1, p2, res);

    int expected_res = 32;
    int *expected_res_ptr = &expected_res;
    assert(!memcmp(res, expected_res_ptr, p2->type_info->element_size));
    printf("Test Passed: composePolynomials\n");

    deletePolynomial(p1);
    deletePolynomial(p2);
    free(res);
}

void test_addPolynomials()
{
    Polynomial *tester = malloc(sizeof(Polynomial));
    createPolynomial(getIntegerTypeInfo(), 3, tester);
    int value;
    int *value_ptr = &value;
    for (int i = 0; i < 3; i++)
    {
        value = (i) * 2;
        setValue(tester, i, (void *)(value_ptr));
    }
    Polynomial *p1 = malloc(sizeof(Polynomial));
    createPolynomial(getIntegerTypeInfo(), 3, p1);
    for (int i = 0; i < 3; i++)
    {
        value = i;
        setValue(p1, i, (void *)(value_ptr));
    }
    Polynomial *p2 = malloc(sizeof(Polynomial));
    createPolynomial(getIntegerTypeInfo(), 3, p2);
    for (int i = 0; i < 3; i++)
    {
        value = i;
        setValue(p2, i, (void *)(value_ptr));
    }
    Polynomial *addedPolynomial = malloc(sizeof(Polynomial));
    addPolynomials(p1, p2, addedPolynomial);
    assert(comparePolynomials(tester, addedPolynomial));
    printf("Test Passed: addPolynomials\n");

    deletePolynomial(tester);
    deletePolynomial(p1);
    deletePolynomial(p2);
    deletePolynomial(addedPolynomial);
}

void test_multiplyPolynomials()
{
    Polynomial *tester = malloc(sizeof(Polynomial));
    createPolynomial(getIntegerTypeInfo(), 3, tester);
    int value;
    int *value_ptr = &value;
    for (int i = 0; i < 3; i++)
    {
        value = i * i;
        setValue(tester, i, (void *)(value_ptr));
    }
    Polynomial *p1 = malloc(sizeof(Polynomial));
    createPolynomial(getIntegerTypeInfo(), 3, p1);
    for (int i = 0; i < 3; i++)
    {
        value = i;
        setValue(p1, i, (void *)(value_ptr));
    }
    Polynomial *p2 = malloc(sizeof(Polynomial));
    createPolynomial(getIntegerTypeInfo(), 3, p2);
    for (int i = 0; i < 3; i++)
    {
        value = i;
        setValue(p2, i, (void *)(value_ptr));
    }
    Polynomial *multiplied_polynomial = malloc(sizeof(Polynomial));
    createPolynomial(getIntegerTypeInfo(), 3, multiplied_polynomial);
    multiplyPolynomials(p1, p2, multiplied_polynomial);
    assert(comparePolynomials(tester, multiplied_polynomial));
    printf("Test Passed: multiplyPolynomials\n");

    deletePolynomial(tester);
    deletePolynomial(p1);
    deletePolynomial(p2);
    deletePolynomial(multiplied_polynomial);
}
