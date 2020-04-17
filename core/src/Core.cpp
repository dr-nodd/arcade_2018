/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Created by folamie,
*/

#include <cstring>
#include <dirent.h>
#include <dlfcn.h>
#include <zconf.h>
#include <iostream>
#include "Core.hpp"

arcade::Core::Core(char *lib) : _selected_game(0), _action(UNDEFINED),
	_game_handle(nullptr)
{
	std::srand(time(0));
	_menu.setBackground();
	_menu.searchGamesLibraries();
	_menu.getLibName();
	loadGraphLib(lib);
	mainMenu();
}

void arcade::Core::loadGraphLib(const char *av)
{
	char *error;
	_graph_handle = dlopen(av, RTLD_LAZY);
	error = dlerror();
	if (!_graph_handle)
		throw (std::runtime_error(error));
	_graph = ((IGraph *(*)())dlsym(_graph_handle, "entryPoint"))();
	error = dlerror();
	if (!_graph)
		throw (std::runtime_error(error));
	whatLibAreThere();
	if (_menu.getRunningState()) {
		for (unsigned long int i = 0; i < _menu.getEntities().size(); i++) {
			if (_menu.getEntities().at(i).getType() == "sprite") {
				_graph->setEntity(_menu.getEntities().at(i).getName(),
								  _menu.getEntities().at(i).getPath(),
								  _menu.getEntities().at(i).getPos());
			} else {
				_graph->setEntity(_menu.getEntities().at(i).getName(),
								  _menu.getEntities().at(i).getText(),
								  _menu.getEntities().at(i).getPos());
			}
		}
	} else {
		for (int i = 0; i < _game->getGameData().getEntityNb(); i++) {
			_graph->setEntity(_game->getGameData().getEntity(i).getName(),
				_game->getGameData().getEntity(i).getPath(),
				_game->getGameData().getEntity(i).getPos());
		}
	}
}

void arcade::Core::whatLibAreThere()
{
	int i = 0;
	struct dirent *entry;
	DIR *dir = opendir("./");
	std::string tmpPath = "./";

	if (dir == nullptr)
		throw (std::runtime_error("Error while opening ./ directory"));
	while ((entry = readdir(dir)) != nullptr)
		if (entry->d_name[0] != '.' &&
			std::strncmp(entry->d_name, "lib_arcade_", 11) == 0) {
			_libs.emplace(i, tmpPath + entry->d_name);
			i++;
		}
	closedir(dir);
}

void arcade::Core::mainMenu()
{
	while (_action != QUIT) {
		_action = arcade::action::UNDEFINED;
		_graph->initFrame();
		_graph->setAction(&_action);
		_menu.setInput(_action);
		_selected_game = _menu.checkAction();
		if (_action != UNDEFINED) {
			checkAction();
			if (_selected_game != 0) {
				if (_menu.getRunningState())
					_menu.setRunningState(false);
				preloadGameLib();
				runArcade();
			}
		}
		this->displayMenu();
		_graph->renderFrame();
	}
	_graph->deleteLib();
	dlclose(_graph_handle);
	if (_game_handle != nullptr)
		dlclose(_game_handle);
}

void arcade::Core::checkAction()
{
	int i = checkCurrentLib();
	int j = checkCurrentGame();
	switch (_action) {
	case (RESTART):
		if (!_menu.getRunningState()) {
			_game->deleteGame();
			dlclose(_game_handle);
			loadGameLib(_games.at(j));
			_action = UNDEFINED;
		}
		break;
	case (BACK):
		if (!_menu.getRunningState()) {
			_menu.setRunningState(true);
		}
		break;
	case (PREV_LIB):
		i -= 1;
		if (i < 0)
			i = static_cast<int>(_libs.size()) - 1;
		_graph->deleteLib();
		dlclose(_graph_handle);
		loadGraphLib(_libs[i].c_str());
		_action = UNDEFINED;
		break;
	case (NEXT_LIB):
		i += 1;
		if (i > static_cast<int>(_libs.size()) - 1)
			i = 0;
		_graph->deleteLib();
		dlclose(_graph_handle);
		loadGraphLib(_libs[i].c_str());
		_action = UNDEFINED;
		break;
	case (PREV_GAME):
		if (!_menu.getRunningState()) {
			j -= 1;
			if (j < 0)
				j = static_cast<int>(_games.size()) - 1;
			for (int n = 0; n < _game->getGameData().getEntityNb(); n++)
				_graph->deleteEntity(_game->getGameData().getEntity(i).getName());
			_game->deleteGame();
			dlclose(_game_handle);
			loadGameLib(_games.at(j));
			int e = 0;
			while (e < _game->getGameData().getEntityNb()) {
				_graph->setEntity(_game->getGameData().getEntity(i).getName(),
					_game->getGameData().getEntity(i).getPath(),
					_game->getGameData().getEntity(i).getPos());
				e++;
			}
			_action = UNDEFINED;
		}
		break;
	case (NEXT_GAME):
		if (!_menu.getRunningState()) {
			j += 1;
			if (j > static_cast<int>(_games.size()) - 1)
				j = 0;
			for (int n = 0; n < _game->getGameData().getEntityNb(); n++)
				_graph->deleteEntity(_game->getGameData().getEntity(i).getName());
			_game->deleteGame();
			dlclose(_game_handle);
			loadGameLib(_games.at(j));
			int e = 0;
			while (e < _game->getGameData().getEntityNb()) {
				_graph->setEntity(_game->getGameData().getEntity(i).getName(),
					_game->getGameData().getEntity(i).getPath(),
					_game->getGameData().getEntity(i).getPos());
				e++;
			}
			_action = UNDEFINED;
		}
		break;
	default:
		break;
	}
}

int arcade::Core::checkCurrentLib()
{
	int i = 0;
	for (const auto &it : _libs) {
		if ("./" + getGraph() == it.second)
			return it.first;
		i++;
	}
	return i;
}

int arcade::Core::checkCurrentGame()
{
	long unsigned int i = 0;
	for (; i < _games.size(); i++)
		if (getGame() == _games.at(i))
			return i;
	return 0;
}

void arcade::Core::displayMenu()
{
	for (long unsigned int i = 0; i < _menu.getEntities().size(); ++i) {
		_graph->updatePos(_menu.getEntities().at(i).getName(),
			_menu.getEntities().at(i).getPos());
		_graph->display(_menu.getEntities().at(i).getName());
	}
}

void arcade::Core::preloadGameLib()
{
	struct dirent *entry;
	DIR *dir = opendir("./games");
	std::string selected_game_lib;

	if (dir == nullptr)
		throw (std::runtime_error("Error in game lib loading"));
	while ((entry = readdir(dir)) != nullptr)
		if (entry->d_name[0] != '.' &&
			strncmp(entry->d_name, "lib_arcade_", 11) == 0)
			_games.emplace_back(entry->d_name);
	if (_games.empty())
		throw (std::runtime_error("Couldn't find any games"));
	selected_game_lib = _games[_selected_game - 1];
	closedir(dir);
	loadGameLib(selected_game_lib);
}

void arcade::Core::loadGameLib(const std::string &selected_game)
{
	char *error;
	std::string path = "./games/" + selected_game;

	_game_handle = dlopen(path.c_str(), RTLD_LAZY);
	error = dlerror();
	if (!_game_handle)
		throw (std::runtime_error(error));
	setGame(((IGame *(*)())dlsym(_game_handle, "entryPoint"))());
	error = dlerror();
	if (error != nullptr)
		throw (std::runtime_error(error));
	_game->initGame();
	if (_menu.getRunningState())
		for (unsigned long int i = 0; i < _menu.getEntities().size(); i++)
			_graph->deleteEntity(_menu.getEntities().at(i).getName());
}

void arcade::Core::graphAlgo()
{
	for (auto i = 0; i != _game->getGameData().getEntityNb(); i++)
		if (_game->getGameData().getEntity(i).getIsAlive()) {
			_graph->updatePos(_game->getGameData().getEntity(i).getName(),
				_game->getGameData().getEntity(i).getPos());
			_graph->display(_game->getGameData().getEntity(i).getName());
		}
	_graph->display("score");
	_graph->updatePos("score", std::make_pair(3.0, 10.0));
	_graph->renderFrame();
}

void arcade::Core::gameAlgo()
{
	_game->updateGame(_action);
}

void arcade::Core::runArcade()
{
	int i = 0;

	while (_action != QUIT) {
		_action = arcade::action::UNDEFINED;
		while (i < _game->getGameData().getEntityNb()) {
			_graph->setEntity(_game->getGameData().getEntity(i).getName(),
				_game->getGameData().getEntity(i).getPath(),
				_game->getGameData().getEntity(i).getPos());
			i++;
		}
		_graph->setEntity("score", "SCORE : " + std::to_string(_game->getScore()), std::make_pair(30.0, 60.0));
		if (_game->getGameData().getEntityNb() != 0) {
			_graph->initFrame();
			_graph->setAction(&_action);
			checkAction();
			if (_action == BACK)
				break;
			gameAlgo();
			graphAlgo();
			if (_game->getEnd()) {
				break;
			}
		} else
			throw (std::runtime_error("Error in arcade"));
	}
}

void arcade::Core::setGame(IGame *game)
{
	_game = game;
}

void arcade::Core::setGraph(IGraph *graph)
{
	_graph = graph;
}

std::string arcade::Core::getGame() const
{
	return _game->getName();
}

std::string arcade::Core::getGraph() const
{
	return _graph->getName();
}