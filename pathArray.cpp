#include"pathArray.h"

void path_array::SetPath() {
    //green
    homePath[0][0].set(7, 1);
    homePath[0][1].set(7, 2);
    homePath[0][2].set(7, 3);
    homePath[0][3].set(7, 4);
    homePath[0][4].set(7, 5);
    homePath[0][5].set(7, 6);

    //yellow
    homePath[1][0].set(1, 7);
    homePath[1][1].set(2, 7);
    homePath[1][2].set(3, 7);
    homePath[1][3].set(4, 7);
    homePath[1][4].set(5, 7);
    homePath[1][5].set(6, 7);

    //red
    homePath[2][0].set(7, 13);
    homePath[2][1].set(7, 12);
    homePath[2][2].set(7, 11);
    homePath[2][3].set(7, 10);
    homePath[2][4].set(7, 9);
    homePath[2][5].set(7, 8);

    //blue
    homePath[3][0].set(13, 7);
    homePath[3][1].set(12, 7);
    homePath[3][2].set(11, 7);
    homePath[3][3].set(10, 7);
    homePath[3][4].set(9, 7);
    homePath[3][5].set(8, 7);

    path[0].set(6, 1);//green start
    path[1].set(6, 2);
    path[2].set(6, 3);
    path[3].set(6, 4);
    path[4].set(6, 5);
    path[5].set(5, 6);
    path[6].set(4, 6);
    path[7].set(3, 6);
    path[8].set(2, 6);
    path[9].set(1, 6);
    path[10].set(0, 6);
    path[11].set(0, 7);//yellow last cell
    path[12].set(0, 8);
    path[13].set(1, 8);//yellow start
    path[14].set(2, 8);
    path[15].set(3, 8);
    path[16].set(4, 8);
    path[17].set(5, 8);
    path[18].set(6, 9);
    path[19].set(6, 10);
    path[20].set(6, 11);
    path[21].set(6, 12);
    path[22].set(6, 13);
    path[23].set(6, 14);
    path[24].set(7, 14);// red last cell
    path[25].set(8, 14);
    path[26].set(8, 13);//red start
    path[27].set(8, 12);
    path[28].set(8, 11);
    path[29].set(8, 10);
    path[30].set(8, 9);
    path[31].set(9, 8);
    path[32].set(10, 8);
    path[33].set(11, 8);
    path[34].set(12, 8);
    path[35].set(13, 8);
    path[36].set(14, 8);
    path[37].set(14, 7);// blue last cell
    path[38].set(14, 6);
    path[39].set(13, 6);//blue start
    path[40].set(12, 6);
    path[41].set(11, 6);
    path[42].set(10, 6);
    path[43].set(9, 6);
    path[44].set(8, 5);
    path[45].set(8, 4);
    path[46].set(8, 3);
    path[47].set(8, 2);
    path[48].set(8, 1);
    path[49].set(8, 0);
    path[50].set(7, 0);//green last cell
    path[51].set(6, 0);
}