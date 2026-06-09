#pragma once
#include"player.h"
#include"pathArray.h"
#include<iostream>
#include <windows.h>

using namespace std;


const int BLACK = 0;
const int BLUE = 1;
const int GREEN = 2;
const int RED = 4;
const int YELLOW = 14;
const int WHITE = 7;
const int BRIGHT_WHITE = 15;


class board {
protected:
    string label[15][15];
    int bg[15][15];
    int fg[15][15];
public:
    
    path_array Path;


    board() {
        initBoard();
        Path.SetPath();
    }

    void initBoard();

	void draw(player* players, int totalPlayers);


};