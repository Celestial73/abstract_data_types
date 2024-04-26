#include "complex.h"

TypeInfo *getComplexTypeInfo()
{
    static TypeInfo instance;
    // printf("Complex Type. Instance's initialized value is: %d\n", instance.initialized);
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
    type_info.makeNeutralForAddition = complexMakeNeutralForAddition;
    type_info.makeNeutralForMultiplication = complexMakeNeutralForMultiplication;
    type_info.element_size = sizeof(Complex);

    return type_info;
}

void complexAddition(const void *v1, const void *v2, void *result)
{
    Complex *res = (Complex *)result;
    res->real = (((Complex *)v1)->real) + (((Complex *)v2)->real);
    res->img = (((Complex *)v1)->img) + (((Complex *)v2)->img);
}

void complexMultiplication(const void *v1, const void *v2, void *result)
{
    Complex *res = (Complex *)result;
    res->real = (((Complex *)v1)->real) * (((Complex *)v2)->real) - ((((Complex *)v1)->img) * (((Complex *)v2)->img));
    res->img = (((Complex *)v1)->real) * (((Complex *)v2)->img) + ((((Complex *)v1)->img) * (((Complex *)v2)->real));
}

void complexInput(void *result)
{
    Complex *res = (Complex *)result;
    scanf("%lf", &(res->real));
    scanf("%lf", &(res->img));
}

void complexPrint(const void *v)
{
    printf("%f + %fi", ((Complex *)v)->real, ((Complex *)v)->img);
}

void complexPower(const void *v1, const int v2, void *result)
{
    Complex *res = (Complex *)result;
    res->real = ((Complex *)v1)->real;
    res->img = ((Complex *)v1)->img;
    void *mult_result = malloc(sizeof(Complex));
    for (int i = 0; i < v2 - 1; i++)
    {
        complexMultiplication((void *)res, v1, mult_result);
        memcpy(res, mult_result, sizeof(Complex));
    }
    free(mult_result);
}

void complexMakeNeutralForAddition(void *destination)
{
    Complex zero = {0, 0};
    *((Complex *)destination) = zero;
}

void complexMakeNeutralForMultiplication(void *destination)
{
    Complex one = {1, 1};
    *((Complex *)destination) = one;
}