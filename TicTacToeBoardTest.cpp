/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

// EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, blankgetWinner)
{
	TicTacToeBoard b;
	ASSERT_EQ(b.getWinner(), Blank);
}

TEST(TicTacToeBoardTest, InvalidgetWinner)
{
	TicTacToeBoard b;
	b.placePiece(2,1);
	ASSERT_EQ(b.getWinner(), Blank);
}

TEST(TicTacToeBoardTest, Otogglepiece)
{
	TicTacToeBoard b;
	b.placePiece(2,1);
	b.placePiece(0,0);
	b.placePiece(0,1);
	ASSERT_EQ(b.placePiece(1,2), Blank);
}

TEST(TicTacToeBoardTest, invalidplacePiece)
{
	TicTacToeBoard b;
	b.placePiece(0,0); //x
	b.placePiece(0,1); //o
	b.placePiece(0,2); //x
	ASSERT_EQ(b.placePiece(32,11), Invalid);
}

TEST(TicTacToeBoardTest, noWinner)
{
	TicTacToeBoard b;
	b.placePiece(0,0); //x
	b.placePiece(0,1); //o
	b.placePiece(0,2); //x
	b.placePiece(1,0); //o
	b.placePiece(1,1); //x
	b.placePiece(1,2); //o
	b.placePiece(2,0); //x
	b.placePiece(2,1); //o
	b.placePiece(2,2); //x
	ASSERT_EQ(b.getWinner(), Invalid);
}

TEST(TicTacToeBoardTest, lastColWinner)
{
	TicTacToeBoard b;
	b.placePiece(2,0); //x
	b.placePiece(1,2); //o
	b.placePiece(2,1); //x
	b.placePiece(1,0); //o
	b.placePiece(2,2); //x
	ASSERT_EQ(b.getWinner(), X);
}

TEST(TicTacToeBoardTest, lastRowWinner)
{
	TicTacToeBoard b;
	b.placePiece(0,2); //x
	b.placePiece(1,1); //o
	b.placePiece(1,2); //x
	b.placePiece(1,0); //o
	b.placePiece(2,2); //x
	
	ASSERT_EQ(b.getWinner(), X);
}

TEST(TicTacToeBoardTest, diagLeftWinner)
{
	TicTacToeBoard b;
	b.placePiece(0,0);
	b.placePiece(1,0); 
	b.placePiece(1,1);
	b.placePiece(0,2); 
	b.placePiece(2,2);
	ASSERT_EQ(b.getWinner(), X);
}

TEST(TicTacToeBoardTest, diagRightWinner)
{
	TicTacToeBoard b;
	b.placePiece(0,2);
	b.placePiece(1,0); 
	b.placePiece(1,1);
	b.placePiece(0,2); 
	b.placePiece(2,0);
	ASSERT_EQ(b.getWinner(), X);
}

TEST(TicTacToeBoardTest, filledSpot)
{
	TicTacToeBoard b;
	b.placePiece(2,1);
	ASSERT_EQ(b.placePiece(2,1), Invalid);
}