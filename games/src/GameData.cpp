/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Game Data
*/

#include <cstring>
#include "Arcade.hpp"
#include "../include/GameData.hpp"

arcade::Entity arcade::GameData::getEntity(int idx) const
{
	return _entityVector.at(idx);
}

arcade::Entity arcade::GameData::getPlayer() const
{
	for (auto &it : _entityVector)
		if (it.getName().find("player") != std::string::npos && it.getIsAlive())
			return it;
	return (_entityVector[0]);
}

arcade::Entity arcade::GameData::getEntity(const std::string &name) const
{
	if (name == "centipede") {
		for (auto &it : _entityVector)
			if (it.getName().find("centipede") != std::string::npos && it.getIsAlive())
				return it;
		return (_entityVector[0]);
	}
	for (auto &it : _entityVector) {
		if (it.getName() == name && it.getIsAlive())
			return it;
	}
	return (_entityVector[0]);
}

int arcade::GameData::getEntityNb() const
{
	return static_cast<int>(_entityVector.size());
}

std::vector<std::pair<float, float>> arcade::GameData::getEntitiesPos(const std::string &name)
{
	std::vector<std::pair<float, float>> res;
	for (auto &it : _entityVector) {
		if (it.getName().find(name) != std::string::npos && it.getIsAlive()) {
			res.push_back(it.getPos());
		}
	}
	return res;
}

void arcade::GameData::addEntity(arcade::Entity entity)
{
	_entityVector.push_back(entity);
}

arcade::action arcade::GameData::getAction() const
{
	return _action;
}

void arcade::GameData::setAction(arcade::action action)
{
	_action = action;
}

void arcade::GameData::reset()
{
	_action = arcade::action::UNDEFINED;
	_entityVector.clear();
}

void arcade::GameData::setEntityPos(const std::string &name, std::pair<float, float> pair, std::string dir)
{
	for (auto &it : _entityVector)
		if (it.getName() == name || (name == "player" && it.getName().find(name) != std::string::npos) || (name == "centipede" && it.getName().find(name) != std::string::npos)) {
			it.setAlive(false);
			if (it.getPath().txt.find(dir) != std::string::npos)
				it.setAlive(true);
			it.setPos(pair.first, pair.second);
		}
}

std::vector<arcade::Entity> arcade::GameData::getEntityVector() const
{
	return _entityVector;
}