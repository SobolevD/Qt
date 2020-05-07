#pragma once

#include <QWidget>

#include "Settings.h"
#include <QPixmap>
#include <QPushButton>

class BallSkinWindow : public QWidget {

	Settings& _settings;
private slots:

	void changeBallSkin1();
	void changeBallSkin2();
	void changeBallSkin3();
	void changeBallSkin4();

public:

	BallSkinWindow(Settings& settings);

};