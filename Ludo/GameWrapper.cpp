#include <iostream>
#include <string>
#include "GameWrapper.h"
#include "Pawn.h"
#include "Home.h"
#include "Tile.h"
#include "Arrow.h"
#include "StartMenu.h"
#include "Dice.h"
#include "pawnCoordinates.hpp"
#include "tileCoordinates.hpp"

GameWrapper::GameWrapper() {
	this->init();
	this->initWindow();
	this->drawBoard();
	this->startMenu = StartMenu();
	this->tCoords = TileCoordinates::getDataVector();
	this->arrowsCoords = TileCoordinates::arrows;
	this->colors = TileCoordinates::colors;
	this->dice = Dice();
}
	
GameWrapper::~GameWrapper() {
	delete this->window;
}

const bool GameWrapper::windowIsOpen() const {
	return this->window->isOpen();
}

void GameWrapper::pollEvents() {
	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape) {
				this->window->close();
			}
		case sf::Event::MouseMoved:
			startMenu.checkHover(sf::Mouse::getPosition(), *this->window);
			dice.checkDiceHover(sf::Mouse::getPosition(), *this->window, startMenu.cleared);
			
			break;
		case sf::Event::MouseButtonPressed:
			if (this->ev.mouseButton.button == sf::Mouse::Left) {
				startMenu.handleClick(sf::Mouse::getPosition(), *this->window);
				dice.handleClick(sf::Mouse::getPosition(), *this->window, startMenu.cleared, startMenu.howManyPlayers);
			}
			break;
		}
	}
}

void GameWrapper::update() {
	this->pollEvents();
}

void GameWrapper::drawPlayerBases() {
	int coordinates[4][2] = {
		80, 80,
		530, 80,
		530, 530,
		80, 530
	};

	std::vector<sf::Color> colors = {
		sf::Color(18, 149, 231),
		sf::Color(232, 20, 36),
		sf::Color(0, 181, 80),
		sf::Color(244, 220, 12)
	};

	for (int i = 0; i < 4; i++) {
		this->playerBases[i].setRadius(100);
		this->playerBases[i].setPosition(coordinates[i][0], coordinates[i][1]);
		this->playerBases[i].setFillColor(colors[i]);
		this->playerBases[i].setOutlineThickness(2);
		this->playerBases[i].setOutlineColor(sf::Color::Black);

		this->playerBasesBorder[i].setFillColor(this->boardColor);
		this->playerBasesBorder[i].setSize(sf::Vector2f(300, 300));
		this->playerBasesBorder[i].setOutlineThickness(2);
		this->playerBasesBorder[i].setOutlineColor(sf::Color::Black);
		this->playerBasesBorder[i].setPosition(coordinates[i][0] - 50, coordinates[i][1] - 50);

		this->window->draw(playerBasesBorder[i]);
		this->window->draw(playerBases[i]);
	}
}

void GameWrapper::drawBoard() {
	// drawing border 
	this->boardBorder.setFillColor(this->boardColor);
	this->boardBorder.setSize(sf::Vector2f(810 - 2 * 30, 810 - 2 * 30));
	this->boardBorder.setOutlineThickness(2);
	this->boardBorder.setOutlineColor(sf::Color::Black);
	this->boardBorder.setPosition(30, 30);

	drawPlayerBases();
}

void GameWrapper::drawHome() {
	Home home(*this->window, colors);
}

void GameWrapper::drawPawns() {
	for (int i = 0; i < pawnCoordinates.size(); i++) {
		Pawn pawn(*this->window, pawnCoordinates[i][2], pawnCoordinates[i][0], pawnCoordinates[i][1]);
	}
}

void GameWrapper::drawTiles() {
	for (int i = 0; i < tCoords.size(); i++) {
		Tile tile(*this->window,
		tCoords[i].x,
		tCoords[i].y,
		static_cast<int>(tCoords[i].col.r),
		static_cast<int>(tCoords[i].col.g),
		static_cast<int>(tCoords[i].col.b));
	}
}

void GameWrapper::drawArrows() {
	const std::string paths[4] = {
		"./images/red_arrow.png",
		"./images/yellow_arrow.png",
		"./images/green_arrow.png",
		"./images/blue_arrow.png"
	};
	for (int i = 0; i < 4; i++) {
		Arrow arrow(paths[i], arrowsCoords[i].x, arrowsCoords[i].y);
		arrow.draw(*this->window);
	}
}

void GameWrapper::render() {
	this->window->clear(this->boardColor);
	

	if (startMenu.cleared) {
	//	dice.animate(*this->window, startMenu.cleared);
		dice.draw(*this->window, startMenu.howManyPlayers);
	}
	startMenu.draw(*this->window);

	this->window->draw(this->boardBorder);
	this->drawPlayerBases();


	drawHome();
	drawTiles();
	drawPawns();
	drawArrows();


	


	

	this->window->display();
}

void GameWrapper::init() {
	this->window = nullptr;
	this->boardColor = sf::Color(234, 182, 118);
}

void GameWrapper::initWindow() {
	this->videoMode.width = 1100;
	this->videoMode.height = 810;
	this->window = new sf::RenderWindow(this->videoMode, "LudoGame", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

