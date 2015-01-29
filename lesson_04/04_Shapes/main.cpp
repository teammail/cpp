#include <iostream>

using namespace std;

// Базовый класс: Фигура
class Shape {
  // Имя фигуры (строка)
  char *name; // Обязательно private
protected:
  // Конструктор для вызова из наследников
  Shape(char *name = NULL) : name(name) {
  }
  // Каждая фигура показывает своё имя
  void show(){
    if(name != NULL){
      cout << name << " ";
    }
  }
};

// Наследники Shape:
class Point : protected Shape {
  double x, y;
public:
  // Конструктор
  Point(char *name, double x, double y) :
      Shape(name), x(x), y(y) {
  }
  void show(){
    cout << "Point ";
    Shape::show();
    cout << "  x = " << x << " y = " << y << endl;
  }
};

class Line : protected Shape {
  // Внутри 2 точки
  Point a, b;
public:
  // Конструктор
  Line(char *name, Point a, Point b) :
    Shape(name), a(a), b(b){
  }
};

class Circle : protected Shape {
  // Одна точка и радиус
  Point center;
  double radius;
  // Конструктор
public:
  Circle(char *name, Point center, double radius) :
    Shape(name), center(center), radius(radius){
  }
};

// Везде метод show() -> показывает свойства фигуры

int main() {
  Point A("A", 1.2, 2.1), B("B", 5, 6);
  Line line1("AB", A, B);
  Circle c1("CircleA", A, 5.0),
    c2("CircleB", B, 7.2);
  A.show(); B.show();
  line1.show();
  c1.show();
  c2.show();

  return 0;
}
