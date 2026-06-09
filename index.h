#pragma once

class index {
public:
    int x, y;
    index(int r = 0, int c = 0) {
        x = r;
        y = c;
    }
    void set(int r, int c);
    
};