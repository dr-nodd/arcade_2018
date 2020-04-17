/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** description
*/

#include <iostream>
#include "SDLEntity.hpp"

arcade::SDLEntity::SDLEntity(const std::string &name, const arcade::path_t &path, const std::pair<float, float> &pos) :
		_name(name), _path(path), _pos(pos), _type("sprite")
{
	initSprite();
}

arcade::SDLEntity::SDLEntity(const std::string &name, const std::string &text, const std::pair<float, float> &pos) :
		_name(name), _pos(pos), _type("text")
{
	initText(text);
}

void arcade::SDLEntity::setPos(std::pair<float, float> pair)
{
	_pos = pair;
}

void arcade::SDLEntity::setText(const std::string &text)
{
	SDL_Color color = {0, 0, 0, 0};
	_text = TTF_RenderText_Solid(_font, text.c_str(), color);
}

std::string arcade::SDLEntity::getName() const
{
	return (_name);
}

arcade::path_t arcade::SDLEntity::getPath() const
{
	return (_path);
}

std::pair<float, float> arcade::SDLEntity::getPos() const
{
	return (_pos);
}

SDL_Surface *arcade::SDLEntity::getSprite() const
{
	return (_sprite);
}

SDL_Surface *arcade::SDLEntity::getText() const
{
	return (_text);
}

std::string arcade::SDLEntity::getType() const
{
	return (_type);
}

void arcade::SDLEntity::initSprite()
{
	_sprite = SDL_LoadBMP(_path.bmp.c_str());
	SDL_SetColorKey(_sprite, SDL_SRCCOLORKEY, SDL_MapRGB(_sprite->format, 0, 0, 0));
	if (!_sprite)
		throw (std::runtime_error("Couldn't load sprite"));
}


void arcade::SDLEntity::initText(const std::string &text)
{
	_font = TTF_OpenFont("assets/pixel.ttf", 50);
	if (!_font)
		throw (std::runtime_error(TTF_GetError()));
	setText(text);
}