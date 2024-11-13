#include <stdio.h>

// Função para imprimir o estado atual do tabuleiro
void imprimirTabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int y = 0; y < 3; y++) {
            printf(" %c ", tabuleiro[i][y]);
            if (y < 2) printf("|"); // Adiciona linhas verticais entre colunas
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n"); // Adiciona linhas horizontais entre linhas
    }
    printf("\n");
}

// Função para verificar se há um vencedor
int verificarVitoria(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        // Verifica linhas
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return 1;
        // Verifica colunas
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return 1;
    }
    // Verifica diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return 1;
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return 1;
    
    return 0; // Retorna 0 se não há vencedor
}

// Função para verificar se o tabuleiro está cheio (empate)
int tabuleiroCheio(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int y = 0; y < 3; y++) {
            if (tabuleiro[i][y] == ' ') return 0; // Ainda há espaço vazio
        }
    }
    return 1; // Tabuleiro está cheio
}

// Função para limpar o tabuleiro no início do jogo
void limparTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int y = 0; y < 3; y++) {
            tabuleiro[i][y] = ' ';
        }
    }
}

// Função principal
int main() {
    char tabuleiro[3][3]; // Matriz para o tabuleiro do jogo
    int linha, coluna, jogador = 1; // Variáveis para linha, coluna e alternância de jogador
    char simbolo;

    limparTabuleiro(tabuleiro); // Inicializa o tabuleiro vazio

    while (1) {
        imprimirTabuleiro(tabuleiro); // Mostra o tabuleiro atualizado
        simbolo = (jogador == 1) ? 'X' : 'O'; // Define o símbolo do jogador atual
        
        // Solicita a jogada ao jogador atual
        printf("Jogador %d (%c), digite linha e coluna (0, 1 ou 2): ", jogador, simbolo);
        scanf("%d %d", &linha, &coluna);

        // Valida a jogada
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada inválida! Tente novamente.\n");
            continue; // Pede nova jogada se a entrada for inválida
        }

        // Insere o símbolo na posição escolhida
        tabuleiro[linha][coluna] = simbolo;

        // Verifica se houve vitória
        if (verificarVitoria(tabuleiro)) {
            imprimirTabuleiro(tabuleiro); // Mostra o tabuleiro final
            printf("Jogador %d venceu!\n", jogador);
            break; // Sai do loop e encerra o jogo
        }

        // Verifica se houve empate (tabuleiro cheio)
        if (tabuleiroCheio(tabuleiro)) {
            imprimirTabuleiro(tabuleiro); // Mostra o tabuleiro final
            printf("Empate! O tabuleiro está cheio e não há vencedor.\n");
            break; // Sai do loop e encerra o jogo
        }

        // Alterna para o próximo jogador
        jogador = (jogador == 1) ? 2 : 1;
    }

    return 0;
}

