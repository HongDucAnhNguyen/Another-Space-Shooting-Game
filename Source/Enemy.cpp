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
	this->enemySprite.setPosition(300, 100);


	this->boundingRect.setFillColor(sf::Color::Transparent);
	this->boundingRect.setOutlineColor(sf::Color::Red);
	this->boundingRect.setOutlineThickness(1);
	this->boundingRect.setSize(sf::Vector2f(
		this->enemySprite.getGlobalBounds().width,
		this->enemySprite.getGlobalBounds().height));

	this->boundingRect.setPosition(this->enemySprite.getPosition());
}

void Enemy::initFont()
{
	if (!this->font.loadFromFile("game_assets/fonts/arial.ttf")) {
		std::cout << "font did not load" << std::endl;
	}
	else std::cout << "font loaded" << std::endl;
}

void Enemy::initHealthText()
{
	this->healthText.setPosition(this->enemySprite.getPosition() - sf::Vector2f(10, 10));
	this->healthText.setFont(font);
	this->healthText.setString(std::to_string(this->hp));
	this->healthText.setCharacterSize(16);
}





Enemy::Enemy() : level(0), enemySpeed(5), hpMax(100),
hp(100),
damage(5),
points_gained_when_killed(10)
{
	this->initTexture();
	this->initSprite();
	this->initFont();
	this->initHealthText();
}




Enemy::~Enemy()
{
}

void Enemy::update()
{
	/*if (checkCollision) {

		health - player damage
	}*/

	if (this->hp > 0) {


		this->healthText.setString(std::to_string(this->hp));
	}
}

void Enemy::render(sf::RenderWindow& window)
{
	if (hp > 0) {
		window.draw(this->enemySprite);
		window.draw(this->boundingRect);
		window.draw(this->healthText);
	}
}

const int Enemy::getEnemyPoints() const
{
	return this->points_gained_when_killed;
}

const sf::FloatRect Enemy::getBounds() const
{
	return this->enemySprite.getGlobalBounds();
}
