#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <array>
#include <vector>
#include "chesspiece.h"
#include "chessmove.h"
class ChessPiece;
class ChessMove;

class ChessBoard{
public:
    ChessBoard();
    ChessBoard(const ChessBoard&);
    ChessPiece* GetPiece(int, int) const;
    ChessBoard* DoMove(const ChessMove&);
    void InitializeBoard();
    bool UnderAttack(ChessColor, int, int) const;
    bool InCheck(ChessColor) const;
    bool NoValidMoves(ChessColor);
    const std::vector<ChessMove*>& GetPsuedoLegalMoves() const;
    void GeneratePsuedoLegalMoves(int, int);
private:
    std::array<std::array<ChessPiece*, 8>, 8> chessBoard;
    void MovePiece(ChessPiece*, int, int);
    void ClearCell(int, int);
    ChessMove* GetKingPosition(ChessColor) const;
    std::vector<ChessMove*> psuedoLegalMoves;
    void GeneratePLPawnMoves(int, int);
    void GeneratePLRookMoves(int, int);
    void GeneratePLKnightMoves(int, int);
    void GeneratePLKingMoves(int, int);
    void GeneratePLQueenMoves(int, int);
    void GeneratePLBishopMoves(int, int);
};

#endif // CHESSBOARD_H
