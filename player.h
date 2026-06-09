#pragma once
#include"pieces.h"

class player {
public:
    pieces p[4];
    char symbol;

    player() { symbol = ' '; }

    player(char sym, int color, int rows[], int cols[]) {
        symbol = sym;

        for (int i = 0; i < 4; i++) {
            p[i] = pieces(rows[i], cols[i], sym, color, i + 1);
        }
    }
};
