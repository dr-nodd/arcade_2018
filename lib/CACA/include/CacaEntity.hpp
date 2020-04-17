/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** description
*/

#ifndef OOP_ARCADE_2018_CACAENTITY_HPP
#define OOP_ARCADE_2018_CACAENTITY_HPP

#include <vector>
#include <caca.h>
#include "Arcade.hpp"

namespace arcade {
	class CacaEntity {

		public:
			CacaEntity(const std::string &, const arcade::path_t &, const std::pair<float, float> &);
			CacaEntity(const std::string &, const std::string &, const std::pair<float, float> &);
			~CacaEntity() = default;

			void setColor();
			void setPos(std::pair<float, float>);
			void setText(const std::string &);

			caca_color getColor() const;
			std::string getName() const;
			arcade::path_t getPath() const;
			std::pair<float, float> getPos() const;
			std::vector<std::string> getAscii() const;
			std::string getText() const;
			std::string getType() const;

		private:
			void initAscii();

			std::string _name;
			arcade::path_t _path;
			std::pair<float, float> _pos;
			std::string _type;
			std::vector<std::string> _ascii;
			caca_color _color;
			std::string _text;
	};
}

#endif //OOP_ARCADE_2018_CACAENTITY_HPP
