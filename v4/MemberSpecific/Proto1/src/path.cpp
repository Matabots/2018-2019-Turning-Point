#include "path.h"
  path::path(){
    this->minStep = 0;
    this->maxStep = 10;
  };
  path::path(CartesianVector initialPos){
    this->waypointList.push_back(initialPos);
    this->minStep = 0;
    this->maxStep = 10;
  };
  path::path(double x, double y, int timeStamp){
    CartesianVector initialPos;
    initialPos.x = x;
    initialPos.y = y;
    initialPos.timeStamp = timeStamp;
    this->waypointList.push_back(initialPos);
    this->minStep = 0;
    this->maxStep = 1000;
  };
  std::vector<CartesianVector> path::get_waypointList(){
    return this->waypointList;
  };
  int path::size(){
    return this->waypointList.size();
  }
  void path::addWaypoint(CartesianVector vector){
    this->waypointList.push_back(vector);
  };

  void path::fillWaypointList(CartesianVector pos, CartesianVector targetPos, double step){
    double xShift = targetPos.x - pos.x;
    double yShift = targetPos.y - pos.y;

    if(abs(step) < abs(this->minStep)){
      step = this->minStep;
    }
    if(abs(step) > abs(this->maxStep)){
      step = this->maxStep;
    }

    int length = (int)(sqrt(pow(abs(xShift),2)+pow(abs(yShift),2))/step);
    xShift = (xShift/abs(xShift))*step;
    printf("xShift: %f\n",xShift);
    yShift = (yShift/abs(yShift))*step;

    CartesianVector tempPos;
    tempPos.x = pos.x;
    tempPos.y = pos.y;
    for(int i=1;i<length+1;i++){
        tempPos.x += xShift;
        tempPos.y += yShift;
        if(abs(tempPos.x)>abs(targetPos.x)){
          tempPos.x = targetPos.x;
        }
        if(abs(tempPos.y)>abs(targetPos.y)){
          tempPos.y = targetPos.y;
        }
        addWaypoint(tempPos);
    }
  };

  CartesianVector path::get_waypointAt(int index){
      return this->waypointList[index];
  };

  void path::set_minStep(int minStep){
    this->minStep = minStep;
  };
  int path::get_minStep(){
    return this->minStep;
  };
  void path::set_maxStep(int maxStep){
    this->maxStep = maxStep;
  };
  int path::get_maxStep(){
    return this->maxStep;
  };
  void path::printWaypoints(){

    for(int i =0;i<(int)(this->waypointList.size());i++){

      printf(" %f,", get_waypointAt(i).x);
      printf("\n");
    }
  };
