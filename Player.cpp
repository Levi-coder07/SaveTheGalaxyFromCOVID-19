#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Game.h"
#include "Player.h"

void Player::initVariables(){
    this->movementSpeed = 10.f;
}

void Player::initShape(){
	
    //this->shape.setFillColor(sf::Color::Green);
    //this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

Player::Player(float x,float y){

    
    this->initVariables();
    this->initShape();

}

Player::~Player(){
}

void Player::updateInput(){
    //Entrada de teclado
    //Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->spr.move(-this->movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->spr.move(this->movementSpeed, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->spr.move(0.f, -this->movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->spr.move(0.f, this->movementSpeed);
	}
}

void Player::update(){
	this->updateInput();
}

void Player::render(sf::RenderTarget* target)
{
	tex.loadFromFile("imagenes/fig1.png");
	spr.setTexture(tex);
	target->draw(this->spr);
	
	//Renderizar
	
}
