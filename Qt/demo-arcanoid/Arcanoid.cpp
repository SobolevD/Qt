#include "Arcanoid.h"
#include <QMouseEvent>
#include <QCursor>
#include "SettingsWindow.h"
	
// Создатель кирпичиков

QGraphicsPixmapItem* Arcanoid::createBrick(int row, int column, double leftBorder, Settings::bricks_skins& brickType) {
	
	// Расстояние между кирпичами
	const int distance = 15;

	// Текстура кирпича
	QPixmap brickPicture;

	// Выбор текстуры кирпича в зависимости от настроек
	switch (brickType) {
		case Settings::bricks_skins::BLUE : {
			brickPicture = QPixmap("resources/bricks/blue_brick.png");
			break;
		}
		case Settings::bricks_skins::GOLD : {
			brickPicture = QPixmap("resources/bricks/gold_brick.png");
			break;
		}
		case Settings::bricks_skins::RED : {
			brickPicture = QPixmap("resources/bricks/red_brick.png");
			break;
		}
		case Settings::bricks_skins::WHITE : {
			brickPicture = QPixmap("resources/bricks/white_brick.jpg");
			break;
		}
	}

	// Уменьшим кирпич до размера размер шарика в высоту и два размера шарика в ширину
	brickPicture = brickPicture.scaled(ballStruct._picture.width() * 2, ballStruct._picture.height());

	// Создадим кирпич на сцене
	QGraphicsPixmapItem* brickEntity = new QGraphicsPixmapItem(brickPicture);
	brickEntity->setPos(leftBorder + distance + column * (brickPicture.width() + distance), distance + row * (brickPicture.height() + distance));
	return brickEntity;
}

// Создадим уровень из кирпичей
vector<QGraphicsPixmapItem*> Arcanoid::createTestLevel(double leftBorder) {

	// Количество умещающихся кирпичей в строку
	const int MAX_BRICKS_IN_ROW	= 26;

	// Количество столбцов
	const int BRICKS_IN_COLUMN	= 8;

	// Текущий скин кирпичика
	Settings::bricks_skins brickSkin;

	// Создаем кирпичи с определенным положением
	for (auto j = 0; j < BRICKS_IN_COLUMN; ++j) {
		if (j == 0 || j == 1) brickSkin = Settings::bricks_skins::BLUE;
		if (j == 2 || j == 3) brickSkin = Settings::bricks_skins::GOLD;
		if (j == 4 || j == 5) brickSkin = Settings::bricks_skins::RED;
		if (j == 6 || j == 7) brickSkin = Settings::bricks_skins::WHITE;
		for (auto i = 0; i < MAX_BRICKS_IN_ROW; ++i) {
			_level.push_back(createBrick(j, i, leftBorder, brickSkin));
			_scene->addItem(_level.back());
		}
	}
	return _level;
}

// Спец уровень
vector<QGraphicsPixmapItem*> Arcanoid::createThanksLevel(double leftBorder) {

	// Количество умещающихся кирпичей в строку
	const int MAX_BRICKS_IN_ROW = 26;

	// Текущий скин кирпичика
	Settings::bricks_skins brickSkin = Settings::bricks_skins::GOLD;

	// Макет уровня
	{
		// row 1
		_level.push_back(createBrick(0, 1, leftBorder, brickSkin));
		_level.push_back(createBrick(0, 3, leftBorder, brickSkin));
		_level.push_back(createBrick(0, 4, leftBorder, brickSkin));
		_level.push_back(createBrick(0, 5, leftBorder, brickSkin));
		_level.push_back(createBrick(0, 8, leftBorder, brickSkin));
		_level.push_back(createBrick(0, 12, leftBorder, brickSkin));
		_level.push_back(createBrick(0, 14, leftBorder, brickSkin));
		_level.push_back(createBrick(0, 16, leftBorder, brickSkin));
		_level.push_back(createBrick(0, 19, leftBorder, brickSkin));
		_level.push_back(createBrick(0, 20, leftBorder, brickSkin));
		_level.push_back(createBrick(0, 23, leftBorder, brickSkin));

		// row 2
		_level.push_back(createBrick(1, 0, leftBorder, brickSkin));
		_level.push_back(createBrick(1, 3, leftBorder, brickSkin));
		_level.push_back(createBrick(1, 5, leftBorder, brickSkin));
		_level.push_back(createBrick(1, 7, leftBorder, brickSkin));
		_level.push_back(createBrick(1, 9, leftBorder, brickSkin));
		_level.push_back(createBrick(1, 11, leftBorder, brickSkin));
		_level.push_back(createBrick(1, 14, leftBorder, brickSkin));
		_level.push_back(createBrick(1, 16, leftBorder, brickSkin));
		_level.push_back(createBrick(1, 18, leftBorder, brickSkin));
		_level.push_back(createBrick(1, 22, leftBorder, brickSkin));
		_level.push_back(createBrick(1, 24, leftBorder, brickSkin));

		// row 3
		_level.push_back(createBrick(2, 0, leftBorder, brickSkin));
		_level.push_back(createBrick(2, 3, leftBorder, brickSkin));
		_level.push_back(createBrick(2, 5, leftBorder, brickSkin));
		_level.push_back(createBrick(2, 7, leftBorder, brickSkin));
		_level.push_back(createBrick(2, 9, leftBorder, brickSkin));
		_level.push_back(createBrick(2, 11, leftBorder, brickSkin));
		_level.push_back(createBrick(2, 14, leftBorder, brickSkin));
		_level.push_back(createBrick(2, 16, leftBorder, brickSkin));
		_level.push_back(createBrick(2, 18, leftBorder, brickSkin));
		_level.push_back(createBrick(2, 19, leftBorder, brickSkin));
		_level.push_back(createBrick(2, 22, leftBorder, brickSkin));
		_level.push_back(createBrick(2, 24, leftBorder, brickSkin));

		// row 4
		_level.push_back(createBrick(3, 0, leftBorder, brickSkin));
		_level.push_back(createBrick(3, 3, leftBorder, brickSkin));
		_level.push_back(createBrick(3, 5, leftBorder, brickSkin));
		_level.push_back(createBrick(3, 7, leftBorder, brickSkin));
		_level.push_back(createBrick(3, 8, leftBorder, brickSkin));
		_level.push_back(createBrick(3, 9, leftBorder, brickSkin));
		_level.push_back(createBrick(3, 11, leftBorder, brickSkin));
		_level.push_back(createBrick(3, 14, leftBorder, brickSkin));
		_level.push_back(createBrick(3, 16, leftBorder, brickSkin));
		_level.push_back(createBrick(3, 18, leftBorder, brickSkin));
		_level.push_back(createBrick(3, 20, leftBorder, brickSkin));
		_level.push_back(createBrick(3, 22, leftBorder, brickSkin));
		_level.push_back(createBrick(3, 24, leftBorder, brickSkin));

		// row 5
		_level.push_back(createBrick(4, 0, leftBorder, brickSkin));
		_level.push_back(createBrick(4, 3, leftBorder, brickSkin));
		_level.push_back(createBrick(4, 5, leftBorder, brickSkin));
		_level.push_back(createBrick(4, 7, leftBorder, brickSkin));
		_level.push_back(createBrick(4, 9, leftBorder, brickSkin));
		_level.push_back(createBrick(4, 11, leftBorder, brickSkin));
		_level.push_back(createBrick(4, 14, leftBorder, brickSkin));
		_level.push_back(createBrick(4, 16, leftBorder, brickSkin));
		_level.push_back(createBrick(4, 18, leftBorder, brickSkin));
		_level.push_back(createBrick(4, 20, leftBorder, brickSkin));
		_level.push_back(createBrick(4, 22, leftBorder, brickSkin));
		_level.push_back(createBrick(4, 24, leftBorder, brickSkin));

		// row 6
		_level.push_back(createBrick(5, 0, leftBorder, brickSkin));
		_level.push_back(createBrick(5, 3, leftBorder, brickSkin));
		_level.push_back(createBrick(5, 5, leftBorder, brickSkin));
		_level.push_back(createBrick(5, 7, leftBorder, brickSkin));
		_level.push_back(createBrick(5, 9, leftBorder, brickSkin));
		_level.push_back(createBrick(5, 11, leftBorder, brickSkin));
		_level.push_back(createBrick(5, 14, leftBorder, brickSkin));
		_level.push_back(createBrick(5, 16, leftBorder, brickSkin));
		_level.push_back(createBrick(5, 18, leftBorder, brickSkin));
		_level.push_back(createBrick(5, 20, leftBorder, brickSkin));
		_level.push_back(createBrick(5, 22, leftBorder, brickSkin));
		_level.push_back(createBrick(5, 24, leftBorder, brickSkin));

		// row 7
		_level.push_back(createBrick(6, 1, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 3, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 5, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 7, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 9, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 12, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 14, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 15, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 16, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 19, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 23, leftBorder, brickSkin));

		// row 7
		_level.push_back(createBrick(6, 1, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 3, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 5, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 7, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 9, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 12, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 14, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 15, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 16, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 19, leftBorder, brickSkin));
		_level.push_back(createBrick(6, 23, leftBorder, brickSkin));
		
		// row 9
		_level.push_back(createBrick(8, 0, leftBorder, brickSkin));
		_level.push_back(createBrick(8, 4, leftBorder, brickSkin));
		_level.push_back(createBrick(8, 9, leftBorder, brickSkin));
		_level.push_back(createBrick(8, 10, leftBorder, brickSkin));
		_level.push_back(createBrick(8, 13, leftBorder, brickSkin));
		_level.push_back(createBrick(8, 17, leftBorder, brickSkin));
		_level.push_back(createBrick(8, 18, leftBorder, brickSkin));
		_level.push_back(createBrick(8, 20, leftBorder, brickSkin));
		_level.push_back(createBrick(8, 24, leftBorder, brickSkin));

		// row 10
		_level.push_back(createBrick(9, 1, leftBorder, brickSkin));
		_level.push_back(createBrick(9, 3, leftBorder, brickSkin));
		_level.push_back(createBrick(9, 5, leftBorder, brickSkin));
		_level.push_back(createBrick(9, 8, leftBorder, brickSkin));
		_level.push_back(createBrick(9, 10, leftBorder, brickSkin));
		_level.push_back(createBrick(9, 12, leftBorder, brickSkin));
		_level.push_back(createBrick(9, 14, leftBorder, brickSkin));
		_level.push_back(createBrick(9, 16, leftBorder, brickSkin));
		_level.push_back(createBrick(9, 20, leftBorder, brickSkin));
		_level.push_back(createBrick(9, 24, leftBorder, brickSkin));

		// row 11
		_level.push_back(createBrick(10, 1, leftBorder, brickSkin));
		_level.push_back(createBrick(10, 3, leftBorder, brickSkin));
		_level.push_back(createBrick(10, 5, leftBorder, brickSkin));
		_level.push_back(createBrick(10, 8, leftBorder, brickSkin));
		_level.push_back(createBrick(10, 10, leftBorder, brickSkin));
		_level.push_back(createBrick(10, 12, leftBorder, brickSkin));
		_level.push_back(createBrick(10, 14, leftBorder, brickSkin));
		_level.push_back(createBrick(10, 16, leftBorder, brickSkin));
		_level.push_back(createBrick(10, 17, leftBorder, brickSkin));
		_level.push_back(createBrick(10, 20, leftBorder, brickSkin));
		_level.push_back(createBrick(10, 24, leftBorder, brickSkin));


		// row 12
		_level.push_back(createBrick(11, 0, leftBorder, brickSkin));
		_level.push_back(createBrick(11, 3, leftBorder, brickSkin));
		_level.push_back(createBrick(11, 4, leftBorder, brickSkin));
		_level.push_back(createBrick(11, 5, leftBorder, brickSkin));
		_level.push_back(createBrick(11, 8, leftBorder, brickSkin));
		_level.push_back(createBrick(11, 10, leftBorder, brickSkin));
		_level.push_back(createBrick(11, 12, leftBorder, brickSkin));
		_level.push_back(createBrick(11, 13, leftBorder, brickSkin));
		_level.push_back(createBrick(11, 14, leftBorder, brickSkin));
		_level.push_back(createBrick(11, 16, leftBorder, brickSkin));
		_level.push_back(createBrick(11, 18, leftBorder, brickSkin));
		_level.push_back(createBrick(11, 20, leftBorder, brickSkin));
		_level.push_back(createBrick(11, 21, leftBorder, brickSkin));
		_level.push_back(createBrick(11, 24, leftBorder, brickSkin));

		// row 13
		_level.push_back(createBrick(12, 1, leftBorder, brickSkin));
		_level.push_back(createBrick(12, 3, leftBorder, brickSkin));
		_level.push_back(createBrick(12, 5, leftBorder, brickSkin));
		_level.push_back(createBrick(12, 8, leftBorder, brickSkin));
		_level.push_back(createBrick(12, 10, leftBorder, brickSkin));
		_level.push_back(createBrick(12, 12, leftBorder, brickSkin));
		_level.push_back(createBrick(12, 14, leftBorder, brickSkin));
		_level.push_back(createBrick(12, 16, leftBorder, brickSkin));
		_level.push_back(createBrick(12, 18, leftBorder, brickSkin));
		_level.push_back(createBrick(12, 20, leftBorder, brickSkin));
		_level.push_back(createBrick(12, 22, leftBorder, brickSkin));
		_level.push_back(createBrick(12, 24, leftBorder, brickSkin));

		// row 14
		_level.push_back(createBrick(13, 1, leftBorder, brickSkin));
		_level.push_back(createBrick(13, 3, leftBorder, brickSkin));
		_level.push_back(createBrick(13, 5, leftBorder, brickSkin));
		_level.push_back(createBrick(13, 8, leftBorder, brickSkin));
		_level.push_back(createBrick(13, 10, leftBorder, brickSkin));
		_level.push_back(createBrick(13, 12, leftBorder, brickSkin));
		_level.push_back(createBrick(13, 14, leftBorder, brickSkin));
		_level.push_back(createBrick(13, 16, leftBorder, brickSkin));
		_level.push_back(createBrick(13, 18, leftBorder, brickSkin));
		_level.push_back(createBrick(13, 20, leftBorder, brickSkin));
		_level.push_back(createBrick(13, 22, leftBorder, brickSkin));
		_level.push_back(createBrick(13, 24, leftBorder, brickSkin));

		// row 15
		_level.push_back(createBrick(14, 0, leftBorder, brickSkin));
		_level.push_back(createBrick(14, 3, leftBorder, brickSkin));
		_level.push_back(createBrick(14, 5, leftBorder, brickSkin));
		_level.push_back(createBrick(14, 8, leftBorder, brickSkin));
		_level.push_back(createBrick(14, 10, leftBorder, brickSkin));
		_level.push_back(createBrick(14, 12, leftBorder, brickSkin));
		_level.push_back(createBrick(14, 14, leftBorder, brickSkin));
		_level.push_back(createBrick(14, 17, leftBorder, brickSkin));
		_level.push_back(createBrick(14, 20, leftBorder, brickSkin));
		_level.push_back(createBrick(14, 21, leftBorder, brickSkin));
		_level.push_back(createBrick(14, 24, leftBorder, brickSkin));
		
	}
	for (auto i : _level)
		_scene->addItem(i);

	//_scene->addItem(_level.back());
	return _level;
}

// Обработчик нажатия
void Arcanoid::mousePressEvent(QMouseEvent* event) {
	_ballFixedOnPlatform = false;
}


Arcanoid::Arcanoid(Settings& settings) : _settings(settings) {

	// ОБЩИЕ НАСТРОЙКИ
	const QPointF startDeskPos			(500.0, 750.0);					// Стартовая позиция нашей доски
	const QPointF startGroundDeskPos	(500.0, 740.0);					// Стартовая позиция покрытия доски
	const QSize	  ballStandardSize		(20, 20);						// Размер шарика
	const QPointF startLivesCountPos	(1500.0, 0.0);					// Стартовая позиция количества жизней

	const double leftBorderShift		= 240.0;						// Сдвиг границы слева
	const double rightBorderShift		= 1640.0;						// Сдвиг границы справа

	setCursor(Qt::BlankCursor);											// Уберем курсор мыши
	
	// МЕНЮ

	const auto fileMenu			= menuBar()->addMenu	(u8"Файл");
	const auto showMainMenu		= fileMenu->addAction	(u8"Главное меню");
	const auto restartLevel		= fileMenu->addAction	(u8"Начать уровень сначала");
	const auto setLevel			= fileMenu->addMenu		(u8"Выбрать уровень");
	const auto exitAction		= fileMenu->addAction	(u8"Выход");
	
	const auto level1Action		= setLevel->addAction	(u8"Тестовый уровень (ну пусть будет уровень 1)");
	const auto level2Action		= setLevel->addAction	(u8"Спасибо, Руслан Романович");

	// Привязка основны функций меню

	connect(showMainMenu, &QAction::triggered, this, &Arcanoid::openMainMenu);
	connect(restartLevel, &QAction::triggered, this, &Arcanoid::restartLevel);
	connect(exitAction, &QAction::triggered, this, &QWidget::close);
	

	// Привязка функций меню "Выбрать уровень"

	connect(level1Action, &QAction::triggered, this, &Arcanoid::goToLevel1);
	connect(level2Action, &QAction::triggered, this, &Arcanoid::goToLevel2);
	
	// Настройки окна

	setWindowIcon(QIcon("resources/balls/ball_red.png"));	// Иконка
	setWindowTitle(u8"Arcanoid");							// Заголовок

	setMaximumSize(1920, 1080);								// Максимальный размер сцены
	
	// Выбор фона

	QPixmap background;												// Создание фона (картинки)

	switch (_settings.background()) {										// Выбирается фон согласно настройкам
	case 0: {
		background = QPixmap("resources/backgrounds/background_1.jpg");
		break;
	}
	case 1: {
		background = QPixmap("resources/backgrounds/background_2.jpg");
		break;
	}
	case 2: {
		background = QPixmap("resources/backgrounds/background_3.jpg");
		break;
	}
	case 3: {
		background = QPixmap("resources/backgrounds/background_4.jpg");
		break;
	}
	}

	// Добавим на сцену фон

	background = background.scaled(1920, 800);						// Уменьшаем фон до нужных размеров
	_backgroundItem = new QGraphicsPixmapItem(background);

	_scene = new QGraphicsScene(this);								// Создаем сцену
	_scene->addItem(_backgroundItem);								// Добавим на сцену фон

	const auto view = new QGraphicsView;							// Создадим "обзор"
	view->setScene(_scene);											// Назначим обзор _scene текущим
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);		// Выключаем горизонтальную прокрутку
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);		// Выключаем вертикальную прокрутку
	setCentralWidget(view);											// Устанавливаем на центр нашего окна обзор нашей сцены
	
	_frameWidth = view->width();									// Ширина нашего окна

	// Добавляем доску (основа)

	deskStruct.picture = QPixmap("resources/desk/desk.png");			// Собачим картинку к доске
	deskStruct.entity = new QGraphicsPixmapItem(deskStruct.picture);	// Создаем новый объект для сцены
	deskStruct.entity->setPos(startDeskPos);							// Устанавливаем доску на изначальные координаты
	_scene->addItem(deskStruct.entity);									// Добавляем на сцену доску

	auto groundDeskWidth	 = deskStruct.groundPicture.size().width();			// Ширина доски
	auto groundDeskHeight	 = deskStruct.groundPicture.size().height();		// Высота доски

	// Добавляем к доске покрытие

	deskStruct.isAnimated = false;													// Анимация: при соударении шарика о доску (анимировано именно покрытие)
	deskStruct.groundPicture = QPixmap("resources/desk/desk_ground.png");			// Собачим картинку к покрытию
	deskStruct.groundEntity = new QGraphicsPixmapItem(deskStruct.groundPicture);	// Создаем новый объект для сцены
	deskStruct.groundEntity->setPos(startGroundDeskPos);							// Устанавливаем покрытие доски на изначальные координаты
	_scene->addItem(deskStruct.groundEntity);										// Добавляем на сцену покрытие доски

	// Добавим шарик

	switch (_settings.ballSkin()) {											// Выбираем скин для шарика (в зависимости от настройки)
	case Settings::ball_skins::BLUE: {
		ballStruct._picture = QPixmap("resources/balls/ball_blue.png");
		break;
	}
	case Settings::ball_skins::GREEN: {
		ballStruct._picture = QPixmap("resources/balls/ball_green.png");
		break;
	}
	case Settings::ball_skins::RED: {
		ballStruct._picture = QPixmap("resources/balls/ball_red.png");
		break;
	}
	case Settings::ball_skins::YELLOW: {
		ballStruct._picture = QPixmap("resources/balls/ball_yellow.png");
		break;
	}
	}

	ballStruct._picture = ballStruct._picture.scaled(ballStandardSize);				// Уменьшаем размер шарика до заданного значения

	// Добавим шарик

	const QPointF startBallPos(startGroundDeskPos.x() + groundDeskWidth / 1.5, startGroundDeskPos.y() - groundDeskHeight);

	ballStruct.entity = new QGraphicsPixmapItem(ballStruct._picture);	// Создадим визуальный объект шарика
	ballStruct.entity->setPos(startBallPos);							// Установим шарик на сцену (на платформу)
	_scene->addItem(ballStruct.entity);									// Добавим шарик на сцену
	_ballFixedOnPlatform = true;										// Начальное положение шарика (привязка к платформе)

	// Создание таймера для регулярного обновления сцены
	const auto timer = new QTimer(this);								// Создаем объект таймера
	connect(timer, &QTimer::timeout, this, &Arcanoid::updateScene);		// Привязываем обработчик сигнала
	timer->start(_timerInterval);										// Ставим интервал таймера, с течением которого происходит обновление сцены)





	QPixmap livesPicture;

	// ИНИЦИАЛИЗАЦИЯ

	switch (_settings.difficult()) {			// Инициализация в зависимости от сложности
	case Settings::difficults::EASY: {
		ballStruct.speedX = Settings::EASY_BALL_SPEED;
		ballStruct.speedY = Settings::EASY_BALL_SPEED;
		_lives = Settings::EASY_LIVES_COUNT;
		livesPicture = QPixmap("resources/misc/Lives3.png");
		
		break;
	}
	case Settings::difficults::NORMAL: {
		ballStruct.speedX = Settings::NORMAL_BALL_SPEED;
		ballStruct.speedY = Settings::NORMAL_BALL_SPEED;
		_lives = Settings::NORMAL_LIVES_COUNT;

		livesPicture = QPixmap("resources/misc/Lives2.png");

		break;
	}
	case Settings::difficults::HARD: {
		ballStruct.speedX = Settings::HARD_BALL_SPEED;
		ballStruct.speedY = Settings::HARD_BALL_SPEED;
		_lives = Settings::HARD_LIVES_COUNT;
		livesPicture = QPixmap("resources/misc/Lives1.png");

		break;
	}
	case Settings::difficults::INSANE: {
		ballStruct.speedX = Settings::INSANE_BALL_SPEED;
		ballStruct.speedY = Settings::INSANE_BALL_SPEED;
		_lives = Settings::INSANE_LIVES_COUNT;
		livesPicture = QPixmap("resources/misc/Lives0.png");

		break;
	}
	}

	// СОЗДАДИМ УРОВЕНЬ

	if (_settings.level() == 0)
		createTestLevel(leftBorderShift);
	if (_settings.level() == 1)
		createThanksLevel(leftBorderShift);


	// Отображение количества жизней
	_livesCountItem = new QGraphicsPixmapItem(livesPicture);
	_livesCountItem->setPos(startLivesCountPos);

	_scene->addItem(_livesCountItem);

	// Изначально уровень не пройден
	_isLevelComplete = false;
}


// Обновление сцены

void Arcanoid::updateScene() {

	const QPointF startLivesCountPos(1500.0, 0.0);						// Стартовая позиция количества жизней

	const int stride			= 180;									// Сдвиг центра доски к мышке
	const int deskGroundHeight	= deskStruct.groundPicture.height();	// Высота покрытия доски
	const int deskGroundWidth	= deskStruct.groundPicture.width();		// Ширина покрытия доски

	const int deskHeight		= deskStruct.picture.height();			// Высота доски
	const int deskWidth			= deskStruct.picture.width();			// Ширина доски

	const auto sceneSize		= size();								// Размер сцены
	const auto ballSize			= ballStruct._picture.size();			// Размер шарика
	
	const double PI = 3.14;												// Константа PI (для вычисления угла)

	const double deskHeightLevel				= 750.0;				// Положение доски относительно нижнего края
	const double deskGroundHeightLevel			= 740.0;				// Положение покрытия доски относительного нижнего края
	const double desksDiff						= 15.0;					// Разность между краями доски и покрытия доски (покрытие меньше на 30)	

	const double boardShift						= 10.0;					// Сдвиг доски вниз при анимации
	const double leftBorderShift				= 240.0;				// Сдвиг границы слева
	const double rightBorderShift				= 1640.0;				// Сдвиг границы справа

	const double boardAnimationReleaseSpeed		= 0.2;					// Скорость восстановления нормального состояния доски (анимация)

	const size_t maxCountHitsOfWall				= 3;					// На случай, если шарик застрянет или будет очень медленно двигаться вверх - после
	size_t currentCountOfHit					= 0;					// Текущее количество отталкиваний шарика от стен

	// Обновляем координаты доски и шарика								// такого количества ударов он поменяет угол движения

	
	if (QCursor::pos().x() > 0 + pos().x() + deskGroundWidth / 2 &&						// Если курсор находится внутри окна
		QCursor::pos().x() < pos().x() + sceneSize.width() - deskGroundWidth / 2) {

		// Положение доски ( pos().x() - положение окна на экране относительно левого края ) (P.S. Координата Y уже выставлена)

		deskStruct.entity->setX			(QCursor::pos().x() - pos().x() + stride);						// Координата X доски
		deskStruct.groundEntity->setX	(QCursor::pos().x() - pos().x() + stride + desksDiff);			// Координата X покрытия доски

		// В начальный момент игры шарик прикреплен к платформе
		if (_ballFixedOnPlatform) {

			ballStruct.entity->setPos(deskStruct.groundEntity->pos());								// Предварительная установка шарика на начало покрытия доски

			ballStruct.entity->setX(ballStruct.entity->x() + deskGroundWidth / 1.5);				// Сдвиг шарика на правую часть покрытия доски
			ballStruct.entity->setY(ballStruct.entity->y() - deskGroundHeight);						// Повышение уровня положения шарика на высоту доски

			ballStruct.angle = 2 * PI * (static_cast<double>((ballStruct.entity->x() - deskStruct.groundEntity->x())) / static_cast<double>(deskGroundWidth));

		}
	}
	
	// Если шарик оторвался от платформы (при нажатии кнопки мыши)

	if (!_ballFixedOnPlatform) {

		// Обновление координат шарика

		ballStruct.entity->setPos(ballStruct.entity->x() - ballStruct.speedX * cos(ballStruct.angle), ballStruct.entity->y() + ballStruct.speedY * sin(ballStruct.angle));

		// Отталкивание шарика от стен

		if (ballStruct.entity->x() <= leftBorderShift || ballStruct.entity->x() >= rightBorderShift + ballSize.width()) {	// Если шарик уходит слева или справа
			ballStruct.speedX *= -1;
			++currentCountOfHit;
		}

		// Если шарик уходит вверх
		if (ballStruct.entity->y() <= 0) {
			ballStruct.speedY *= -1;			// Отражение скорости по вертикали
			currentCountOfHit = 0;
		}

		// Проверка на наличие доски (если нет - шарик уходит вниз и теряется одна жизнь)
		if (ballStruct.entity->y() + ballSize.height() >= deskHeightLevel &&
			ballStruct.entity->x() > deskStruct.entity->x() && ballStruct.entity->x() < deskStruct.entity->x() + deskWidth) {

			ballStruct.speedY *= -1;			// Отражение скорости по вертикали
			deskStruct.isAnimated = true;		// Активация анимации доски

			// Новый угол отталкивания

			ballStruct.angle = 2 * PI * 
				(static_cast<double>(	abs(ballStruct.entity->x() - (deskStruct.groundEntity->x()+ deskGroundWidth /2))	) / static_cast<double>(deskGroundWidth /2	));



			// Если попадем на левую половину доски
			if (ballStruct.entity->x() > deskStruct.groundEntity->x() && ballStruct.entity->x() < deskStruct.groundEntity->x() + 0.5 * deskGroundWidth)
				if (ballStruct.speedX > 0)
					ballStruct.speedX *= -1;	// Отражение скорости по горизонтали

			// Если попадем мячиком на правую половину доски
			if (ballStruct.entity->x() >= deskStruct.groundEntity->x() + 0.5 * deskGroundWidth && ballStruct.entity->x() < deskStruct.groundEntity->x() + deskGroundWidth)
				if (ballStruct.speedX < 0)
					ballStruct.speedX *= -1;	// Отражение скорости по горизонтали
			
			// Анимация отталкивания (опускание доски вниз)
			if (deskStruct.groundEntity->y() <= deskGroundHeightLevel)
				deskStruct.groundEntity->setY(deskStruct.groundEntity->y() + boardShift);

			// Костыль :( поскольку шарик просто "выбивает доску" из своей пролежни
			ballStruct.entity->setY(ballStruct.entity->y()-2);
		}

		// Анимация отталкивания (возврат доски в исходное положение)
		if (deskStruct.isAnimated)
			if (deskStruct.groundEntity->y() > deskGroundHeightLevel)
				deskStruct.groundEntity->setY(deskStruct.groundEntity->y() - boardAnimationReleaseSpeed);
			else
				deskStruct.isAnimated = false;

		// Если шарик бессмысленно бьет стены уже "maxCountHitsOfWall" раз, то меняем угол движения
		if (currentCountOfHit == maxCountHitsOfWall) {
			if (ballStruct.speedY > 0) 
				ballStruct.angle = PI / 4;

			if (ballStruct.speedY < 0)
				ballStruct.angle = (3 * PI) / 4;
		}



		// Если шарик улетел
		if (ballStruct.entity->y() > deskGroundHeightLevel + desksDiff) {
			_ballFixedOnPlatform = true;

			
			// Если жизней больше нет, обновляем фон на GameOver
			if (_lives == 0) {
				for (auto i : _scene->items()) {
					if (i == _backgroundItem) {
						_scene->removeItem(i);

						delete _backgroundItem;
						QPixmap background("resources/backgrounds/game_over_background.png");
						background = background.scaled(1920, 800);								// Уменьшаем фон до нужных размеров

						_backgroundItem = new QGraphicsPixmapItem(background);
						_scene->addItem(_backgroundItem);

						setCursor(Qt::CrossCursor);

						break;
					}
				}
			}
			else {	// Изменение количества жизней
				
				--_lives;

				currentCountOfHit = 0;

				// Удаляем старую картинку с жизнями
				for (auto i : _scene->items()) {
					if (i == _livesCountItem) {

						_scene->removeItem(i);

						delete _livesCountItem;

						// Установим новую картинку с жизнями
						
						QPixmap livesCountPicture;

						switch (_lives) {
						case 2: {
							livesCountPicture = QPixmap("resources/misc/Lives2.png");
							break;
						}
						case 1: {
							livesCountPicture = QPixmap("resources/misc/Lives1.png");
							break;
						}
						case 0: {
							livesCountPicture = QPixmap("resources/misc/Lives0.png");
							break;
						}
						}

						_livesCountItem = new QGraphicsPixmapItem(livesCountPicture);

						_livesCountItem->setPos(startLivesCountPos);

						_scene->addItem(_livesCountItem);


						break;
					}
				}
			}


		}
	}
	
	// Обрабатываем коллизию шарика с кирпичиком

	if (!_scene->collidingItems(ballStruct.entity).empty()) {
		for (auto i : _scene->collidingItems(ballStruct.entity)) {
			for (auto j = _level.begin(); j != _level.end(); ++j) {
				if (*j == i) {
					_scene->removeItem(i);
					ballStruct.speedY *= -1;
					_level.erase(j);
					break;
					
					currentCountOfHit = 0;
					
				}
			}
		}
	}

	// Если все кирпичики уничтожены, то удалим шарик и выведем надпись завершения уровня
	if (_level.empty() && !_isLevelComplete) {
				
		// Изменим значение флажка
		_isLevelComplete = true;

		// Удалим шарик и все остальное, кроме доски и фона

		for (auto i : _scene->items()) {
			if (i == ballStruct.entity) {
				_scene->removeItem(i);
				break;
			}
		}

		// Выведем надпись завершения уровня

		QPixmap levelCompletePicture("resources/misc/level_complete.png");
		
		_levelCompleteItem = new QGraphicsPixmapItem(levelCompletePicture);

		// Рассчитаем позицию (чтобы выводилось по центру экрана)
		
		{
			const auto centerOfScreenX = rightBorderShift - leftBorderShift;
			const auto centerOfScreenY = _scene->height() / 2;

			_levelCompleteItem->setPos(centerOfScreenX - levelCompletePicture.width(), centerOfScreenY - 0.5 * levelCompletePicture.height());
		}

		_scene->addItem(_levelCompleteItem);
	}

	
}

/////////////////
// Другие слоты
/////////////////

// Слот открывания меню настроек (гравного меню)
void Arcanoid::openMainMenu() {
	const auto mainMenu = new SettingsWindow(_settings);
	mainMenu->setAttribute(Qt::WA_DeleteOnClose);
	mainMenu->show();

	this->close();
}

// Слот рестарта уровня
void Arcanoid::restartLevel() {

	const auto newGameWindow = new Arcanoid(_settings);
	newGameWindow->setAttribute(Qt::WA_DeleteOnClose);
	newGameWindow->setFixedSize(newGameWindow->sizeHint());
	//gameWindow->setParent(this);
	newGameWindow->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
	newGameWindow->setWindowModality(Qt::WindowModal);
	newGameWindow->show();
	this->close();

}

// Слоты навигации между уровнями
void Arcanoid::goToLevel1() {
	_settings.setLevel(0);
	restartLevel();
}

void Arcanoid::goToLevel2() {
	_settings.setLevel(1);
	restartLevel();
}
