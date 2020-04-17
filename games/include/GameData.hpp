/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Game Data
*/

#ifndef OOP_ARCADE_2018_MAP_HPP
#define OOP_ARCADE_2018_MAP_HPP

#include <vector>
#include "Arcade.hpp"
#include "Entity.hpp"

namespace arcade {
	class GameData {
	public:

		arcade::Entity getEntity(const std::string &name) const;
		arcade::Entity getPlayer() const;
		arcade::Entity getEntity(int) const;
		int getEntityNb() const;
		std::vector<std::pair<float, float>>  getEntitiesPos(const std::string &);
		void addEntity(arcade::Entity entity);
		arcade::action getAction() const;
		void setAction(arcade::action action);
		void reset();
		void setEntityPos(const std::string &, std::pair<float, float>, std::string dir);
		std::vector<arcade::Entity> getEntityVector() const;

	private:
		std::vector<arcade::Entity> _entityVector;
		arcade::action _action;
	};
}

#endif //OOP_ARCADE_2018_MAP_HPP
