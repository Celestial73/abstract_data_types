#include "typeInfo.h"

BinaryOperation getAdd(TypeInfo *type_info)
{
    return (BinaryOperation)type_info->add;
}
BinaryOperation getMultiply(TypeInfo *type_info)
{
    return (BinaryOperation)type_info->multiply;
}

UnaryOperation getPrint(TypeInfo *type_info)
{
    return (UnaryOperation)type_info->printElement;
}

EmptyOperation getInput(TypeInfo *type_info)
{
    return (EmptyOperation)type_info->inputValue;
}

PowerOperation getPower(TypeInfo *type_info)
{
    return (PowerOperation)type_info->power;
}