#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Digite quantos bits cada numero tem: ");
    scanf("%d", &n);

    int A[n], B[n], C[n+1];
    int borrow = 0;

    printf("O numero deve ser digitado bit por bit, ex(1 0 1 1)\n");

    printf("Digite o primeiro numero binario: ");
    for(int i=0; i<n; i++){
        scanf("%d", &A[i]);
    }

    printf("Digite o segundo numero binario: ");
    for(int i=0; i<n; i++){
        scanf("%d", &B[i]);
    }

    for(int i=0; i<n; i++){
        if(A[i] < B[i]){
            printf("Subtracao nao e possivel (A < B).\n");
            return 1;
        }
        if(A[i] > B[i]) break;
    }

    for(int i = n - 1; i >= 0; i--){
        int bit = A[i] - B[i] - borrow;

        if(bit < 0){
            bit += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }

        C[i + 1] = bit;
    }

    C[0] = 0;

    printf("Resultado da subtracao em binario: ");
    for(int i=0; i<n+1; i++){
        printf("%d", C[i]);
    }
    printf("\n");

    return 0;
}
