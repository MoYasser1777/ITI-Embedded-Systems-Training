///p1
/*
#include <stdio.h>

void main()
{
	int num1, num2, num3;

    printf("enter first number: ");
    scanf("%d", &num1);
	printf("enter second number: ");
    scanf("%d", &num2);
	printf("enter third number: ");
    scanf("%d", &num3);

    if (num1 >= num2) 
	{
        if (num1 >= num3) 
            printf("max number= %d\n", num1);
          else 
            printf("max number= %d\n", num3);
    } 
	else 
	{
        if (num2 >= num3)
            printf("max number= %d\n", num2);
          else 
            printf("max number= %d\n", num3);
    }
	
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///p2
/*
#include <stdio.h>

void main()
{
	int h;
    printf("enter the hieght: ");
    scanf("%d", &h);

    for (int i=1; i<=h; i++) 
	{
        for (int j=1; j <= h-i; j++)
            printf(" ");

        for (int k=1; k<=(2*i)-1; k++)
            printf("*");

        printf("\n");
    }
	
}*/

#include <stdio.h>

int max_num(int nums[]) 
{
    int max = nums[0];
	
    for (int i=1; i<4; i++) 
	{
        if (nums[i] > max)
            max = nums[i];
    }
    return max;
}

int min_num(int nums[]) 
{
    int min = nums[0];
	
    for (int i=1; i<4; i++) 
	{
        if (nums[i] < min)
            min = nums[i];
    }
    return min;
}

void main()
{
	int nums[4];

    printf("enter the four numbers: ");
    for (int i=0; i<4; i++) 
        scanf("%d", &nums[i]);

    printf("max number= %d\n", max_num(nums));
    printf("min number= %d\n", min_num(nums));
}