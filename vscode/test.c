/*COMPLETE HELP MODEL FROM CHATGPT!!!*/


#include <stdio.h>
#include <math.h>

typedef struct {
    double real;
    double imag;
} Complex;

// Function to add two complex numbers
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// Function to subtract two complex numbers
Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

// Function to multiply two complex numbers
Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

// Function to divide two complex numbers
Complex divide(Complex a, Complex b) {
    Complex result;
    double denominator = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}

// Function to find the modulus of a complex number
double modulus(Complex a) {
    return sqrt(a.real * a.real + a.imag * a.imag);
}

// Function to raise a complex number to an integer power
Complex power(Complex a, int n) {
    Complex result = {1, 0}; // Initialize to 1 (multiplicative identity)
    Complex temp = a;
    for (int i = 0; i < n; i++) {
        result = multiply(result, temp);
    }
    return result;
}

// Function to display a complex number
void printComplex(Complex a) {
    if (a.imag >= 0)
        printf("%.2f + %.2fi\n", a.real, a.imag);
    else
        printf("%.2f - %.2fi\n", a.real, -a.imag);
}

int main() {
    Complex num1, num2, result;
    char operator;
    int exponent;

    // Input first complex number
    printf("Enter the first complex number (real and imaginary parts): ");
    scanf("%lf %lf", &num1.real, &num1.imag);

    // Input operation
    printf("Enter operator (+, -, *, /, %, ^): ");
    scanf(" %c", &operator);

    if (operator != '^' && operator != '%') {
        // Input second complex number for operations except modulus and power
        printf("Enter the second complex number (real and imaginary parts): ");
        scanf("%lf %lf", &num2.real, &num2.imag);
    }

    // Perform the operation
    switch (operator) {
        case '+':
            result = add(num1, num2);
            printf("Result: ");
            printComplex(result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("Result: ");
            printComplex(result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("Result: ");
            printComplex(result);
            break;
        case '/':
            if (num2.real == 0 && num2.imag == 0) {
                printf("Error: Division by zero.\n");
            } else {
                result = divide(num1, num2);
                printf("Result: ");
                printComplex(result);
            }
            break;
        case '%':
            printf("Modulus of the first complex number: %.2f\n", modulus(num1));
            break;
        case '^':
            printf("Enter the power to which you want to raise the complex number: ");
            scanf("%d", &exponent);
            result = power(num1, exponent);
            printf("Result: ");
            printComplex(result);
            break;
        default:
            printf("Invalid operator.\n");
            break;
    }

    return 0;
}