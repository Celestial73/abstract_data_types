#include "typeInfo.h"

BinaryOperation getAdd(const TypeInfo *type_info)
{
    return (BinaryOperation)type_info->add;
}
BinaryOperation getMultiply(const TypeInfo *type_info)
{
    return (BinaryOperation)type_info->multiply;
}

EmptyOperation getPrint(const TypeInfo *type_info)
{
    return (EmptyOperation)type_info->printElement;
}

EmptyOperation getInput(const TypeInfo *type_info)
{
    return (EmptyOperation)type_info->inputValue;
}

PowerOperation getPower(const TypeInfo *type_info)
{
    return (PowerOperation)type_info->power;
}

EmptyOperation getNeutralForAddition(const TypeInfo *type_info)
{
    return (EmptyOperation)type_info->makeNeutralForAddition;
}
EmptyOperation getNeutralForMultiplication(const TypeInfo *type_info)
{
    return (EmptyOperation)type_info->makeNeutralForMultiplication;
}
