#include <gtest/gtest.h>
#include "chess_gui.h"
#include "constants.h"

int findPieceAtPosition(int x, int y);

TEST(LoadInitPosTest, WhiteQueenOnD1) {
    loadBoard("");

    int x = SQUARESIZE * 3;  // D
    int y = SQUARESIZE * 7;  // 1

    int i = findPieceAtPosition(x, y);

    ASSERT_LT(i, 32);

    sf::IntRect rect = pieces[i].getTextureRect();
    PieceType actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, QUEEN);

    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);
}

TEST(LoadInitPosTest, BlackQueenOnD8) {
    loadBoard("");

    int x = SQUARESIZE * 3;  // D
    int y = SQUARESIZE * 0;  // 8

    int i = findPieceAtPosition(x, y);

    ASSERT_LT(i, 32);

    sf::IntRect rect = pieces[i].getTextureRect();
    PieceType actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, QUEEN);

    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, BLACK);
}

TEST(LoadInitPosTest, WhitePawnOnE2) {
    loadBoard("");

    int x = SQUARESIZE * 4;  // E
    int y = SQUARESIZE * 6;  // 2

    int i = findPieceAtPosition(x, y);

    ASSERT_LT(i, 32);

    sf::IntRect rect = pieces[i].getTextureRect();
    PieceType actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, PAWN);

    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);
}


TEST(LoadInitPosTest, BlackPawnOnC7) {
    loadBoard("");

    int x = SQUARESIZE * 2;  // C
    int y = SQUARESIZE * 1;  // 7

    int i = findPieceAtPosition(x, y);

    ASSERT_LT(i, 32);

    sf::IntRect rect = pieces[i].getTextureRect();
    PieceType actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, PAWN);

    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, BLACK);
}

TEST(LoadInitPosTest, EmptySquareOnE3) {
    loadBoard("");

    int x = SQUARESIZE * 4;  // E
    int y = SQUARESIZE * 5;  // 3

    int i = findPieceAtPosition(x, y);

    ASSERT_EQ(i, INT_MAX);
}

TEST(LoadInitPosTest, EmptySquareOnB6) {
    loadBoard("");

    int x = SQUARESIZE * 1;  // B
    int y = SQUARESIZE * 2;  // 6

    int i = findPieceAtPosition(x, y);

    ASSERT_EQ(i, INT_MAX);
}

int findPieceAtPosition(int x, int y) {
    for (int i = 0; i < 32; i++) {
        if (pieces[i].getPosition().x == x && pieces[i].getPosition().y == y) {
            return i;
        }
    }

    return INT_MAX;
}