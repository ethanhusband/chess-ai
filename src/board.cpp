#include "board.h"

typedef unsigned long long U64;

class Board
{
    U64 pieceBB[12];
    U64 blackBB;
    U64 whiteBB;

    enum pieceIndex
    {
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

public:
    Board()
    {
        // Initialise all values w/ starting board
        pieceBB[wPawns] = 0x000000000000FF00;
        pieceBB[bPawns] = 0x00FF000000000000;
        pieceBB[wKnights] = 0x0000000000000042;
        pieceBB[bKnights] = 0x4200000000000000;
        pieceBB[wBishops] = 0x0000000000000024;
        pieceBB[bBishops] = 0x2400000000000000;
        pieceBB[wRooks] = 0x0000000000000081;
        pieceBB[bRooks] = 0x8100000000000000;
        pieceBB[wQueens] = 0x0000000000000010;
        pieceBB[bQueens] = 0x1000000000000000;
        pieceBB[wKing] = 0x000000000000008;
        pieceBB[bKing] = 0x0800000000000000;

        // Instantiate the team bitboards
        BlackBB();
        WhiteBB();
    }

    Board(charBoard charboard)
    {
        // Initialise from some arbitrary entered board
    }

    void BlackBB()
    {
        U64 bb = 0x0000000000000000;
        for (int i = bPawns; i < bKing; i++)
        {
            bb |= pieceBB[i];
        }
        blackBB = bb;
    }

    void WhiteBB()
    {
        U64 bb = 0x0000000000000000;
        for (int i = bPawns; i < bKing; i++)
        {
            bb |= pieceBB[i];
        }
        whiteBB = bb;
    }
};

