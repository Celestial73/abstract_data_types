// Этот файл содержит только

// #include "./types/integer.h"
// #include "./types/real.h"
// #include "./types/complex.h"

// polynomial_tests.h включает в себя как все модули для тестирования, так и модули типов данных, перечисленные сверху
#include "tests/polynomial_tests.h"

Polynomial createPolynomial();

Polynomial createPolynomial()
{
    int n;
    char type;
    Polynomial polynomial;
    printf("Input the degree of the polynomial (n) : ");
    scanf("%d", &n);
    polynomial.size = n;
    printf("Input the polynomial type\n ('i' for integer, 'r' for real, 'c' for complex'): \n");
    fgetchar();
    type = fgetchar();
    switch (type - '0')
    {
    case 'i' - '0':
        printf("The type is Integer\n");
        polynomial = createIntegerPolynomial(n);
        break;
    case 'r' - '0':
        printf("The type is Real\n");
        polynomial = createRealPolynomial(n);
        break;
    case 'c' - '0':
        printf("The type is Complex\n");
        printf("Intput the real part first, that the imaginary.\n");
        polynomial = createComplexPolynomial(n);
        break;
    default:
        printf("Unsupported value type. \n");
        return createPolynomial();
    }

    printf("Enter the polynomial coefficients.\n");
    fgetchar();
    void *value;
    for (int i = 0; i < n; i++)
    {

        printf("Coefficient %d: ", i + 1);
        void *coefficient = getInput(polynomial.getTypeInfo())();
        // memcpy(value, coefficient, polynomial.element_size);
        setValue(&polynomial, i, coefficient);
        free(coefficient);
    }

    printf("The polynomial is: \n");
    printPolynomial(&polynomial);
    printf("\n\n");
    return polynomial;
}

void additionOfPolynomials()
{
    printf("Creating the first polynomial.\n");
    Polynomial p1 = createPolynomial();
    printf("Creating the second polynomial.\n");
    Polynomial p2 = createPolynomial();
    Polynomial *added_polynomial = addPolynomials(&p1, &p2);
    printf("The polynomial after addition is:\n");
    printPolynomial(added_polynomial);
}

void multiplicationOfPolynomials()
{
    printf("Creating the first polynomial.\n");
    Polynomial p1 = createPolynomial();
    printf("Creating the second polynomial.\n");
    Polynomial p2 = createPolynomial();
    Polynomial *multiplied_polynomial = multiplyPolynomials(&p1, &p2);
    printf("The polynomial after multiplication is:\n");
    printPolynomial(multiplied_polynomial);
    free(multiplied_polynomial);
}

void compositionOfPolynomials()
{
    printf("Creating the first polynomial.\n");
    Polynomial p1 = createPolynomial();
    printf("Creating the second polynomial.\n");
    Polynomial p2 = createPolynomial();
    printf("The result is:\n");
    getPrint(p1.getTypeInfo())(composePolynomials(&p1, &p2));
}

void multiplicationOfPolynomialByScalar()
{
    printf("Creating the polynomial.\n");
    Polynomial p1 = createPolynomial();
    printf("Enter the scalar. It has to be of the same type as the polynome.\n");
    void *scalar = getInput(p1.getTypeInfo());
    printf("The entered scalar is: \n");
    getPrint(p1.getTypeInfo())(scalar);
    printf("\n");
    Polynomial *multiplied_polynomial = multiplyPolynomialByScalar(&p1, scalar);
    printf("The polynomial after multiplication is:\n");
    printPolynomial(multiplied_polynomial);
    free(multiplied_polynomial);
}

void calculationOfPolynomial()
{
    printf("Creating the polynomial.\n");
    Polynomial p1 = createPolynomial();
    printf("Enter the value of x. It has to be of the same type as the polynome.");
    void *value = getInput(p1.getTypeInfo())();
    printf("The result is:\n");
    getPrint(p1.getTypeInfo())(calculatePolynomial(&p1, value));
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
