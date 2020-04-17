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
#include "Centipede.hpp"

std::string arcade::Centipede::getName() const
{
	return "lib_arcade_centipede.so";
}

void arcade::Centipede::initGame()
{
	_isRunning = true;
	_clock_nbr = 0;
	_action = UNDEFINED;
	_score = 1;
	arcade::Entity background("background_nibbler", {"./assets/centipede/background.png", "./assets/centipede/background.bmp", "./assets/nibbler/background.txt"}, 0, 0, true);
	_gameData.addEntity(background);
	for (int i = 0; i < 30; i++) {
		arcade::Entity bonus("bonus" + std::to_string(i),
			{"./assets/centipede/bonus.png", "./assets/centipede/bonus.bmp",
				"./assets/nibbler/bonus.txt"}, (std::rand() % 98 + 1.0),
			std::rand() % 80 + 1.7, true);
		_gameData.addEntity(bonus);
	}
	arcade::Entity playerDown("playerDown", {"./assets/nibbler/player_down.png", "./assets/nibbler/player_down.bmp", "./assets/nibbler/player_down.txt"}, 51, 49.6, false);
	arcade::Entity playerUp("playerUp", {"./assets/nibbler/player_up.png", "./assets/nibbler/player_up.bmp", "./assets/nibbler/player_up.txt"}, 0, 0, false);
	arcade::Entity playerLeft("playerLeft", {"./assets/nibbler/player_left.png", "./assets/nibbler/player_left.bmp", "./assets/nibbler/player_left.txt"}, 0, 0, false);
	arcade::Entity playerRight("playerRight", {"./assets/nibbler/player_right.png", "./assets/nibbler/player_right.bmp", "./assets/nibbler/player_right.txt"}, 50, 5, true);
	for (int i = 1; i < 11; i++) {
		arcade::Entity body("body" + std::to_string(i),
			{"./assets/nibbler/body.png", "./assets/nibbler/body.bmp",
				"./assets/nibbler/body.txt"}, -10, -10, true);
		_gameData.addEntity(body);
	}
	_gameData.addEntity(playerLeft);
	_gameData.addEntity(playerRight);
	_gameData.addEntity(playerUp);
	_gameData.addEntity(playerDown);
	arcade::Entity ship("ship", {"./assets/centipede/ship.png", "./assets/centipede/ship.bmp", "./assets/centipede/ship.txt"}, 50, 90, true);
	_gameData.addEntity(ship);
	arcade::Entity laser("laser", {"./assets/centipede/laser.bmp", "./assets/centipede/laser.bmp", "./assets/centipede/laser.txt"}, -10, -90, true);
	_gameData.addEntity(laser);

	_walls = _gameData.getEntitiesPos("bonus");
}

arcade::GameData arcade::Centipede::getGameData() const
{
	return _gameData;
}

void arcade::Centipede::updateGame(arcade::action action)
{
	if (action != UNDEFINED)
		_action = action;
	static auto start = std::chrono::system_clock::now();
	auto end = std::chrono::system_clock::now();
	std::chrono::system_clock::to_time_t(end);
	std::chrono::duration<double> elapsed_seconds = end-start;

	if ((elapsed_seconds.count() > 0.01)) {
		start = std::chrono::system_clock::now();
		if (_action == LEFT && _gameData.getEntity("ship").getPos().first >= 3)
			_gameData.setEntityPos("ship", std::make_pair(_gameData.getEntity("ship").getPos().first - 1.5, _gameData.getEntity("ship").getPos().second + 0), "ship");
		else if (_action == RIGHT && _gameData.getEntity("ship").getPos().first <= 95)
			_gameData.setEntityPos("ship", std::make_pair(_gameData.getEntity("ship").getPos().first + 1.5, _gameData.getEntity("ship").getPos().second + 0), "ship");
		else if (_action == UP && _gameData.getEntity("ship").getPos().second >= 70)
			_gameData.setEntityPos("ship", std::make_pair(_gameData.getEntity("ship").getPos().first + 0, _gameData.getEntity("ship").getPos().second - 2), "ship");
		else if (_action == DOWN && _gameData.getEntity("ship").getPos().second <= 89)
			_gameData.setEntityPos("ship", std::make_pair(_gameData.getEntity("ship").getPos().first + 0, _gameData.getEntity("ship").getPos().second + 2), "ship");
		else if (_action == ACTION && _gameData.getEntity("laser").getPos().second < 0)
			_gameData.setEntityPos("laser", std::make_pair(_gameData.getEntity("ship").getPos().first + 1, _gameData.getEntity("ship").getPos().second - 2), "laser");
		_clock_nbr += 1;
		_gameData.setEntityPos("laser", std::make_pair(_gameData.getEntity("laser").getPos().first, _gameData.getEntity("laser").getPos().second - 2), "laser");
		if (_action != PAUSE)
			_action = UNDEFINED;
	}
	if (_clock_nbr == 9) {
		if (_gameData.getPlayer().getName() == "playerRight")
			setBodyPos(2, 0, "right");
		else if (_gameData.getPlayer().getName() == "playerLeft")
			setBodyPos(-2, 0, "left");
		getBonus();
		isDead();
		_clock_nbr = 0;
	}

	if (_clock_nbr == 1 && _gameData.getPlayer().getPos().first <= _gameData.getEntity("laser").getPos().first && _gameData.getPlayer().getPos().first + 2 >= _gameData.getEntity("laser").getPos().first && _gameData.getPlayer().getPos().second <= _gameData.getEntity("laser").getPos().second && _gameData.getPlayer().getPos().second + 4 >= _gameData.getEntity("laser").getPos().second) {
		int nbr = _gameData.getEntityNb();

		while (nbr >= 1) {
			_gameData.setEntityPos("body" + std::to_string(nbr), std::make_pair(-10, -10), "body");
			--nbr;
		}
		_gameData.setEntityPos("player", std::make_pair(100 - _gameData.getPlayer().getPos().first, 0), "right");
		_score += 1;
	}
	int nbr = 1;

	while (nbr <= _gameData.getEntityNb()) {
		if (_gameData.getEntity("body" + std::to_string(nbr)).getPos().first <= _gameData.getEntity("laser").getPos().first && _gameData.getPlayer().getPos().first + 4 >= _gameData.getEntity("laser").getPos().first && _gameData.getPlayer().getPos().second -2 <= _gameData.getEntity("laser").getPos().second && _gameData.getPlayer().getPos().second + 4 >= _gameData.getEntity("laser").getPos().second) {
			_gameData.setEntityPos("body" + std::to_string(nbr), std::make_pair(-10, -10), "body");
			_gameData.getEntity("body" + std::to_string(nbr)).setAlive(false);
		}
		++nbr;
	}

	nbr = _gameData.getEntityNb();
	while (nbr >= 1) {
		if (_gameData.getEntity("ship").getPos().first >= _gameData.getEntity("body" + std::to_string(nbr)).getPos().first && _gameData.getEntity("ship").getPos().first <= _gameData.getEntity("body" + std::to_string(nbr)).getPos().first + 2 && _gameData.getEntity("ship").getPos().second >= _gameData.getEntity("body" + std::to_string(nbr)).getPos().second && _gameData.getEntity("ship").getPos().second <= _gameData.getEntity("body" + std::to_string(nbr)).getPos().second + 4 && _gameData.getEntity("body" + std::to_string(nbr)).getIsAlive()) {
			_isRunning = false;
			return;
		}
		--nbr;
	}
}

void arcade::Centipede::isDead()
{
	if (_gameData.getPlayer().getPos().first <= 0 || _gameData.getPlayer().getPos().second <= 1.5) {
		setBodyPos(0, 4, "right");
	}
	if (_gameData.getPlayer().getPos().first >= 99) {
		setBodyPos(0, 4, "left");
	}
	if ( _gameData.getPlayer().getPos().second >= 96) {
		int nbr = _gameData.getEntityNb() - 6;
		_gameData.setEntityPos("player", std::make_pair(100 - _gameData.getPlayer().getPos().first, -10), "right");
		while (nbr >= 1) {
			_gameData.getEntity("body" + std::to_string(nbr)).setAlive(true);
			--nbr;
		}
		_score -= 1;
		if (_score < 1)
			_score = 1;
	}
}

void arcade::Centipede::setBodyPos(float x, float y, std::string dir)
{
	int nbr = _gameData.getEntityNb();

	while (nbr >= 2) {
		if (_gameData.getEntity("body" + std::to_string(nbr)).getIsAlive())
			_gameData.setEntityPos("body" + std::to_string(nbr), std::make_pair(_gameData.getEntity("body" + std::to_string(nbr - 1)).getPos().first, _gameData.getEntity("body" + std::to_string(nbr - 1)).getPos().second), "body");
		--nbr;
	}
	_gameData.setEntityPos("body1", std::make_pair(_gameData.getPlayer().getPos().first, _gameData.getPlayer().getPos().second), "body");
	_gameData.setEntityPos("player", std::make_pair(_gameData.getPlayer().getPos().first + x, _gameData.getPlayer().getPos().second + y), dir);
}

void arcade::Centipede::getBonus()
{
	for(const auto &it : _walls) {
		if (_gameData.getPlayer().getPos().first <= it.first && _gameData.getPlayer().getPos().first + 2 >= it.first && _gameData.getPlayer().getPos().second <= it.second && _gameData.getPlayer().getPos().second + 4 >= it.second) {
			if (_gameData.getPlayer().getName() == "playerRight")
				setBodyPos(0, 4, "left");
			else if (_gameData.getPlayer().getName() == "playerLeft")
				setBodyPos(0, 4, "right");
			return;
		}
	}
}

bool arcade::Centipede::getEnd() const
{
	return !_isRunning;
}

int arcade::Centipede::getScore() const
{
	return (_score);
}

void arcade::Centipede::deleteGame()
{
	_gameData.reset();
}

extern "C" arcade::IGame *entryPoint()
{
	return new arcade::Centipede;
}