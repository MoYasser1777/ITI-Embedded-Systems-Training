#include <stdio.h>
#include <stdlib.h> 

void remove_duplicates(int arr[], int *ptr, int *newSize) {
    ptr[0] = arr[0];
    *newSize = 1;

    for (int i = 1; i < 10; i++) {
        int flag = 1;

        for (int j = 0; j < *newSize; j++) {
            if (arr[i] == ptr[j]) {
                flag = 0;
                break;
            }
        }

        if (flag) {
            ptr[*newSize] = arr[i];
            (*newSize)++;
        }
    }
}

void main() {
    int arr[10];
    int ptr[10];
    int new_size;

    printf("Enter 10 numbers:\n");

    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    remove_duplicates(arr, ptr, &new_size);

    printf("Array after removing duplicates:\n");

    for (int i = 0; i < new_size; i++) {
        printf("%d ", ptr[i]);
    }

}
