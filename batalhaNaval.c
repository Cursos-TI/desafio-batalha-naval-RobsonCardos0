#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define OCUPADO 3
#define AGUA 0

int main() {
    // Declaração e inicialização do tabuleiro (vetor bidimensional)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa todas as posições com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas iniciais dos navios (definidas manualmente)
    int linhaHorizontal = 2;
    int colunaHorizontal = 3;

    int linhaVertical = 5;
    int colunaVertical = 6;

    // Posicionamento do navio horizontal
    printf("Posicionando navio horizontal nas coordenadas:\n");
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = OCUPADO;
        printf("(%d, %d)\n", linhaHorizontal, colunaHorizontal + i);
    }

    // Posicionamento do navio vertical
    printf("\nPosicionando navio vertical nas coordenadas:\n");
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaVertical + i][colunaVertical] = OCUPADO;
        printf("(%d, %d)\n", linhaVertical + i, colunaVertical);
    }

    return 0;
}
