#pragma once
#include "../utility/polynomial.h"

Polynomial createIntegerPolynomial();
void *integerAddition();
void *integerMultiplication();
void *integerPower();
void *integerInput();
void *integerPrint();

TypeInfo createIntegerTypeInfo();
TypeInfo *getIntegerTypeInfo();
