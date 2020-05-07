#pragma once

#include <QWidget>

#include "Settings.h"
#include <QPixmap>
#include <QPushButton>

class BricksSkinWindow : public QWidget {

	Settings& _settings;
private slots:

	void changeBricksSkin1();
	void changeBricksSkin2();
	void changeBricksSkin3();
	void changeBricksSkin4();

public:

	BricksSkinWindow(Settings& settings);

};