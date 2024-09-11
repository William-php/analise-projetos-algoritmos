#include <stdio.h>
#include <stdlib.h>
float deltaFunction(float a, float b, float c) {
    float delta = (b * b) - (4 * a * c);
    return delta;
}

void function(float delta, float a, float b, float c) {
    float result;
    if (delta == 0) {
        result = (b * -1) / (2 * a);
        printf("Result with delta = 0: %.2f\n", result);
        return;
    }

    float x1, x2;

    x1 = ((b * -1) + delta) / (2 * a);
    x2 = ((b * -1) - delta) / (2 * a);
    printf("x1: %.2f\n", x1);
    printf("x2: %.2f\n", x2);
}

void main() {
    float a, b, c, delta;
    printf("Enter a value for a: ");
    scanf("%f", &a);

    printf("Enter a value for b: ");
    scanf("%f", &b);

    printf("Enter a value for c: ");
    scanf("%f", &c);

    delta = deltaFunction(a, b, c);
    if (delta < 0) {
        printf("function is not defined\n");
        exit(1);
    }

    function(delta, a, b, c);
    return;
}