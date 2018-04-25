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

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
*/

//Check if turn toggle properly first time.
TEST(TicTacToeBoardTest, turnXThenO)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.toggleTurn()==O);
}

//Check if turn toggles properly second time.
TEST(TicTacToeBoardTest, turnOThenX)
{
  TicTacToeBoard obj;
  obj.toggleTurn();
  ASSERT_TRUE(obj.toggleTurn()==X);
}

//Ensure turn is not Invalid.
TEST(TicTacToeBoardTest, turnNotInvalid)
{
  TicTacToeBoard obj;
  ASSERT_FALSE(obj.toggleTurn()==Invalid);
}

//Ensure turn is not Blank.
TEST(TicTacToeBoardTest, turnNotBlank)
{
  TicTacToeBoard obj;
  ASSERT_FALSE(obj.toggleTurn()==Blank);
}

//Check get piece on blank.
TEST(TicTacToeBoardTest, getPieceBlank)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.getPiece(0,0)==Blank);
}

//Check get piece below row.
TEST(TicTacToeBoardTest, getPieceBelowRow)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.getPiece(-1,0)==Invalid);
}

//Check get piece below column.
TEST(TicTacToeBoardTest, getPieceBelowColumn)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.getPiece(0,-1)==Invalid);
}

//Check get piece below row and column.
TEST(TicTacToeBoardTest, getPieceBelowBoth)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.getPiece(-1,-1)==Invalid);
}

//Check get piece above row.
TEST(TicTacToeBoardTest, getPieceAboveRow)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.getPiece(3,0)==Invalid);
}

//Check get piece above column.
TEST(TicTacToeBoardTest, getPieceAboveColumn)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.getPiece(0,3)==Invalid);
}

//Check get piece above row and column.
TEST(TicTacToeBoardTest, getPieceAboveBoth)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.getPiece(3,3)==Invalid);
}

//Check if X is placed correctly.
TEST(TicTacToeBoardTest, placeXInBounds)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.placePiece(0,0)==X);
}

//Check get piece on X.
TEST(TicTacToeBoardTest, getPieceOnX)
{
  TicTacToeBoard obj;
  obj.placePiece(0,0);
  ASSERT_TRUE(obj.getPiece(0,0)==X);
}

//Check if O is placed correctly.
TEST(TicTacToeBoardTest, placeOInBounds)
{
  TicTacToeBoard obj;
  obj.toggleTurn();
  ASSERT_TRUE(obj.placePiece(0,0)==O);
}

//Check get piece on O.
TEST(TicTacToeBoardTest, getPieceOnO)
{
  TicTacToeBoard obj;
  obj.toggleTurn();
  obj.placePiece(0,0);
  ASSERT_TRUE(obj.getPiece(0,0)==O);
}

//Check place piece below bounds on Row.
TEST(TicTacToeBoardTest, placePieceBelowBoundsOnRow)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.placePiece(-1,0)==Invalid);
}

//Check place piece below bounds on Column.
TEST(TicTacToeBoardTest, placePieceBelowBoundsOnColumn)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.placePiece(0,-1)==Invalid);
}

//Check place piece below bounds on Row and Column.
TEST(TicTacToeBoardTest, placePieceBelowBoundsOnBoth)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.placePiece(-1,-1)==Invalid);
}

//Check place piece above bounds on Row.
TEST(TicTacToeBoardTest, placePieceAboveBoundsOnRow)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.placePiece(3,0)==Invalid);
}

//Check place piece above bounds on Column.
TEST(TicTacToeBoardTest, placePieceAboveBoundsOnColumn)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.placePiece(0,3)==Invalid);
}

//Check place piece above bounds on Row and Column.
TEST(TicTacToeBoardTest, placePieceAboveBoundsOnBoth)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.placePiece(3,3)==Invalid);
}

//Check place piece below bounds on Row and above on Column.
TEST(TicTacToeBoardTest, placePieceBelowRowAboveColumn)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.placePiece(-1,3)==Invalid);
}

//Check place piece above bounds on Row and below on Column.
TEST(TicTacToeBoardTest, placePieceAboveRowBelowColumn)
{
  TicTacToeBoard obj;
  ASSERT_TRUE(obj.placePiece(3,-1)==Invalid);
}

//Check place piece on existing piece returns existing piece.
TEST(TicTacToeBoardTest, placePieceOnPiece)
{
  TicTacToeBoard obj;
  obj.placePiece(0,0);
  ASSERT_TRUE(obj.placePiece(0,0)==X);
}

//Check place piece on Blank after win doesn't change turn and should return blank.
TEST(TicTacToeBoardTest, placePieceOnBlankAfterWin)
{
  TicTacToeBoard obj;
  obj.placePiece(0,0);
  obj.placePiece(0,2);
  obj.placePiece(1,0);
  obj.placePiece(1,2);
  obj.placePiece(2,0);
  ASSERT_TRUE(obj.placePiece(2,2)==Blank);
}

//Check that getWinner succesfully recognizes win on top row.
TEST(TicTacToeBoardTest, topRowWin)
{
  TicTacToeBoard obj;
  obj.placePiece(0,0);
  obj.placePiece(1,2);
  obj.placePiece(0,1);
  obj.placePiece(1,1);
  obj.placePiece(0,2);
  ASSERT_TRUE(obj.getWinner()==X);
}

//Check that getWinner succesfully recognizes win on bottom row.
TEST(TicTacToeBoardTest, bottomRowWin)
{
  TicTacToeBoard obj;
  obj.placePiece(2,0);
  obj.placePiece(1,2);
  obj.placePiece(2,1);
  obj.placePiece(1,1);
  obj.placePiece(2,2);
  ASSERT_TRUE(obj.getWinner()==X);
}

//Check that getWinner succesfully recognizes win on middle row.
TEST(TicTacToeBoardTest, midRowWin)
{
  TicTacToeBoard obj;
  obj.placePiece(1,0);
  obj.placePiece(0,2);
  obj.placePiece(1,1);
  obj.placePiece(0,1);
  obj.placePiece(1,2);
  ASSERT_TRUE(obj.getWinner()==X);
}

//Check that getWinner succesfully recognizes win on middle column.
TEST(TicTacToeBoardTest, midColWin)
{
  TicTacToeBoard obj;
  obj.placePiece(0,1);
  obj.placePiece(1,2);
  obj.placePiece(1,1);
  obj.placePiece(0,0);
  obj.placePiece(2,1);
  ASSERT_TRUE(obj.getWinner()==X);
}

//Check that getWinner succesfully recognizes win on right column.
TEST(TicTacToeBoardTest, rightColWin)
{
  TicTacToeBoard obj;
  obj.placePiece(0,2);
  obj.placePiece(1,1);
  obj.placePiece(1,2);
  obj.placePiece(0,0);
  obj.placePiece(2,2);
  ASSERT_TRUE(obj.getWinner()==X);
}

//Check that getWinner succesfully recognizes win on back diagonal.
TEST(TicTacToeBoardTest, backDiagonalWin)
{
  TicTacToeBoard obj;
  obj.placePiece(0,0);
  obj.placePiece(0,1);
  obj.placePiece(1,1);
  obj.placePiece(0,2);
  obj.placePiece(2,2);
  ASSERT_TRUE(obj.getWinner()==X);
}

//Check that getWinner succesfully recognizes win on forward diagonal.
TEST(TicTacToeBoardTest, forDiagonalWin)
{
  TicTacToeBoard obj;
  obj.placePiece(0,2);
  obj.placePiece(1,2);
  obj.placePiece(1,1);
  obj.placePiece(0,0);
  obj.placePiece(2,0);
  ASSERT_TRUE(obj.getWinner()==X);
}

//Check getWinner returns win on finished game on not full board.
TEST(TicTacToeBoardTest, getWinnerOnWinNotFull)
{
  TicTacToeBoard obj;
  obj.placePiece(0,0);
  obj.placePiece(0,2);
  obj.placePiece(1,0);
  obj.placePiece(1,2);
  obj.placePiece(2,0);
  ASSERT_TRUE(obj.getWinner()==X);
}

//Check getWinner returns win on finished game with full board.
TEST(TicTacToeBoardTest, getWinnerOnWinFull)
{
  TicTacToeBoard obj;
  obj.placePiece(0,0);
  obj.placePiece(0,2);
  obj.placePiece(1,0);
  obj.placePiece(1,2);
  obj.placePiece(2,0);
  obj.placePiece(0,1);
  obj.placePiece(1,1);
  obj.placePiece(2,1);
  obj.placePiece(2,2);
  ASSERT_TRUE(obj.getWinner()==X);
}

//Check getWinner returns Invalid on unfinished game on not full board.
TEST(TicTacToeBoardTest, getWinnerOnNoWinNotFull)
{
  TicTacToeBoard obj;
  obj.placePiece(0,0);
  obj.placePiece(0,2);
  obj.placePiece(1,0);
  obj.placePiece(1,2);
  ASSERT_TRUE(obj.getWinner()==Invalid);
}

//Check getWinner returns Blank on finished game with full board, no winners.
TEST(TicTacToeBoardTest, getWinnerOnNoWinFull)
{
  TicTacToeBoard obj;
  obj.placePiece(0,0);
  obj.placePiece(0,2);
  obj.placePiece(0,1);
  obj.placePiece(1,0);
  obj.placePiece(1,2);
  obj.placePiece(1,1);
  obj.placePiece(2,2);
  obj.placePiece(2,1);
  obj.placePiece(2,0);
  ASSERT_TRUE(obj.getWinner()==Blank);
}
