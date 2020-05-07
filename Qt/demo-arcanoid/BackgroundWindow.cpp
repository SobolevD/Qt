#pragma once

#include "BackgroundWindow.h"
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <iostream>
using namespace std;
void BackgroundWindow::changeBackground1() {
	_settings.setBackground(0);
	close();
}
void BackgroundWindow::changeBackground2() {
	_settings.setBackground(1);
	close();
}
void BackgroundWindow::changeBackground3() {
	_settings.setBackground(2);
	close();
}
void BackgroundWindow::changeBackground4() {
	_settings.setBackground(3);
	close();
}

BackgroundWindow::BackgroundWindow(Settings& settings) : _settings(settings) {
	auto picture1 = new QPixmap("resources/backgrounds/background_1.jpg");
	auto picture2 = new QPixmap("resources/backgrounds/background_2.jpg");
	auto picture3 = new QPixmap("resources/backgrounds/background_3.jpg");
	auto picture4 = new QPixmap("resources/backgrounds/background_4.jpg");

	// Размер картинки
	QSize pictureSize(390, 300);

	// Сжимаем картинки

	*picture1 = picture1->scaled(pictureSize);
	*picture2 = picture2->scaled(pictureSize);
	*picture3 = picture3->scaled(pictureSize);
	*picture4 = picture4->scaled(pictureSize);

	auto layout = new QGridLayout(this);

	auto mainLabel = new QLabel(this);
	mainLabel->setText("Choose background: ");

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
	
	connect(backgroundButton1, &QAbstractButton::pressed, this, &BackgroundWindow::changeBackground1);
	connect(backgroundButton2, &QAbstractButton::pressed, this, &BackgroundWindow::changeBackground2);
	connect(backgroundButton3, &QAbstractButton::pressed, this, &BackgroundWindow::changeBackground3);
	connect(backgroundButton4, &QAbstractButton::pressed, this, &BackgroundWindow::changeBackground4);
}