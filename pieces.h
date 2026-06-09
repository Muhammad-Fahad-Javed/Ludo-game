#pragma once

class pieces {
public:
    bool OpenCheck;
    bool finished;

    bool inHome = false;
    int homeIndex = -1;

    int path_Index = -1;

    int x, y;
    char sym;
    int color;
    int id;

    pieces& operator++();

    pieces() {
        x = y = color = id = 0; sym = ' ';
        OpenCheck = false;
        finished = false;
    }

    pieces(int row, int col, char s, int clr, int i) {
        OpenCheck = false;
        finished = false;
        x = row;
        y = col;
        sym = s;
        color = clr;
        id = i;
    }

};