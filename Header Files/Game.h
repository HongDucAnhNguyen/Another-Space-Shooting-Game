#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Framerate.h"
#include "Math.h"


/*Game engine wrapper class*/

class Game
{
private:

	//variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::Clock clock;
	float delta_time;
	Player* player;
	Enemy* enemy;
	Framerate* frameRate;
	Math* math;

	//textures container for the game
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> bullets;

	//private functions
	void initWindow();
	void initTextures();
	void createPlayer();
	void createEnemy();
	void createFramerateInformation();
	void createMathSystem();

public:


	//constructors/Destructors
	Game();
	~Game();


	//functions
	void update();
	void render();
	void run();
	void updatePollEvents();
	void updateInputs();
	void updateBullets();




};

