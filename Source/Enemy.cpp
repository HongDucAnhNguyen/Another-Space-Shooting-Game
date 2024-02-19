#include "../Header Files/Enemy.h"
#include <iostream>

void Enemy::initTexture()
{
	if (this->enemyTexture.loadFromFile("game_assets/enemy pack/enemy_lvl1.png")) {

		std::cout << "loaded enemy texture" << std::endl;

	}
	else std::cout << "cannot load enemy texture" << std::endl;
}

void Enemy::initSprite()
{
	this->enemySprite.setTexture(this->enemyTexture);
	this->enemySprite.setTextureRect(sf::IntRect(0, 0, 219, 243));
	this->enemySprite.scale(.2f, .2f);

	this->enemySprite.setPosition(300, 0);
}

Enemy::Enemy() : level(0), enemySpeed(5), hpMax(100),
hp(100),
damage(5),
points_gained_when_killed(10)
{
	this->initTexture();
	this->initSprite();
}



Enemy::~Enemy()
{
}

void Enemy::update()
{
}

void Enemy::render(sf::RenderWindow& window)
{
	if (hp > 0) {
		window.draw(this->enemySprite);
	}
}

const int Enemy::getEnemyPoints() const
{
	return this->points_gained_when_killed;
}
