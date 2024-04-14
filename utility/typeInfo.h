
typedef void *(*PowerOperation)(void *, int);
typedef void *(*BinaryOperation)(void *, void *);
typedef void *(*UnaryOperation)(void *);
typedef void *(*EmptyOperation)();

typedef struct type
{
    int initialized;

    void *(*inputValue)();
    void *(*printElement)(void *);
    void *(*add)(void *, void *);
    void *(*multiply)(void *, void *);
    void *(*power)(void *, int);
} TypeInfo;

BinaryOperation getAdd(TypeInfo *type_info);
BinaryOperation getMultiply(TypeInfo *type_info);
UnaryOperation getPrint(TypeInfo *type_info);
EmptyOperation getInput(TypeInfo *type_info);
PowerOperation getPower(TypeInfo *type_info);