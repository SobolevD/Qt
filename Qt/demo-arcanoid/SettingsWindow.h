#pragma once

#include <QWidget>

#include "BackgroundWindow.h"
#include "BallSkinWindow.h"
#include "BricksSkinWindow.h"
#include "Arcanoid.h"

#include "Settings.h"

/**
 * Окно для отображения и возможного изменения настроек.
 */
class SettingsWindow : public QWidget {

Q_OBJECT

private:

    Settings &_settings; // Настройки игры

private slots:

    void setDifficultEasy();
    void setDifficultNormal();
    void setDifficultHard();
    void setDifficultInsane();

    void openBackgroundWindow();
    void openBallSkinWindow();
    void openBricksSkinWindow();

    void startGame();

public:

    /**
     * Конструктор.
     *
     * @param settings Настройки для отображения и возможного изменения.
     */
    explicit SettingsWindow(Settings &settings);

    /**
     * Запрещённый конструктор копирования.
     */
    SettingsWindow(const SettingsWindow &) = delete;

    /**
     * Запрещённый оператор присваивания копированием.
     */
    SettingsWindow &operator=(const SettingsWindow &) = delete;

};
