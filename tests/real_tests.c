#include "real_tests.h"

void test_getRealTypeInfo()
{
    TypeInfo *type_info = getRealTypeInfo();

    assert(type_info->initialized == 1);
    assert(type_info->add == realAddition);
    assert(type_info->inputValue == realInput);
    assert(type_info->printElement == realPrint);
    assert(type_info->multiply == realMultiplication);
    assert(type_info->power == realPower);

    printf("Test Passed: getRealTypeInfo\n");
}

void test_createRealTypeInfo()
{
    TypeInfo type_info = createRealTypeInfo();

    assert(type_info.initialized == 1);
    assert(type_info.add == realAddition);
    assert(type_info.inputValue == realInput);
    assert(type_info.printElement == realPrint);
    assert(type_info.multiply == realMultiplication);
    assert(type_info.power == realPower);

    printf("Test Passed: createRealTypeInfo\n");
}

void test_createRealPolynomial()
{
    Polynomial *polynomial = malloc(sizeof(Polynomial));
    createPolynomial(getRealTypeInfo(), 5, polynomial);

    assert(polynomial->size == 5);
    assert(polynomial->type_info->element_size == sizeof(double));
    assert(polynomial->type_info == getRealTypeInfo());

    printf("Test Passed: createIntegerPolynomial\n");
}

int compareReal(double x, double y)
{
    double epsilon = 0.00001f;
    if (fabs(x - y) < epsilon)
    {
        return 1; // they are same
    }
    return 0; // they are not same
}

void test_realAddition()
{
    double c1 = 1.5;
    double c2 = 2.33;
    void *result = malloc(sizeof(double));
    realAddition(&c1, &c2, result);
    double expected_result = 3.83;
    assert(compareReal(*((double *)result), expected_result));
    free(result);
    printf("Test Passed: realAddition\n");
}

void test_realMultiplication()
{
    double c1 = 5.5;
    double c2 = 8.3;

    void *result = malloc(sizeof(double));
    realMultiplication(&c1, &c2, result);
    double expected_result = 45.65;
    assert(compareReal(*((double *)result), expected_result));

    printf("Test Passed: realMultiplication\n");
}

void test_realPower()
{
    double c = 2.5;
    void *result = malloc(sizeof(double));
    realPower(&c, 3, result);
    double expected_result = 15.625;
    assert(compareReal(*((double *)result), expected_result));

    printf("Test Passed: realPower\n");
}