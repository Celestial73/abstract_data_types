#include "real.h"

TypeInfo *getRealTypeInfo()
{
    static TypeInfo instance;
    // printf("Real Type. Instance's initialized value is: %d\n", instance.initialized);
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
    type_info.makeNeutralForAddition = realMakeNeutralForAddition;
    type_info.makeNeutralForMultiplication = realMakeNeutralForMultiplication;
    type_info.element_size = sizeof(double);

    return type_info;
}

void realAddition(const void *v1, const void *v2, void *result)
{
    double *res = (double *)result;
    *res = (*((double *)v1)) + (*((double *)v2));
}

void realMultiplication(const void *v1, const void *v2, void *result)
{
    double *res = (double *)result;
    *res = (*((double *)v1)) * (*((double *)v2));
}

void realInput(void *result)
{
    double *res = (double *)result;
    scanf("%lf", res);
}

void realPrint(const void *v)
{
    printf("%f", *(double *)v);
}

void realPower(const void *v1, const int v2, void *result)
{
    double *res = (double *)result;
    *res = 1;
    for (int i = 0; i < v2; i++)
    {
        *res = (*res) * (*((double *)v1));
    }
}

void realMakeNeutralForAddition(void *destination)
{
    *((double *)destination) = 0.0;
}

void realMakeNeutralForMultiplication(void *destination)
{
    *((double *)destination) = 1.0;
}