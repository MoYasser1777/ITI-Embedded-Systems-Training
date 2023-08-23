#include <stdio.h>

int sum(int *num1, int *num2) {
    return (*num1) + (*num2);
}

void main() {
    int val1, val2;
    
    printf("Enter the first value: ");
    scanf("%d", &val1);
    
    printf("Enter the second value: ");
    scanf("%d", &val2);
    
    int res = sum(&val1, &val2);
    
    printf("The summation is: %d\n", res);
    
}
