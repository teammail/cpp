#include <iostream>

using namespace std;

// Базовый класс: Фигура
class Shape {
  // Имя фигуры (строка)
  char *name; // Обязательно private
};

// Наследники Shape:
class Point
  // Конструктор

class Line
// Внутри 2 точки
  // Конструктор

class Circle
// Одна точка и радиус
  // Конструктор

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
