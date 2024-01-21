#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Pawn
{
private:
	sf::CircleShape c1;
	sf::CircleShape c2;
	sf::CircleShape c3;
	std::vector<std::vector<sf::Color>> colors;
	int color;
	int posx; int posy;
	float radius1; float radius2; float radius3;
public:
	Pawn(sf::RenderTarget& window, int color, int posx, int posy);
	void initShape();
	void update();
	void render();
	void drawPawn(sf::RenderTarget &window);

};

