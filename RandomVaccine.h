#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
class RandomVaccine
{
private:
	sf::CircleShape shape;

	void initShape(const sf::RenderWindow& window);
public:
	RandomVaccine(const sf::RenderWindow& window);
	virtual ~RandomVaccine();

	void update();
	void render(sf::RenderTarget& target);
};
