/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** description
*/

#include <iostream>
#include <caca++.h>
#include "CacaLib.hpp"

arcade::Caca::Caca() : _event_mask(CACA_EVENT_KEY_PRESS | CACA_EVENT_RESIZE |
	CACA_EVENT_MOUSE_PRESS | CACA_EVENT_QUIT)
{
	_canvas = caca_create_canvas(0, 0);
	if (!_canvas)
		throw (std::runtime_error("Couldn't initialize libcaca"));
	caca_set_canvas_size(_canvas, 240, 64);
	caca_set_color_ansi(_canvas, CACA_WHITE, CACA_BLACK);
	_display = caca_create_display(_canvas);
	if (!_display)
		throw (std::runtime_error ("Couldn't initialize libcaca"));
	caca_set_display_title(_display, "ARCADE");
	initFrame();
}

arcade::Caca::~Caca() = default;

void arcade::Caca::deleteLib()
{
	caca_free_canvas(_canvas);
	caca_free_display(_display);
}

void arcade::Caca::initFrame()
{
}

void arcade::Caca::renderFrame()
{
	caca_refresh_display(_display);
}

std::string arcade::Caca::getName() const
{
	return ("lib_arcade_caca.so");
}

void arcade::Caca::setAction(arcade::action *action)
{
	_evt = caca_get_event(_display, _event_mask, &_event, 0);
	if (caca_get_event_type(&_event) & CACA_EVENT_QUIT)
		*action = arcade::action::QUIT;
	if (caca_get_event_type(&_event) & CACA_EVENT_KEY_PRESS) {
		switch (caca_get_event_key_ch(&_event)) {
			case (CACA_KEY_UP):
				*action = arcade::action::UP;
				break;
			case (CACA_KEY_DOWN):
				*action = arcade::action::DOWN;
				break;
			case (CACA_KEY_LEFT):
				*action = arcade::action::LEFT;
				break;
			case (CACA_KEY_RIGHT):
				*action = arcade::action::RIGHT;
				break;
			case ('p'):
				*action = arcade::action::PAUSE;
				break;
			case (CACA_KEY_RETURN):
				*action = arcade::action::ENTER;
				break;
			case (' '):
				*action = arcade::action::ACTION;
				break;
			case (CACA_KEY_ESCAPE):
				*action = arcade::action::QUIT;
				break;
			case ('w'):
				*action = arcade::action::PREV_LIB;
				break;
			case ('c'):
				*action = arcade::action::NEXT_LIB;
				break;
			case ('a'):
				*action = arcade::action::PREV_GAME;
				break;
			case ('e'):
				*action = arcade::action::NEXT_GAME;
				break;
			case ('q'):
				*action = arcade::action::BACK;
				break;
			case ('d'):
				*action = arcade::action::RESTART;
				break;
			default:
				*action = arcade::action::UNDEFINED;
		}
	}
}

void arcade::Caca::setEntity(const std::string &name, const path_t &path, const std::pair <float, float> &pos)
{
	for (const auto &it : _entities)
		if (name == it.getName())
			return;
	_entities.emplace_back(name, path, std::make_pair((pos.first * caca_get_canvas_width(_canvas)) / 100.0, (pos.second * caca_get_canvas_height(_canvas)) / 100.0));
}

void arcade::Caca::setEntity(const std::string &name, const std::string &text, const std::pair<float, float> &pos)
{
	for (auto &it : _entities)
		if (name == it.getName()) {
			it.setText(text);
			return;
		}
	_entities.emplace_back(name, text, pos);
}

void arcade::Caca::deleteEntity(const std::string &name)
{
	for (unsigned long i = 0; i < _entities.size(); i++)
		if (name == _entities.at(i).getName())
			_entities.erase(_entities.begin() + i);
}

void arcade::Caca::updatePos(const std::string &name, const std::pair<float, float> &pos)
{
	for (auto &it : _entities)
		if (it.getName() == name) {
			it.setPos(std::make_pair((pos.first * caca_get_canvas_width(_canvas)) / 100.0, (pos.second * caca_get_canvas_height(_canvas)) / 100.0));
		}
}

void arcade::Caca::display(const std::string &name)
{
	for (const auto &it : _entities) {
		if (it.getName() == name) {
			if (it.getType() == "sprite") {
				int i = static_cast<int>(it.getPos().second);
				for (const auto &k : it.getAscii()) {
					caca_set_color_ansi(_canvas, it.getColor(), CACA_BLACK);
					caca_put_str(_canvas, static_cast<int>(it.getPos().first), i, k.c_str());
					i++;
				}
			}
			else if (it.getType() == "text") {
				caca_set_color_ansi(_canvas, CACA_WHITE, CACA_BLACK);
				caca_put_str(_canvas, static_cast<int>(it.getPos().first), static_cast<int>(it.getPos().second), it.getText().c_str());
			}
		}
	}
}

extern "C" arcade::IGraph *entryPoint()
{
	return new arcade::Caca;
}
