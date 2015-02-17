#include <QCoreApplication>
#include <cassert>

// bits - количество бит на число
// size - размер массива
template <int bits, int size>
class PackedArray {
  unsigned char data[(size * bits + 7) / 8];
public:
  void setValue(int index, int value){
    int bitNo = index * bits;
  }
  int getValue(int index){

  }
};


int main(int argc, char *argv[]) {
  QCoreApplication a(argc, argv);

  PackedArray<1,8> pa;
  for(int i = 0; i < 8; ++i)
    for(int v = 0; v <= 1; ++v){
      pa.setValue(i, v);
      assert(pa.getValue(i) == v);
    }

  return a.exec();
}
