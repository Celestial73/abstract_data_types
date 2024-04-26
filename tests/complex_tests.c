#include "complex_tests.h"

void test_getComplexTypeInfo()
{
    TypeInfo *type_info = getComplexTypeInfo();

    assert(type_info->initialized == 1);
    assert(type_info->add == complexAddition);
    assert(type_info->inputValue == complexInput);
    assert(type_info->printElement == complexPrint);
    assert(type_info->multiply == complexMultiplication);
    assert(type_info->power == complexPower);

    printf("Test Passed: getComplexTypeInfo\n");
}

void test_createComplexTypeInfo()
{
    TypeInfo type_info = createComplexTypeInfo();

    assert(type_info.initialized == 1);
    assert(type_info.add == complexAddition);
    assert(type_info.inputValue == complexInput);
    assert(type_info.printElement == complexPrint);
    assert(type_info.multiply == complexMultiplication);
    assert(type_info.power == complexPower);

    printf("Test Passed: createComplexTypeInfo\n");
}

void test_createComplexPolynomial()
{
    Polynomial *polynomial = malloc(sizeof(Polynomial));
    createPolynomial(getComplexTypeInfo(), 5, polynomial);

    assert(polynomial->size == 5);
    assert(polynomial->type_info->element_size == sizeof(Complex));
    assert(polynomial->type_info == getComplexTypeInfo());

    printf("Test Passed: createIntegerPolynomial\n");
    deletePolynomial(polynomial);
}

void test_complexAddition()
{
    Complex c1 = {3.0, 4.0};
    Complex c2 = {1.0, 2.0};

    Complex *result = malloc(sizeof(Complex));
    complexAddition(&c1, &c2, result);

    assert(result->real == 4.0);
    assert(result->img == 6.0);

    printf("Test Passed: complexAddition\n");
    free(result);
}

void test_complexMultiplication()
{
    Complex c1 = {3.0, 4.0};
    Complex c2 = {1.0, 2.0};

    Complex *result = malloc(sizeof(Complex));
    complexMultiplication(&c1, &c2, result);

    assert(result->real == -5.0);
    assert(result->img == 10.0);

    printf("Test Passed: complexMultiplication\n");
    free(result);
}

void test_complexPower()
{
    Complex c = {3.0, 4.0};

    Complex *result = malloc(sizeof(Complex));
    complexPower(&c, 3, result);

    assert(result->real == -117.0);
    assert(result->img == 44.0);

    printf("Test Passed: complexPower\n");
    free(result);
}