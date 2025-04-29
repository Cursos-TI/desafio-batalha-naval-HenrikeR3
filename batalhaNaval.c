#include <stdio.h>

// Define o tamanho do tabuleiro
#define TAMANHO 10

int main() {
    // Declara o tabuleiro e inicializa todas as posições com 0 (água)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Define o tamanho fixo dos navios
    int tamanho_navio = 3;

    // Define os navios como vetores (não necessário, mas seguimos o enunciado)
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Coordenadas iniciais dos navios (definido diretamente no código)
    int linha_horizontal = 2; // Linha inicial do navio horizontal
    int coluna_horizontal = 1; // Coluna inicial do navio horizontal

    int linha_vertical = 5; // Linha inicial do navio vertical
    int coluna_vertical = 7; // Coluna inicial do navio vertical

    // Validação - Verificar se o navio horizontal cabe no tabuleiro
    if (coluna_horizontal + tamanho_navio > TAMANHO) {
        printf("Erro: navio horizontal ultrapassa o limite do tabuleiro.\n");
        return 1;
    }

    // Validação - Verificar se o navio vertical cabe no tabuleiro
    if (linha_vertical + tamanho_navio > TAMANHO) {
        printf("Erro: navio vertical ultrapassa o limite do tabuleiro.\n");
        return 1;
    }

    // Validação - Verificar sobreposição para o navio horizontal
    for (int i = 0; i < tamanho_navio; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0) {
            printf("Erro: sobreposição detectada no posicionamento do navio horizontal.\n");
            return 1;
        }
    }

    // Posiciona o navio horizontal no tabuleiro
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
    }

    // Validação - Verificar sobreposição para o navio vertical
    for (int i = 0; i < tamanho_navio; i++) {
        if (tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
            printf("Erro: sobreposição detectada no posicionamento do navio vertical.\n");
            return 1;
        }
    }

    // Posiciona o navio vertical no tabuleiro
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
