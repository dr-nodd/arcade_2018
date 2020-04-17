/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Menu
*/

#include <dirent.h>
#include <cstring>
#include "Entity.hpp"
#include "Menu.hpp"

arcade::Menu::Menu() : _isRunning(true)
{
}

void arcade::Menu::setBackground()
{
	arcade::Entity backgroundEntity("background",
		{"./assets/menu/background.png", "./assets/menu/background.bmp",
			"./assets/menu/background.txt"}, 0, 0, true);

	_data.addEntity(backgroundEntity);
	_data.setEntityPos("background", std::make_pair(0, 0), "background");
}

void arcade::Menu::setGameName()
{
	_sizeModifier = 100 / (_gamesLibraries.size() + 1);
	arcade::Entity arrowEntity("arrow",
		{"./assets/menu/arrow.bmp", "./assets/menu/arrow.bmp",
			"./assets/menu/arrow.txt"}, _sizeModifier, 55, true);
	_data.addEntity(arrowEntity);
	_data.setEntityPos("arrow", std::make_pair(_sizeModifier, 55), "arrow");
	_arrowPos = _sizeModifier;
	int pos = 0;
	for (const auto &it : _gamesLibraries) {
		pos += _sizeModifier;
		arcade::Entity gameNameEntity(cutGameName(it), cutGameName(it), pos, 50);
		_data.addEntity(gameNameEntity);
		_data.setEntityPos(cutGameName(it), std::make_pair(pos, 50), cutGameName(it));
	}
}

void arcade::Menu::getLibName()
{
	struct dirent *entry;
	DIR *dir = opendir("./");
	std::string tmpPath = "./";

	if (dir == nullptr)
		throw (std::runtime_error("Error while opening ./ directory"));
	while ((entry = readdir(dir)) != nullptr) {
		if (entry->d_name[0] != '.' &&
			std::strncmp(entry->d_name, "lib_arcade_", 11) == 0) {
			_libs.emplace_back(tmpPath + entry->d_name);
		}
	}
	closedir(dir);
	setLibName();
}

void arcade::Menu::setLibName()
{
	int pos = 75;
	for (const auto &it : _libs) {
		arcade::Entity libNameEntity(cutLibName(it), cutLibName(it), 85, pos);
		_data.addEntity(libNameEntity);
		_data.setEntityPos(cutLibName(it), std::make_pair(85, pos), cutLibName(it));
		pos += 5;
	}
}

std::string arcade::Menu::cutGameName(const std::string libName)
{
	std::string res_name = libName.substr(11, libName.length());

	res_name.resize(res_name.length() - 3);
	return (res_name);
}

std::string arcade::Menu::cutLibName(const std::string libName)
{
	std::string res_name = libName.substr(13, libName.length());

	res_name.resize(res_name.length() - 3);
	return (res_name);
}

std::vector<arcade::Entity> arcade::Menu::getEntities()
{
	return _data.getEntityVector();
}

void arcade::Menu::setRunningState(bool state)
{
	_isRunning = state;
}

bool arcade::Menu::getRunningState()
{
	return _isRunning;
}

void arcade::Menu::searchGamesLibraries()
{
	struct dirent *entry;
	std::vector<std::string> game_names;
	DIR *dir = opendir("./games");

	if (dir == nullptr)
		throw (std::runtime_error("Error while opening ./games directory"));
	while ((entry = readdir(dir)) != nullptr)
		if (entry->d_name[0] != '.' &&
			strncmp(entry->d_name, "lib_arcade_", 11) == 0)
			_gamesLibraries.emplace_back(entry->d_name);
	closedir(dir);
	setGameName();
}

void arcade::Menu::setInput(arcade::action action)
{
	_action = action;
}

int arcade::Menu::checkAction()
{
	switch (_action) {
	case (RIGHT):
		_arrowPos += _sizeModifier;
		if (_arrowPos >= 99)
			_arrowPos = _sizeModifier;
		_data.setEntityPos("arrow", std::make_pair(_arrowPos, 55), "arrow");
		_action = UNDEFINED;
		break;
	case (LEFT):
		_arrowPos -= _sizeModifier;
		if (_arrowPos < 1)
			_arrowPos = _sizeModifier * (_gamesLibraries.size());
		_data.setEntityPos("arrow", std::make_pair(_arrowPos, 55), "arrow");
		_action = UNDEFINED;
		break;
	case (UP):
		_action = UNDEFINED;
		break;
	case (DOWN):
		_action = UNDEFINED;
		break;
	case (ENTER):
		_action = UNDEFINED;
		return (_arrowPos / _sizeModifier);
	case (PREV_LIB):
		_action = UNDEFINED;
		break;
	case (NEXT_LIB):
		_action = UNDEFINED;
		break;
	default:
		break;
	}
	return (0);
}
