#include <stdio.h>
#include <stdlib.h>
void insert(int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("Enter a number: ");
        scanf("%d", &array[i]);
    }
}

void print(int *array, int length) {
    for (int i = 0; i < length; i++) printf("|%d|\t", array[i]);
    printf("\n");
}

int search(int *array, int length, int key) {
    for (int i = 0; i < length; i++) {
        if (array[i] == key) return i;
    }
    return -1;
}
void main() {
    int length, key, index;
    printf("Enter a number for length: ");
    scanf("%d", &length);
    int *array = (int*)malloc(sizeof(int) * length);
    
    insert(array, length);
    print(array, length);
    printf("Enter a number for key: ");
    scanf("%d", &key);

    index = search(array, length, key);
    if (index > -1) {
        printf("Key: %d did find, your index: %d\n", key, index);
        exit(1);
    }

    printf("Key did not found\n");
}