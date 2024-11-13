#include <stdio.h>

// Yann Thallys e Alisson Batis



// Fun��o para imprimir o estado atual do tabuleiro
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

// Fun��o para verificar se h� um vencedor
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
    
    return 0; // Retorna 0 se n�o h� vencedor
}

// Fun��o para verificar se o tabuleiro est� cheio (empate)
int tabuleiroCheio(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int y = 0; y < 3; y++) {
            if (tabuleiro[i][y] == ' ') return 0; // Ainda h� espa�o vazio
        }
    }
    return 1; // Tabuleiro est� cheio
}

// Fun��o para limpar o tabuleiro no in�cio do jogo
void limparTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int y = 0; y < 3; y++) {
            tabuleiro[i][y] = ' ';
        }
    }
}

// Fun��o principal
int main() {
    char tabuleiro[3][3]; // Matriz para o tabuleiro do jogo
    int linha, coluna, jogador = 1; // Vari�veis para linha, coluna e altern�ncia de jogador
    char simbolo;

    limparTabuleiro(tabuleiro); // Inicializa o tabuleiro vazio

    while (1) {
        imprimirTabuleiro(tabuleiro); // Mostra o tabuleiro atualizado
        simbolo = (jogador == 1) ? 'X' : 'O'; // Define o s�mbolo do jogador atual
        
        // Solicita a jogada ao jogador atual
        printf("Jogador %d (%c), digite linha e coluna (0, 1 ou 2): ", jogador, simbolo);
        scanf("%d %d", &linha, &coluna);

        // Valida a jogada
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada inv�lida! Tente novamente.\n");
            continue; // Pede nova jogada se a entrada for inv�lida
        }

        // Insere o s�mbolo na posi��o escolhida
        tabuleiro[linha][coluna] = simbolo;

        // Verifica se houve vit�ria
        if (verificarVitoria(tabuleiro)) {
            imprimirTabuleiro(tabuleiro); // Mostra o tabuleiro final
            printf("Jogador %d venceu!\n", jogador);
            break; // Sai do loop e encerra o jogo
        }

        // Verifica se houve empate (tabuleiro cheio)
        if (tabuleiroCheio(tabuleiro)) {
            imprimirTabuleiro(tabuleiro); // Mostra o tabuleiro final
            printf("Empate! O tabuleiro est� cheio e n�o h� vencedor.\n");
            break; // Sai do loop e encerra o jogo
        }

        // Alterna para o pr�ximo jogador
        jogador = (jogador == 1) ? 2 : 1;
    }

    return 0;
}

