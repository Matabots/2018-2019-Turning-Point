
// GLOBAL VARIABLES
const int diameter = 4; // inches
const int tile_length = 24; // inches
const float pi = 22 / 7;    // 3.14159...
const float circumference = (pi * diameter);     // the total distance one full rotation of the wheel covers (inches)
const float rotations_per_tile = (tile_length / circumference);    // the number of rotations the wheel makes to cover one tile
const float radius_of_robot = 5.5;            // this is the length from the center of the robot to the wheel (in inches)
const float RobotCircumference = (2 * pi * radius_of_robot);    // this is the circumference of the circle that would be made by a turning robot
float target;   // desired distance
float Rcurrent, Lcurrent, tolerance;
int weight, MinPower;
int DirectionFacing = 2;

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
    {  0, 0, 0, 0, 0, 0 },
    { 99, 0, 1, 1, 0, 2 },
    {  0, 0, 1, 1, 0, 0 },
    {  0, 0, 0, 0, 0, 0 },
    {  0, 0, 0, 0, 0, 0 }
};


float degToInch(int degree)
{
    float inch = ((4 * pi) * (degree/360));
    return inch;
}

bool nearTol(float Rcurrent, float Lcurrent, float target, float tolerance)     // checks whether value of encoder is within tolerance
{
    bool check = true;
    if((Rcurrent <= (target - tolerance) || Rcurrent >= (target + tolerance)) && (Lcurrent <= (target - tolerance) || Lcurrent >= (target + tolerance)))
    {
        check = false;
    }
    return check;
}  

void move(float distance)
{
    SensorValue[REncoder] = 0;
    SensorValue[LEncoder] = 0:
    target = (distance);
    Rcurrent = degToInch(SensorValue[REncoder]);    // current distance
    Lcurrent = degToInch(SensorValue[LEncoder]);
    weight = 15;
    tolerance = 1;    // inches
    MinPower = 25;    // Minimum power for Motor
    while(nearTol(Rcurrent, Lcurrent, target, tolerance))
    {
        Rcurrent = degToInch(SensorValue[REncoder]);
        Lcurrent = degToInch(SensorValue[LEncoder]);

        motor[RMotor] = (target - Rcurrent) * weight;
        motor[LMotor] = (target - Lcurrent) * weight;
        if((abs(motor[RMotor]) && abs(motor[LMotor]) < MinPower)
        {

            if((motor[RMotor] && motor[LMotor]) > 0)
            {
                motor[RMotor] = MinPower;
                motor[LMotor] = MinPower;
            }
            else if ((motor[RMotor] && motor[LMotor]) < 0)
            {
                motor[RMotor] = -MinPower;
                motor[LMotor] = -MinPower;
            }
        }
    }
    motor[RMotor] = 0;
    motor[LMotor] = 0;
    SensorValue[REncoder] = 0;
    SensorValue[LEncoder] = 0:

}

void turn(int NumofDegrees)
{
    SensorValue[REncoder] = 0;
    SensorValue[LEncoder] = 0:
    target = (RobotCircumference / 360) * NumofDegrees;
    Rcurrent = degToInch(SensorValue[REncoder]);
    Lcurrent = degToInch(SensorValue[LEncoder]);
    weight = 5;
    tolerance = 3.8;    // inches
    MinPower = 18;        // Minimum power for Motor
    while(nearTol(Rcurrent, Lcurrent, target, tolerance))
    {
        Rcurrent = degToInch(SensorValue[REncoder]);
        Lcurrent = degToInch(SensorValue[LEncoder]);

        motor[RMotor] = -((target - Rcurrent) * weight);
        motor[LMotor] = ((target - Lcurrent) * weight);
        if((abs(motor[RMotor]) && abs(motor[LMotor]) < MinPower)
        {
            if((motor[RMotor] > 0) && (motor[LMotor] > 0))
            {
                motor[RMotor] = -MinPower;
                motor[LMotor] = MinPower;
            }
            else if ((motor[RMotor] < 0) && (motor[LMotor]) < 0))
            {
                motor[RMotor] = MinPower;
                motor[LMotor] = -MinPower;
            }
        }
    }
    motor[RMotor] = 0;
    motor[LMotor] = 0;
    SensorValue[REncoder] = 0;
    SensorValue[LEncoder] = 0:

}

void faceDirection(int DirectionFacing, int GoalDirection)
{
    // N = 1, E = 2, S = 3, W = 4
    int DirectionToTurn = DirectionFacing - GoalDirection;
    switch(DirectionToTurn)
    {
    case 1:
    case -3:
        turn(-90);
        break;
    case -1:
    case 3:
        turn(90);
        break;
    case 2:
    case -2:
        turn(180);
        break;
    default:
        break;
    }
    DirectionFacing = GoalDirection;
}


void PrintField()
{
   for(int i = 0; i < X_size; i++)
   {
    printf(" [ ");
    for(int j = 0; j < Y_size; j++)
    {
        if(field[i][j] == 2)
        {
            printf(" G ");
        }
        else if(field[i][j] == 99)
        {
            printf(" R ");
        }
        else if(field[i][j] == -1)
        {
            printf(" * ");
        }
        else
        {
            printf(" %i ", field[i][j]);
        }
    }
    printf(" ] \n");
   }
   print("\n\n");
}

void MakePaths()
{
    int goal_x, goal_y;
    int stepsValue = 2;
    bool check = true;

    // FIND GOAL
    while(check == true)
    {
        check = false;
        for(int i = 0; i < X_size; i++)
        {
            for(int j = 0; j < Y_size; j++)
            {
                if(field[i][j] == stepsValue)    // If Goal is found
                {
                    check = true;
                    goal_x = i;
                    goal_y = j;
                    // Increment values around stepsValue
                    if((field[goal_x-1][goal_y] == 0) && (goal_x >= 0))     // increment left element
                    {
                        field[goal_x-1][goal_y] == stepsValue + 1;
                    }
                    if((field[goal_x+1][goal_y] == 0) && (goal_x < (X_size-1)))   // increment right element
                    {
                        field[goal_x+1][goal_y] == stepsValue + 1;
                    }
                    if((field[goal_x][goal_y-1] == 0) && (goal_y >= 0))     // increment upward element
                    {
                        field[goal_x][goal_y-1] == stepsValue + 1;
                    }
                    if((field[goal_x][goal_y+1] == 0) && (goal_y < (Y_size-1)))   // increment downward element
                    {
                        field[goal_x][goal_y+1] == stepsValue + 1;
                    }
                    PrintField();
                    stepsValue++;
                }
             }
        }
    }
}

void TakePath()
{
    int GoalDirection;
    int nextValue = 99;
    int current_x, current_y;
    int next_x, next_y;

    while(field[current_x][current_y] != 2)
    {
        for(int i = 0; i < X_size; i++)
        {
            for(int j = 0; j < Y_size; j++)
            {
                // FIND ROBOT
                if(field[i][j] == 99)   
                {
                    current_x = i;
                    current_y = j;
                    if((field[current_x-1][current_y] != 1) && (current_x >= 0) && (field[current_x-1][current_y] < nextValue))     // check left element
                    {
                        nextValue = field[current_x-1][current_y];
                        next_x = current_x-1;
                        next_y = current_y;
                        GoalDirection = 4;
                    }
                    if((field[current_x+1][current_y] != 1) && (current_x < (X_size-1)) && (field[current_x+1][current_y] < nextValue))   // check right element
                    {
                        nextValue = field[current_x+1][current_y];
                        next_x = current_x+1;
                        next_y = current_y;
                        GoalDirection = 2;
                    }
                    if((field[current_x][current_y-1] != 1) && (current_y >= 0) && (field[current_x][current_y-1] < nextValue))     // check upward element
                    {
                        nextValue = field[current_x][current_y-1];
                        next_x = current_x;
                        next_y = current_y-1;
                        GoalDirection = 1;
                    }
                    if((field[current_x][current_y+1] != 1) && (current_y < (Y_size-1)) && (field[current_x][current_y+1] < nextValue))   // check downward element
                    {
                        nextValue = field[current_x][current_y+1];
                        next_x = current_x;
                        next_y = current_y+1;
                        GoalDirection = 3;
                    }
                    field[current_x][current_y] = -1;
                    field[next_x][next_y] = 99;
                    faceDirection(DirectionFacing, GoalDirection);
                    move(tile_length);
                    PrintField();
                }
            }
        }
    }
}

void DoPathfinding()
{
    PrintField();
    MakePaths();
    TakePath();
}

task main()
{
    DoPathfinding();
}
