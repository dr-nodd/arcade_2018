/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Lib for SDL
*/

#include <iostream>
#include "SDLLib.hpp"
#include "SDLEntity.hpp"

arcade::SDL::SDL()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) == -1)
		throw (std::runtime_error(SDL_GetError()));
	if (TTF_Init() == -1)
		throw (std::runtime_error(TTF_GetError()));
	_window = SDL_SetVideoMode(1920, 1080, 32, SDL_FULLSCREEN | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("ARCADE", nullptr);
	if (_window == nullptr)
		throw (std::runtime_error(SDL_GetError()));
	initFrame();
	renderFrame();
}

arcade::SDL::~SDL() = default;

void arcade::SDL::deleteLib()
{
	TTF_Quit();
	SDL_Quit();
}

void arcade::SDL::initFrame()
{
	SDL_FillRect(_window, nullptr, SDL_MapRGB(_window->format, 0, 0, 0));
}

void arcade::SDL::renderFrame()
{
	SDL_Flip(_window);
}

std::string arcade::SDL::getName() const
{
	return ("lib_arcade_sdl.so");
}

void arcade::SDL::setAction(arcade::action *action)
{
	while (SDL_PollEvent(&_event)) {
		if (_event.type == SDL_QUIT)
			*action = arcade::action::QUIT;
		if (_event.type == SDL_KEYDOWN) {
			switch(_event.key.keysym.sym) {
				case (SDLK_UP):
					*action = arcade::action::UP;
					break;
				case (SDLK_DOWN):
					*action = arcade::action::DOWN;
					break;
				case (SDLK_LEFT):
					*action = arcade::action::LEFT;
					break;
				case (SDLK_RIGHT):
					*action = arcade::action::RIGHT;
					break;
			case (SDLK_p):
					*action = arcade::action::PAUSE;
					break;
				case (SDLK_RETURN):
					*action = arcade::action::ENTER;
					break;
				case (SDLK_SPACE):
					*action = arcade::action::ACTION;
					break;
				case (SDLK_ESCAPE):
					*action = arcade::action::QUIT;
					break;
				case (SDLK_w):
					*action = arcade::action::PREV_LIB;
					break;
				case (SDLK_c):
					*action = arcade::action::NEXT_LIB;
					break;
				case (SDLK_a):
					*action = arcade::action::PREV_GAME;
					break;
				case (SDLK_e):
					*action = arcade::action::NEXT_GAME;
					break;
				case (SDLK_q):
					*action = arcade::action::BACK;
					break;
				case (SDLK_d):
					*action = arcade::action::RESTART;
					break;
				default:
					*action = arcade::action::UNDEFINED;
			}
		}
	}
}

void arcade::SDL::setEntity(const std::string &name, const arcade::path_t &path, const std::pair<float, float> &pos)
{
	for (const auto &it : _entities)
		if (name == it.getName())
			return;
	_entities.emplace_back(name, path, pos);
}

void arcade::SDL::setEntity(const std::string &name, const std::string &text, const std::pair<float, float> &pos)
{
	for (auto &it : _entities)
		if (name == it.getName()) {
			it.setText(text);
			return;
		}
	_entities.emplace_back(name, text, pos);
}

void arcade::SDL::deleteEntity(const std::string &name)
{
	for (unsigned long i = 0; i < _entities.size(); i++)
		if (name == _entities.at(i).getName())
			_entities.erase(_entities.begin() + i);
}

void arcade::SDL::updatePos(const std::string &name, const std::pair<float, float> &pos)
{
	for (auto &it : _entities)
		if (it.getName() == name) {
			it.setPos(std::make_pair((pos.first * _window->w) / 100.0, (pos.second * _window->h) / 100.0));
		}
}

void arcade::SDL::display(const std::string &name)
{
	for (const auto &it : _entities) {
		if (it.getName() == name) {
			SDL_Rect pos;
			pos.x = static_cast<Sint16>(it.getPos().first);
			pos.y = static_cast<Sint16>(it.getPos().second);
			if (it.getType() == "sprite")
				SDL_BlitSurface(it.getSprite(), nullptr, _window, &pos);
			else if (it.getType() == "text")
				SDL_BlitSurface(it.getText(), nullptr, _window, &pos);
		}
	}
}

extern "C" arcade::IGraph *entryPoint()
{
	return new arcade::SDL;
}