
#ifndef BOTUART_H
#define BOTUART_H
#include "API.h"
#include "gameobject.h"
// #include <stdio.h>
//#include <string>
//#include <iostream>
//#include <vector>


class botUart{
private:
  gameobject* yellow;
  gameobject* red;
  gameobject* blue;
  char workingData[100];
  char finishedData[100];
  char* rcvChar;
  int arrCount;
  bool finalNum = false;

public:

  botUart();
  // void allocatePls(){
  //   // mudafuckinptr = (char*) malloc (sizeof(char)*51);
  //   this->workingData = (char*) malloc (sizeof(char)*51);
  //   this->finishedData = (char*) malloc (sizeof(char)*51);
  // }
  int pow(int base, int exp);

  void setObVals();
  void printSizeOf();
  void printObVals();
  void printStr();
  void clearFinArr();
  void clearFinArr(int num);
  void clearWorkArr();
  void clearWorkArr(int num);
  void readData();
  void runUART();
};
#endif
