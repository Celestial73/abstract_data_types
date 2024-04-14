#ifndef MAIN_H
#define MAIN_H

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
    int element_size;
    void *coefficients;

    TypeInfo *(*getTypeInfo)();

} Polynomial;

void setValue(Polynomial *p, int i, void *value);
void *getValue(Polynomial *p, int i);

void *composePolynomials(Polynomial *p1, Polynomial *p2);
void copyPolynomials(Polynomial *p1, Polynomial *p2);
void printPolynomial(Polynomial *p);
Polynomial *addPolynomials(Polynomial *p1, Polynomial *p2);
Polynomial *multiplyPolynomials(Polynomial *p1, Polynomial *p2);
Polynomial *multiplyPolynomialByScalar(Polynomial *p, void *);
void *calculatePolynomial(Polynomial *p1, void *argument);

int comparePolynomials(Polynomial *p1, Polynomial *p2);

void test_addPolynomial();

#endif