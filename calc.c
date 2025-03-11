#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void add(float* a, float* b) {
    float c = *a + *b;
    printf("%f\n", c);
}

void subtract(float *a, float *b) {
    float c = *a - *b;
    printf("%f\n", c);
}

void multiply(float *a, float *b) {
    float c = *a * *b;
    printf("%f\n", c);
}

void divide(float *a, float *b) {
    if (*b == 0) {
        printf("Dividing by 0? Don't think so :(\n");
    } else {
        float c = *a / *b;
        printf("%f\n", c);
    }
}

void modulo(float *a, float *b) {
    if (*b == 0) {
        printf("Modulo with 0? Nah\n");
    } else {
        float c = fmod(*a, *b);
        printf("%f\n", c);
    }
}

int main() {

    float a;
    float b;

    printf("Calculator. Please type in first Number\n");
    scanf("%f", &a);

    printf("Type in second Number:\n");
    scanf("%f", &b);

    char operation;
    printf("Select operation: + - * / %% \n");
    scanf(" %c", &operation);

    switch (operation) {
        case '+':
            add(&a, &b);
            break;
        case '-':
            subtract(&a, &b);
            break;
        case '*':
            multiply(&a, &b);
            break;
        case '/':
            divide(&a, &b);
            break;
        case '%':
            modulo(&a, &b);
            break;
        default:
            printf("Choice not accepted :(\n");
    }

    return EXIT_SUCCESS;
}
