#pragma once
#include <SFML/Graphics.hpp>
class Player
{

private:
	sf::Sprite playerSprite;
	sf::Texture playerTexture;
	float playerSpeed;
	int damage;

	float shootingCooldown;
	float shootingCooldownMax;



	void initPlayer();

	void initTexture();



public:
	Player();
	~Player();




	void update();
	void render(sf::RenderWindow& window);
	void move(const float dirX, const float dirY);
	const sf::Vector2f& getCurrentPos() const;
	const float getCurrentSpeed() const;
	bool playerCanShoot();

};

