#pragma once
#include "../utility/polynomial.h"
typedef struct ComplexNumber
{
    double real;
    double img;
} Complex;

// Polynomial createComplexPolynomial();
// void *complexAddition();
// void *complexMultiplication();
// void *complexPower();
// void *complexInput();
// void *complexPrint();

// TypeInfo createComplexTypeInfo();
// TypeInfo *getComplexTypeInfo();

void complexAddition(const void *v1, const void *v2, void *result);
void complexMultiplication(const void *v1, const void *v2, void *result);
void complexPower(const void *v1, const int v2, void *result);
void complexInput(void *result);
void complexPrint(const void *v);
void complexMakeNeutralForAddition(void *destination);
void complexMakeNeutralForMultiplication(void *destination);

TypeInfo createComplexTypeInfo();
TypeInfo *getComplexTypeInfo();
