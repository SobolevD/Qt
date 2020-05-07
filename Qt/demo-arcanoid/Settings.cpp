#include "Settings.h"

#include <stdexcept>

Settings::Settings() : _difficult(difficults::NORMAL), _ballSkin(ball_skins::RED), _bricksSkin(bricks_skins::RED), _background(0), _currentLevel(0) {}

Settings::difficults Settings::difficult() const {
	return _difficult;
}

Settings::ball_skins Settings::ballSkin() const {
	return _ballSkin;
}

Settings::bricks_skins Settings::bricksSkin() const {
	return _bricksSkin;
}

size_t Settings::background() const {
	return _background;
}

size_t Settings::level() const {
	return _currentLevel;
}

void Settings::setDifficult(difficults newDifficult) {
	if (newDifficult != difficults::EASY && newDifficult != difficults::NORMAL && newDifficult != difficults::HARD && newDifficult != difficults::INSANE)
		throw std::invalid_argument("difficult");

	_difficult = newDifficult;
}

void Settings::setBallSkin(ball_skins newBallSkin) {
	if (newBallSkin != ball_skins::RED && newBallSkin != ball_skins::BLUE && newBallSkin != ball_skins::GREEN && newBallSkin != ball_skins::YELLOW)
		throw std::invalid_argument("ball_skin");

	_ballSkin = newBallSkin;
}

void Settings::setBricksSkin(bricks_skins newBricksSkin) {
	if (newBricksSkin != bricks_skins::BLUE && newBricksSkin != bricks_skins::GOLD && newBricksSkin != bricks_skins::RED && newBricksSkin != bricks_skins::WHITE)
		throw std::invalid_argument("bricks_skin");

	_bricksSkin = newBricksSkin;
}

void Settings::setBackground(size_t newBackground) {
	if (newBackground <= 0 && newBackground > 3)
		throw std::invalid_argument("background");

	_background = newBackground;
}

void Settings::setLevel(size_t levelID) {
	_currentLevel = levelID;
}