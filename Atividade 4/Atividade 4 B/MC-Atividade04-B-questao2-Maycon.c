#include <stdio.h>

void solveSystem(float inverseA[3][3], int b[3]);

int main() {

    float inverseA[3][3] = {
        { 1,    0,     0   },
        { -0.5, 0,   0.5 },
        { 0.5,  1,    -1.5 }
    };

    int b[3] = { 4, 9, 8 };

    solveSystem(inverseA, b);

    return 0;
}

void solveSystem(float inverseA[3][3], int b[3]) {
    float x[3];

    for (int i = 0; i < 3; i++) {
        x[i] = 0;

        for (int j = 0; j < 3; j++) {
            x[i] += inverseA[i][j] * b[j];
        }
    }

    printf("Solução do sistema (vetor x): X = {");
    for (int i = 0; i < 3; i++) {
        printf(" %.f ", x[i]);
    }
    printf("}\n");
}
