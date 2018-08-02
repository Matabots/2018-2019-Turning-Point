#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "API.h"
class gameobject{

private:
  int x;
  int y;

public:

      gameobject();
      void setX(int x);
      int getX();
      void setY(int y);
      int getY();
};

#endif
