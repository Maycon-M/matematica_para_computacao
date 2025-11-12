#include <stdio.h>

#define N 5

void print_matrix(int A[N][N]);
int total_sum(int A[N][N]);
int total_sum_inverted(int A[N][N]);
int sum_without_diagonal(int A[N][N]);
int diagonal_sum(int A[N][N]);
int sum_above_diagonal(int A[N][N]);
int sum_below_diagonal(int A[N][N]);
int sum_of_symmetric_products(int A[N][N]);
int sum_with_x(int A[N][N], int x);

int main() {
    int A[N][N] = {
        {0, 2, 8, 1, 7},
        {1, 5, 8, 2, 2},
        {3, 4, 0, 8, 1},
        {9, 1, 2, 7, 2},
        {3, 0, 1, 0, 4},
    };

    int x;
    
    
    printf("---- Matriz A -----\n");
    print_matrix(A);
    printf("\n\n");
    
    printf ("Digite o valor de x: ");
    scanf ("%d", &x);

    printf("\n\n");
    printf("(Questão A) Soma total dos elementos da matriz: %d\n", total_sum(A));
  
    printf("(Questão B) Soma total dos elementos da matriz invertida: %d\n", total_sum_inverted(A));

    printf("(Questão C) Soma dos elementos fora da diagonal principal: %d\n", sum_without_diagonal(A));

    printf("(Questão D) Soma dos elementos da diagonal principal: %d\n", diagonal_sum(A));

    printf("(Questão E) Soma dos elementos acima da diagonal principal: %d\n", sum_above_diagonal(A));

    printf("(Questão F) Soma dos elementos abaixo da diagonal principal: %d\n", sum_below_diagonal(A));

    printf("(Questão G) Soma dos produtos dos elementos simétricos: %d\n", sum_of_symmetric_products(A));

    printf("(Questão H) Soma dos elementos da matriz multiplicados por %d: %d\n", x, sum_with_x(A, x));

    // Questão I - Vetor V com soma dos elementos de cada linha
    int V[N];
    for (int i = 0; i < N; i++) {
        V[i] = 0;
        for (int j = 0; j < N; j++) {
            V[i] += A[i][j];
        }
    }
    printf("(Questão I) Vetor V com soma dos elementos de cada linha:\n");
    for (int i = 0; i < N; i++) {
        printf("V[%d] = %d\n", i, V[i]);
    }

    // Questão J - Vetor P com o produto dos elementos de cada coluna
    int P[N];
    for (int j = 0; j < N; j++) {
        P[j] = 1;
        for (int i = 0; i < N; i++) {
            P[j] *= A[i][j];
        }
    }

    printf("(Questão J) Vetor P com o produto dos elementos de cada coluna:\n");
    for (int j = 0; j < N; j++) {
        printf("P[%d] = %d\n", j, P[j]);
    }

    return 0;
}

// Função para imprimir a matriz
void print_matrix(int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

// Questão A - Soma total dos elementos da matriz
int total_sum(int A[N][N]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += A[i][j];
        }
    }
    return sum;
}

// Questão B - Soma total dos elementos da matriz invertida
int total_sum_inverted(int A[N][N]) {
    int sum = 0;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            sum += A[i][j];
        }
    }
    return sum;
}

// Questão C - Soma dos elementos fora da diagonal principal
int sum_without_diagonal(int A[N][N]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                sum += A[i][j];
            }
        }
    }
    return sum;
}

// Questão D - Soma dos elementos da diagonal principal
int diagonal_sum(int A[N][N]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i][i];
    }
    return sum;
}

// Questão E - Soma dos elementos acima da diagonal principal
int sum_above_diagonal(int A[N][N]) {
    int sum = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            sum += A[i][j];
        }
    }
    return sum;
}

// Questão F - Soma dos elementos abaixo da diagonal principal
int sum_below_diagonal(int A[N][N]) {
    int sum = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            sum += A[i][j];
        }
    }
    return sum;
}

// Questão G - Soma dos produtos dos elementos simétricos
int sum_of_symmetric_products(int A[N][N]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += A[i][j] * A[j][i];
        }
    }
    return sum;
}

// Questão H - Soma dos elementos da matriz multiplicados por x
int sum_with_x(int A[N][N], int x) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += A[i][j] * x;
        }
    }
    return sum;
}
