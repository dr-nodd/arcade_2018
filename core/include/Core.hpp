/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Created by folamie,
*/

#ifndef OOP_ARCADE_2018_CORE_HPP
#define OOP_ARCADE_2018_CORE_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include "Arcade.hpp"
#include "Entity.hpp"
#include "IGame.hpp"
#include "IGraph.hpp"
#include "GameData.hpp"
#include "Menu.hpp"

namespace arcade {
	class Core {
	public:
		Core(char *);
		virtual ~Core() = default;

		void loadGraphLib(const char *);
		void preloadGameLib();
		void loadGameLib(const std::string &);
		int checkCurrentLib();
		int checkCurrentGame();
		void whatLibAreThere();

		void mainMenu();
		void displayMenu();

		void graphAlgo();
		void gameAlgo();
		void runArcade();

		void checkAction();

		void setGame(IGame *game);
		void setGraph(IGraph *graph);

		std::string getGame() const;
		std::string getGraph() const;

	private:
		IGame *_game;
		IGraph *_graph;
		arcade::Menu _menu;
		int _selected_game;
		arcade::action _action;
		std::vector<std::string> _games;
		std::unordered_map<int, std::string> _libs;
		void *_graph_handle;
		void *_game_handle;
	};
}

#endif //OOP_ARCADE_2018_CORE_HPP
