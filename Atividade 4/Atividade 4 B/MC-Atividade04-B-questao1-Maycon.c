#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate(int A[10][10]);

int checkDiagonallyDominant(int A[10][10]);

void printMatrix(int A[10][10]);

int main() {
    int A[10][10];
    srand(time(NULL));

    generate(A);

    printf("Matriz A:\n");
    printMatrix(A);

    if (checkDiagonallyDominant(A))
        printf("\nA matriz A é diagonalmente dominante.\n");
    else
        printf("\nA matriz A NÃO é diagonalmente dominante.\n");

    return 0;
}

void generate(int A[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            A[i][j] = rand() % 10 + 1; 
        }
    }
}

int checkDiagonallyDominant(int A[10][10]) {
    for (int i = 0; i < 10; i++) {
        int soma = 0;

        for (int j = 0; j < 10; j++) {
            if (j != i)
                soma += abs(A[i][j]);  
        }

        if (abs(A[i][i]) < soma) {
            return 0;  
        }
    }

    return 1;  
}

void printMatrix(int A[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%3d ", A[i][j]);
        }
        printf("\n");
    }
}
