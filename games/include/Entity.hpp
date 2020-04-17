/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Created by folamie,
*/

#ifndef OOP_ARCADE_2018_ENTITY_HPP
#define OOP_ARCADE_2018_ENTITY_HPP

#include <vector>
#include "Arcade.hpp"

namespace arcade {
	class Entity {
	public:
		Entity(const std::string &name, const arcade::path_t &path, float x, float y, bool is_alive);
		Entity(const std::string &, const std::string &, float x, float y);
		~Entity() = default;

		void setName(const std::string &);
		void setPath(const arcade::path_t &);
		void setText(const std::string &);
		void setPos(float, float);
		void setAlive(bool);

		std::string getName() const;
		arcade::path_t getPath() const;
		std::string getText() const;
		std::pair<float, float> getPos() const;
		bool getIsAlive() const;
		std::string getType() const;

	private:
		std::string _name;
		arcade::path_t _path;
		std::string _text;
		std::pair<float, float> _pos;
		bool _is_alive;
		std::string _type;
	};
}

#endif //OOP_ARCADE_2018_ENTITY_HPP
