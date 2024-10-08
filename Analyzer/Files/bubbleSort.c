#include <stdio.h>

void bubbleSort(int *array, int n) {
    for (int i = 0; i < n; i++) { // openLoop
        for (int j = 0; j < n; j++) { // openLoop
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        } // closeLoop
    } // closeLoop
}

void main() {
    int array[4] = {1, 3 , 2, 5};
    int length = sizeof(array) / sizeof(array[0]);

    bubbleSort(array, length);
}