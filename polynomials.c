#include "./types/integer.h"
#include "./tests/integer_tests.h"
#include "./types/real.h"
#include "./types/complex.h"

// polynomial_tests.h включает в себя как все модули для тестирования, так и модули типов данных, перечисленные сверху
#include "tests/polynomial_tests.h"

void creationOfPolynomial(Polynomial *destination)
{
    int size;
    char type;
    printf("Input the degree of the polynomial (n) : ");
    scanf("%d", &size);
    printf("Input the polynomial type\n ('i' for integer, 'r' for real, 'c' for complex'): \n");
    fgetchar();
    type = fgetchar();
    TypeInfo *type_info;
    switch (type - '0')
    {
    case 'i' - '0':
        printf("The type is Integer\n");
        type_info = getIntegerTypeInfo();
        break;
    case 'r' - '0':
        printf("The type is Real\n");
        type_info = getRealTypeInfo();
        break;
    case 'c' - '0':
        printf("The type is Complex\n");
        printf("Input the real part first, that the imaginary.\n");
        type_info = getComplexTypeInfo();
        break;
    default:
        printf("Unsupported value type. \n");
        return;
    }
    createPolynomial(type_info, size, destination);
    printf("Enter the polynomial coefficients.\n");
    fgetchar();
    void *coefficient = malloc(destination->type_info->element_size);
    for (int i = 0; i < size; i++)
    {

        printf("Coefficient %d: ", i + 1);
        getInput(destination->type_info)(coefficient);
        setValue(destination, i, coefficient);
    }
    free(coefficient);

    printf("The polynomial is: \n");
    printPolynomial(destination);
    printf("\n\n");
    return;
}

void additionOfPolynomials()
{
    printf("Creating the first polynomial.\n");
    Polynomial *p1 = malloc(sizeof(Polynomial));
    creationOfPolynomial(p1);
    printf("p1 is.\n");
    printPolynomial(p1);
    printf("Creating the second polynomial.\n");
    Polynomial *p2 = malloc(sizeof(Polynomial));
    creationOfPolynomial(p2);
    Polynomial *added_polynomial = malloc(sizeof(Polynomial));
    addPolynomials(p1, p2, added_polynomial);
    printf("The polynomial after addition is:\n");
    printPolynomial(added_polynomial);

    deletePolynomial(p1);
    deletePolynomial(p2);
    deletePolynomial(added_polynomial);
}

void multiplicationOfPolynomials()
{
    printf("Creating the first polynomial.\n");
    Polynomial *p1 = malloc(sizeof(Polynomial));
    creationOfPolynomial(p1);
    printf("Creating the second polynomial.\n");
    Polynomial *p2 = malloc(sizeof(Polynomial));
    creationOfPolynomial(p2);
    Polynomial *multiplied_polynomial = malloc(sizeof(Polynomial));
    multiplyPolynomials(p1, p2, multiplied_polynomial);
    printf("The polynomial after multiplication is:\n");
    printPolynomial(multiplied_polynomial);
    deletePolynomial(p1);
    deletePolynomial(p2);
    deletePolynomial(multiplied_polynomial);
}

void compositionOfPolynomials()
{
    printf("Creating the first polynomial.\n");
    Polynomial *p1 = malloc(sizeof(Polynomial));
    creationOfPolynomial(p1);
    printPolynomial(p1);
    printf("Creating the second polynomial.\n");
    Polynomial *p2 = malloc(sizeof(Polynomial));
    creationOfPolynomial(p2);
    printf("The result is:\n");
    void *res = malloc(p1->type_info->element_size);
    composePolynomials(p1, p2, res);
    getPrint(p1->type_info)(res);
    deletePolynomial(p1);
    deletePolynomial(p2);
}

void multiplicationOfPolynomialByScalar()
{
    printf("Creating the polynomial.\n");
    Polynomial *p1 = malloc(sizeof(Polynomial));
    creationOfPolynomial(p1);

    printf("Enter the scalar. It has to be of the same type as the polynome.\n");
    void *scalar = malloc(p1->type_info->element_size);
    getInput(p1->type_info)(scalar);
    printf("The entered scalar is: \n");
    getPrint(p1->type_info)(scalar);
    printf("\n");

    Polynomial *multiplied_polynomial = malloc(sizeof(Polynomial));
    multiplyPolynomialByScalar(p1, scalar, multiplied_polynomial);
    printf("The polynomial after multiplication is:\n");
    printPolynomial(multiplied_polynomial);
    deletePolynomial(p1);

    free(multiplied_polynomial);
}

void calculationOfPolynomial()
{
    printf("Creating the polynomial.\n");
    Polynomial *p1 = malloc(sizeof(Polynomial));
    creationOfPolynomial(p1);
    printf("Enter the value of x. It has to be of the same type as the polynome.");
    void *value = malloc(p1->type_info->element_size);
    getInput(p1->type_info)(value);
    void *res = malloc(p1->type_info->element_size);
    calculatePolynomial(p1, value, res);
    printf("Result is: ");
    getPrint(p1->type_info)(res);
    deletePolynomial(p1);
    free(value);
    free(res);
}

void test_Polynomial()
{
    test_composePolynomials();
    test_addPolynomials();
    test_multiplyPolynomials();
    test_calculatePolynomial();
    printf("Polynomial tests passed. \n\n");
}

int main()
{
    test_Polynomial();
    testInteger();
    testComplex();
    testReal();
    printf("Choose an option: \n1) Add up two polynomials \n2) Multiply two polynomials \n3) Multiply a polynomial by scalar \n4) Calculate a polynomial with a given value of x\n5) Compose two polynomials\n");
    switch (fgetchar() - '0')
    {
    case '1' - '0':
        additionOfPolynomials();
        break;
    case '2' - '0':
        multiplicationOfPolynomials();
        break;
    case '3' - '0':
        multiplicationOfPolynomialByScalar();
        break;
    case '4' - '0':
        calculationOfPolynomial();
        break;
    case '5' - '0':
        compositionOfPolynomials();
        break;
    default:
        printf("UNKNOWN CODE OF OPERATION");
        break;
    }
}
