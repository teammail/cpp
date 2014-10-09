#include <iostream>

using namespace std;

typedef double MyType;

union InMemory {
   MyType value;
   unsigned char bytes[sizeof(MyType)];
};

int main()
{
   InMemory m;
   m.value = 0.3;
   for(int i = 0; i < sizeof(MyType); ++i){
     int byte = (MyType)m.bytes[i];
     for(int bit = 7; bit >= 0; --bit){
       cout << ((byte >> bit) & 1);
     }
     cout << " " << byte << endl;
   }

   return 0;
}
