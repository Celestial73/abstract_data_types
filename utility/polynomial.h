#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "typeInfo.h"

typedef struct
{
    int size;
    void *coefficients;

    const TypeInfo *type_info;
} Polynomial;

void setValue(Polynomial *p, const int i, const void *value);
void getValue(const Polynomial *p, const int i, void *destination);

void composePolynomials(const Polynomial *p1, const Polynomial *p2, void *result);
void copyPolynomialStucture(Polynomial *destination, const Polynomial *source);
void printPolynomial(const Polynomial *p);
void addPolynomials(const Polynomial *p1, const Polynomial *p2, Polynomial *result);
void multiplyPolynomials(const Polynomial *p1, const Polynomial *p2, Polynomial *result);
void multiplyPolynomialByScalar(const Polynomial *p, const void *scalar, Polynomial *result);
void calculatePolynomial(const Polynomial *p1, const void *argument, void *result);
void createPolynomial(const TypeInfo *type_info, const int size, Polynomial *result);
void deletePolynomial(Polynomial *polynomial);

int comparePolynomials(const Polynomial *p1, const Polynomial *p2);

void test_addPolynomial();
