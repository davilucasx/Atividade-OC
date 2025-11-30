#include <stdio.h>
#include <stdlib.h>

int main(){
int n;
    printf("Digite quantos bits cada numero tem: ");
    scanf("%d", &n);

    int A[n], B[n], C[2*n];

    printf("Digite o primeiro numero binario: ");
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);

    printf("Digite o segundo numero binario: ");
    for (int i = 0; i < n; i++) scanf("%d", &B[i]);

    int a = 0;
    if (A[0] == 1) { 
        for (int i = 0; i < n; i++)
            A[i] = 1 - A[i];
        int carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            int soma = A[i] + carry;
            A[i] = soma % 2;
            carry = soma / 2;
        }
        for (int i = 0; i < n; i++)
            a = a * 2 + A[i];
        a = -a;
    } else { // positivo
        for (int i = 0; i < n; i++)
            a = a * 2 + A[i];
    }

    int b = 0;
    if (B[0] == 1) {
        for (int i = 0; i < n; i++)
            B[i] = 1 - B[i];
        int carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            int soma = B[i] + carry;
            B[i] = soma % 2;
            carry = soma / 2;
        }
        for (int i = 0; i < n; i++)
            b = b * 2 + B[i];
        b = -b;
    } else {
        for (int i = 0; i < n; i++)
            b = b * 2 + B[i];
    }

    int produto = a * b;

    int tam = 2 * n;
    int temp = produto;

    if (temp < 0) { 
        temp = -temp;
        for (int i = tam - 1; i >= 0; i--) {
            C[i] = temp % 2;
            temp /= 2;
        }
        for (int i = 0; i < tam; i++)
            C[i] = 1 - C[i];

        int carry = 1;
        for (int i = tam - 1; i >= 0; i--) {
            int soma = C[i] + carry;
            C[i] = soma % 2;
            carry = soma / 2;
        }
    }
    else { 
        for (int i = tam - 1; i >= 0; i--) {
            C[i] = temp % 2;
            temp /= 2;
        }
    }

    printf("Resultado da multiplicacao (2n bits): ");
    for (int i = 0; i < tam; i++)
        printf("%d", C[i]);
    printf("\n");

    return 0;
}