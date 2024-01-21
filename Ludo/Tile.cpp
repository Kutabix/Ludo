#include "Tile.h"

Tile::Tile(sf::RenderTarget& window, int px, int py, int r, int g, int b) {
    this->px = px;
    this->py = py;
    this->r = r;
    this->g = g;
    this->b = b;
    this->initShape();
    this->drawTile(window);
}

void Tile::initShape() {
    tile.setSize(sf::Vector2f(50, 50));
    tile.setPosition(px, py);
    tile.setFillColor(sf::Color(r, g, b));
    
    tile.setOutlineColor(sf::Color::Black);
    tile.setOutlineThickness(1.0f);
}

void Tile::drawTile(sf::RenderTarget& window) {
    window.draw(tile);
}