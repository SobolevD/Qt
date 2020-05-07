#include "Arcanoid.h"
#include <QMouseEvent>
#include <QCursor>
#include "SettingsWindow.h"
	
// ��������� ����������

QGraphicsPixmapItem* Arcanoid::createBrick(int row, int column, double leftBorder, Settings::bricks_skins& brickType) {
	
	// ���������� ����� ���������
	const int distance = 15;

	// �������� �������
	QPixmap brickPicture;

	// ����� �������� ������� � ����������� �� ��������
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

	// �������� ������ �� ������� ������ ������ � ������ � ��� ������� ������ � ������
	brickPicture = brickPicture.scaled(ballStruct._picture.width() * 2, ballStruct._picture.height());

	// �������� ������ �� �����
	QGraphicsPixmapItem* brickEntity = new QGraphicsPixmapItem(brickPicture);
	brickEntity->setPos(leftBorder + distance + column * (brickPicture.width() + distance), distance + row * (brickPicture.height() + distance));
	return brickEntity;
}

// �������� ������� �� ��������
vector<QGraphicsPixmapItem*> Arcanoid::createTestLevel(double leftBorder) {

	// ���������� ����������� �������� � ������
	const int MAX_BRICKS_IN_ROW	= 26;

	// ���������� ��������
	const int BRICKS_IN_COLUMN	= 8;

	// ������� ���� ���������
	Settings::bricks_skins brickSkin;

	// ������� ������� � ������������ ����������
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

// ���� �������
vector<QGraphicsPixmapItem*> Arcanoid::createThanksLevel(double leftBorder) {

	// ���������� ����������� �������� � ������
	const int MAX_BRICKS_IN_ROW = 26;

	// ������� ���� ���������
	Settings::bricks_skins brickSkin = Settings::bricks_skins::GOLD;

	// ����� ������
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

// ���������� �������
void Arcanoid::mousePressEvent(QMouseEvent* event) {
	_ballFixedOnPlatform = false;
}


Arcanoid::Arcanoid(Settings& settings) : _settings(settings) {

	// ����� ���������
	const QPointF startDeskPos			(500.0, 750.0);					// ��������� ������� ����� �����
	const QPointF startGroundDeskPos	(500.0, 740.0);					// ��������� ������� �������� �����
	const QSize	  ballStandardSize		(20, 20);						// ������ ������
	const QPointF startLivesCountPos	(1500.0, 0.0);					// ��������� ������� ���������� ������

	const double leftBorderShift		= 240.0;						// ����� ������� �����
	const double rightBorderShift		= 1640.0;						// ����� ������� ������

	setCursor(Qt::BlankCursor);											// ������ ������ ����
	
	// ����

	const auto fileMenu			= menuBar()->addMenu	(u8"����");
	const auto showMainMenu		= fileMenu->addAction	(u8"������� ����");
	const auto restartLevel		= fileMenu->addAction	(u8"������ ������� �������");
	const auto setLevel			= fileMenu->addMenu		(u8"������� �������");
	const auto exitAction		= fileMenu->addAction	(u8"�����");
	
	const auto level1Action		= setLevel->addAction	(u8"�������� ������� (�� ����� ����� ������� 1)");
	const auto level2Action		= setLevel->addAction	(u8"�������, ������ ���������");

	// �������� ������� ������� ����

	connect(showMainMenu, &QAction::triggered, this, &Arcanoid::openMainMenu);
	connect(restartLevel, &QAction::triggered, this, &Arcanoid::restartLevel);
	connect(exitAction, &QAction::triggered, this, &QWidget::close);
	

	// �������� ������� ���� "������� �������"

	connect(level1Action, &QAction::triggered, this, &Arcanoid::goToLevel1);
	connect(level2Action, &QAction::triggered, this, &Arcanoid::goToLevel2);
	
	// ��������� ����

	setWindowIcon(QIcon("resources/balls/ball_red.png"));	// ������
	setWindowTitle(u8"Arcanoid");							// ���������

	setMaximumSize(1920, 1080);								// ������������ ������ �����
	
	// ����� ����

	QPixmap background;												// �������� ���� (��������)

	switch (_settings.background()) {										// ���������� ��� �������� ����������
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

	// ������� �� ����� ���

	background = background.scaled(1920, 800);						// ��������� ��� �� ������ ��������
	_backgroundItem = new QGraphicsPixmapItem(background);

	_scene = new QGraphicsScene(this);								// ������� �����
	_scene->addItem(_backgroundItem);								// ������� �� ����� ���

	const auto view = new QGraphicsView;							// �������� "�����"
	view->setScene(_scene);											// �������� ����� _scene �������
	view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);		// ��������� �������������� ���������
	view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);		// ��������� ������������ ���������
	setCentralWidget(view);											// ������������� �� ����� ������ ���� ����� ����� �����
	
	_frameWidth = view->width();									// ������ ������ ����

	// ��������� ����� (������)

	deskStruct.picture = QPixmap("resources/desk/desk.png");			// ������� �������� � �����
	deskStruct.entity = new QGraphicsPixmapItem(deskStruct.picture);	// ������� ����� ������ ��� �����
	deskStruct.entity->setPos(startDeskPos);							// ������������� ����� �� ����������� ����������
	_scene->addItem(deskStruct.entity);									// ��������� �� ����� �����

	auto groundDeskWidth	 = deskStruct.groundPicture.size().width();			// ������ �����
	auto groundDeskHeight	 = deskStruct.groundPicture.size().height();		// ������ �����

	// ��������� � ����� ��������

	deskStruct.isAnimated = false;													// ��������: ��� ���������� ������ � ����� (����������� ������ ��������)
	deskStruct.groundPicture = QPixmap("resources/desk/desk_ground.png");			// ������� �������� � ��������
	deskStruct.groundEntity = new QGraphicsPixmapItem(deskStruct.groundPicture);	// ������� ����� ������ ��� �����
	deskStruct.groundEntity->setPos(startGroundDeskPos);							// ������������� �������� ����� �� ����������� ����������
	_scene->addItem(deskStruct.groundEntity);										// ��������� �� ����� �������� �����

	// ������� �����

	switch (_settings.ballSkin()) {											// �������� ���� ��� ������ (� ����������� �� ���������)
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

	ballStruct._picture = ballStruct._picture.scaled(ballStandardSize);				// ��������� ������ ������ �� ��������� ��������

	// ������� �����

	const QPointF startBallPos(startGroundDeskPos.x() + groundDeskWidth / 1.5, startGroundDeskPos.y() - groundDeskHeight);

	ballStruct.entity = new QGraphicsPixmapItem(ballStruct._picture);	// �������� ���������� ������ ������
	ballStruct.entity->setPos(startBallPos);							// ��������� ����� �� ����� (�� ���������)
	_scene->addItem(ballStruct.entity);									// ������� ����� �� �����
	_ballFixedOnPlatform = true;										// ��������� ��������� ������ (�������� � ���������)

	// �������� ������� ��� ����������� ���������� �����
	const auto timer = new QTimer(this);								// ������� ������ �������
	connect(timer, &QTimer::timeout, this, &Arcanoid::updateScene);		// ����������� ���������� �������
	timer->start(_timerInterval);										// ������ �������� �������, � �������� �������� ���������� ���������� �����)





	QPixmap livesPicture;

	// �������������

	switch (_settings.difficult()) {			// ������������� � ����������� �� ���������
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

	// �������� �������

	if (_settings.level() == 0)
		createTestLevel(leftBorderShift);
	if (_settings.level() == 1)
		createThanksLevel(leftBorderShift);


	// ����������� ���������� ������
	_livesCountItem = new QGraphicsPixmapItem(livesPicture);
	_livesCountItem->setPos(startLivesCountPos);

	_scene->addItem(_livesCountItem);

	// ���������� ������� �� �������
	_isLevelComplete = false;
}


// ���������� �����

void Arcanoid::updateScene() {

	const QPointF startLivesCountPos(1500.0, 0.0);						// ��������� ������� ���������� ������

	const int stride			= 180;									// ����� ������ ����� � �����
	const int deskGroundHeight	= deskStruct.groundPicture.height();	// ������ �������� �����
	const int deskGroundWidth	= deskStruct.groundPicture.width();		// ������ �������� �����

	const int deskHeight		= deskStruct.picture.height();			// ������ �����
	const int deskWidth			= deskStruct.picture.width();			// ������ �����

	const auto sceneSize		= size();								// ������ �����
	const auto ballSize			= ballStruct._picture.size();			// ������ ������
	
	const double PI = 3.14;												// ��������� PI (��� ���������� ����)

	const double deskHeightLevel				= 750.0;				// ��������� ����� ������������ ������� ����
	const double deskGroundHeightLevel			= 740.0;				// ��������� �������� ����� �������������� ������� ����
	const double desksDiff						= 15.0;					// �������� ����� ������ ����� � �������� ����� (�������� ������ �� 30)	

	const double boardShift						= 10.0;					// ����� ����� ���� ��� ��������
	const double leftBorderShift				= 240.0;				// ����� ������� �����
	const double rightBorderShift				= 1640.0;				// ����� ������� ������

	const double boardAnimationReleaseSpeed		= 0.2;					// �������� �������������� ����������� ��������� ����� (��������)

	const size_t maxCountHitsOfWall				= 3;					// �� ������, ���� ����� ��������� ��� ����� ����� �������� ��������� ����� - �����
	size_t currentCountOfHit					= 0;					// ������� ���������� ������������ ������ �� ����

	// ��������� ���������� ����� � ������								// ������ ���������� ������ �� �������� ���� ��������

	
	if (QCursor::pos().x() > 0 + pos().x() + deskGroundWidth / 2 &&						// ���� ������ ��������� ������ ����
		QCursor::pos().x() < pos().x() + sceneSize.width() - deskGroundWidth / 2) {

		// ��������� ����� ( pos().x() - ��������� ���� �� ������ ������������ ������ ���� ) (P.S. ���������� Y ��� ����������)

		deskStruct.entity->setX			(QCursor::pos().x() - pos().x() + stride);						// ���������� X �����
		deskStruct.groundEntity->setX	(QCursor::pos().x() - pos().x() + stride + desksDiff);			// ���������� X �������� �����

		// � ��������� ������ ���� ����� ���������� � ���������
		if (_ballFixedOnPlatform) {

			ballStruct.entity->setPos(deskStruct.groundEntity->pos());								// ��������������� ��������� ������ �� ������ �������� �����

			ballStruct.entity->setX(ballStruct.entity->x() + deskGroundWidth / 1.5);				// ����� ������ �� ������ ����� �������� �����
			ballStruct.entity->setY(ballStruct.entity->y() - deskGroundHeight);						// ��������� ������ ��������� ������ �� ������ �����

			ballStruct.angle = 2 * PI * (static_cast<double>((ballStruct.entity->x() - deskStruct.groundEntity->x())) / static_cast<double>(deskGroundWidth));

		}
	}
	
	// ���� ����� ��������� �� ��������� (��� ������� ������ ����)

	if (!_ballFixedOnPlatform) {

		// ���������� ��������� ������

		ballStruct.entity->setPos(ballStruct.entity->x() - ballStruct.speedX * cos(ballStruct.angle), ballStruct.entity->y() + ballStruct.speedY * sin(ballStruct.angle));

		// ������������ ������ �� ����

		if (ballStruct.entity->x() <= leftBorderShift || ballStruct.entity->x() >= rightBorderShift + ballSize.width()) {	// ���� ����� ������ ����� ��� ������
			ballStruct.speedX *= -1;
			++currentCountOfHit;
		}

		// ���� ����� ������ �����
		if (ballStruct.entity->y() <= 0) {
			ballStruct.speedY *= -1;			// ��������� �������� �� ���������
			currentCountOfHit = 0;
		}

		// �������� �� ������� ����� (���� ��� - ����� ������ ���� � �������� ���� �����)
		if (ballStruct.entity->y() + ballSize.height() >= deskHeightLevel &&
			ballStruct.entity->x() > deskStruct.entity->x() && ballStruct.entity->x() < deskStruct.entity->x() + deskWidth) {

			ballStruct.speedY *= -1;			// ��������� �������� �� ���������
			deskStruct.isAnimated = true;		// ��������� �������� �����

			// ����� ���� ������������

			ballStruct.angle = 2 * PI * 
				(static_cast<double>(	abs(ballStruct.entity->x() - (deskStruct.groundEntity->x()+ deskGroundWidth /2))	) / static_cast<double>(deskGroundWidth /2	));



			// ���� ������� �� ����� �������� �����
			if (ballStruct.entity->x() > deskStruct.groundEntity->x() && ballStruct.entity->x() < deskStruct.groundEntity->x() + 0.5 * deskGroundWidth)
				if (ballStruct.speedX > 0)
					ballStruct.speedX *= -1;	// ��������� �������� �� �����������

			// ���� ������� ������� �� ������ �������� �����
			if (ballStruct.entity->x() >= deskStruct.groundEntity->x() + 0.5 * deskGroundWidth && ballStruct.entity->x() < deskStruct.groundEntity->x() + deskGroundWidth)
				if (ballStruct.speedX < 0)
					ballStruct.speedX *= -1;	// ��������� �������� �� �����������
			
			// �������� ������������ (��������� ����� ����)
			if (deskStruct.groundEntity->y() <= deskGroundHeightLevel)
				deskStruct.groundEntity->setY(deskStruct.groundEntity->y() + boardShift);

			// ������� :( ��������� ����� ������ "�������� �����" �� ����� ��������
			ballStruct.entity->setY(ballStruct.entity->y()-2);
		}

		// �������� ������������ (������� ����� � �������� ���������)
		if (deskStruct.isAnimated)
			if (deskStruct.groundEntity->y() > deskGroundHeightLevel)
				deskStruct.groundEntity->setY(deskStruct.groundEntity->y() - boardAnimationReleaseSpeed);
			else
				deskStruct.isAnimated = false;

		// ���� ����� ������������ ���� ����� ��� "maxCountHitsOfWall" ���, �� ������ ���� ��������
		if (currentCountOfHit == maxCountHitsOfWall) {
			if (ballStruct.speedY > 0) 
				ballStruct.angle = PI / 4;

			if (ballStruct.speedY < 0)
				ballStruct.angle = (3 * PI) / 4;
		}



		// ���� ����� ������
		if (ballStruct.entity->y() > deskGroundHeightLevel + desksDiff) {
			_ballFixedOnPlatform = true;

			
			// ���� ������ ������ ���, ��������� ��� �� GameOver
			if (_lives == 0) {
				for (auto i : _scene->items()) {
					if (i == _backgroundItem) {
						_scene->removeItem(i);

						delete _backgroundItem;
						QPixmap background("resources/backgrounds/game_over_background.png");
						background = background.scaled(1920, 800);								// ��������� ��� �� ������ ��������

						_backgroundItem = new QGraphicsPixmapItem(background);
						_scene->addItem(_backgroundItem);

						setCursor(Qt::CrossCursor);

						break;
					}
				}
			}
			else {	// ��������� ���������� ������
				
				--_lives;

				currentCountOfHit = 0;

				// ������� ������ �������� � �������
				for (auto i : _scene->items()) {
					if (i == _livesCountItem) {

						_scene->removeItem(i);

						delete _livesCountItem;

						// ��������� ����� �������� � �������
						
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
	
	// ������������ �������� ������ � ����������

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

	// ���� ��� ��������� ����������, �� ������ ����� � ������� ������� ���������� ������
	if (_level.empty() && !_isLevelComplete) {
				
		// ������� �������� ������
		_isLevelComplete = true;

		// ������ ����� � ��� ���������, ����� ����� � ����

		for (auto i : _scene->items()) {
			if (i == ballStruct.entity) {
				_scene->removeItem(i);
				break;
			}
		}

		// ������� ������� ���������� ������

		QPixmap levelCompletePicture("resources/misc/level_complete.png");
		
		_levelCompleteItem = new QGraphicsPixmapItem(levelCompletePicture);

		// ���������� ������� (����� ���������� �� ������ ������)
		
		{
			const auto centerOfScreenX = rightBorderShift - leftBorderShift;
			const auto centerOfScreenY = _scene->height() / 2;

			_levelCompleteItem->setPos(centerOfScreenX - levelCompletePicture.width(), centerOfScreenY - 0.5 * levelCompletePicture.height());
		}

		_scene->addItem(_levelCompleteItem);
	}

	
}

/////////////////
// ������ �����
/////////////////

// ���� ���������� ���� �������� (�������� ����)
void Arcanoid::openMainMenu() {
	const auto mainMenu = new SettingsWindow(_settings);
	mainMenu->setAttribute(Qt::WA_DeleteOnClose);
	mainMenu->show();

	this->close();
}

// ���� �������� ������
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

// ����� ��������� ����� ��������
void Arcanoid::goToLevel1() {
	_settings.setLevel(0);
	restartLevel();
}

void Arcanoid::goToLevel2() {
	_settings.setLevel(1);
	restartLevel();
}
