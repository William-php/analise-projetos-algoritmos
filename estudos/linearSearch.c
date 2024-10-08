#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *array, int n, int k) {
    int i = 0;
    while (i < n && array[i] != k) i++;
    if (i <= n) return i;
    return -1;
}

void main() {
    int array[5] = {1, 5, 45, 32, 6};
    int length = sizeof(array) / sizeof(array[0]);
    int key, position;

    printf("Enter with a number for key: ");
    scanf("%d", &key);
    position = linearSearch(array, length, key);
    printf("Position: %d\n", position);
}