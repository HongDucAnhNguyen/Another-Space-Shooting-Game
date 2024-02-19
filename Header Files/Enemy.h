#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{

private:
	sf::Sprite enemySprite;
	sf::Texture enemyTexture;

	int hp;
	int hpMax;
	int damage;
	int points_gained_when_killed;
	int level;
	float enemySpeed;

	void initTexture();
	void initSprite();

public:
	Enemy();
	~Enemy();

	void update();
	void render(sf::RenderWindow& window);

	const int getEnemyPoints() const;

};

