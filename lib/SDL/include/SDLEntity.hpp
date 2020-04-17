/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SDL Entity
*/

#ifndef OOP_ARCADE_2018_SDLENTITY_HPP
#define OOP_ARCADE_2018_SDLENTITY_HPP

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "Arcade.hpp"

namespace arcade {
	class SDLEntity {

		public:
			SDLEntity(const std::string &, const arcade::path_t &, const std::pair<float, float> &);
			SDLEntity(const std::string &, const std::string &, const std::pair<float, float> &);
			~SDLEntity() = default;

			void setPos(std::pair<float, float>);
			void setText(const std::string &);

			std::string getName() const;
			arcade::path_t getPath() const;
			std::pair<float, float> getPos() const;
			SDL_Surface *getSprite() const;
			SDL_Surface *getText() const;
			std::string getType() const;

		private:
			void initSprite();
			void initText(const std::string &);

			std::string _name;
			arcade::path_t _path;
			std::pair<float, float> _pos;
			std::string _type;
			SDL_Surface *_sprite;
			SDL_Rect _rect;
			TTF_Font *_font;
			SDL_Surface *_text;
	};
}

#endif //OOP_ARCADE_2018_SDLENTITY_HPP
