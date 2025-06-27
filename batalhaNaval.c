#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define OCUPADO 3
#define AGUA 0

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Verifica se há espaço e sem sobreposição para navio horizontal
int podeColocarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != AGUA) return 0;
    }
    return 1;
}

// Verifica se há espaço e sem sobreposição para navio vertical
int podeColocarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != AGUA) return 0;
    }
    return 1;
}

// Verifica se há espaço e sem sobreposição para navio diagonal ↘
int podeColocarDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != AGUA) return 0;
    }
    return 1;
}

// Verifica se há espaço e sem sobreposição para navio diagonal ↙
int podeColocarDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || coluna - TAMANHO_NAVIO + 1 < 0) return 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] != AGUA) return 0;
    }
    return 1;
}

// Coloca navio horizontal
void colocarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = OCUPADO;
    }
}

// Coloca navio vertical
void colocarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = OCUPADO;
    }
}

// Coloca navio diagonal ↘
void colocarDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = OCUPADO;
    }
}

// Coloca navio diagonal ↙
void colocarDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = OCUPADO;
    }
}

// Exibe o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais definidas manualmente (podem ser ajustadas)
    int lh = 1, ch = 1; // Horizontal
    int lv = 0, cv = 7; // Vertical
    int ld1 = 3, cd1 = 3; // Diagonal ↘
    int ld2 = 4, cd2 = 6; // Diagonal ↙

    // Posicionamento com validação
    if (podeColocarHorizontal(tabuleiro, lh, ch))
        colocarHorizontal(tabuleiro, lh, ch);
    else
        printf("Erro: navio horizontal fora do tabuleiro ou sobreposto.\n");

    if (podeColocarVertical(tabuleiro, lv, cv))
        colocarVertical(tabuleiro, lv, cv);
    else
        printf("Erro: navio vertical fora do tabuleiro ou sobreposto.\n");

    if (podeColocarDiagonalPrincipal(tabuleiro, ld1, cd1))
        colocarDiagonalPrincipal(tabuleiro, ld1, cd1);
    else
        printf("Erro: navio diagonal ↘ fora do tabuleiro ou sobreposto.\n");

    if (podeColocarDiagonalSecundaria(tabuleiro, ld2, cd2))
        colocarDiagonalSecundaria(tabuleiro, ld2, cd2);
    else
        printf("Erro: navio diagonal ↙ fora do tabuleiro ou sobreposto.\n");

    // Exibir tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
