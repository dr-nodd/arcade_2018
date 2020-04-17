/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** description
*/

#include <iostream>
#include "SFMLEntity.hpp"

arcade::SFMLEntity::SFMLEntity(const std::string &name, const arcade::path_t &path, const std::pair<float, float> &pos) :
		_name(name), _path(path), _pos(pos), _type("sprite")
{
	initSprite();
}

arcade::SFMLEntity::SFMLEntity(const std::string &name, const std::string &text, const std::pair<float, float> &pos) :
		_name(name), _pos(pos), _type("text")
{
	initText(text);
}

void arcade::SFMLEntity::setPos(std::pair<float, float> pair)
{
	_pos = pair;
	_sprite.setPosition(pair.first, pair.second);
	_text.setPosition(pair.first, pair.second);
}

void arcade::SFMLEntity::setText(const std::string &text)
{
	_text.setString(text);
}

std::string arcade::SFMLEntity::getName() const
{
	return (_name);
}

arcade::path_t arcade::SFMLEntity::getPath() const
{
	return (_path);
}

std::pair<float, float> arcade::SFMLEntity::getPos() const
{
	return (_pos);
}

sf::Sprite arcade::SFMLEntity::getSprite() const
{
	return (_sprite);
}

sf::Text arcade::SFMLEntity::getText() const
{
	return (_text);
}

std::string arcade::SFMLEntity::getType() const
{
	return (_type);
}

void arcade::SFMLEntity::initSprite()
{
	if (!_texture.loadFromFile(_path.png))
		throw (std::runtime_error("Couldn't load sprite"));
	_sprite.setTexture(_texture);
}

void arcade::SFMLEntity::initText(const std::string &text)
{
	if (!_font.loadFromFile("assets/pixel.ttf"))
		throw (std::runtime_error("Couldn't load font for SFML"));
	_text.setFont(_font);
	_text.setCharacterSize(50);
	_text.setFillColor(sf::Color::Black);
	_text.setPosition(_pos.first, _pos.second);
	setText(text);
}