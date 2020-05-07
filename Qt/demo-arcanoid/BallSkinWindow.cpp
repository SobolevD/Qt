#pragma once

#include "BallSkinWindow.h"
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <iostream>
using namespace std;
void BallSkinWindow::changeBallSkin1() {
	_settings.setBallSkin(Settings::ball_skins::BLUE);
	close();
}
void BallSkinWindow::changeBallSkin2() {
	_settings.setBallSkin(Settings::ball_skins::YELLOW);
	close();
}
void BallSkinWindow::changeBallSkin3() {
	_settings.setBallSkin(Settings::ball_skins::GREEN);
	close();
}
void BallSkinWindow::changeBallSkin4() {
	_settings.setBallSkin(Settings::ball_skins::RED);
	close();
}

BallSkinWindow::BallSkinWindow(Settings& settings) : _settings(settings) {
	auto picture1 = new QPixmap("resources/balls/ball_blue.png");
	auto picture2 = new QPixmap("resources/balls/ball_yellow.png");
	auto picture3 = new QPixmap("resources/balls/ball_green.png");
	auto picture4 = new QPixmap("resources/balls/ball_red.png");

	// Размер картинки
	
	QSize pictureSize(250, 250);

	// Сжимаем картинки

	*picture1 = picture1->scaled(pictureSize);
	*picture2 = picture2->scaled(pictureSize);
	*picture3 = picture3->scaled(pictureSize);
	*picture4 = picture4->scaled(pictureSize);

	auto layout = new QGridLayout(this);

	auto mainLabel = new QLabel(this);
	mainLabel->setText("Choose ball skin: ");

	// Настройка шрифта
	QFont fontMainLabel;
	fontMainLabel.setPixelSize(80);
	mainLabel->setFont(fontMainLabel);

	auto backgroundButton1 = new QPushButton(this);
	auto backgroundButton2 = new QPushButton(this);
	auto backgroundButton3 = new QPushButton(this);
	auto backgroundButton4 = new QPushButton(this);

	backgroundButton1->setIcon(QIcon(*picture1));
	backgroundButton2->setIcon(QIcon(*picture2));
	backgroundButton3->setIcon(QIcon(*picture3));
	backgroundButton4->setIcon(QIcon(*picture4));

	backgroundButton1->setIconSize(pictureSize);
	backgroundButton2->setIconSize(pictureSize);
	backgroundButton3->setIconSize(pictureSize);
	backgroundButton4->setIconSize(pictureSize);

	layout->addWidget(mainLabel, 0, 0, 1, 2);
	layout->addWidget(backgroundButton1, 1, 0);
	layout->addWidget(backgroundButton2, 1, 1);
	layout->addWidget(backgroundButton3, 2, 0);
	layout->addWidget(backgroundButton4, 2, 1);

	connect(backgroundButton1, &QAbstractButton::pressed, this, &BallSkinWindow::changeBallSkin1);
	connect(backgroundButton2, &QAbstractButton::pressed, this, &BallSkinWindow::changeBallSkin2);
	connect(backgroundButton3, &QAbstractButton::pressed, this, &BallSkinWindow::changeBallSkin3);
	connect(backgroundButton4, &QAbstractButton::pressed, this, &BallSkinWindow::changeBallSkin4);
}