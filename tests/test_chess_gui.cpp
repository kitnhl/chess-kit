#include "../include/constants.hpp"
#include "../include/chess_gui.hpp"
#include <gtest/gtest.h>

int findPieceAtPosition(string squareName);

TEST(LoadInitPosTest, WhiteQueenOnD1) {
    loadBoard("");
    int i = findPieceAtPosition("d1");
    ASSERT_LT(i, 32);

    sf::IntRect rect = pieces[i].getTextureRect();
    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);

    PieceType actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, QUEEN);
}

TEST(LoadInitPosTest, BlackQueenOnD8) {
    loadBoard("");
    int i = findPieceAtPosition("d8");
    ASSERT_LT(i, 32);

    sf::IntRect rect = pieces[i].getTextureRect();
    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, BLACK);

    PieceType actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, QUEEN);
}

TEST(LoadInitPosTest, WhitePawnOnE2) {
    loadBoard("");
    int i = findPieceAtPosition("e2");
    ASSERT_LT(i, 32);

    sf::IntRect rect = pieces[i].getTextureRect();
    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);

    PieceType actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, PAWN);
}


TEST(LoadInitPosTest, BlackPawnOnC7) {
    loadBoard("");
    int i = findPieceAtPosition("c7");
    ASSERT_LT(i, 32);

    sf::IntRect rect = pieces[i].getTextureRect();
    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, BLACK);

    PieceType actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, PAWN);
}

TEST(LoadInitPosTest, EmptySquareOnE3) {
    loadBoard("");
    int i = findPieceAtPosition("e3");
    ASSERT_EQ(i, INT_MAX);
}

TEST(LoadInitPosTest, EmptySquareOnB6) {
    loadBoard("");
    int i = findPieceAtPosition("b6");
    ASSERT_EQ(i, INT_MAX);
}

TEST(LoadGamePosTest, QueensGambitAccepted) {
    loadBoard("d2d4 d7d5 c2c4 d5c4 e7e5 g1f3 ");

    int i = findPieceAtPosition("d4");
    ASSERT_LT(i, 32);
    sf::IntRect rect = pieces[i].getTextureRect();
    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);
    PieceType actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, PAWN);

    i = findPieceAtPosition("f3");
    ASSERT_LT(i, 32);
    rect = pieces[i].getTextureRect();
    actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);
    actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, KNIGHT);


    i = findPieceAtPosition("x");  // captured piece
    ASSERT_LT(i, 32);
    rect = pieces[i].getTextureRect();
    actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);
    actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, PAWN);

    i = findPieceAtPosition("c4");
    ASSERT_LT(i, 32);
    rect = pieces[i].getTextureRect();
    actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, BLACK);
    actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, PAWN);

    i = findPieceAtPosition("d7");
    ASSERT_EQ(i, INT_MAX);

    i = findPieceAtPosition("d5");
    ASSERT_EQ(i, INT_MAX);
}

TEST(LoadGamePosTest, SicilianDefense) {
    loadBoard("e2e4 c7c5 g1f3 d7d6 d2d4 c5d4 ");

    int i = findPieceAtPosition("e4");
    ASSERT_LT(i, 32);
    sf::IntRect rect = pieces[i].getTextureRect();
    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);
    PieceType actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, PAWN);

    i = findPieceAtPosition("f3");
    ASSERT_LT(i, 32);
    rect = pieces[i].getTextureRect();
    actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);
    actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, KNIGHT);

    i = findPieceAtPosition("x");  // captured piece
    ASSERT_LT(i, 32);
    rect = pieces[i].getTextureRect();
    actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);
    actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, PAWN);

    i = findPieceAtPosition("d4");
    ASSERT_LT(i, 32);
    rect = pieces[i].getTextureRect();
    actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, BLACK);
    actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, PAWN);
    
    i = findPieceAtPosition("d6");
    ASSERT_LT(i, 32);
    rect = pieces[i].getTextureRect();
    actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, BLACK);
    actualPieceType = static_cast<PieceType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceType, PAWN);

    i = findPieceAtPosition("c7");
    ASSERT_EQ(i, INT_MAX);

    i = findPieceAtPosition("c5");
    ASSERT_EQ(i, INT_MAX);
}

int findPieceAtPosition(string squareName) {
    auto coord = toCoord(squareName);
    for (int i = 0; i < 32; i++) {
        if (pieces[i].getPosition().x == coord.x && pieces[i].getPosition().y == coord.y) 
        {
            return i;
        }
    }

    return INT_MAX;
}