#pragma once
#include "../utility/polynomial.h"

void integerAddition(const void *v1, const void *v2, void *result);
void integerMultiplication(const void *v1, const void *v2, void *result);
void integerPower(const void *v1, const int v2, void *result);
void integerInput(void *result);
void integerPrint(const void *v);
void integerMakeNeutralForAddition(void *destination);
void integerMakeNeutralForMultiplication(void *destination);

TypeInfo createIntegerTypeInfo();
TypeInfo *getIntegerTypeInfo();
