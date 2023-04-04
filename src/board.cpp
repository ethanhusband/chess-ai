#include "board.h"

typedef unsigned long long U64;

void generateChildren(Node *node)
{
    // Identify each piece in the board which is that of the current turn
    // Generate moves for that piece via a map which returns a set of functions for a given piece
}

class Board
{
    U64 bitboards[12];
    
    enum pieceIndex {
        wPawns,
        wKnights,
        wBishops,
        wRooks,
        wQueens,
        wKing,

        bPawns,
        bKnights,
        bBishops,
        bRooks,
        bQueens,
        bKing,
    };

    
    
};