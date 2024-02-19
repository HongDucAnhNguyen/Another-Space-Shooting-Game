#include "../Header Files/Player.h"
#include <iostream>
void Player::initPlayer()
{
	this->playerSprite.setTexture(this->playerTexture);
	this->playerSprite.setTextureRect(sf::IntRect(0, 0, 392, 338));
	this->playerSprite.scale(0.2f, 0.2f);

	this->playerSprite.setPosition(100, 100);
}

void Player::initTexture()
{

	if (!this->playerTexture.loadFromFile("game_assets/ship.png")) {

		std::cout << "Error loading texture" << std::endl;


	}
	else std::cout << "loaded player texture" << std::endl;


}

Player::Player() : playerSpeed(.5), shootingCooldown(20), shootingCooldownMax(20), damage(10)
{
	this->initTexture();
	this->initPlayer();
}

Player::~Player()
{
}

void Player::update()
{

	if (this->shootingCooldown < this->shootingCooldownMax) {
		this->shootingCooldown += 1;

	}


}

void Player::render(sf::RenderWindow& window)
{


	window.draw(this->playerSprite);


}

void Player::move(const float dirX, const float dirY)
{
	this->playerSprite.move(this->playerSpeed * dirX, this->playerSpeed * dirY);
}

const sf::Vector2f& Player::getCurrentPos() const
{
	return this->playerSprite.getPosition();
}

const float Player::getCurrentSpeed() const
{
	return this->playerSpeed;
}

bool Player::playerCanShoot()
{

	if (this->shootingCooldown >= this->shootingCooldownMax) {
		this->shootingCooldown = 0;
		return true;
	}
	else return false;
}

