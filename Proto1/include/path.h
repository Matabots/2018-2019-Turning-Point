#ifndef PATH_H
#define PATH
#include "vector.h"
#include <vector>
#include <API.h>
#include "math.h"
class path{

private:
  std::vector<CartesianVector> waypointList;
  int minStep;
  int maxStep;
public:
  path();
  path(CartesianVector initialPos);
  path(double x, double y, int timeStamp);
  std::vector<CartesianVector> get_waypointList();
  int size();
  void addWaypoint(CartesianVector vector);
  void fillWaypointList(CartesianVector pos, CartesianVector targetPos, double step = 0);
  CartesianVector get_waypointAt(int index);
  void set_minStep(int minStep);
  int get_minStep();
  void set_maxStep(int maxStep);
  int get_maxStep();
  void printWaypoints();
};

#endif
