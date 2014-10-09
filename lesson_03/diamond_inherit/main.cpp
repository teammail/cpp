#include <iostream>

using namespace std;

struct X {
  void show(){
    cout << "X" << endl;
  };
};

struct A {
  char name;
  A() : name('A') {};
  virtual
  void show(){
    cout << "show_A " << name << endl;
  };
};

struct B : public A {
  B() { A::name = 'B'; };
  void show(){
    cout << "show_B 643 " << 2*10 << name << endl;
  };
};

struct C : public A {
  C(){ A::name = 'C'; };
  void show(){
    cout << "show_C " << name << endl;
  };
};

struct D : public B, public C {
  D(){ B::name = 'D'; };
  void show(){
    cout << "D " << B::name << endl;
    //B::show();
    //C::show();
    //C::A::show();
  };
};

int main()
{
//  D d;
//  d.show();
  //A* x[3] = {new A, new B, new C};
  //for(int i = 0; i < 3; ++i)
   // x[i]->show();

  // Полиморфизм
  A* x[3] = { new B, new A, new C };
 /* A* x[4];
  x[0] = new C;
  x[1] = new B;
  x[2] = new A;
  x[3] = new D; */

  cout << "sizeof(X) = " << sizeof(X) << endl;
  cout << "sizeof(*X) = " << sizeof(X*) << endl;

  cout << "+ VMT" << endl;
  cout << "sizeof(A) = " << sizeof(A) << endl;
  cout << "sizeof(*A) = " << sizeof(A*) << endl;

  for(int i = 0; i < 4; ++i)
    x[i]->show();

  for(int i = 0; i < 4; ++i)
    delete x[i];

  return 0;
}
