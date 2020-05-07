#pragma once
#include "SettingsWindow.h"

#include <QFormLayout>
#include <QIcon>
#include <QPushButton>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QLabel>
#include <vector>

using namespace std;

// Обработчики радио кнопок (сложность)

void SettingsWindow::setDifficultEasy() {
	_settings.setDifficult(Settings::difficults::EASY);
}
void SettingsWindow::setDifficultNormal() {
	_settings.setDifficult(Settings::difficults::NORMAL);
}
void SettingsWindow::setDifficultHard() {
	_settings.setDifficult(Settings::difficults::HARD);
}
void SettingsWindow::setDifficultInsane() {
	_settings.setDifficult(Settings::difficults::INSANE);
}

// Обработчики для кнопок (настройки фона, шарика и кирпичиков)

void SettingsWindow::openBackgroundWindow() {
	const auto backgroundWindow = new BackgroundWindow(_settings);
	backgroundWindow->setAttribute(Qt::WA_DeleteOnClose);
	backgroundWindow->setFixedSize(backgroundWindow->sizeHint());
	backgroundWindow->setParent(this);
	backgroundWindow->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
	backgroundWindow->setWindowModality(Qt::WindowModal);
	backgroundWindow->show();
}

void SettingsWindow::openBallSkinWindow() {
	const auto ballSkinWindow = new BallSkinWindow(_settings);
	ballSkinWindow->setAttribute(Qt::WA_DeleteOnClose);
	ballSkinWindow->setFixedSize(ballSkinWindow->sizeHint());
	ballSkinWindow->setParent(this);
	ballSkinWindow->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
	ballSkinWindow->setWindowModality(Qt::WindowModal);
	ballSkinWindow->show();
}

void SettingsWindow::openBricksSkinWindow() {
	const auto bricksSkinWindow = new BricksSkinWindow(_settings);
	bricksSkinWindow->setAttribute(Qt::WA_DeleteOnClose);
	bricksSkinWindow->setFixedSize(bricksSkinWindow->sizeHint());
	bricksSkinWindow->setParent(this);
	bricksSkinWindow->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
	bricksSkinWindow->setWindowModality(Qt::WindowModal);
	bricksSkinWindow->show();
}

// Запуск игры

void SettingsWindow::startGame() {
	const auto gameWindow = new Arcanoid(_settings);
	gameWindow->setAttribute(Qt::WA_DeleteOnClose);
	gameWindow->setFixedSize(gameWindow->sizeHint());
	gameWindow->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowTitleHint | Qt::CustomizeWindowHint);
	gameWindow->setWindowModality(Qt::WindowModal);
	gameWindow->show();
	this->close();
}

// Создать радио кнопки
static QVBoxLayout* createRadioButtons(QWidget* parent, const vector<QString>& texts, vector<QRadioButton*>& rButtons) {
	auto button1 = new QRadioButton(parent);
	auto button2 = new QRadioButton(parent);
	vector<QRadioButton*> radioButtons;

	// Спец шрифт
	QFont radioButtonTextFont;
	radioButtonTextFont.setPixelSize(30);

	for (auto i = 0; i < texts.size(); ++i) {
		radioButtons.push_back(new QRadioButton(parent));
		radioButtons[i]->setText(texts[i]);
		radioButtons[i]->setFont(radioButtonTextFont);
	}

	auto radioButtonsLayout = new QVBoxLayout(parent);
	for (auto i = 0; i < radioButtons.size(); ++i)
		radioButtonsLayout->addWidget(radioButtons[i]);

	rButtons = radioButtons;

	return radioButtonsLayout;
}

// Создать кнопку
static QPushButton* createPushButton(QWidget* parent, const QString& text) {
	auto pushButton = new QPushButton(parent);
	
	// Спец шрифт
	QFont textFont;
	textFont.setPixelSize(30);

	pushButton->setText(text);
	pushButton->setFont(textFont);

	return pushButton;
}

// Окно настроек
SettingsWindow::SettingsWindow(Settings& settings) : _settings(settings) {
	   // setWindowIcon(QIcon("resources/icons/settings.png"));
	    setWindowTitle(u8"Настройки");
		setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint | Qt::WindowTitleHint | Qt::CustomizeWindowHint);

		setBackgroundRole(QPalette::ColorRole::BrightText);
		// Главная форма
		auto formLayout = new QHBoxLayout(this);

		// Коллекция с радио кнопками
		vector<QRadioButton*> radioButtons;

		// Настройки сложности игры

		vector<QString> difficultsTexts = { u8"Легко", u8"Нормально", u8"Сложно", u8"Эксперт" };
		auto radioButtonsCascade = createRadioButtons(nullptr, difficultsTexts, radioButtons);

		const auto difficultLabel = new QLabel(this);
		difficultLabel->setText(u8"Сложность:");
		
		// Спец шрифт
		QFont labelFont;
		labelFont.setPixelSize(30);

		difficultLabel->setFont(labelFont);


		const auto radioButtonsLayout = new QVBoxLayout(this);

		radioButtonsLayout->addWidget(difficultLabel);
		radioButtonsLayout->addLayout(radioButtonsCascade);

		// Дополнительные настройки

		const auto settingsLabel = new QLabel(this);
		settingsLabel->setText(u8"Другие настройки:");
		settingsLabel->setFont(labelFont);

		auto buttonBackground		= createPushButton(this, u8"Выбор фона");
		auto buttonBallSkin			= createPushButton(this, u8"Выбор шарика");
		auto buttonStartGame		= createPushButton(this, u8"СТАРТ ИГРЫ!");

		const auto otherSettingsLayout = new QVBoxLayout(this);
		otherSettingsLayout->addWidget(settingsLabel);
		otherSettingsLayout->addWidget(buttonBackground);
		otherSettingsLayout->addWidget(buttonBallSkin);
		//otherSettingsLayout->addWidget(buttonBricksSkin);
		otherSettingsLayout->addWidget(buttonStartGame);

		// Создадим два столбца

		formLayout->addLayout(radioButtonsLayout);
		formLayout->addLayout(otherSettingsLayout);

		// Стартовая настройка сложности
		
		radioButtons[1]->toggle();						// Сложность NORMAL

		// Привязка событий радио кнопок к функциям

		connect(radioButtons[0], &QRadioButton::pressed, this, &SettingsWindow::setDifficultEasy);
		connect(radioButtons[1], &QRadioButton::pressed, this, &SettingsWindow::setDifficultNormal);
		connect(radioButtons[2], &QRadioButton::pressed, this, &SettingsWindow::setDifficultHard);
		connect(radioButtons[3], &QRadioButton::pressed, this, &SettingsWindow::setDifficultInsane);

		// Привязка кнопок с выбором фона, скина шарика и кирпичей

		connect(buttonBackground, &QPushButton::pressed, this, &SettingsWindow::openBackgroundWindow);
		connect(buttonBallSkin, &QPushButton::pressed, this, &SettingsWindow::openBallSkinWindow);
		connect(buttonStartGame, &QPushButton::pressed, this, &SettingsWindow::startGame);
}

