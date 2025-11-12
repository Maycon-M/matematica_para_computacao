#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINE_A 4
#define COLUMN_A 4
#define LINE_B 4
#define COLUMN_B 3

void printMatrix(int lines, int columns, int Matrix[lines][columns]);

void multiplyMatrices(int A[LINE_A][COLUMN_A], int B[LINE_B][COLUMN_B], int C[LINE_A][COLUMN_B]);


int main() {
    int A[LINE_A][COLUMN_A];
    int B[LINE_B][COLUMN_B];
    int C[LINE_A][COLUMN_B];

    srand(time(NULL));

    
    for (int i = 0; i < LINE_A; i++) {
        for (int j = 0; j < COLUMN_A; j++) {
            A[i][j] = rand() % 50 + 1;
        }
    }
    printf("Matriz A:\n");
    printMatrix(LINE_A, COLUMN_A, A);

    for (int i = 0; i < LINE_B; i++) {
        for (int j = 0; j < COLUMN_B; j++) {
            B[i][j] = rand() % 50 + 1;
        }
    }

    printf("\nMatriz B:\n");
    printMatrix(LINE_B, COLUMN_B, B);

    multiplyMatrices(A, B, C);
 
    printf("\nMatriz C = A x B:\n");
    printMatrix(LINE_A, COLUMN_B, C);

    return 0;
}


void printMatrix(int lines, int columns, int Matrix[lines][columns]) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%4d ", Matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int A[LINE_A][COLUMN_A], int B[LINE_B][COLUMN_B], int C[LINE_A][COLUMN_B]) {
    for (int i = 0; i < LINE_A; i++) {
        for (int j = 0; j < COLUMN_B; j++) {
            C[i][j] = 0;
            for (int k = 0; k < COLUMN_A; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}