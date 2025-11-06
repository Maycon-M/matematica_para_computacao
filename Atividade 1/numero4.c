#include <stdio.h>
#include <stdlib.h>

#define N 6

void read_array(int V[N]);
int verify_condition(int V1[N], int V2[N], int x, int y);

int main(void) {
    int V1[N];
    int V2[N];
    int x, y, result;

    printf("Digite os elementos do primeiro vetor:\n");
    read_array(V1);
    printf("\nDigite os elementos do segundo vetor:\n");
    read_array(V2);

    do {
        printf("\nDigite o valor de x (x != 0): ");
        scanf("%d", &x);
    } while (x == 0);

    do {
        printf("Digite o valor de y (y != 0): ");
        scanf("%d", &y);
    } while (y == 0);

    result = verify_condition(V1, V2, x, y);

    if (result) {
        printf("\nOs vetores satisfazem a condicao.\n");
    } else {
        printf("\nOs vetores nao satisfazem a condicao.\n");
    }

    return 0;
}

void read_array(int V[N]) {
    printf("Digite %d numeros inteiros:\n", N);
    for (int i = 0; i < N; i++) {
        printf("V[%d]: ", i + 1);
        scanf("%d", &V[i]);
    }
}

int verify_condition(int V1[N], int V2[N], int x, int y) {
    long long sum = 0;
    long long product = 1;

    for (int i = 1; i < N; i += 2) {
        sum += x * abs(V1[i]);
    }


    for (int i = 0; i < N; i += 2) {
        product *= (y * V2[i]);
    }


    if (sum <= product) {
        return 1;
    } else {
        return 0;
    }
}
