#pragma once
#include "../utility/polynomial.h"

Polynomial createRealPolynomial();
void *realAddition();
void *realMultiplication();
void *realPower();
void *realInput();
void *realPrint();

TypeInfo createRealTypeInfo();
TypeInfo *getRealTypeInfo();
