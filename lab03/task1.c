#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main(void) {
    int arr[SIZE];
    srand(time(NULL));

    
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 101 - 50; // random number between -50 and 50
        printf("%d ", arr[i]);
    }
    printf("\n\n");  

    int count = 0;

    
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < 0) {
            count++;
        }
        if (arr[i] % 2 == 0) {
            arr[i] = 0;
        }
    }

    
    printf("Count of negative elements: %d\n", count);
    printf("Modified array: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}