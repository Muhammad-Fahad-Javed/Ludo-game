#pragma once
class Cell {
public:
    int x, y;
    Cell(int r = 0, int c = 0) : x(r), y(c) {}
    virtual bool isSafe() = 0;
    virtual bool operator == (Cell& C) = 0;
    virtual ~Cell() {}
};
