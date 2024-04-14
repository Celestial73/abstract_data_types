#include "polynomial.h"

int comparePolynomials(Polynomial *p1, Polynomial *p2)
{
    if (!(p1->getTypeInfo() == p2->getTypeInfo()))
    {
        return 0;
    }
    for (int i = 0; i < (*p1).size; i++)
    {
        void *first_value = getValue(p1, i);
        void *second_value = getValue(p2, i);
        if ((memcmp(first_value, second_value, p1->element_size)))
        {
            return 0;
        }
        free(first_value);
        free(second_value);
    }
    return 1;
}

Polynomial *addPolynomials(Polynomial *p1, Polynomial *p2)
{
    Polynomial *res = (Polynomial *)malloc(sizeof(Polynomial));
    copyPolynomials(res, p1);
    for (int i = 0; i < (*p1).size; i++)
    {
        void *arg1 = getValue(p1, i);
        void *arg2 = getValue(p2, i);
        //        setValue(res, i, p1.add(getValue(p1,i), getValue(p2,i)));
        void *addition_result = getAdd((*p1).getTypeInfo())(arg1, arg2);
        setValue(res, i, addition_result);
        free(arg1);
        free(arg2);
    }
    return res;
}

void *composePolynomials(Polynomial *p1, Polynomial *p2)
{
    void *res = getValue(p1, 0);
    for (int i = 1; i < (*p1).size; i++)
    {
        void *power_arg = getValue(p2, i);
        void *powered_arg = getPower((*p1).getTypeInfo())(power_arg, i);
        void *multiplier = getValue(p1, i);
        void *multiplication_result = getMultiply((*p1).getTypeInfo())(multiplier, powered_arg);
        void *addition_result = getAdd((*p1).getTypeInfo())(res, multiplication_result);
        memcpy(res, addition_result, (*p1).element_size);
        free(power_arg);
        free(multiplier);
        free(powered_arg);
        free(multiplication_result);
        free(addition_result);
    }
    return res;
}

void *calculatePolynomial(Polynomial *p1, void *argument)
{
    void *res = getValue(p1, 0);
    for (int i = 1; i < (*p1).size; i++)
    {
        void *powered_arg = getPower((*p1).getTypeInfo())(argument, i);
        void *multiplier = getValue(p1, i);
        void *multiplication_result = getMultiply((*p1).getTypeInfo())(multiplier, powered_arg);
        void *addition_result = getAdd((*p1).getTypeInfo())(res, multiplication_result);
        memcpy(res, addition_result, (*p1).element_size);
        free(multiplier);
        free(multiplication_result);
        free(addition_result);
        free(powered_arg);
    }
    return res;
}

Polynomial *multiplyPolynomials(Polynomial *p1, Polynomial *p2)
{
    Polynomial *res = (Polynomial *)malloc(sizeof(Polynomial));
    copyPolynomials(res, p1);
    for (int i = 0; i < (*p1).size; i++)
    {
        void *arg1 = getValue(p1, i);
        void *arg2 = getValue(p2, i);
        void *multiply_result = getMultiply((*p1).getTypeInfo())(arg1, arg2);
        setValue(res, i, multiply_result);
        free(arg1);
        free(arg2);
        free(multiply_result);
    }
    return res;
}

Polynomial *multiplyPolynomialByScalar(Polynomial *p1, void *scalar)
{
    Polynomial *res = (Polynomial *)malloc(sizeof(Polynomial));
    copyPolynomials(res, p1);
    for (int i = 0; i < (*p1).size; i++)
    {
        void *multiplier = getValue(p1, i);
        void *multiplication_result = getMultiply((*p1).getTypeInfo())(multiplication_result, scalar);
        setValue(res, i, multiplication_result);
        free(multiplication_result);
        free(multiplier);
    }
    return res;
}

// Copies everything except for element values
void copyPolynomials(Polynomial *p1, Polynomial *p2)
{
    (*p1).size = (*p2).size;
    (*p1).element_size = (*p2).element_size;

    (*p1).getTypeInfo = (*p2).getTypeInfo;

    (*p1).coefficients = malloc(p1->size * p1->element_size);
}

void printPolynomial(Polynomial *p)
{
    for (int i = 0; i < (*p).size; i++)
    {
        if (i != 0)
            printf(" + ");
        printf("(");
        void *argument = getValue(p, i);
        getPrint(p->getTypeInfo())(argument);
        printf(")x^%d", i);
    }
    printf("\n");
}

void *getValue(Polynomial *p, int i)
{
    void *val = malloc((*p).element_size);
    if (i <= (*p).size)
    {
        memcpy(val, ((char *)(*p).coefficients + i * (*p).element_size), (*p).element_size);
    }
    return val;
}

void setValue(Polynomial *p, int i, void *value)
{
    memcpy(((char *)(*p).coefficients + i * (*p).element_size), value, (*p).element_size);
}