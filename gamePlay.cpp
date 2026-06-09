#include"gamePlay.h"

int gamePlay::chaka_ghuma() {
    return rand() % 6 + 1;
}

void gamePlay:: draw() {
    LudoBoard.draw(players, totalPlayers);
}

void gamePlay:: safeMove(pieces& goti, int moves, int playerIndex) {

    int stop[4] = { 50, 11, 24, 37 };

    for (int i = 0; i < moves; i++) {

        if (!goti.inHome) {

            if (goti.path_Index == stop[playerIndex]) {
                goti.inHome = true;
                goti.homeIndex = 0;

                goti.x = LudoBoard.Path.homePath[playerIndex][0].x;
                goti.y = LudoBoard.Path.homePath[playerIndex][0].y;
                continue;
            }

            goti.path_Index = (goti.path_Index + 1) % 52;

            goti.x = LudoBoard.Path.path[goti.path_Index].x;
            goti.y = LudoBoard.Path.path[goti.path_Index].y;
        }

        else {

            if (goti.homeIndex < 5) {
                goti.homeIndex++;

                goti.x = LudoBoard.Path.homePath[playerIndex][goti.homeIndex].x;
                goti.y = LudoBoard.Path.homePath[playerIndex][goti.homeIndex].y;
            }

            if (goti.homeIndex == 5) {
                goti.finished = true;
                break;
            }
        }
    }
}


void gamePlay::openPiece(pieces& goti, int playerIndex) const {
    goti.OpenCheck = true;

    if (playerIndex == 0) goti.path_Index = 0;
    else if (playerIndex == 1) goti.path_Index = 13;
    else if (playerIndex == 2) goti.path_Index = 26;
    else if (playerIndex == 3) goti.path_Index = 39;

    goti.path_Index %= 52;

    goti.x = LudoBoard.Path.path[goti.path_Index].x;
    goti.y = LudoBoard.Path.path[goti.path_Index].y;
}


bool gamePlay::isSafe(int r, int c) {

    SafeCell temp(r, c);

    for (int i = 0; i < 8; i++) {
        if (*cell[i] == temp)
            return true;
    }
    return false;
}


void gamePlay:: killOpponent(int currentPlayer) {

    for (int p = 0; p < totalPlayers; p++) {
        if (p == currentPlayer) continue;

        for (int i = 0; i < 4; i++) {

            pieces& enemyGoti = players[p].p[i];
            if (enemyGoti.finished || !enemyGoti.OpenCheck) continue;

            for (int j = 0; j < 4; j++) {

                pieces& goti = players[currentPlayer].p[j];

                if (goti.x == enemyGoti.x && goti.y == enemyGoti.y) {

                    if (isSafe(enemyGoti.x, enemyGoti.y)) return;

                    enemyGoti.OpenCheck = false;
                    enemyGoti.inHome = false;
                    enemyGoti.homeIndex = -1;
                    enemyGoti.path_Index = -1;

                    if (p == 0) { enemyGoti.x = 2; enemyGoti.y = 3; }
                    else if (p == 1) { enemyGoti.x = 2; enemyGoti.y = 11; }
                    else if (p == 2) { enemyGoti.x = 11; enemyGoti.y = 11; }
                    else if (p == 3) { enemyGoti.x = 11; enemyGoti.y = 3; }

                    std::cout << "Piece KILLED!\n";
                }
            }
        }
    }
}

void gamePlay:: play() {

    int currentPlayer = 0;
    int chaka;

    while (true) {

        draw();
        std::cout << "Current Player:     ";

        if (currentPlayer == 0) std::cout << "GREEN" << endl;
        else if (currentPlayer == 1) std::cout << "YELLOW" << endl;
        else if (currentPlayer == 2) std::cout << "RED" << endl;
        else std::cout << "BLUE" << endl;

        system("pause");

        chaka = chaka_ghuma();
        std::cout << "Dice: " << chaka << endl;

        std::cout << "Select Goti (1-4): ";
        int pieceIndex;
        std::cin >> pieceIndex;
        pieceIndex--;

        if (pieceIndex < 0 || pieceIndex >= 4) {
            std::cout << "Invalid!" << endl;
            continue;
        }

        pieces& goti = players[currentPlayer].p[pieceIndex];

        if (goti.finished) {
            std::cout << "Already finished" << endl;
            continue;
        }

        if (!goti.OpenCheck) {
            if (chaka == 6) {
                openPiece(goti, currentPlayer);
                killOpponent(currentPlayer);
            }
            else {
                currentPlayer = (currentPlayer + 1) % totalPlayers;
                continue;
            }
        }
        else {

            safeMove(goti, chaka, currentPlayer);
            killOpponent(currentPlayer);
        }

        bool win = (players[currentPlayer].p[0].finished && players[currentPlayer].p[1].finished && players[currentPlayer].p[2].finished && players[currentPlayer].p[3].finished);

        if (win) {
            std::cout << "Player "; 
            if (currentPlayer == 0) {
				cout << "GREEN Won!" << endl;
            }
            else if (currentPlayer == 1) {
				cout << "YELLOW Won!" << endl;
            }
            else if (currentPlayer == 2) {
                cout << "RED Won!" << endl;
            }
            else if (currentPlayer == 3) {
                cout << "Blue Won!" << endl;
            }
                
                
                
            exit(0);
        }

        if (chaka != 6)
            currentPlayer = (currentPlayer + 1) % 4;
        else
            std::cout << "Bonus Turn!" << endl;
    }
}
