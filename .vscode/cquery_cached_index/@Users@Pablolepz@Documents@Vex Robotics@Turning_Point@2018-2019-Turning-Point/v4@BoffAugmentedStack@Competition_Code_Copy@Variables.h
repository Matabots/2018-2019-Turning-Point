

int lastPost = 0;
int n =  1;
int firstCone = 80;
int secondCone = 75;
int thirdCone = 58;

float pitch;
float enc = 0;
float offSet = 126;
float minS;
float target;
float error;
float errorD;//error is the difference between the goal and current distance
float tolerance;
float toleranceD;//how accurate do I want the robot to be
float kp;
float kp2;		//Kp is a multiplier to calibrate the power
float totalError;
float totalErrorD;
float ki;
float ki2;
float targetDeg;
float deltaGyro;
float gyroVal;
float targetGyro;
float kd2;
float minGo;
float encAvg;

bool cone = false;
bool same;
bool polarity;
bool atGyro = false;
bool mobUp = false;
bool mobDown = false;
bool lineFound = false;
bool gyroOn = true;
int timeVal = 0;
int potentVal = 0;
int currentStack = 0;
