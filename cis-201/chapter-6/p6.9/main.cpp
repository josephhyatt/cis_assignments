#include <cstdlib>
#include <iostream>

using namespace std;

const int X = 1, O =- 1, EMPTY = 0; //possible marks
int board[3][3]; //playing board
int currentPlayer; //current player (X or O)

void clearBoard() { //clear the board
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 ; j++){
            board[i][j] = EMPTY; //the board is empty
        }
    }
    currentPlayer = X; //player X starts
}

void putMark(int i, int j) { //mark row i, column j
    board[i][j] = currentPlayer; //mark with current player
    currentPlayer = -currentPlayer; //switch player
}

bool isWinner(int mark) { //is mark the winner
    int win = 3*mark; //+3 for X, -3 for O
    return ((board[0][0] + board[0][1] + board[0][2] == win)
            ||  (board[1][0] + board[1][1] + board[1][2] == win)
            ||  (board[2][0] + board[2][1] + board[2][2] == win)
            ||  (board[0][0] + board[1][0] + board[2][0] == win)
            ||  (board[0][1] + board[1][1] + board[2][1] == win)
            ||  (board[0][2] + board[1][2] + board[2][2] == win)
            ||  (board[0][0] + board[1][1] + board[2][2] == win)
            ||  (board[2][0] + board[1][1] + board[0][2] == win));
}

int getWinner() { //who wins? (EMPTY means tie)
    if (isWinner(X)) return X;
    else if (isWinner(O)) return O;
    else return EMPTY;
}

void printBoard() { //print board
    for (int i = 0; i < 3; i++ ) {
        for (int j = 0; j < 3; j++ ) {
            switch (board[i][j]) {
                case X:     cout << "X"; break;
                case O:     cout << "O"; break;
                case EMPTY: cout << " "; break;
            }
            if (j < 2) cout << "|"; //column boundary
        }
        if (i < 2) cout << "\n-+-+-\n"; //row boundary
    }
}

void playGame() {
    int position = 0, positionsPlayed[9]; //current position played & current positions played
    int winner = getWinner(); //get winner


    cout << "\nYou can only use the values 1 to 9 to play." << endl;
    cout << endl;
    cout << "1|2|3" << endl;
    cout << "-+-+-" << endl;
    cout << "4|5|6" << endl;
    cout << "-+-+-" << endl;
    cout << "7|8|9" << endl;
    cout << endl; //print end of line

    for (int i = 0; winner == EMPTY; i++) {
        if (i >= 9) break;
        cout << "Player " << (currentPlayer == 1 ? "One" : "Two") << "'s turn." << endl;
        cout << "Enter position on board: ";
        cin >> position; //allow users to enter position

        bool isPlayed = false; //current position is not played
        for (int j = 0; j < i + 1; j++) {
            if (positionsPlayed[j] == position) { //if current position has been played
                cout << "Sorry, that position has already been played." << endl;
                isPlayed = true; //set current position played to TRUE
            }
        }

        if (isPlayed == false && position > 0 && position < 10) {
            positionsPlayed[i] = position; //include the current position played in the array of positions played

            switch(position) { //set player mark
                case 1: putMark(0,0); break;
                case 2: putMark(0,1); break;
                case 3: putMark(0,2); break;
                case 4: putMark(1,0); break;
                case 5: putMark(1,1); break;
                case 6: putMark(1,2); break;
                case 7: putMark(2,0); break;
                case 8: putMark(2,1); break;
                case 9: putMark(2,2); break;
            }
        }

        printBoard(); //print the final board

        cout << endl; //print end of line
        cout << endl; //print end of line

        winner = getWinner(); //check if there is a winner so far
    }
}

int main() {
    clearBoard(); //clear the board

    playGame(); //play game

    int winner = getWinner(); //check if there is a winner
    if (winner != EMPTY)
        cout << "Player " << (winner == X ? '1' : '2') << " wins" << endl; //if there is a winner, echo winner
    else
        cout << "Tie" << endl; //if there is now winner (EMPTY), then there is no winner

    return EXIT_SUCCESS;
}







