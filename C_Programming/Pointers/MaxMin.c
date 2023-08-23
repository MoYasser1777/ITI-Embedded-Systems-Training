#include <stdio.h>

void solve(int arr[], int *max, int *min) {
    
    *max = *min = arr[0];

    for (int i = 1; i < 5; i++) {
		
        if (arr[i] > *max)
            *max = arr[i];
		
        else if (arr[i] < *min)
            *min = arr[i];
    }
}

void main() {
    int array[] = {1, 2, 3, 4, 5};

    int max, min;
    solve(array, &max, &min);

    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
}
