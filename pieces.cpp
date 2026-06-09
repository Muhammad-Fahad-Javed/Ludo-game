#include "pieces.h"

pieces& pieces:: operator++() {
    if (path_Index != -1)
        path_Index = (path_Index + 1) % 52;

    return *this;
}