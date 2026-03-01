
#include <stdio.h>

#define N 3

void decomposicao_lu(double A[N][N], double L[N][N], double U[N][N]) {
    int i, j, k;

    for (i = 0; i < N; i++) {

        for (j = i; j < N; j++) {
            double soma = 0.0;
            for (k = 0; k < i; k++) {
                soma += L[i][k] * U[k][j];
            }
            U[i][j] = A[i][j] - soma;
        }

        for (j = i; j < N; j++) {
            if (i == j) {
                L[i][i] = 1.0;
            } else {
                double soma = 0.0;
                for (k = 0; k < i; k++) {
                    soma += L[j][k] * U[k][i];
                }
                L[j][i] = (A[j][i] - soma) / U[i][i];
            }
        }
    }
}

void substituicao_direta(double L[N][N], double b[N], double y[N]) {
    int i, j;

    for (i = 0; i < N; i++) {
        double soma = 0.0;
        for (j = 0; j < i; j++) {
            soma += L[i][j] * y[j];
        }
        y[i] = b[i] - soma;
    }
}

void substituicao_retroativa(double U[N][N], double y[N], double x[N]) {
    int i, j;

    for (i = N - 1; i >= 0; i--) {
        double soma = 0.0;
        for (j = i + 1; j < N; j++) {
            soma += U[i][j] * x[j];
        }
        x[i] = (y[i] - soma) / U[i][i];
    }
}

void imprime_matriz(const char *nome, double M[N][N]) {
    int i, j;
    printf("\nMatriz %s:\n", nome);
    for (i = 0; i < N; i++) {
        printf("  [ ");
        for (j = 0; j < N; j++) {
            printf("%8.4f ", M[i][j]);
        }
        printf("]\n");
    }
}

void imprime_vetor(const char *nome, double v[N]) {
    int i;
    printf("\nVetor %s:\n", nome);
    for (i = 0; i < N; i++) {
        printf("  [ %8.4f ]\n", v[i]);
    }
}

int main(void) {

    double A[N][N] = {
        { 3.0,  2.0,  4.0 },
        { 1.0,  1.0,  2.0 },
        { 4.0,  3.0, -2.0 }
    };

    double b[N] = { 1.0, 2.0, 3.0 };

    double L[N][N] = { {0} };
    double U[N][N] = { {0} };

    double y[N] = {0};
    double x[N] = {0};

    printf("============================================\n");
    printf("  DECOMPOSICAO LU - Solucao de Ax = b\n");
    printf("============================================\n");

    decomposicao_lu(A, L, U);

    imprime_matriz("L", L);
    imprime_matriz("U", U);

    substituicao_direta(L, b, y);

    imprime_vetor("y  (solucao de Ly = b)", y);

    substituicao_retroativa(U, y, x);

    imprime_vetor("x  (solucao de Ux = y)", x);

    printf("\n============================================\n");
    printf("  SOLUCAO DO SISTEMA  Ax = b\n");
    printf("============================================\n");
    printf("  x1 = %.4f\n", x[0]);
    printf("  x2 = %.4f\n", x[1]);
    printf("  x3 = %.4f\n", x[2]);
    printf("============================================\n");

    return 0;
}
