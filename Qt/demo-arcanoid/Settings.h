#pragma once
#include <vector>

// Настройки игры

class Settings final {
public:
    // Сложности
    enum class difficults {
        EASY,
        NORMAL,
        HARD,
        INSANE
    };

    // Текстуры шарика

    enum class ball_skins
    {
        BLUE,
        YELLOW,
        GREEN,
        RED
    };

    // Текстуры кирпичей
    enum class bricks_skins {
        BLUE,
        GOLD,
        RED,
        WHITE
    };
private:
    difficults _difficult;       // Сложность игры: задает скорость шарика и количество жизней
    ball_skins _ballSkin;        // Определяет текстуру шарика
    bricks_skins _bricksSkin;    // Определяет текстуры кирпичиков
    size_t _background;          // Определяет фон
    size_t _currentLevel;        // Текущий уровень

   
public:

    // Константы

    constexpr static const double EASY_BALL_SPEED   = 2.0;      // Скорость шарика на уровне сложности EASY
    constexpr static const double NORMAL_BALL_SPEED = 4.0;      // Скорость шарика на уровне сложности NORMAL
    constexpr static const double HARD_BALL_SPEED   = 6.0;      // Скорость шарика на уровне сложности HARD
    constexpr static const double INSANE_BALL_SPEED = 8.0;     // Скорость шарика на уровне сложности INSANE

    constexpr static const int EASY_LIVES_COUNT     = 3;        // Количество жизней на уровне сложности EASY
    constexpr static const int NORMAL_LIVES_COUNT   = 2;        // Количество жизней на уровне сложности NORMAL
    constexpr static const int HARD_LIVES_COUNT     = 1;        // Количество жизней на уровне сложности HARD
    constexpr static const int INSANE_LIVES_COUNT   = 0;        // Количество жизней на уровне сложности INSANE

public:
  
    // Конструктор по умолчанию (Сложность - NORMAL, текстура шарика - RED, текстура кирпичика - RED, фон - 0 (первый) )
    Settings();

    /**
     * Запрещённый конструктор копирования.
     */
    Settings(const Settings &) = delete;

    /**
     * Запрещённый оператор присваивания копированием.
     */
    Settings &operator=(const Settings &) = delete;

    // Получение текущей сложности
    difficults difficult() const;

    // Получение текущей текстуры шарика
    ball_skins ballSkin() const;

    // Получение текущей текстуры кирпичика
    bricks_skins bricksSkin() const;

    // Получение текущего фона
    size_t background() const;

    // Получение текущего ID уровня
    size_t level() const;

    // Установка новой сложности
    void setDifficult(difficults newDifficult);

    // Установка новой текстуры шарика
    void setBallSkin(ball_skins newBallSkin);

    // Установка новой текстуры кирпичика
    void setBricksSkin(bricks_skins newBricksSkin);

    // Установка нового фона
    void setBackground(size_t newBackground);

    // Установка нового уровня
    void setLevel(size_t levelID);
};
