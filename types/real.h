#pragma once
#include "../utility/polynomial.h"

// Polynomial createRealPolynomial();
// void *realAddition();
// void *realMultiplication();
// void *realPower();
// void *realInput();
// void *realPrint();

// TypeInfo createRealTypeInfo();
// TypeInfo *getRealTypeInfo();

void realAddition(const void *v1, const void *v2, void *result);
void realMultiplication(const void *v1, const void *v2, void *result);
void realPower(const void *v1, const int v2, void *result);
void realInput(void *result);
void realPrint(const void *v);
void realMakeNeutralForAddition(void *destination);
void realMakeNeutralForMultiplication(void *destination);

TypeInfo createRealTypeInfo();
TypeInfo *getRealTypeInfo();
