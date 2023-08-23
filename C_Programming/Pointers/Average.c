#include <stdio.h>

void average(int* ptr, double* avg);

void main() {
    int arr[3] = {5, 6, 7};
    double avg;
	int*ptr=arr;

    average(arr, &avg);

    printf("Average = %f", avg);

}

void average(int* ptr, double* avg) {
    *avg = 0;
    for (int i = 0; i < 3; i++)
        *avg += ptr[i];

    *avg /= 3.0;
}
