#include "botUart.h"

botUart::botUart()
{
  this->yellow = new gameobject();
  this->red =  new gameobject();
  this->blue =  new gameobject();
  usartInit(uart1, 9600, SERIAL_DATABITS_8);
  // this->rcvChar =(uint8_t*) malloc (sizeof(uint8_t)*1);
  this->arrCount = 0;
  // clearFinArr();
  // clearWorkArr();
};

int botUart::pow(int base, int exp)
{
  if(exp == 0)
  {
    return 1;
  }
  else if (exp % 2)
  {
    return base * pow(base, exp - 1);
  }
  else
  {
    int tmp = pow(base, exp / 2);
    return tmp * tmp;
  }

}
void botUart::setObVals()
{
  int i = 0;
  int comCnt = 0;
  int powNum = 0;
  int numTot = 0;

  while(this->finishedData[i] != '&')
  {
    //  printf("in loop\n");
    // printf("Character is currently: %c\n",this->finishedData[i]);
    i++;
  }
  //printf("STOPPED, ENCOUNTERED '&'\n");
  i--; //i is at the index of the first encountered &;
  while(i > -1)
  {
    if(this->finishedData[i] != ',')
    {
      char tmp = ((char)this->finishedData[i] - '0');
      int tmp2 = (int)tmp;
      // printf("%d",tmp2);
      // printf("%d\n",tmp);
      numTot = numTot + (tmp2 * pow(10, powNum));
      // numTot = numTot + ((this->finishedData[i]) * pow(10, powNum));
      powNum++;
    }
    else
    {
      switch(comCnt)
      {
        case 0:
          this->red->setY(numTot);
          break;
        case 1:
          this->red->setX(numTot);
          break;
        case 2:
          this->blue->setY(numTot);
          break;
        case 3:
          this->blue->setX(numTot);
          break;
        case 4:
          this->yellow->setY(numTot);
          break;
        case 5:
          this->yellow->setX(numTot);
          break;
        default:
          printf("%s\n", "End of string.");
          break;
      }
      comCnt++;
      powNum = 0;
      numTot = 0;
    }
    i--;
  }
}
void botUart::printSizeOf()
{
  printf("%d\n",sizeof(this->yellow));
}
void botUart::printObVals()
{
  printf("%d,%d,%d,%d,%d,%d--\n\n",this->yellow->getX(),this->yellow->getY(),this->blue->getX(),this->blue->getY(),this->red->getX(),this->red->getY());
}

void botUart::printStr()
{
  int i = 0;
  // printf("%c", 't');
  while (this->finishedData[i] != '&')
  {
    // printf("%c", 't');
    printf("%c", this->finishedData[i]);
    i++;
  }
  printf("\n");
}

void botUart::clearFinArr()
{
  int z = 0;
  while(z < 20)
  {
    (this->finishedData[z]) = '&';
    z++;
  }
}
void botUart::clearFinArr(int num)
{
  int i = num;
  while(i < 99)
  {
    this->finishedData[i] = '&';
    i++;
  }
}
void botUart::clearWorkArr()
{
  int i = 0;
  while(i < 99)
  {
    this->workingData[i] = '&';
    i++;
  }
}
void botUart::clearWorkArr(int num)
{
  int i = num;
  while(i < 99)
  {
    this->workingData[i] = '&';
    i++;
  }
}

void botUart::readData()
{
  int i = 0;
  // this->workingData = (char*) malloc (sizeof(char)*100);
  // this->finishedData = (char*) malloc (sizeof(char)*100);
  fgets(this->workingData, 50, uart1);
  // printf("tits\n");
  // printf("%d\n", sizeof(mudafuckinptr));
  //printf("%d\n", sizeof(*finishedData));
  //fread(this->rcvChar,sizeof(uint8_t),1,uart1);
  // printf("%c\n", (char)*this->rcvChar);
  // if(*this->rcvChar == '&')
  // {
    // this->finishedData = this->workingData;
    clearFinArr();
    while(i < 99)
    {
      if(this->workingData[i] == '&'){
       i=100;
      }else{
        this->finishedData[i] = this->workingData[i];
        i++;
      }
    }
    clearFinArr(i);
    clearWorkArr();
    this->arrCount = 0;
    // delete workingData;
    // delete finishedData;
  }
  // else
  // {
  //   this->workingData[this->arrCount] = *this->rcvChar;
  //   // this->workingData = this->workingData + this->rcvChar;
  //   this->arrCount++;
  // }
// };
// void request(int objectId){
//   switch(objectId):
//     case 1:
//       break;
//     case 2:
//       break;
//     case 3:
//       break;
// }

// void read(){
//   fgets(this->rcvChar, 50, uart1);
//   printf("%s\n", this->rcvChar);
// }
void botUart::runUART()
{
  printf("anything\n");
  readData();
  setObVals();
  printObVals();
}
