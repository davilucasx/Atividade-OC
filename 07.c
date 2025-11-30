#include <stdio.h>
#include <stdlib.h>

int main(){
int n;
    printf("Digite quantos digitos BCD o numero possui: ");
    scanf("%d", &n);

    int A[4*n], B[4*n], C[4*n + 4];

    printf("Digite o primeiro numero em BCD (bit a bit): ");
    for(int i = 0; i < 4*n; i++) scanf("%d", &A[i]);

    printf("Digite o segundo numero em BCD (bit a bit): ");
    for(int i = 0; i < 4*n; i++) scanf("%d", &B[i]);

    int carry = 0;

    for (int d = n - 1; d >= 0; d--) {

        int a = A[4*d]   * 8 + A[4*d+1] * 4 + A[4*d+2] * 2 + A[4*d+3];
        int b = B[4*d]   * 8 + B[4*d+1] * 4 + B[4*d+2] * 2 + B[4*d+3];

        int soma = a + b + carry;

        if (soma > 9) {
            soma -= 10;
            carry = 1;
        } else {
            carry = 0;
        }

        C[4*d]   = (soma >> 3) & 1;
        C[4*d+1] = (soma >> 2) & 1;
        C[4*d+2] = (soma >> 1) & 1;
        C[4*d+3] =  soma       & 1;
    }

    int extra = carry;

    C[0] = 0;
    C[1] = 0;
    C[2] = 0;
    C[3] = extra;

    for (int i = 4*n + 3; i >= 4; i--)
        C[i] = C[i - 4];


    printf("Resultado da soma em BCD: ");
    for(int i = 0; i < 4*n + 4; i++)
        printf("%d", C[i]);

    printf("\n");

    return 0;
}