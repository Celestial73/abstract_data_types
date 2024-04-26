#include "integer_tests.h"

void test_getIntegerTypeInfo()
{
    TypeInfo *type_info = getIntegerTypeInfo();

    assert(type_info->initialized == 1);
    assert(type_info->add == integerAddition);
    assert(type_info->inputValue == integerInput);
    assert(type_info->printElement == integerPrint);
    assert(type_info->multiply == integerMultiplication);
    assert(type_info->power == integerPower);

    printf("Test Passed: getintegerTypeInfo\n");
}

void test_createIntegerTypeInfo()
{
    TypeInfo type_info = createIntegerTypeInfo();

    assert(type_info.initialized == 1);
    assert(type_info.add == integerAddition);
    assert(type_info.inputValue == integerInput);
    assert(type_info.printElement == integerPrint);
    assert(type_info.multiply == integerMultiplication);
    assert(type_info.power == integerPower);

    printf("Test Passed: createIntegerTypeInfo\n");
}

void test_createIntegerPolynomial()
{
    Polynomial *polynomial = malloc(sizeof(Polynomial));
    createPolynomial(getIntegerTypeInfo(), 5, polynomial);

    assert(polynomial->size == 5);
    assert(polynomial->type_info->element_size == sizeof(int));
    assert(polynomial->type_info == getIntegerTypeInfo());

    printf("Test Passed: createIntegerPolynomial\n");
}

void test_integerAddition()
{
    int c1 = 1;
    int c2 = 2;
    void *result = malloc(4);
    integerAddition(&c1, &c2, result);
    assert(*((int *)result) == 3);
    free(result);
    printf("Test Passed: integerAddition\n");
}

void test_integerMultiplication()
{
    int c1 = 5;
    int c2 = 8;
    void *result = malloc(4);
    integerMultiplication(&c1, &c2, result);

    assert(*((int *)result) == 40);

    printf("Test Passed: intMultiplication\n");
}

void test_integerPower()
{
    int c = 5;
    void *result = malloc(4);
    integerPower(&c, 3, result);

    assert(*((int *)result) == 125);

    printf("Test Passed: integerPower\n");
}