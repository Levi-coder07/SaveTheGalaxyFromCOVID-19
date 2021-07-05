#pragma once
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


class Player
{
	private:
		float movementSpeed;//Variable para definir la velocidad a la que se movera el personaje
		//sf::RectangleShape shape;
		void initVariables();
		void initShape();//Para el color y tamaño
		sf::Texture tex;
		sf::Text text;
		sf::Sprite spr;
	public:
		Player(float x = 0.f,float y=0.f);//Crear la nave en una posicion determinada
		virtual ~Player();
		void update();
		void render(sf::RenderTarget* target);
		void updateInput();

};


