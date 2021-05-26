//T02_G11
#ifndef T02_G11_STRUCTS_H
#define T02_G11_STRUCTS_H

struct Position // general method for positions (robots, posts, player, ...)
{
    int row, col;
};

struct Movement // general method for moves (robots and player)
{
    int dRow, dCol;
};

#endif //T02_G11_STRUCTS_H