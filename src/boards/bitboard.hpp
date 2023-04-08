// 64 bitstring which acts as a singular bitboard
typedef unsigned long long U64;

// Structure which represents a board
struct Bitboard
{
    U64 pieceBB[12];
    U64 blackBB;
    U64 whiteBB;
};
// Define shorthand
typedef struct Bitboard BB;