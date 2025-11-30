#include <stdio.h>
#include <stdlib.h>

int main(){
int n;
    printf("Digite quantos digitos BCD o numero possui: ");
    scanf("%d", &n);

    int A[4*n], B[4*n], C[4*n];

    printf("Digite o primeiro numero em BCD: ");
    for (int i = 0; i < 4*n; i++) scanf("%d", &A[i]);

    printf("Digite o segundo numero em BCD: ");
    for (int i = 0; i < 4*n; i++) scanf("%d", &B[i]);

    int a = 0;
    for (int d = 0; d < n; d++) {
        int digit = A[4*d] * 8 + A[4*d+1] * 4 + A[4*d+2] * 2 + A[4*d+3];
        a = a * 10 + digit;
    }

    int b = 0;
    for (int d = 0; d < n; d++) {
        int digit = B[4*d] * 8 + B[4*d+1] * 4 + B[4*d+2] * 2 + B[4*d+3];
        b = b * 10 + digit;
    }

    if (b > a) {
        printf("Erro: subtracao impossivel (B > A).\n");
        return 1;
    }

    int resultado = a - b;

    for (int d = n - 1; d >= 0; d--) {
        int digit = resultado % 10;
        resultado /= 10;

        C[4*d]   = (digit >> 3) & 1;
        C[4*d+1] = (digit >> 2) & 1;
        C[4*d+2] = (digit >> 1) & 1;
        C[4*d+3] =  digit       & 1;
    }

    printf("Resultado da subtracao em BCD: ");
    for (int i = 0; i < 4*n; i++)
        printf("%d", C[i]);

    printf("\n");
    return 0;
}