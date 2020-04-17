/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** ISound
*/

#ifndef OOP_ARCADE_2018_ISOUND_HPP
#define OOP_ARCADE_2018_ISOUND_HPP

#include "Arcade.hpp"

namespace arcade {
	class ISound {
	public:
		virtual ~ISound() = default;
		virtual void setMusic() = 0;
		virtual void playMusic() = 0;
		virtual void stopMusic() = 0;
	};
}

#endif //OOP_ARCADE_2018_ISOUND_HPP
