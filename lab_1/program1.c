#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void main(int argc, char *argv[]) {
    
    // Convert command line arguments to integers
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    swap(&num1, &num2);
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
}
