#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#include "chess_lib.h"

typedef struct {
    char* state;
    char* activeColor;
    char* castling;
    char* enPassant;
} Board;

char chessBoard[8][8];
char testPos[64];

uint64_t whitePawn      = 65280ULL;
uint64_t whiteKnight    = 66ULL;
uint64_t whiteBishop    = 36ULL;
uint64_t whiteRook      = 129ULL;
uint64_t whiteKing      = 8ULL;
uint64_t whiteQueen     = 16ULL;

uint64_t blackPawn      = 71776119061217280ULL;
uint64_t blackKnight    = 4755801206503243776ULL;
uint64_t blackBishop    = 2594073385365405696ULL;
uint64_t blackRook      = 9295429630892703744ULL;
uint64_t blackKing      = 576460752303423488ULL;
uint64_t blackQueen     = 1152921504606846976ULL;


int main()
{
    print_signature();
    printf("Insert starting position: ");
    scanf("%s", testPos);
    putchar('\n');

    Board startPos = {
        .state = testPos,
        .activeColor = "w",
        .castling = "KQkq",
        .enPassant = "-",
    };

    // empty the board (setting '.' in every cell)
    for (int row = 0; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            chessBoard[row][col] = '.';
        }
    }

    // insert every piece to the correct chessboard position
    int row = 0;
    int col = 0;

    for (int i = 0; testPos[i] != '\0'; ++i)
    {
        switch (testPos[i])
        {
        case '/':
            row++;
            col = 0;
            break;
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
            // insert empty squares
            for (int j = 0; j < (testPos[i] - '0'); j++)
            {
                chessBoard[row][col++] = '.';
            }
            break;
        default:
            chessBoard[row][col++] = testPos[i];
        }
    }

    draw_board(chessBoard);

    printf("Board state: %s\n", startPos.state);

    printf("\nWhite pawn bitmap:\t");
    binary_printer_64(whitePawn);

    printf("\nWhite knight bitmap:\t");
    binary_printer_64(whiteKnight);

    printf("\nWhite bishop bitmap:\t");
    binary_printer_64(whiteBishop);

    printf("\nWhite rook bitmap:\t");
    binary_printer_64(whiteRook);

    printf("\nWhite queen bitmap:\t");
    binary_printer_64(whiteQueen);

    printf("\nWhite king bitmap:\t");
    binary_printer_64(whiteKing);

    putchar('\n');

    printf("\nBlack pawn bitmap:\t");
    binary_printer_64(blackPawn);

    printf("\nBlack knight bitmap:\t");
    binary_printer_64(blackKnight);

    printf("\nBlack bishop bitmap:\t");
    binary_printer_64(blackBishop);

    printf("\nBlack rook bitmap:\t");
    binary_printer_64(blackRook);

    printf("\nBlack queen bitmap:\t");
    binary_printer_64(blackQueen);

    printf("\nBlack king bitmap:\t");
    binary_printer_64(blackKing);

    putchar('\n');


    return 0;
}
