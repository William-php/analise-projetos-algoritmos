#include <stdio.h>

int partition(int *array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    int temp;
    for (int j = low; j <= high - 1; j++) {
        if (array[j] < pivot) {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

void quickSort(int *array, int low, int high) {
    if (low < high) {
        int p = partition(array, low, high);
        quickSort(array, low, p - 1);
        quickSort(array, p + 1, high);
    }
}

void print(int *array, int length) {
    for (int i = 0; i < length; i++) printf("%d\n", array[i]);
}

void main() {
    int array[] = {10, 7, 8, 9, 1, 5};
    int length = sizeof(array) / sizeof(array[0]);
    quickSort(array, 0, length - 1);
    print(array, length);
}