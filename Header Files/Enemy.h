#pragma once
#include <SFML/Graphics.hpp>

class Enemy
{

private:
	sf::Sprite enemySprite;
	sf::Texture enemyTexture;
	sf::Font font;
	sf::Text healthText;



	int hpMax;
	int damage;
	int points_gained_when_killed;
	int level;
	float enemySpeed;

public:
	sf::RectangleShape boundingRect;
	int hp;

private:

	void initTexture();
	void initSprite();
	void initFont();
	void initHealthText();




public:
	Enemy();
	~Enemy();

	void update();
	void render(sf::RenderWindow& window);

	const int getEnemyPoints() const;
	const sf::FloatRect getBounds() const;

};

