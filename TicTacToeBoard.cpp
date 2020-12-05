#include "TicTacToeBoard.h"
#include <iostream>
using namespace std;
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X)
    turn = O;
  else
    turn = X;
  
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  //game over, no need to play 
  if(getWinner() == Invalid ) 
  {
    //out of bounds
    Piece curPiece = getPiece(row, column);
    if (curPiece == Invalid)
    {
      return Invalid;
    }
    else if (curPiece == Blank)
    {
      curPiece = turn;
      board[row][column] = curPiece;	
      toggleTurn();
      
    }
    //filled spot
    cout<<"Curpiece: "<<curPiece<<endl;
    return curPiece;
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if (row >= BOARDSIZE || row < 0 || column >= BOARDSIZE || column < 0)
  {
    return Invalid;
  }
  //should return Blank or the Piece
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{

  for( int i=0; i<BOARDSIZE; ++i)
  {
    if(board[i][0] != Blank)
    {
      //vertical check
      if((board[i][0] == board[i][1]) && (board[i][0] == board[i][2]))
      {
        return board[i][0];
      }
    }
    if(board[0][i] != Blank)
    {
      //horizontal
      if((board[0][i] == board[1][i]) && (board[0][i] == board[2][i]))
      {
        return board[0][i];
      }
    }

  }

  //diagonal
  if ((board[0][0] != Blank) && (board[0][0] == board[1][1]) && (board[0][0] == board[2][2]))
  {
    return board[0][0];
  }
  if ((board[2][0] != Blank) && (board[2][0] == board[1][1]) && (board[2][0] == board[0][2]))
  {
    return board[2][0];
  }

  //returns invalid if yhere are places empty
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      if (board[i][j] == Blank)
      {
        cout<<"GetWinner() returns Invalid\n";
        return Invalid;

      }
    }
  }

  //returns Blank if all rows has been has been filled
  cout<<"GetWinner() returns Blank\n";
  return Blank;
}
