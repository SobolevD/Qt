#pragma once

#include <QWidget>

#include "Settings.h"
#include <QPixmap>
#include <QPushButton>

class BackgroundWindow : public QWidget {

	Settings& _settings;
private slots:

	void changeBackground1();
	void changeBackground2();
	void changeBackground3();
	void changeBackground4();

public:

	BackgroundWindow(Settings& settings);

};