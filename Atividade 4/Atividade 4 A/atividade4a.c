#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5

void read_matrix(int V[N][N]); // Funcao usada apenas para testar com entradas manuais
void generateMatrix(int matrix[N][N]);
void printMatrix(int matrix[N][N]);
void multiplyMatrices(int matrixA[N][N], int matrixB[N][N], int result[N][N]);
int isIdentityMatrix(int matrix[N][N]);

int main(void) {
    int matrixA[N][N];
    int matrixB[N][N];
    int result[N][N];

    srand(time(NULL));

    generateMatrix(matrixA);
    // read_matrix(matrixA);

    printf("Matrix A:\n");
    printMatrix(matrixA);

    generateMatrix(matrixB);
    // read_matrix(matrixB);

    printf("\nMatrix B:\n");
    printMatrix(matrixB);

    multiplyMatrices(matrixA, matrixB, result);

    printf("\nA x B=\n");
    printMatrix(result);

    if (isIdentityMatrix(result)) {
        printf("B é inversa de A\n");
    } else {
        printf("B nao e inversa de A\n");
    }

    return 0;
}

void generateMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 30 + 1;
        }
    }
}

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int matrixA[N][N], int matrixB[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int isIdentityMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                if (matrix[i][j] != 1) {
                    return 0;
                }
            } else {
                if (matrix[i][j] != 0) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

void read_matrix(int V[N][N]) {
    printf("Digite %d numeros inteiros:\n", N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("V[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &V[i][j]);
        }
    }
}
