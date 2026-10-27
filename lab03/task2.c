#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

int main(void) {
    int matrix[ROWS][COLS];
    int negative_count = 0;

    srand((unsigned int)time(NULL));

    // 1. Fill matrix with random values from -20 to 20
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = rand() % 41 - 20;
        }
    }

    // 2. Print initial matrix
    printf("Initial matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    // 3. Process matrix (Row-Major Order)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] < 0) {
                negative_count++;
            }
            if (matrix[i][j] % 2 == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // 4. Print results
    printf("\nNegative elements count: %d\n\n", negative_count);

    printf("Matrix after processing (even numbers replaced with 0):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}