#include "real.h"

TypeInfo *getRealTypeInfo()
{
    static TypeInfo instance;
    if (instance.initialized == 0)
    {
        instance = createRealTypeInfo();
    }
    return &instance;
}

TypeInfo createRealTypeInfo()
{
    TypeInfo type_info;

    type_info.initialized = 1;

    type_info.add = realAddition;
    type_info.inputValue = realInput;
    type_info.printElement = realPrint;
    type_info.multiply = realMultiplication;
    type_info.power = realPower;

    return type_info;
}

Polynomial createRealPolynomial(int size)
{
    Polynomial polynomial;

    polynomial.size = size;
    polynomial.element_size = sizeof(double);
    polynomial.coefficients = malloc(polynomial.size * polynomial.element_size);

    polynomial.getTypeInfo = getRealTypeInfo;
    return polynomial;
}

void *realAddition(void *v1, void *v2)
{
    double *res = (double *)malloc(sizeof(double));
    *res = (*((double *)v1)) + (*((double *)v2));
    return (void *)res;
}

void *realMultiplication(void *v1, void *v2)
{
    double *res = (double *)malloc(sizeof(double));
    *res = (*((double *)v1)) * (*((double *)v2));
    return (void *)res;
}

void *realInput()
{
    double *res = (double *)malloc(sizeof(double));
    scanf("%lf", res);
    return (void *)res;
}

void *realPrint(void *v)
{
    printf("%f", *(double *)v);
    return (void *)v;
}

void *realPower(void *v1, int v2)
{
    double *res = (double *)malloc(sizeof(double));
    *res = 1;
    for (int i = 0; i < v2; i++)
    {
        *res = (*res) * (*((double *)v1));
    }
    return (void *)res;
}
