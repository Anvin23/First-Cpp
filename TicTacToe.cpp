#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const char HUMAN = 'O';
const char COMPUTER = 'X';
const char EMPTY = ' ';

class TicTacToe
{
private:
    vector<vector<char>> board;

public:
    TicTacToe() : board(3, vector<char>(3, EMPTY)) {}

    void displayBoard()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << board[i][j] << (j < 2 ? " | " : "");
            }
            cout << endl;
            if (i < 2)
                cout << "--+---+--" << endl;
        }
        cout << endl;
    }

    bool isMovesLeft()
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == EMPTY)
                    return true;
        return false;
    }

    int evaluate()
    {
        for (int row = 0; row < 3; row++)
        {
            if (board[row][0] == board[row][1] && board[row][1] == board[row][2])
            {
                if (board[row][0] == COMPUTER)
                    return 10;
                else if (board[row][0] == HUMAN)
                    return -10;
            }
        }

        for (int col = 0; col < 3; col++)
        {
            if (board[0][col] == board[1][col] && board[1][col] == board[2][col])
            {
                if (board[0][col] == COMPUTER)
                    return 10;
                else if (board[0][col] == HUMAN)
                    return -10;
            }
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            if (board[0][0] == COMPUTER)
                return 10;
            else if (board[0][0] == HUMAN)
                return -10;
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        {
            if (board[0][2] == COMPUTER)
                return 10;
            else if (board[0][2] == HUMAN)
                return -10;
        }

        return 0;
    }

    int minimax(bool isMax)
    {
        int score = evaluate();

        if (score == 10)
            return score;
        if (score == -10)
            return score;
        if (!isMovesLeft())
            return 0;

        if (isMax)
        {
            int best = -std::numeric_limits<int>::max();
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] == EMPTY)
                    {
                        board[i][j] = COMPUTER;
                        best = max(best, minimax(!isMax));
                        board[i][j] = EMPTY;
                    }
                }
            }
            return best;
        }
        else
        {
            int best = std::numeric_limits<int>::max();
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board[i][j] == EMPTY)
                    {
                        board[i][j] = HUMAN;
                        best = min(best, minimax(!isMax));
                        board[i][j] = EMPTY;
                    }
                }
            }
            return best;
        }
    }

    pair<int, int> findBestMove()
    {
        int bestVal = -std::numeric_limits<int>::max();
        pair<int, int> bestMove = {-1, -1};

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == EMPTY)
                {
                    board[i][j] = COMPUTER;
                    int moveVal = minimax(false);
                    board[i][j] = EMPTY;

                    if (moveVal > bestVal)
                    {
                        bestMove = {i, j};
                        bestVal = moveVal;
                    }
                }
            }
        }
        return bestMove;
    }

    void playGame()
    {
        int row, col;
        while (true)
        {
            displayBoard();

            int val = evaluate();

            if (val == 10)
            {
                cout << "Computer wins!\n"
                     << endl;
                break;
            }
            else if (val == -10)
            {
                cout << "Human wins!\n"
                     << endl;
                break;
            }
            else if (!isMovesLeft())
            {
                cout << "It's a draw!\n"
                     << endl;
                break;
            }

            cout << "Enter your move (row and column): ";
            cin >> row >> col;
            if (board[row][col] == EMPTY)
            {
                board[row][col] = HUMAN;
            }
            else
            {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            if (!isMovesLeft())
            {
                cout << "\nIt's a draw!\n"
                     << endl;
                break;
            }

            pair<int, int> bestMove = findBestMove();
            board[bestMove.first][bestMove.second] = COMPUTER;
        }
        displayBoard();
    }
};

int main()
{
    TicTacToe game;
    game.playGame();
    return 0;
}
