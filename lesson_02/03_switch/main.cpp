#include <iostream>

using namespace std;

int main()
{
    //system("chcp(65001)");

    // N < 0 => ошибка
    // 0 углов => пустота
    // 1 угол => точка
    // 2 угла => отрезок
    // 3 угла => треугольник
    // 4 угла => четырёхугольник
    // N >= 5 углов => N-угольник
    int N;
    cout << "Enter number of edges: ";
    cin >> N;

    switch(N){
    case 0:
        cout << "emptiness" << endl;
        break;
    case 1:
        cout << "point" << endl; // Точка
        cout << "..." << endl;
        break;
       //...
       //cout << "segment"
    default:
        cout << ((N < 0) ? "error" : "N-edged polygon") << endl;
    }

    //cout << "N-угольник" << endl;

    return 0;
}
