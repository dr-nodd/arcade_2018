/*RED
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** description
*/

#include <fstream>
#include <iostream>
#include <unordered_map>
#include "CacaEntity.hpp"

const std::unordered_map<std::string, caca_color> color({{"player", CACA_GREEN}, {"background", CACA_WHITE},
														 {"bonus", CACA_MAGENTA}, {"body", CACA_GREEN},
														 {"ship", CACA_BLUE}, {"laser", CACA_RED}});

arcade::CacaEntity::CacaEntity(const std::string &name, const arcade::path_t &path, const std::pair<float, float> &pos) :
		_name(name), _path(path), _pos(pos), _type("sprite")
{
	initAscii();
	setColor();
}

arcade::CacaEntity::CacaEntity(const std::string &name, const std::string &text, const std::pair<float, float> &pos) :
		_name(name), _pos(pos), _type("text"), _text(text)
{
}

void arcade::CacaEntity::setColor()
{
	for (const auto &it : color)
		if (_name == it.first || _name.find(it.first) != std::string::npos)
			_color = it.second;
}

void arcade::CacaEntity::setPos(std::pair<float, float> pair)
{
	_pos = pair;
}

void arcade::CacaEntity::setText(const std::string &text)
{
	_text = text;
}

caca_color arcade::CacaEntity::getColor() const
{
	return (_color);
}

std::string arcade::CacaEntity::getName() const
{
	return (_name);
}

arcade::path_t arcade::CacaEntity::getPath() const
{
	return (_path);
}

std::pair<float, float> arcade::CacaEntity::getPos() const
{
	return (_pos);
}

std::vector<std::string> arcade::CacaEntity::getAscii() const
{
	return (_ascii);
}

std::string arcade::CacaEntity::getText() const
{
	return (_text);
}

std::string arcade::CacaEntity::getType() const
{
	return (_type);
}

void arcade::CacaEntity::initAscii()
{
	std::ifstream file(_path.txt);
	if (file.is_open()) {
		std::string tmp;
		while (std::getline(file, tmp)) {
			_ascii.push_back(tmp);
		}
	}
}
