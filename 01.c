#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Digite quantos bits cada numero tem: ");
    scanf("%d", &n);

    int A[n], B[n], C[n+1];
    printf("O numero deve ser digitado bit por bit, ex(1 0 1 1 )\n");
    printf("Digite o primeiro numero binario: ");
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }
    printf("Digite o segundo numero binario: ");
    for(int i=0; i<n; i++){
        scanf("%d", &B[i]);
    }

    int carry = 0;

    for (int i = n - 1; i >= 0; i--) {
        int soma = A[i] + B[i] + carry;

        C[i + 1] = soma % 2;   
        carry = soma / 2;      
    }

    C[0] = carry;
    
    printf("Resultado da soma em binario: ");
    for (int i = 0; i < n + 1; i++) {
        printf("%d", C[i]);
    }
    printf("\n");

    return 0;
}