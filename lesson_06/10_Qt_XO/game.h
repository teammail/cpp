#ifndef GAME_H
#define GAME_H

#include <QString>
#include <QFile>
#include <vector>

// Состояние игры
enum State {
    X_MOVE, // Ход крестиков
    O_MOVE, // Ход ноликов
    X_WIN,  // Крестики выйграли
    O_WIN,  // Нолики выйграли
    DRAW    // Ничья
};

// Размер поля игры
extern int MapSize;
//const int MapSize = 3;

/*enum E {
    a = 1,
    b = 20
};*/

// Все что происодит на поле и логика игрового мира
// Ходы, выйгрыш/проигрыш
class Game
{
    State state; // Текущее состояние игры
    std::vector<std::vector<char> >
      Map; // Игровое поле
    // Проверка выйгрыша
    void line(std::vector<char> a);
public:
    // Конструктор
    Game();
    // Новая игра без пересоздания объекта
    void newGame();
    // Получаем строку, соответствующую состоянию игры
    QString getStateString();
    // Совершаем ход, возвращает строку для клетки на форме
    QString makeMove(int row, int col);
    // Проверяем на окончание игры
    void checkGameOver();
    // Сохранение игры
    void save(QString fileName);
    // Загрузка игры
    void load(QString fileName);
    // Состояние ячейки
    const char* getCell(int i, int j);
};

#endif // GAME_H
