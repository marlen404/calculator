#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HISTORY_SIZE 5
float history[HISTORY_SIZE] = {0};
int history_index = 0;


void save_to_history(float result) {
    history[history_index % HISTORY_SIZE] = result;
    history_index++;
}

void print_history() {
    printf("Last %d results:\n", HISTORY_SIZE);
    for(int i = 0; i<HISTORY_SIZE; i++) {
        printf("%d: %f\n", i+1, history[i]);
    }
}

void add(float* a, float* b) {
    float c = *a + *b;
    printf("%f\n", c);
    save_to_history(c);
}

void subtract(float *a, float *b) {
    float c = *a - *b;
    printf("%f\n", c);
    save_to_history(c);
}

void multiply(float *a, float *b) {
    float c = *a * *b;
    printf("%f\n", c);
    save_to_history(c);
}

void divide(float *a, float *b) {
    if (*b == 0) {
        printf("Dividing by 0? Don't think so :(\n");
    } else {
        float c = *a / *b;
        printf("%f\n", c);
        save_to_history(c);
    }
}

void modulo(float *a, float *b) {
    if (*b == 0) {
        printf("Modulo with 0? Nah\n");
    } else {
        float c = fmod(*a, *b);
        printf("%f\n", c);
        save_to_history(c);
    }
}

void power(float *a, float *b) {
    float c = fmod(*a, *b);
    printf("Result: %f\n", c);
    save_to_history(c);
}

int main() {

    int more = 1;
    do {
        
        char operation;
        printf("Calculator. Select operation: + - * / %% ^ h (history)\n");
        scanf(" %c", &operation);

        if (operation == 'h') {
            print_history();
        } else {
            float a, b;
            printf("Please type in first Number:\n");
            scanf("%f", &a);

            printf("Type in second Number:\n");
            scanf("%f", &b);

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
                case '^':
                    power(&a, &b);
                    break;
                default:
                    printf("Choice not accepted :(\n");
            }
        }

        printf("Calculate something else? Type 1 for Yes, 0 for No\n");
        scanf("%d", &more);
    } while(more == 1);

    printf("Thanks for using the calculator. Bye!\n");
    return EXIT_SUCCESS;
}
