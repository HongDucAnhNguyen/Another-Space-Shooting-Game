#include "../Header Files/Game.h"
#include <iostream>

Game::Game() : window(nullptr), delta_time(0), player(nullptr), enemy(nullptr),
frameRate(nullptr), math(nullptr)
{
	this->initWindow();
	this->initTextures();
	this->createPlayer();
	this->createEnemy();
	this->createFramerateInformation();
	this->createMathSystem();

}

Game::~Game()
{
	delete this->window;
	delete this->player;
	delete this->enemy;
	delete this->frameRate;
	delete this->math;


	//delete textures
	for (auto& i : this->textures) {

		//i first is the key, i second is the val
		delete i.second;
	}

	//delete bullets
	for (auto* i : this->bullets) {

		delete i;
	}
}
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "another space shooting game");
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);


}
void Game::initTextures()
{
	this->textures["BULLET"] = new sf::Texture();
	if (this->textures["BULLET"]->loadFromFile("game_assets/bullet.png")) {

		std::cout << "loaded bullet texture" << std::endl;
	}
	else std::cout << "cannot load bullet texture" << std::endl;


}


/*Game entities creation*/
void Game::createPlayer()
{
	this->player = new Player();
}
void Game::createEnemy()
{
	this->enemy = new Enemy();
}
void Game::createFramerateInformation() {

	this->frameRate = new Framerate();
}
void Game::createMathSystem() {
	this->math = new Math();
}

/*Game entities creation*/




void Game::update()
{


	this->updatePollEvents();
	this->updateInputs();
	this->frameRate->update(this->delta_time);
	this->player->update();
	this->enemy->update();
	this->updateBullets();





}

void Game::render()
{


	this->window->clear();
	this->player->render(*(this->window));
	this->enemy->render(*(this->window));
	this->frameRate->render(*(this->window));


	for (auto* bullet : this->bullets) {

		bullet->render(*(this->window));
	}

	this->window->display();

}

void Game::run()
{


	while (this->window->isOpen())
	{

		this->delta_time = this->clock.restart().asSeconds() * 1000;

		this->update();
		this->render();
	}
}

void Game::updatePollEvents()
{

	while (this->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->window->close();


		if (event.type == sf::Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
			this->window->close();

	}
}

void Game::updateInputs()
{


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

		(this->player->move(-1 * this->player->getCurrentSpeed() * delta_time, 0));


	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

		this->player->move(1 * this->player->getCurrentSpeed() * delta_time, 0);


	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

		this->player->move(0, 1 * this->player->getCurrentSpeed() * delta_time);


	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

		this->player->move(0, -1 * this->player->getCurrentSpeed() * delta_time);


	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->playerCanShoot()) {






		this->bullets.push_back(
			new Bullet(this->textures["BULLET"], this->player->getCurrentPos(), sf::Vector2f(0, -1), .5)
		);
		std::cout << "shot a bullet" << std::endl;



	}
}

void Game::updateBullets()
{






	//check for every bullet to see if offscreen
	for (int index_offset = this->bullets.size() - 1; index_offset >= 0; index_offset--) {

		this->bullets[index_offset]->update(this->delta_time);


		if (this->bullets[index_offset]->getBounds().top + this->bullets[index_offset]->getBounds().height < 0) {

			delete this->bullets.at(index_offset);

			this->bullets.erase(this->bullets.begin() + index_offset);

			std::cout << "bullet deleted" << std::endl;


		}
		else {
			if (math->checkAABBCollision(this->bullets[index_offset]->getBounds(),
				this->enemy->getBounds())) {


				if (this->enemy->hp <= 0) {
					this->enemy->hp = 0;
				}


				else {
					this->enemy->boundingRect.setOutlineColor(sf::Color::Yellow);
					this->enemy->hp -= this->player->damage;
					std::cout << "enemy hit" << std::endl;
					std::cout << "enemy health: " << this->enemy->hp << std::endl;
					delete this->bullets.at(index_offset);

					this->bullets.erase(this->bullets.begin() + index_offset);

					std::cout << "bullet deleted" << std::endl;
				}


			}

		}





	}




}
