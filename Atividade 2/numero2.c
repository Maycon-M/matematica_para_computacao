#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50

void fill_array(int V[N]);
void modify_array(int V[N]);
void print_array(int V[N]);

int main(void) {
    int V[N];

    srand(time(NULL));

    fill_array(V);

    printf("Vetor Original: \n");
    print_array(V);

    modify_array(V);

    printf("\nVetor Modificado: \n");
    print_array(V);

    return 0;
}

void fill_array(int V[N]) {
    for (int i = 0; i < N; i++) {
        V[i] = rand() % 100 + 1;
    }
}

void modify_array(int V[N]) {
    int total_sum = 0;
    
    for (int i = 0; i < N; i++) {
        total_sum += V[i];
    }
    
    for (int i = 0; i < N; i++) {
        V[i] = total_sum - V[i];
    }
}

void print_array(int V[N]) {
    for (int i = 0; i < N; i++) {
        printf("%4d  ", V[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
}
