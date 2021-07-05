#pragma once
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Player.h"
#include "RandomVaccine.h"
#include <vector>
class Game
{
	private:
		sf::VideoMode videoMode;
		sf::RenderWindow* window;
		sf::Texture imagen;
		Player player;
		bool endGame;
		sf::Event event;
		void initVariable();
		void initWindow();
		std::vector<RandomVaccine> vaccine;
		float spawnTimerMax;
		float spawnTimer;
		int maxSwagBalls;
	public:
		//Constructor y destructor
		
	
		Game();
		~Game();
		
		const bool running() const;
		void pollEvents();
		//Functions
		void update();
		void render();//funcion para renderizar la ventana 
		void spawnVaccine();
};



