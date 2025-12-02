#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 3
#define COLS 3

double columnNorm(int matrix[ROWS][COLS]);
double rowNorm(int matrix[ROWS][COLS]);
double euclideanNorm(int matrix[ROWS][COLS]);

int main(void) {
    int A[ROWS][COLS] = {
        { 3,  7,  5},
        { 1, -4,  2},
        { 8,  3, -2}
    };

    double columnNormValue = columnNorm(A);
    double rowNormValue = rowNorm(A);
    double euclideanNormValue = euclideanNorm(A);

    printf("Matriz A:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }
    printf("\n\nNORMAS DA MATRIZ A:\n");

    printf("Coluna     : %.2f\n", columnNormValue);
    printf("Linha      : %.2f\n", rowNormValue);
    printf("Euclidiana : %.4f\n", euclideanNormValue);

    return 0;
}

double columnNorm(int matrix[ROWS][COLS]) {
    double maxColumnSum = 0.0;

    for (int j = 0; j < COLS; j++) {
        double columnSum = 0.0;

        for (int i = 0; i < ROWS; i++) {
            columnSum += abs(matrix[i][j]);
        }

        if (j == 0 || columnSum > maxColumnSum) {
            maxColumnSum = columnSum;
        }
    }

    return maxColumnSum;
}

double rowNorm(int matrix[ROWS][COLS]) {
    double maxRowSum = 0.0;

    for (int i = 0; i < ROWS; i++) {
        double rowSum = 0.0;

        for (int j = 0; j < COLS; j++) {
            rowSum += abs(matrix[i][j]);
        }

        if (i == 0 || rowSum > maxRowSum) {
            maxRowSum = rowSum;
        }
    }

    return maxRowSum;
}

double euclideanNorm(int matrix[ROWS][COLS]) {
    double sumOfSquares = 0.0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sumOfSquares += matrix[i][j] * matrix[i][j];
        }
    }

    return sqrt(sumOfSquares);
}