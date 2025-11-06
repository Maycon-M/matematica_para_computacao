#include <stdio.h>

#define N 30

void read_array(int V[N]);
int max_sum_k_consecutive(int V[N], int k);

int main(void) {
    int V[N];
    int k, result;

    read_array(V);

    do {
        printf("\nDigite o valor de k (1 <= k <= 4): ");
        scanf("%d", &k);
    } while (k < 1 || k > 4);

    result = max_sum_k_consecutive(V, k);

    printf("\nA soma maxima de %d elementos consecutivos e: %d\n", k, result);

    return 0;
}

void read_array(int V[N]) {
    printf("Digite 30 numeros inteiros:\n");
    for (int i = 0; i < N; i++) {
        printf("V[%d]: ", i + 1);
        scanf("%d", &V[i]);
    }
}

int max_sum_k_consecutive(int V[N], int k) {
    int max_sum = 0;

    for (int i = 0; i < k; i++) {
        max_sum += V[i];
    }

    int current_sum = max_sum;

    for (int i = 1; i <= N - k; i++) {
        current_sum = current_sum - V[i - 1] + V[i + k - 1];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;
}