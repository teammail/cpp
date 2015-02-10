// Перечисления
#include <iostream>

using namespace std;

// Направления
const int X_UP = 0;
const int X_DOWN = 1;
const int X_LEFT = 2;
const int X_RIGHT = 3;
int direction = X_UP;

enum Direction {
  UP = 4 /* 0 */, DOWN = 13 /* 1 */,
  LEFT = (1LL << 31) - 1 /* 2 */, RIGHT = 7/* 3 */
};

enum DirectionX {
  T_UP /* 0 */, T_DOWN /* 1 */,
  T_LEFT /* 2 */, T_RIGHT /* 3 */
};

#pragma pack(1)

struct S {
  DirectionX dir1:2;
  DirectionX dir2:2;
  DirectionX dir3:2;
  DirectionX dir4:2;
  /*DirectionX dir5:2;
  DirectionX dir6:2;
  DirectionX dir7:2;
  DirectionX dir8:2;
  DirectionX dir9:2;
  DirectionX dir10:2;
  DirectionX dir11:2;
  DirectionX dir12:2;
  DirectionX dir13:2;
  DirectionX dir14:2;
  DirectionX dir15:2;
  DirectionX dir16:2;

  DirectionX dir17:2; */
} __attribute__((gcc_struct, __packed__));

//#pragma pack(4)

Direction directionEnum = UP;

#define SHOW(x) { cout << #x << " = " << x << endl; }


enum DirectionXX {
  XX_UP = 4, XX_DOWN /* 5 */,
  XX_LEFT /* 6 */, XX_RIGHT /* 7 */
};

int main(int argc, char *argv[])
{
  SHOW(sizeof(S));

  direction = X_DOWN;
  directionEnum = DOWN;

  if(direction == DOWN){

  }
  switch(direction){
    case X_UP:
    case X_LEFT:
      break;
  }

  switch(directionEnum){
    case UP:
       ;
 // case DOWN:
   //   ;
  }
  directionEnum = LEFT;
  cout << "LEFT =  " <<  directionEnum << endl;
  directionEnum = UP;
  cout << "UP =  " <<  directionEnum << endl;

  SHOW(XX_UP);
  SHOW(XX_LEFT);

  return 0;
}
