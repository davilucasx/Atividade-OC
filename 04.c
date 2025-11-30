#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Digite quantos bits cada numero tem: ");
    scanf("%d", &n);

    int A[n], B[n], C[n];
    printf("O numero deve ser digitado bit por bit, ex(1 0 1 1)\n");

    printf("Digite o primeiro numero binario: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Digite o segundo numero binario: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
    }

    int carry = 1;
    int B_inv[n];

    for (int i = 0; i < n; i++) {
        B_inv[i] = 1 - B[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        int soma = A[i] + B_inv[i] + carry;
        C[i] = soma % 2;
        carry = soma / 2;
    }

    int sinalA = A[0];
    int sinalB = B[0];
    int sinalC = C[0];

    if (sinalA != sinalB && sinalC != sinalA) {
        printf("Erro: overflow! A subtracao nao e possivel em complemento de 2.\n");
        return 1;
    }

    printf("Resultado da subtracao em binario (com sinal): ");
    for (int i = 0; i < n; i++) {
        printf("%d", C[i]);
    }
    printf("\n");

    return 0;
}