#include "Pawn.h"

Pawn::Pawn(sf::RenderTarget& window, int color, int posx, int posy) {
	this->posx = posx;
	this->posy = posy;
	this->radius1 = 5;
	this->radius2 = 15;
	this->radius3 = 20;
	this->colors = {
		{sf::Color(250, 121, 5), sf::Color(232, 20, 36), sf::Color(255, 255, 255)},
		{sf::Color(5, 230, 121), sf::Color(0, 181, 80), sf::Color(255, 255, 255)},
		{sf::Color(5, 121, 250), sf::Color(18, 149, 231), sf::Color(255, 255, 255)},
		{sf::Color(255, 255, 89), sf::Color(244, 220, 12), sf::Color(255, 255, 255)}
	};

	// 0 - r
	// 1 - g
	// 2 - b
	// 3 - y
	this->color = color;

	this->initShape();
	this->drawPawn(window);
}

void Pawn::initShape() {
	this->c1.setRadius(radius1);
	this->c2.setRadius(radius2);
	this->c3.setRadius(radius3);

	this->c1.setPosition(posx - radius1, posy - radius1);
	this->c2.setPosition(posx - radius2, posy - radius2);
	this->c3.setPosition(posx - radius3, posy - radius3);

	c1.setFillColor(this->colors[this->color][0]);
	c2.setFillColor(this->colors[this->color][1]);
	c3.setFillColor(this->colors[this->color][2]);
}

void Pawn::drawPawn(sf::RenderTarget& window) {
	window.draw(this->c3);
	window.draw(this->c2);
	window.draw(this->c1);
}