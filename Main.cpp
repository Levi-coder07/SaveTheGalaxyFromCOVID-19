#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "RandomVaccine.h"
#include "Game.h"
#include "Player.h"
int main() {
	Game game;
	while (game.running()) {
		game.update();
		game.render();
	}
}