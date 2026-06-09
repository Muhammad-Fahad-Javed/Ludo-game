#pragma once
#include"cell.h"
class SafeCell : public Cell {
public:
    SafeCell(int r = 0, int c = 0) : Cell(r, c) {}
    bool isSafe() override;
	bool operator == (Cell& C) override;
    
};
