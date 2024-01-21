#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "tileCoordinates.hpp"
#include "StartMenu.h"
#include "Dice.h"

class GameWrapper
{
private:
	void init();
	void initWindow();
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videoMode;
	sf::RectangleShape boardBorder;
	sf::Color boardColor;
	sf::CircleShape playerBases[4];
	sf::RectangleShape playerBasesBorder[4];
	std::vector <TileStruct> tCoords;
	std::vector<ArrowStruct> arrowsCoords;
	std::vector<sf::Color> colors;
	StartMenu startMenu;
	Dice dice;

public:
	GameWrapper();
	virtual ~GameWrapper();
	const bool windowIsOpen() const;
	void update();
	void render();
	void pollEvents();
	void drawPlayerBases();
	void drawBoard();
	void drawHome();
	void drawPawns();
	void drawTiles();
	void drawArrows();
};

