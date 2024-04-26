#pragma once
typedef void (*PowerOperation)(const void *, const int, void *);
typedef void (*BinaryOperation)(const void *, const void *, void *);
typedef void (*UnaryOperation)(const void *, void *);
typedef void (*EmptyOperation)(void *);

typedef struct type
{
    int initialized;
    int element_size;

    void (*inputValue)();
    void (*printElement)(const void *);
    void (*add)(const void *, const void *, void *);
    void (*multiply)(const void *, const void *, void *);
    void (*power)(const void *, const int, void *);
    void (*makeNeutralForAddition)(void *);
    void (*makeNeutralForMultiplication)(void *);
} TypeInfo;

BinaryOperation getAdd(const TypeInfo *type_info);
BinaryOperation getMultiply(const TypeInfo *type_info);
EmptyOperation getPrint(const TypeInfo *type_info);
EmptyOperation getInput(const TypeInfo *type_info);
EmptyOperation getNeutralForAddition(const TypeInfo *type_info);
EmptyOperation getNeutralForMultiplication(const TypeInfo *type_info);
PowerOperation getPower(const TypeInfo *type_info);