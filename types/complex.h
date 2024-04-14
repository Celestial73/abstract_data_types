#include "../utility/polynomial.h"
typedef struct ComplexNumber
{
    double real;
    double img;
} Complex;

Polynomial createComplexPolynomial();
void *complexAddition();
void *complexMultiplication();
void *complexPower();
void *complexInput();
void *complexPrint();

TypeInfo createComplexTypeInfo();
TypeInfo *getComplexTypeInfo();
