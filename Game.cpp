#include "RandomVaccine.h"
#include <vector>
#include "Game.h"
#include "Player.h"



void Game::initVariable()
{
	this->endGame = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxSwagBalls = 10;
}

void Game::initWindow()
{
	this->videoMode = sf::VideoMode(1000, 600);
	this->window = new sf::RenderWindow(this->videoMode, "Save the Galaxy", sf::Style::Close | sf::Style::Titlebar);
}

Game::Game()
{
	this->initVariable();
	this->initWindow();
}

Game::~Game()
{ 
	delete this->window;
}
const bool Game::running() const
{
	return this->window->isOpen();
}
void Game::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}
void Game::update()//Actualizar cada frame 
{
	this->pollEvents();
	this->player.update();
	this->spawnVaccine();
	
}
void Game::render()
{
	this->window->clear();//limpiar la ventana
	//renderizar
	this->imagen.loadFromFile("imagenes/HubbleLegacyField.jpg");
	sf::Sprite fondo(imagen);
	this->window->draw(fondo);
	for (auto i : this->vaccine)
	{
		i.render(*this->window);
	}

	this->player.render(this->window);
	this->window->display();
}

void Game::spawnVaccine()
{
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer += 1.f;
	else
	{
		if (this->vaccine.size() < this->maxSwagBalls)
		{
			this->vaccine.push_back(RandomVaccine(*this->window));

			this->spawnTimer = 0.f;
		}
	}
}
