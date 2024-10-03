
#include <iostream>
using namespace std;

char board[3][3]; // Tabuleiro 3x3
char currentPlayer;

void initializeBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void printBoard() {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; i++) {
        cout << i << ' ';
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << '|';
        }
        cout << endl;
        if (i < 2) cout << "  -----\n";
    }
}

bool isWinner(char player) {
    // Verifica linhas, colunas e diagonais
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    initializeBoard();
    currentPlayer = 'X';
    int row, col;

    while (true) {
        printBoard();
        cout << "Jogador " << currentPlayer << ", escolha a linha e a coluna (0-2): ";
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Jogada inválida, tente novamente." << endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if (isWinner(currentPlayer)) {
            printBoard();
            cout << "Parabéns! Jogador " << currentPlayer << " venceu!" << endl;
            break;
        }

        if (isDraw()) {
            printBoard();
            cout << "Empate!" << endl;
            break;
        }

        switchPlayer();
    }

    return 0;
}
