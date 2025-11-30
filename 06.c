#include <stdio.h>
#include <stdlib.h>

int main(){
int n;
    printf("Digite quantos bits cada numero tem: ");
    scanf("%d", &n);

    int A[n], B[n], C[n], R[n];

    printf("Digite o primeiro numero binario: ");
    for (int i = 0; i < n; i++) scanf("%d", &A[i]);

    printf("Digite o segundo numero binario: ");
    for (int i = 0; i < n; i++) scanf("%d", &B[i]);

    int a = 0;
    for (int i = 0; i < n; i++)
        a = a * 2 + A[i];

    int b = 0;
    for (int i = 0; i < n; i++)
        b = b * 2 + B[i];

    if (b == 0) {
        printf("Erro: divisao por zero!\n");
        return 1;
    }

    int quociente = a / b;
    int resto = a % b;

    for (int i = n - 1; i >= 0; i--) {
        C[i] = quociente % 2;
        quociente /= 2;
    }


    for (int i = n - 1; i >= 0; i--) {
        R[i] = resto % 2;
        resto /= 2;
    }

    printf("Quociente: ");
    for (int i = 0; i < n; i++)
        printf("%d", C[i]);

    printf("\nResto:     ");
    for (int i = 0; i < n; i++)
        printf("%d", R[i]);

    printf("\n");
    return 0;
}