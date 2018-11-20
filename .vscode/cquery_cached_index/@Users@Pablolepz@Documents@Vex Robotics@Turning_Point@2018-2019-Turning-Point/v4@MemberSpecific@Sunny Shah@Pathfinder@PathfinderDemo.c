#include "PathfinderMethods.c"
#include "PathfinderPID.c"

// SET FIELDS
//  0 == Open / Empty Space
//  1 == Obstacle
//  2 == Goal / Target
// 99 == Robot
const int X_size = 6;
const int Y_size = 6;
int field[X_size][Y_size] = 
{
    {  0, 0, 0, 0, 0, 0 },
    {  0, 0, 0, 1, 0, 0 },
    {  0, 1, 0, 0, 0, 2 },
    {  0, 1, 1, 1, 1, 0 },
    { 99, 0, 1, 0, 0, 0 },
    {  1, 0, 0, 1, 0, 1 }
};

task main()
    {
        DoPathfinding();
        return 0;
    }