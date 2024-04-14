#include "complex.h"

TypeInfo *getComplexTypeInfo()
{
    static TypeInfo instance;
    if (instance.initialized == 0)
    {
        instance = createComplexTypeInfo();
    }
    return &instance;
}

TypeInfo createComplexTypeInfo()
{
    TypeInfo type_info;

    type_info.initialized = 1;

    type_info.add = complexAddition;
    type_info.inputValue = complexInput;
    type_info.printElement = complexPrint;
    type_info.multiply = complexMultiplication;
    type_info.power = complexPower;

    return type_info;
}

Polynomial createComplexPolynomial(int size)
{
    Polynomial polynomial;

    polynomial.size = size;
    polynomial.element_size = sizeof(Complex);
    polynomial.coefficients = malloc(polynomial.size * polynomial.element_size);

    polynomial.getTypeInfo = getComplexTypeInfo;
    return polynomial;
}

void *complexAddition(void *v1, void *v2)
{
    Complex *temp = (Complex *)malloc(sizeof(Complex));
    temp->real = (((Complex *)v1)->real) + (((Complex *)v2)->real);
    temp->img = (((Complex *)v1)->img) + (((Complex *)v2)->img);
    return (void *)temp;
}

void *complexMultiplication(void *v1, void *v2)
{
    Complex *temp = (Complex *)malloc(sizeof(Complex));
    temp->real = (((Complex *)v1)->real) * (((Complex *)v2)->real) - ((((Complex *)v1)->img) * (((Complex *)v2)->img));
    temp->img = (((Complex *)v1)->real) * (((Complex *)v2)->img) + ((((Complex *)v1)->img) * (((Complex *)v2)->real));
    return (void *)temp;
}

void *complexInput()
{
    Complex *res = (Complex *)malloc(sizeof(Complex));
    scanf("%lf", &(res->real));
    scanf("%lf", &(res->img));
    return (void *)res;
}

void *complexPrint(void *v)
{
    printf("%f + %fi", ((Complex *)v)->real, ((Complex *)v)->img);
    return (void *)v;
}

void *complexPower(void *v1, int v2)
{
    Complex *temp = (Complex *)malloc(sizeof(Complex));
    temp->real = ((Complex *)v1)->real;
    temp->img = ((Complex *)v1)->img;
    for (int i = 0; i < v2 - 1; i++)
    {
        void *mult_result = complexMultiplication((void *)temp, v1);
        memcpy(temp, mult_result, sizeof(Complex));
        free(mult_result);
    }
    return (void *)temp;
}
