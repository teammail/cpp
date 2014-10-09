#include <iostream>

long long factorial(int n){
  long long res = 1;
  for(int i = n; i > 1; --i)
    res *= i;
  return res;
}

using namespace std;

int main() {
  for(int i = 1; i <= 100; ++i){
    long long res = factorial(i);
    cout << i << "! = " << res << endl;
  }
  return 0;
}
