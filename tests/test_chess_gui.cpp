#include "../include/constants.hpp"
#include "../include/chess_gui.hpp"
#include <gtest/gtest.h>

int findPieceSpriteAtPosition(string squareName);

TEST(LoadInitPosTest, WhiteQueenOnD1) {
    loadBoard("");
    int i = findPieceSpriteAtPosition("d1");
    ASSERT_LT(i, 32);

    sf::IntRect rect = pieces[i].getTextureRect();
    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);

    PieceSpriteType actualPieceSpriteType = static_cast<PieceSpriteType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceSpriteType, QUEEN_SPRITE);
}

TEST(LoadInitPosTest, BlackQueenOnD8) {
    loadBoard("");
    int i = findPieceSpriteAtPosition("d8");
    ASSERT_LT(i, 32);

    sf::IntRect rect = pieces[i].getTextureRect();
    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, BLACK);

    PieceSpriteType actualPieceSpriteType = static_cast<PieceSpriteType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceSpriteType, QUEEN_SPRITE);
}

TEST(LoadInitPosTest, WhitePawnOnE2) {
    loadBoard("");
    int i = findPieceSpriteAtPosition("e2");
    ASSERT_LT(i, 32);

    sf::IntRect rect = pieces[i].getTextureRect();
    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);

    PieceSpriteType actualPieceSpriteType = static_cast<PieceSpriteType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceSpriteType, PAWN_SPRITE);
}


TEST(LoadInitPosTest, BlackPawnOnC7) {
    loadBoard("");
    int i = findPieceSpriteAtPosition("c7");
    ASSERT_LT(i, 32);

    sf::IntRect rect = pieces[i].getTextureRect();
    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, BLACK);

    PieceSpriteType actualPieceSpriteType = static_cast<PieceSpriteType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceSpriteType, PAWN_SPRITE);
}

TEST(LoadInitPosTest, EmptySquareOnE3) {
    loadBoard("");
    int i = findPieceSpriteAtPosition("e3");
    ASSERT_EQ(i, INT_MAX);
}

TEST(LoadInitPosTest, EmptySquareOnB6) {
    loadBoard("");
    int i = findPieceSpriteAtPosition("b6");
    ASSERT_EQ(i, INT_MAX);
}

TEST(LoadGamePosTest, QueensGambitAccepted) {
    loadBoard("d2d4 d7d5 c2c4 d5c4 e7e5 g1f3 ");

    int i = findPieceSpriteAtPosition("d4");
    ASSERT_LT(i, 32);
    sf::IntRect rect = pieces[i].getTextureRect();
    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);
    PieceSpriteType actualPieceSpriteType = static_cast<PieceSpriteType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceSpriteType, PAWN_SPRITE);

    i = findPieceSpriteAtPosition("f3");
    ASSERT_LT(i, 32);
    rect = pieces[i].getTextureRect();
    actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);
    actualPieceSpriteType = static_cast<PieceSpriteType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceSpriteType, KNIGHT_SPRITE);


    i = findPieceSpriteAtPosition("x");  // captured piece
    ASSERT_LT(i, 32);
    rect = pieces[i].getTextureRect();
    actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);
    actualPieceSpriteType = static_cast<PieceSpriteType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceSpriteType, PAWN_SPRITE);

    i = findPieceSpriteAtPosition("c4");
    ASSERT_LT(i, 32);
    rect = pieces[i].getTextureRect();
    actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, BLACK);
    actualPieceSpriteType = static_cast<PieceSpriteType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceSpriteType, PAWN_SPRITE);

    i = findPieceSpriteAtPosition("d7");
    ASSERT_EQ(i, INT_MAX);

    i = findPieceSpriteAtPosition("d5");
    ASSERT_EQ(i, INT_MAX);
}

TEST(LoadGamePosTest, SicilianDefense) {
    loadBoard("e2e4 c7c5 g1f3 d7d6 d2d4 c5d4 ");

    int i = findPieceSpriteAtPosition("e4");
    ASSERT_LT(i, 32);
    sf::IntRect rect = pieces[i].getTextureRect();
    PieceColor actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);
    PieceSpriteType actualPieceSpriteType = static_cast<PieceSpriteType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceSpriteType, PAWN_SPRITE);

    i = findPieceSpriteAtPosition("f3");
    ASSERT_LT(i, 32);
    rect = pieces[i].getTextureRect();
    actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);
    actualPieceSpriteType = static_cast<PieceSpriteType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceSpriteType, KNIGHT_SPRITE);

    i = findPieceSpriteAtPosition("x");  // captured piece
    ASSERT_LT(i, 32);
    rect = pieces[i].getTextureRect();
    actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, WHITE);
    actualPieceSpriteType = static_cast<PieceSpriteType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceSpriteType, PAWN_SPRITE);

    i = findPieceSpriteAtPosition("d4");
    ASSERT_LT(i, 32);
    rect = pieces[i].getTextureRect();
    actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, BLACK);
    actualPieceSpriteType = static_cast<PieceSpriteType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceSpriteType, PAWN_SPRITE);
    
    i = findPieceSpriteAtPosition("d6");
    ASSERT_LT(i, 32);
    rect = pieces[i].getTextureRect();
    actualPieceColor = static_cast<PieceColor>(rect.top / SQUARESIZE);
    EXPECT_EQ(actualPieceColor, BLACK);
    actualPieceSpriteType = static_cast<PieceSpriteType>(rect.left / SQUARESIZE);
    EXPECT_EQ(actualPieceSpriteType, PAWN_SPRITE);

    i = findPieceSpriteAtPosition("c7");
    ASSERT_EQ(i, INT_MAX);

    i = findPieceSpriteAtPosition("c5");
    ASSERT_EQ(i, INT_MAX);
}

int findPieceSpriteAtPosition(string squareName) {
    auto coord = toCoord(squareName);
    for (int i = 0; i < 32; i++) {
        if (pieces[i].getPosition().x == coord.x && pieces[i].getPosition().y == coord.y) 
        {
            return i;
        }
    }

    return INT_MAX;
}