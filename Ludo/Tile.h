#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Tile
{
private:
	sf::RectangleShape tile;

	int px; int py;
	sf::Color col;
	int r; int g; int b;

public:
	Tile(sf::RenderTarget& window, int px, int py, int r, int g, int b);
	void initShape();
	void drawTile(sf::RenderTarget& window);
};

