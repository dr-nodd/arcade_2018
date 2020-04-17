/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** description
*/

#ifndef OOP_ARCADE_2018_CENTIPEDE_HPP
#define OOP_ARCADE_2018_CENTIPEDE_HPP

#include "IGame.hpp"

namespace arcade {
	class Centipede : public IGame {
		public:
		~Centipede() override = default;
		std::string getName() const override;
		void initGame() override;
		arcade::GameData getGameData() const override;
		void updateGame(arcade::action) override;
		void deleteGame() override;
		int getScore() const override;
		bool getEnd() const override;

		private:
		void isDead();
		void getBonus();
		void setBodyPos(float x, float y, std::string);

		arcade::GameData _gameData;
		size_t _score;
		arcade::action _action;
		std::vector<std::pair<float, float>> _walls;
		int _clock_nbr;
		bool _isRunning;

	};
}

#endif //OOP_ARCADE_2018_CENTIPEDE_HPP
