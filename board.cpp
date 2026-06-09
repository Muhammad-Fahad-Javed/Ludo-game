#include"board.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// COLORSs
void setColor(int fgColor, int bgColor) {
    SetConsoleTextAttribute(hConsole, (bgColor * 16) + fgColor);
}


void board:: initBoard() {

    for (int r = 0; r < 15; r++) {
        for (int c = 0; c < 15; c++) {
            label[r][c] = "   ";
            bg[r][c] = BRIGHT_WHITE;
            fg[r][c] = BLACK;
        }
    }

    // BASES
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 6; c++) bg[r][c] = GREEN;
        for (int c = 9; c < 15; c++) bg[r][c] = YELLOW;
    }

    for (int r = 9; r < 15; r++) {
        for (int c = 0; c < 6; c++) bg[r][c] = BLUE;
        for (int c = 9; c < 15; c++) bg[r][c] = RED;
    }

    // PATHS
    for (int i = 1; i < 6; i++) {
        bg[i][7] = YELLOW;
        bg[8 + i][7] = BLUE;
        bg[7][i] = GREEN;
        bg[7][14 - i] = RED;
    }

    // CENTER
    for (int r = 6; r <= 8; r++)
        for (int c = 6; c <= 8; c++)
            label[r][c] = " H ";

    // SAFE ZONES
    label[8][2] = " @ ";
    bg[6][1] = GREEN;
    label[2][6] = " @ ";
    bg[1][8] = YELLOW;
    label[6][12] = " @ ";
    bg[8][13] = RED;
    label[12][8] = " @ ";
    bg[13][6] = BLUE;


    //centre
    bg[6][6] = WHITE;
    bg[6][7] = WHITE;
    bg[6][8] = WHITE;
    bg[7][6] = WHITE;
    bg[7][7] = WHITE;
    bg[7][8] = WHITE;
    bg[8][6] = WHITE;
    bg[8][7] = WHITE;
    bg[8][8] = WHITE;
}



void board::draw(player* players, int totalPlayers) {

    system("cls");

    cout << "\t\t\t\t\tDesinged by Waleed Ahmad And Fahad Javed.\n\n";

    std::cout << "\n\t\t\t    ==== LUDO GAME ====\n\n";

    for (int r = 0; r < 15; r++) {
        std::cout << "\t";

        for (int c = 0; c < 15; c++) {

            int count = 0;
            char sym = ' ';
            int id = 0;

            for (int pl = 0; pl < totalPlayers; pl++) {
                for (int i = 0; i < 4; i++) {

                    if (players[pl].p[i].x == r && players[pl].p[i].y == c) {
                        count++;
                        sym = players[pl].symbol;
                        id = players[pl].p[i].id;
                    }
                }
            }

            setColor(BLACK, bg[r][c]);

            if (count == 1) {
                std::cout << sym << id << " ";
            }
            else if (count > 1) {
                std::cout << count << sym << " ";
            }
            else {
                std::cout << label[r][c];
            }

            setColor(WHITE, BLACK);
            std::cout << "|";
        }


        std::cout << endl;

    }

}


