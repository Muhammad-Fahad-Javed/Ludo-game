#pragma once
#include"cell.h"
#include"safeCell.h"
#include"index.h"
#include"pathArray.h"
#include"pieces.h"
#include"player.h"
#include"board.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <ctime>

using std::string;
using std::endl;

class gamePlay {
    int totalPlayers;
    board LudoBoard;
    player* players;
    Cell* cell[8];

public:

    gamePlay(int n): totalPlayers(n < 4 ? 4 : n) {
        srand(static_cast<unsigned int>(time(nullptr)));
        players = new player[totalPlayers];

        int gR[4] = { 1,1,4,4 }, gC[4] = { 1,4,1,4 };
        int yR[4] = { 1,1,4,4 }, yC[4] = { 10,13,10,13 };
        int rR[4] = { 10,10,13,13 }, rC[4] = { 10,13,10,13 };
        int bR[4] = { 10,10,13,13 }, bC[4] = { 1,4,1,4 };

        players[0] = player('G', GREEN, gR, gC);
        players[1] = player('Y', YELLOW, yR, yC);
        players[2] = player('R', RED, rR, rC);
        players[3] = player('B', BLUE, bR, bC);

        cell[0] = new SafeCell(6, 1);
        cell[1] = new SafeCell(1, 8);
        cell[2] = new SafeCell(8, 3);
        cell[3] = new SafeCell(13, 6);
        cell[4] = new SafeCell(8, 2);
        cell[5] = new SafeCell(12, 8);
        cell[6] = new SafeCell(2, 6);
        cell[7] = new SafeCell(6, 12);
    }

    int chaka_ghuma();

	void draw();
    
	void safeMove(pieces& pc, int steps, int playerIndex);

	void openPiece(pieces& pc, int playerIndex) const;

	bool isSafe(int r, int c);

	void killOpponent(int currentPlayer);

	void play();

    ~gamePlay() {
        delete[] players;
        players = nullptr;
        for (int i = 0;i < 8;i++) {
            delete cell[i];
            cell[i] = nullptr;
        }
        
    }
};