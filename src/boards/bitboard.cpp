#include "bitboard.hpp"
#include "charboard.hpp"
#include "macros.hpp"

class BitBoardOps
{
    /// @brief Indexes for each piece in the bitboard pieceBB array
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
    /// @brief Give the starting board of the game as a bitboard
    /// @return bitboard
    BB InitialBoard()
    {
        BB board;
        // Initialise all values w/ starting board
        board.pieceBB[wPawns] = 0x000000000000FF00;
        board.pieceBB[bPawns] = 0x00FF000000000000;
        board.pieceBB[wKnights] = 0x0000000000000042;
        board.pieceBB[bKnights] = 0x4200000000000000;
        board.pieceBB[wBishops] = 0x0000000000000024;
        board.pieceBB[bBishops] = 0x2400000000000000;
        board.pieceBB[wRooks] = 0x0000000000000081;
        board.pieceBB[bRooks] = 0x8100000000000000;
        board.pieceBB[wQueens] = 0x0000000000000010;
        board.pieceBB[bQueens] = 0x1000000000000000;
        board.pieceBB[wKing] = 0x000000000000008;
        board.pieceBB[bKing] = 0x0800000000000000;

        // Instantiate the team bitboards
        BlackBB(&board);
        WhiteBB(&board);
        return board;
    };

    /// @brief Instantiate a bitboard from a given charboard
    /// @param charboard
    /// @return corresponding bitboard
    BB FromCharBoard(CB charboard)
    {
        BB bitboard;
        for (int i = 0; i < BOARD_SIZE; i++)
        {
            U64 binary = 0x0000000000000001 << (BOARD_SIZE - i - 1);

            /* Map an arrayBoard piece to its corresponding bitboard index */
            switch (charboard[i])
            {
            case CB_WHITE_PAWN:
                bitboard.pieceBB[wPawns] |= binary;
                break;
            case CB_WHITE_KNIGHT:
                bitboard.pieceBB[wKnights] |= binary;
                ;
                break;
            case CB_WHITE_BISHOP:
                bitboard.pieceBB[wBishops] |= binary;
                break;
            case CB_WHITE_ROOK:
                bitboard.pieceBB[wRooks] |= binary;
                break;
            case CB_WHITE_QUEEN:
                bitboard.pieceBB[wQueens] |= binary;
                break;
            case CB_WHITE_KING:
                bitboard.pieceBB[wKing] |= binary;
                break;
            case CB_BLACK_PAWN:
                bitboard.pieceBB[bPawns] |= binary;
                break;
            case CB_BLACK_KNIGHT:
                bitboard.pieceBB[bKnights] |= binary;
                break;
            case CB_BLACK_BISHOP:
                bitboard.pieceBB[bBishops] |= binary;
                break;
            case CB_BLACK_ROOK:
                bitboard.pieceBB[bRooks] |= binary;
                break;
            case CB_BLACK_QUEEN:
                bitboard.pieceBB[bQueens] |= binary;
                break;
            case CB_BLACK_KING:
                bitboard.pieceBB[bKing] |= binary;
                break;
            };
        }
        BlackBB(&bitboard);
        WhiteBB(&bitboard);
        return bitboard;
    };

    /// @brief Generate a bitboard for the black pieces
    /// @param board
    void BlackBB(BB *board)
    {
        U64 bb = 0x0000000000000000;
        for (int i = bPawns; i < bKing; i++)
        {
            bb |= board->pieceBB[i];
        }
        board->blackBB = bb;
    };

    /// @brief Generate a bitboard for all the white pieces
    /// @param board
    void WhiteBB(BB *board)
    {
        U64 bb = 0x0000000000000000;
        for (int i = bPawns; i < bKing; i++)
        {
            bb |= board->pieceBB[i];
        }
        board->whiteBB = bb;
    }
};
