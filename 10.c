#include <stdio.h>
#include <stdlib.h>

int somarBinario(int *A, int *B, int *C, int bits) {
    int carry = 0;
    for (int i = bits - 1; i >= 0; i--) {
        int soma = A[i] + B[i] + carry;
        C[i] = soma & 1;
        carry = soma >> 1;
    }
    return carry; 
}

char bin4_para_hex(int *v) {
    int valor = v[0]*8 + v[1]*4 + v[2]*2 + v[3];
    if (valor < 10) return '0' + valor;
    return 'A' + (valor - 10);
}

void imprimir_hex(int *bin, int bits) {
    printf("0x");
    for (int i = 0; i < bits; i += 4)
        printf("%c", bin4_para_hex(&bin[i]));
    printf("\n");
}

int main() {
    int n;
    printf("Digite numero de bits hexadecimais: ");
    scanf("%d", &n);

    int bits = 4 * n;

    int *A = malloc(bits * sizeof(int));
    int *B = malloc(bits * sizeof(int));
    int *B_inv = malloc(bits * sizeof(int));
    int *C = malloc(bits * sizeof(int));

    printf("Digite A em binario (%d bits):\n", bits);
    for (int i = 0; i < bits; i++) scanf("%d", &A[i]);

    printf("Digite B em binario (%d bits):\n", bits);
    for (int i = 0; i < bits; i++) scanf("%d", &B[i]);

    for (int i = 0; i < bits; i++)
        B_inv[i] = 1 - B[i];

    int *B_comp2 = malloc(bits * sizeof(int));
    int *um = calloc(bits, sizeof(int));
    um[bits - 1] = 1; 

    somarBinario(B_inv, um, B_comp2, bits);

    int overflow = somarBinario(A, B_comp2, C, bits);

    if (overflow != 0) {
        printf("Erro: overflow! Subtracao nao cabe em %d bits.\n", bits);
    } else {
        printf("Resultado em hexadecimal:\n");
        imprimir_hex(C, bits);
    }

    free(A);
    free(B);
    free(B_inv);
    free(C);
    return 0;
}