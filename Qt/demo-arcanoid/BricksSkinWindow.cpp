#pragma once

#include "BricksSkinWindow.h"
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <iostream>
using namespace std;
void BricksSkinWindow::changeBricksSkin1() {
	_settings.setBricksSkin(Settings::bricks_skins::BLUE);
	close();
}
void BricksSkinWindow::changeBricksSkin2() {
	_settings.setBricksSkin(Settings::bricks_skins::GOLD);
	close();
}
void BricksSkinWindow::changeBricksSkin3() {
	_settings.setBricksSkin(Settings::bricks_skins::RED);
	close();
}
void BricksSkinWindow::changeBricksSkin4() {
	_settings.setBricksSkin(Settings::bricks_skins::WHITE);
	close();
}

BricksSkinWindow::BricksSkinWindow(Settings& settings) : _settings(settings) {
	auto picture1 = new QPixmap("resources/bricks/blue_brick.png");
	auto picture2 = new QPixmap("resources/bricks/gold_brick.png");
	auto picture3 = new QPixmap("resources/bricks/red_brick.png");
	auto picture4 = new QPixmap("resources/bricks/white_brick.jpg");

	// Размер картинки

	QSize pictureSize(250, 80);

	// Сжимаем картинки

	*picture1 = picture1->scaled(pictureSize);
	*picture2 = picture2->scaled(pictureSize);
	*picture3 = picture3->scaled(pictureSize);
	*picture4 = picture4->scaled(pictureSize);

	auto layout = new QGridLayout(this);

	auto mainLabel = new QLabel(this);
	mainLabel->setText("Choose bricks skin: ");

	// Настройка шрифта
	QFont fontMainLabel;
	fontMainLabel.setPixelSize(60);
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

	connect(backgroundButton1, &QAbstractButton::pressed, this, &BricksSkinWindow::changeBricksSkin1);
	connect(backgroundButton2, &QAbstractButton::pressed, this, &BricksSkinWindow::changeBricksSkin2);
	connect(backgroundButton3, &QAbstractButton::pressed, this, &BricksSkinWindow::changeBricksSkin3);
	connect(backgroundButton4, &QAbstractButton::pressed, this, &BricksSkinWindow::changeBricksSkin4);
}