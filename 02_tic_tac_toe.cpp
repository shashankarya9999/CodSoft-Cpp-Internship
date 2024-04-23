#include <iostream>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

void printBoard(const std::vector<std::vector<char>>& board) 
{
    for(const auto& row : board) 
    {
        for(char cell : row) 
        {
            cout << cell << " ";
        }
        
        cout << endl;
    }
}

bool checkWin(const std::vector<std::vector<char>>& board, char player) 
{
    // check rows
    for(int i = 0; i < 3; ++i) 
    {
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player) 
        {
            return true;
        }
    }

    // check columns
    for(int i = 0; i < 3; ++i) 
    {
        if(board[0][i] == player && board[1][i] == player && board[2][i] == player) 
        {
            return true;
        }
    }

    // Check diagonals
    if((board[0][0] == player && board[1][1] == player && board[2][2] == player) || (board[0][2] == player && board[1][1] == player && board[2][0] == player)) 
    {
        return true;
    }

    return false;
}

int main() 
{
    vector<std::vector<char>> board = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    char currentPlayer = 'X';
    int moves = 0;

    while( moves < 9 ) 
    {
        printBoard(board);

        int move;
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if( move < 1 || move > 9 ) 
        {
            cout << "Invalid move. Please enter a number between 1 and 9." << endl;
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if( board[row][col] == 'X' || board[row][col] == 'O' ) 
        {
            cout << "That cell is already taken. Please choose another one." << endl;
            continue;
        }

        board[row][col] = currentPlayer;

        if(checkWin(board, currentPlayer)) 
        {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        currentPlayer = ( currentPlayer == 'X' ) ? 'O' : 'X';
        moves++;
    }

    if(moves == 9) 
    {
        printBoard(board);
        cout << "It's a tie!" << endl;
    }

    return 0;
}
