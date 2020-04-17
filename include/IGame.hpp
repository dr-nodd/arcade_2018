/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Created by folamie,
*/

#ifndef OOP_ARCADE_2018_IGRAME_H
#define OOP_ARCADE_2018_IGRAME_H

#include <string>

#include "Arcade.hpp"
#include "GameData.hpp"

namespace arcade {
	class IGame {
	public:
		virtual ~IGame() = default;

		virtual std::string getName() const = 0;
		virtual void initGame() = 0;
		virtual arcade::GameData getGameData() const = 0;
		virtual void updateGame(arcade::action) = 0;
		virtual void deleteGame() = 0;
		virtual int getScore() const = 0;
		virtual bool getEnd() const = 0;

	};
}

#endif //OOP_ARCADE_2018_IGRAME_H
