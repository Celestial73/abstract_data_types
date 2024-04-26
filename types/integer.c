#include "integer.h"

TypeInfo *getIntegerTypeInfo()
{
    static TypeInfo instance;
    // printf("Integer Type. Instance's initialized value is: %d\n", instance.initialized);
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
    type_info.element_size = 4;
    type_info.add = integerAddition;
    type_info.inputValue = integerInput;
    type_info.printElement = integerPrint;
    type_info.multiply = integerMultiplication;
    type_info.power = integerPower;
    type_info.makeNeutralForAddition = integerMakeNeutralForAddition;
    type_info.makeNeutralForMultiplication = integerMakeNeutralForMultiplication;

    return type_info;
}

void integerAddition(const void *v1, const void *v2, void *result)
{
    *((int *)result) = (*((int *)v1)) + (*((int *)v2));
}

void integerMultiplication(const void *v1, const void *v2, void *result)
{
    *((int *)result) = (*((int *)v1)) * (*((int *)v2));
}

void integerInput(void *result)
{
    int d;
    scanf("%d", &d);
    memcpy(result, &d, sizeof(int));
}

void integerPrint(const void *v)
{
    printf("%d", *(int *)v);
}

void integerPower(const void *v1, const int v2, void *result)
{
    int *res = (int *)result;
    *res = 1;
    for (int i = 0; i < v2; i++)
    {
        *res = (*res) * (*((int *)v1));
    }
}

void integerMakeNeutralForAddition(void *destination)
{
    *((int *)destination) = 0;
}

void integerMakeNeutralForMultiplication(void *destination)
{
    *((int *)destination) = 1;
}