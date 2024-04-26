#include "polynomial.h"

void createPolynomial(const TypeInfo *type_info, const int size, Polynomial *destination)
{
    destination->size = size;
    destination->type_info = type_info;
    destination->coefficients = malloc((type_info->element_size) * size);
}

void deletePolynomial(Polynomial *polynomial)
{
    free(polynomial->coefficients);
    free(polynomial);
}

int comparePolynomials(const Polynomial *p1, const Polynomial *p2)
{
    if (!(p1->type_info == p2->type_info))
    {
        return 0;
    }
    void *first_value = malloc(p1->type_info->element_size);
    void *second_value = malloc(p1->type_info->element_size);
    for (int i = 0; i < (*p1).size; i++)
    {
        getValue(p1, i, first_value);
        getValue(p2, i, second_value);
        if ((memcmp(first_value, second_value, p1->type_info->element_size)))
        {
            return 0;
        }
    }
    free(first_value);
    free(second_value);
    return 1;
}

void addPolynomials(const Polynomial *p1, const Polynomial *p2, Polynomial *result)
{
    createPolynomial(p1->type_info, p1->size, result);
    void *arg1 = malloc(p1->type_info->element_size);
    void *arg2 = malloc(p1->type_info->element_size);
    void *addition_result = malloc(p1->type_info->element_size);
    getNeutralForAddition(p1->type_info)(addition_result);
    for (int i = 0; i < (*p1).size; i++)
    {
        getValue(p1, i, arg1);
        getValue(p2, i, arg2);
        getAdd((*p1).type_info)(arg1, arg2, addition_result);
        setValue(result, i, addition_result);
    }
    free(arg1);
    free(arg2);
    free(addition_result);
}

void composePolynomials(const Polynomial *p1, const Polynomial *p2, void *result)
{
    void *power_arg = malloc(p1->type_info->element_size);
    void *powered_arg = malloc(p1->type_info->element_size);
    void *multiplier = malloc(p1->type_info->element_size);
    void *multiplication_result = malloc(p1->type_info->element_size);
    void *addition_result = malloc(p1->type_info->element_size);
    getNeutralForAddition(p1->type_info)(result);
    for (int i = 0; i < (*p1).size; i++)
    {
        getValue(p2, i, power_arg);
        getPower((*p1).type_info)(power_arg, i, powered_arg);
        getValue(p1, i, multiplier);
        getMultiply((*p1).type_info)(multiplier, powered_arg, multiplication_result);
        getAdd((*p1).type_info)(result, multiplication_result, addition_result);
        memcpy(result, addition_result, (*p1).type_info->element_size);
    }
    free(power_arg);
    free(multiplier);
    free(powered_arg);
    free(multiplication_result);
    free(addition_result);
}

void calculatePolynomial(const Polynomial *p1, const void *argument, void *result)
{
    void *powered_arg = malloc(p1->type_info->element_size);
    void *multiplier = malloc(p1->type_info->element_size);
    void *multiplication_result = malloc(p1->type_info->element_size);
    void *addition_result = malloc(p1->type_info->element_size);
    getNeutralForAddition(p1->type_info)(result);
    for (int i = 0; i < p1->size; i++)
    {
        getPower((*p1).type_info)(argument, i, powered_arg);
        getValue(p1, i, multiplier);
        getMultiply((*p1).type_info)(multiplier, powered_arg, multiplication_result);
        getAdd((*p1).type_info)(result, multiplication_result, addition_result);
        memcpy(result, addition_result, (*p1).type_info->element_size);
    }
    free(multiplier);
    free(multiplication_result);
    free(addition_result);
    free(powered_arg);
}

void multiplyPolynomials(const Polynomial *p1, const Polynomial *p2, Polynomial *result)
{
    copyPolynomialStucture(result, p1);
    void *arg1 = malloc(p1->type_info->element_size);
    void *arg2 = malloc(p1->type_info->element_size);
    void *multiplication_result = malloc(p1->type_info->element_size);
    getNeutralForMultiplication(multiplication_result);
    for (int i = 0; i < (*p1).size; i++)
    {
        getValue(p1, i, arg1);
        getValue(p2, i, arg2);
        getMultiply((*p1).type_info)(arg1, arg2, multiplication_result);
        setValue(result, i, multiplication_result);
    }
    free(arg1);
    free(arg2);
    free(multiplication_result);
}

void multiplyPolynomialByScalar(const Polynomial *p, const void *scalar, Polynomial *result)
{
    copyPolynomialStucture(result, p);
    void *multiplier = malloc(p->type_info->element_size);
    void *multiplication_result = malloc(p->type_info->element_size);
    getNeutralForMultiplication(multiplication_result);
    for (int i = 0; i < (*p).size; i++)
    {
        getValue(p, i, multiplier);
        getMultiply((*p).type_info)(multiplication_result, scalar, multiplication_result);
        setValue(result, i, multiplication_result);
    }
    free(multiplication_result);
    free(multiplier);
}

// Copies everything except for element values
void copyPolynomialStucture(Polynomial *destination, const Polynomial *source)
{
    destination->size = source->size;
    destination->type_info = source->type_info;

    destination->coefficients = malloc(destination->size * destination->type_info->element_size);
}

void printPolynomial(const Polynomial *p)
{
    void *argument = malloc(p->type_info->element_size);
    for (int i = 0; i < (*p).size; i++)
    {
        if (i != 0)
            printf(" + ");
        printf("(");
        getValue(p, i, argument);
        getPrint(p->type_info)(argument);
        printf(")x^%d", i);
    }
    free(argument);
    printf("\n");
}

void getValue(const Polynomial *p, const int i, void *destination)
{
    if (i <= (*p).size)
    {
        memcpy(destination, ((char *)(*p).coefficients + i * (*p).type_info->element_size), (*p).type_info->element_size);
    }
}

void setValue(Polynomial *p, const int i, const void *value)
{
    memcpy(((char *)(*p).coefficients + i * (*p).type_info->element_size), value, (*p).type_info->element_size);
}