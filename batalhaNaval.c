#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Inicializa o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Cria matriz cone (5x5) dinamicamente
void criarMatrizCone(int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= 2 - i && j <= 2 + i && i <= 2) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }
}

// Cria matriz cruz (5x5)
void criarMatrizCruz(int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == 2 || j == 2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }
}

// Cria matriz octaedro (5x5)
void criarMatrizOctaedro(int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }
}

// Sobrepõe a habilidade no tabuleiro (com checagem de limites)
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linhaCentro, int colunaCentro) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int li = linhaCentro - 2 + i;
            int co = colunaCentro - 2 + j;

            if (li >= 0 && li < TAMANHO_TABULEIRO && co >= 0 && co < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1 && tabuleiro[li][co] == AGUA) {
                    tabuleiro[li][co] = HABILIDADE;
                }
            }
        }
    }
}

// Exibe o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA) {
                printf("~ ");
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("N ");
            } else if (tabuleiro[i][j] == HABILIDADE) {
                printf("* ");
            }
        }
        printf("\n");
    }
}

// Posiciona navio simples horizontal
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (coluna + i < TAMANHO_TABULEIRO) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    }
}

// Posiciona navio simples vertical
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        if (linha + i < TAMANHO_TABULEIRO) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    inicializarTabuleiro(tabuleiro);

    // Posiciona alguns navios
    posicionarNavioHorizontal(tabuleiro, 2, 3);
    posicionarNavioVertical(tabuleiro, 5, 1);

    // Cria matrizes de habilidade
    criarMatrizCone(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);

    // Define pontos de origem e aplica habilidades
    aplicarHabilidade(tabuleiro, cone, 1, 1);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);

    // Exibe o tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}
