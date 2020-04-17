/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** description
*/

#include <fstream>
#include <iostream>
#include "Arcade.hpp"
#include "../include/Entity.hpp"

arcade::Entity::Entity(const std::string &name, const arcade::path_t &path, float x, float y, bool is_alive) : _name(name), _path(path), _pos(std::make_pair(x, y)), _is_alive(is_alive), _type("sprite")
{

}

arcade::Entity::Entity(const std::string &name, const std::string &text, float x, float y) : _name(name), _text(text), _pos(std::make_pair(x, y)), _type("text")
{

}

void arcade::Entity::setAlive(bool val)
{
	_is_alive = val;
}

bool arcade::Entity::getIsAlive() const
{
	return _is_alive;
}

void arcade::Entity::setName(const std::string &name)
{
	_name = name;
}

std::string arcade::Entity::getName() const
{
	return _name;
}

void arcade::Entity::setPath(const arcade::path_t &path)
{
	_path = path;
}

arcade::path_t arcade::Entity::getPath() const
{
	return _path;
}

void arcade::Entity::setPos(float a, float b)
{
	_pos = std::make_pair(a, b);
}

std::pair<float, float> arcade::Entity::getPos() const
{
	return _pos;
}

void arcade::Entity::setText(const std::string &text)
{
	_text = text;
}

std::string arcade::Entity::getText() const
{
	return _text;
}

std::string arcade::Entity::getType() const
{
	return _type;
}