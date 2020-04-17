/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** description
*/

#ifndef OOP_ARCADE_2018_SFMLENTITY_HPP
#define OOP_ARCADE_2018_SFMLENTITY_HPP

#include <SFML/Graphics.hpp>
#include "Arcade.hpp"

namespace arcade {
	class SFMLEntity {

		public:
			SFMLEntity(const std::string &, const arcade::path_t &, const std::pair<float, float> &);
			SFMLEntity(const std::string &, const std::string &, const std::pair<float, float> &);
			~SFMLEntity() = default;

			void setPos(std::pair<float, float>);
			void setText(const std::string &);

			std::string getName() const;
			arcade::path_t getPath() const;
			std::pair<float, float> getPos() const;
			sf::Sprite getSprite() const;
			sf::Text getText() const;
			std::string getType() const;

		private:
			void initSprite();
			void initText(const std::string &);

			std::string _name;
			arcade::path_t _path;
			std::pair<float, float> _pos;
			std::string _type;
			sf::Sprite _sprite;
			sf::Texture _texture;
			sf::Font _font;
			sf::Text _text;
	};
}

#endif //OOP_ARCADE_2018_SFMLENTITY_HPP
