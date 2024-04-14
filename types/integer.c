#include "integer.h"

TypeInfo *getIntegerTypeInfo()
{
    static TypeInfo instance;
    if (instance.initialized == 0)
    {
        instance = createIntegerTypeInfo();
    }
    return &instance;
}

TypeInfo createIntegerTypeInfo()
{
    TypeInfo type_info;

    type_info.initialized = 1;

    type_info.add = integerAddition;
    type_info.inputValue = integerInput;
    type_info.printElement = integerPrint;
    type_info.multiply = integerMultiplication;
    type_info.power = integerPower;

    return type_info;
}

Polynomial createIntegerPolynomial(int size)
{
    Polynomial polynomial;

    polynomial.size = size;
    polynomial.element_size = sizeof(int);
    polynomial.coefficients = malloc(polynomial.size * polynomial.element_size);

    polynomial.getTypeInfo = getIntegerTypeInfo;
    return polynomial;
}

void *integerAddition(void *v1, void *v2)
{
    int *res = (int *)malloc(sizeof(int));
    *res = (*((int *)v1)) + (*((int *)v2));
    return (void *)res;
}

void *integerMultiplication(void *v1, void *v2)
{
    int *res = (int *)malloc(sizeof(int));
    *res = (*((int *)v1)) * (*((int *)v2));
    return (void *)res;
}

void *integerInput()
{
    int *res = (int *)malloc(sizeof(int));
    int d;
    scanf("%d", &d);
    memcpy(res, &d, sizeof(int));
    return (void *)res;
}

void *integerPrint(void *v)
{
    printf("%d", *(int *)v);
    return (void *)v;
}

void *integerPower(void *v1, int v2)
{
    int *res = (int *)malloc(sizeof(int));
    *res = 1;
    for (int i = 0; i < v2; i++)
    {
        *res = (*res) * (*((int *)v1));
    }
    return (void *)res;
}
