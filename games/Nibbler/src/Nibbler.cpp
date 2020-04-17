/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** description
*/

#include <chrono>
#include <time.h>
#include <zconf.h>
#include "Entity.hpp"
#include "Nibbler.hpp"

std::string arcade::Nibbler::getName() const
{
	return "lib_arcade_nibbler.so";
}

void arcade::Nibbler::initGame()
{
	_isRunning = true;
	_action = UNDEFINED;
	_score = 1;
	arcade::Entity background("background_nibbler", {"./assets/nibbler/background.png", "./assets/nibbler/background.bmp", "./assets/nibbler/background.txt"}, 0, 0, true);
	arcade::Entity bonus("bonus", {"./assets/nibbler/bonus.png", "./assets/nibbler/bonus.bmp", "./assets/nibbler/bonus.txt"}, (std::rand() % 98 + 1.0), std::rand() % 90 + 1.7, true);
	arcade::Entity playerDown("playerDown", {"./assets/nibbler/player_down.png", "./assets/nibbler/player_down.bmp", "./assets/nibbler/player_down.txt"}, 51, 49.6, false);
	arcade::Entity playerUp("playerUp", {"./assets/nibbler/player_up.png", "./assets/nibbler/player_up.bmp", "./assets/nibbler/player_up.txt"}, 0, 0, false);
	arcade::Entity playerLeft("playerLeft", {"./assets/nibbler/player_left.png", "./assets/nibbler/player_left.bmp", "./assets/nibbler/player_left.txt"}, 0, 0, false);
	arcade::Entity playerRight("playerRight", {"./assets/nibbler/player_right.png", "./assets/nibbler/player_right.bmp", "./assets/nibbler/player_right.txt"}, 51, 49.6, true);
	arcade::Entity body1("body1", {"./assets/nibbler/body.png", "./assets/nibbler/body.bmp", "./assets/nibbler/body.txt"}, -10, -10, true);
	arcade::Entity body2("body2", {"./assets/nibbler/body.png", "./assets/nibbler/body.bmp", "./assets/nibbler/body.txt"}, -10, -10, true);
	arcade::Entity body3("body3", {"./assets/nibbler/body.png", "./assets/nibbler/body.bmp", "./assets/nibbler/body.txt"}, -10, -10, true);

	_gameData.addEntity(background);
	_gameData.addEntity(bonus);
	_gameData.addEntity(body1);
	_gameData.addEntity(body2);
	_gameData.addEntity(body3);
	_gameData.addEntity(playerLeft);
	_gameData.addEntity(playerUp);
	_gameData.addEntity(playerDown);
	_gameData.addEntity(playerRight);
}

arcade::GameData arcade::Nibbler::getGameData() const
{
	return _gameData;
}

void arcade::Nibbler::updateGame(arcade::action action)
{
	if (action != UNDEFINED)
		_action = action;
	static auto start = std::chrono::system_clock::now();
	auto end = std::chrono::system_clock::now();
	std::chrono::system_clock::to_time_t(end);

	std::chrono::duration<double> elapsed_seconds = end-start;

	if ((elapsed_seconds.count() > 0.15 - (static_cast<float>(_score) / 500.0) ) || (_action == ACTION && elapsed_seconds.count() > 0.08 - (static_cast<float>(_score) / 500.0))) {
		start = std::chrono::system_clock::now();
		if (_action == arcade::action::LEFT && _gameData.getPlayer().getName().find("Down") != std::string::npos)
			setBodyPos(2, 0, "right");
		else if (_action == arcade::action::RIGHT && _gameData.getPlayer().getName().find("Down") != std::string::npos)
			setBodyPos(-2, 0, "left");
		else if (_action == arcade::action::LEFT && _gameData.getPlayer().getName().find("Up") != std::string::npos)
			setBodyPos(-2, 0, "left");
		else if (_action == arcade::action::RIGHT && _gameData.getPlayer().getName().find("Up") != std::string::npos)
			setBodyPos(2, 0, "right");
		else if (_action == arcade::action::LEFT && _gameData.getPlayer().getName().find("Right") != std::string::npos)
			setBodyPos(0, -4, "up");
		else if (_action == arcade::action::RIGHT && _gameData.getPlayer().getName().find("Right") != std::string::npos)
			setBodyPos(0, 4, "down");
		else if (_action == arcade::action::LEFT && _gameData.getPlayer().getName().find("Left") != std::string::npos)
			setBodyPos(0, 4, "down");
		else if (_action == arcade::action::RIGHT && _gameData.getPlayer().getName().find("Left") != std::string::npos)
			setBodyPos(0, -4, "up");
		else if (_action != arcade::action::LEFT && _action != RIGHT && _action != PAUSE) {
			if (_gameData.getPlayer().getName() == "playerUp")
				setBodyPos(0, -4, "up");
			else if (_gameData.getPlayer().getName() == "playerDown")
				setBodyPos(0, 4, "down");
			else if (_gameData.getPlayer().getName() == "playerRight")
				setBodyPos(2, 0, "right");
			else if (_gameData.getPlayer().getName() == "playerLeft")
				setBodyPos(-2, 0, "left");
		}
		if (_action != PAUSE && _action != ACTION)
			_action = UNDEFINED;
	}
	getBonus();
	isDead();
}

bool arcade::Nibbler::getEnd() const
{
	return !_isRunning;
}

void arcade::Nibbler::isDead()
{
	if (_gameData.getPlayer().getPos().first <= 0 || _gameData.getPlayer().getPos().second <= 1.5 || _gameData.getPlayer().getPos().first >= 99 || _gameData.getPlayer().getPos().second >= 96) {
		_isRunning = false;
	}
	int nbr = _gameData.getEntityNb() - 6;
	while (nbr >= 1) {
		if (_gameData.getPlayer().getPos() == _gameData.getEntity("body" + std::to_string(nbr)).getPos())
			_isRunning = false;
		--nbr;
	}
}

void arcade::Nibbler::setBodyPos(float x, float y, std::string dir)
{
	int nbr = _gameData.getEntityNb() - 6;

	while (nbr >= 2) {
		_gameData.setEntityPos("body" + std::to_string(nbr), std::make_pair(_gameData.getEntity("body" + std::to_string(nbr - 1)).getPos().first, _gameData.getEntity("body" + std::to_string(nbr - 1)).getPos().second), "body");
		--nbr;
	}
	_gameData.setEntityPos("body1", std::make_pair(_gameData.getPlayer().getPos().first, _gameData.getPlayer().getPos().second), "body");
	_gameData.setEntityPos("player", std::make_pair(_gameData.getPlayer().getPos().first + x, _gameData.getPlayer().getPos().second + y), dir);
}

void arcade::Nibbler::getBonus()
{
	if (_gameData.getPlayer().getPos().first <= _gameData.getEntity("bonus").getPos().first && _gameData.getPlayer().getPos().first + 2 >= _gameData.getEntity("bonus").getPos().first && _gameData.getPlayer().getPos().second <= _gameData.getEntity("bonus").getPos().second && _gameData.getPlayer().getPos().second + 4 >= _gameData.getEntity("bonus").getPos().second) {
		_gameData.setEntityPos("bonus", std::make_pair(std::rand() % 95 + 1, std::rand() % 90 + 1.7), "bonus");
		if (std::rand() % 2 == 0) {
			arcade::Entity body(
				"body" + (std::to_string(_gameData.getEntityNb() - 5)),
				{"assets/nibbler/body.png", "assets/nibbler/body.bmp",
					"assets/nibbler/body.txt"}, -100, -100, true);
			_gameData.addEntity(body);
		} else {
			arcade::Entity body(
				"body" + (std::to_string(_gameData.getEntityNb() - 5)),
				{"assets/nibbler/body.png", "assets/nibbler/body.bmp",
					"assets/nibbler/body.txt"}, -100, -100, true);
			_gameData.addEntity(body);
			arcade::Entity body2(
				"body" + (std::to_string(_gameData.getEntityNb() - 5)),
				{"assets/nibbler/body.png", "assets/nibbler/body.bmp",
					"assets/nibbler/body.txt"}, -100, -100, true);
			_gameData.addEntity(body2);
		}
		_score += 1;
	}
}

int arcade::Nibbler::getScore() const
{
	return static_cast<int>(_score);
}

void arcade::Nibbler::deleteGame()
{
}

extern "C" arcade::IGame *entryPoint()
{
	return new arcade::Nibbler;
}