/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Menu
*/

#ifndef OOP_ARCADE_2018_MENU_HPP
#define OOP_ARCADE_2018_MENU_HPP

#include <string>
#include <vector>
#include "Arcade.hpp"
#include "Entity.hpp"
#include "GameData.hpp"

namespace arcade {
	class Menu {
		public:
			Menu();
			std::vector<arcade::Entity> getEntities();
			void searchGamesLibraries();
			std::string cutGameName(const std::string);
			std::string cutLibName(const std::string);
			int checkAction();
			void setInput(arcade::action);
			void setBackground();
			void setGameName();
			void getLibName();
			void setLibName();
			void setRunningState(bool);
			bool getRunningState();

		private:
			arcade::GameData _data;
			bool _isRunning;
			arcade::action _action;
			std::vector<std::string> _gamesLibraries;
			std::vector<std::string> _libs;
			int _sizeModifier;
			int _arrowPos;
	};
}

#endif //OOP_ARCADE_2018_MENU_HPP
