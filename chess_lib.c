#include <stdio.h>
#include <stdint.h>

#include "chess_lib.h"

char StartingPosition[] = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";

void print_signature()
{
    printf("Chess program written by\n");
    printf("Istvan Sibalin\n- 2025 September -\n\n");
}

void binary_printer_64(uint64_t x)                     // print out the binary representation of a number in 64 bits.
{
    for (int i = 63; i >= 0; --i)
    {
        putchar((x & (1ULL << i)) ? '1' : '0');     // binary AND operation with "unsigned long long 1" shifted "i" spaces to the left.
                                                    // if the result is true, print '1', else print '0'
        if (i % 8 ==0 )                             // put spaces after every 8th bit
        {
            putchar(' ');
        }
    }
}

void draw_board(char grid[8][8])
{
    printf("  |A B C D E F G H\n");
    printf("--|---------------\n");
    for (int row = 0; row <= 7; ++row)
    {
        printf("%d |", row);
        for (int col = 0; col <= 7; ++col)
            {
                printf("%c ", grid[row][col]);
            }
            putchar('\n');
    }
    putchar('\n');
}
