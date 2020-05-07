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

	// ��������� �����
	struct deskInfo {
		bool isAnimated;						// ���� �� ������ �������� �����
		QPixmap picture;						// �������� �����
		QPixmap groundPicture;					// �������� ����������� �����
		QGraphicsPixmapItem* entity;			// ���� �����
		QGraphicsPixmapItem* groundEntity;		// �� ��������

		deskInfo() : isAnimated(false), entity(nullptr), groundEntity(nullptr) {}
	};

	// �����
	struct ballInfo {
		QPixmap _picture;						// �������� ������
		QGraphicsPixmapItem* entity;			// ��� �����
		double speedX;							// �������� �������� �� X
		double speedY;							// �������� �������� �� Y
		double angle;							// ���� �������� (���� ��������)

		ballInfo() : entity(nullptr) { }
	};
	
	QGraphicsPixmapItem* _backgroundItem;		// ���������
	QGraphicsPixmapItem* _livesCountItem;		// �������� ���������� ������
	QGraphicsPixmapItem* _levelCompleteItem;	// �������� � �������� "������� �������"

	vector<QGraphicsPixmapItem*> _level;		// ������� ������� (������� �� ������ ����������)

	size_t _frameWidth;							// ������ ����

	deskInfo deskStruct;						// ��������� �����

	ballInfo ballStruct;						// ��������� ������

	int _lives;									// ������� ���������� ������

	QGraphicsScene* _scene;						// �����
	QGraphicsView* _view;
	
	Settings& _settings;						// ���������
	const int _timerInterval = 10;				// �������� ���������� �����

	bool _ballFixedOnPlatform;					// ������: ���������� �� ��� � ����� (��������� ����)

	bool _isLevelComplete;						// ������: ������� �� �������


	void mousePressEvent(QMouseEvent* event) override;	// ���������� ������� ����� (������ ������ � �����)

	QGraphicsPixmapItem*			createBrick(int row, int column, double leftBorder, Settings::bricks_skins& brickType);	// �������� ������ ���������
	vector<QGraphicsPixmapItem*>	createTestLevel(double leftBorder);														// �������� ��������� ������
	vector<QGraphicsPixmapItem*>	createThanksLevel(double leftBorder);													// �������� ��� ������ ������
private slots:

	void updateScene();
	void openMainMenu();
	void restartLevel();

	// ��������� �� �������
	void goToLevel1();
	void goToLevel2();

public:
	Arcanoid(Settings& settings);
};