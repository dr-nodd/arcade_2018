/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Created by folamie,
*/

#ifndef OOP_ARCADE_2018_ARCADE_HPP
#define OOP_ARCADE_2018_ARCADE_HPP

#include <iostream>

namespace arcade {
	struct path_t {
		std::string png;
		std::string bmp;
		std::string txt;
	};
	enum action {
		UNDEFINED = 0,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		PAUSE,
		ENTER,
		ACTION,
		QUIT,
		PREV_LIB,
		NEXT_LIB,
		PREV_GAME,
		NEXT_GAME,
		RESTART,
		BACK,
	};
}

#endif //OOP_ARCADE_2018_ARCADE_HPP
