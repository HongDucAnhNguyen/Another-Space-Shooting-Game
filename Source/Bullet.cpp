#include "../Header Files/Bullet.h"

//Bullet::Bullet() :bulletSpeed(0)
//{
//
//}

Bullet::Bullet(sf::Texture* texture, const sf::Vector2f& position, const sf::Vector2f& direction, float bulletSpeed)
{
	this->bulletSprite.setTexture(*texture);
	this->bulletSprite.setTextureRect(sf::IntRect(0, 0, 94, 68));
	this->bulletSprite.setRotation(-90);
	this->bulletSprite.setPosition(position);

	this->direction = direction;
	this->bulletSpeed = bulletSpeed;
}

Bullet::~Bullet()
{
}


//for collision stuff later
const sf::FloatRect Bullet::getBounds() const
{
	return this->bulletSprite.getGlobalBounds();
}






void Bullet::update(float deltaTime)
{
	this->bulletSprite.move(this->bulletSpeed * this->direction * deltaTime);
}

void Bullet::render(sf::RenderWindow& window)
{
	window.draw(this->bulletSprite);
}
