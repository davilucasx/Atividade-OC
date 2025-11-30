#include <stdio.h>
#include <stdlib.h>

int somarHexBinario(int *A, int *B, int *C, int bits) {
    int carry = 0;

    for (int i = bits - 1; i >= 0; i--) {
        int soma = A[i] + B[i] + carry;

        C[i] = soma & 1;   
        carry = (soma >> 1); 
    }

    return carry != 0 ? -1 : 0;
}

char bin4_para_hex(int *v) {
    int valor = v[0]*8 + v[1]*4 + v[2]*2 + v[3]*1;

    if (valor < 10) return '0' + valor;
    return 'A' + (valor - 10);
}

void imprimir_hex(int *bin, int bits) {
    printf("0x");
    for (int i = 0; i < bits; i += 4) {
        printf("%c", bin4_para_hex(&bin[i]));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Digite o valor de bits do numero hexadecimal: ");
    scanf("%d", &n);

    int bits = 4 * n;

    int *A = malloc(bits * sizeof(int));
    int *B = malloc(bits * sizeof(int));
    int *C = malloc(bits * sizeof(int));

    printf("Digite o primeiro numero (em binario, %d bits):\n", bits);
    for (int i = 0; i < bits; i++) scanf("%d", &A[i]);

    printf("Digite o segundo numero (em binario, %d bits):\n", bits);
    for (int i = 0; i < bits; i++) scanf("%d", &B[i]);

    if (somarHexBinario(A, B, C, bits) == -1) {
        printf("Erro: overflow! Soma nao cabe em %d bits.\n", bits);
    } else {
        printf("Resultado em hexadecimal: ");
        imprimir_hex(C, bits);
    }

    free(A);
    free(B);
    free(C);

    return 0;
}
