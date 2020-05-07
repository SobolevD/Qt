#pragma once

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <QGraphicsItem>
#include <QDir>
#include <QSize>
#include <QIcon>
#include <QMenuBar>
#include <QTimer>
#include <QAction>
#include "Settings.h"
#include <iostream>

using namespace std;
class Arcanoid : public QMainWindow {

	// Структура доски
	struct deskInfo {
		bool isAnimated;						// Есть ли сейчас анимация доски
		QPixmap picture;						// Картинка доски
		QPixmap groundPicture;					// Картинка поверхности доски
		QGraphicsPixmapItem* entity;			// Сама доска
		QGraphicsPixmapItem* groundEntity;		// Ее покрытие

		deskInfo() : isAnimated(false), entity(nullptr), groundEntity(nullptr) {}
	};

	// Шарик
	struct ballInfo {
		QPixmap _picture;						// Картинка шарика
		QGraphicsPixmapItem* entity;			// Сам шарик
		double speedX;							// Проекция скорости по X
		double speedY;							// Проекция скорости по Y
		double angle;							// Угол поворота (угол движения)

		ballInfo() : entity(nullptr) { }
	};
	
	QGraphicsPixmapItem* _backgroundItem;		// Бэкграунд
	QGraphicsPixmapItem* _livesCountItem;		// Картинка количества жизней
	QGraphicsPixmapItem* _levelCompleteItem;	// Картинка с надписью "Уровень пройден"

	vector<QGraphicsPixmapItem*> _level;		// Текущий уровень (состоит из ентити кирпичиков)

	size_t _frameWidth;							// Ширина окна

	deskInfo deskStruct;						// Структура доски

	ballInfo ballStruct;						// Структура шарика

	int _lives;									// Текущее количество жизней

	QGraphicsScene* _scene;						// Сцена
	QGraphicsView* _view;
	
	Settings& _settings;						// Настройки
	const int _timerInterval = 10;				// Интервал обновления сцены

	bool _ballFixedOnPlatform;					// Флажок: прикреплен ли мяч к доски (начальный этап)

	bool _isLevelComplete;						// Флажок: пройден ли уровень


	void mousePressEvent(QMouseEvent* event) override;	// Обработчик нажатия мышки (выброс шарика с доски)

	QGraphicsPixmapItem*			createBrick(int row, int column, double leftBorder, Settings::bricks_skins& brickType);	// Создание одного кирпичика
	vector<QGraphicsPixmapItem*>	createTestLevel(double leftBorder);														// Создание тестового уровня
	vector<QGraphicsPixmapItem*>	createThanksLevel(double leftBorder);													// Создание еще одного уровня
private slots:

	void updateScene();
	void openMainMenu();
	void restartLevel();

	// Навигация по уровням
	void goToLevel1();
	void goToLevel2();

public:
	Arcanoid(Settings& settings);
};