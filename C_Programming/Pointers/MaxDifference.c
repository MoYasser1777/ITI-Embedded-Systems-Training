#include <stdio.h>
#include <stdlib.h>

void max_difference(int arr[]) {
	
    int max = 0;
    int *ptr1, *ptr2;

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
			
            int diff = abs(arr[i] - arr[j]);
			
            if (diff > max) {
                max = diff;
                ptr1 = arr + i;
                ptr2 = arr + j;
            }
        }
    }
    printf("The two elements with max difference: %d and %d\n", *ptr1, *ptr2);
}

int main() {
   int arr[10];

    printf("Enter 10 numbers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", arr + i);
    }

    max_difference(arr);
}
