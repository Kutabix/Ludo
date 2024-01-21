#include "Arrow.h"

Arrow::Arrow(const std::string& imgPath, float x, float y) {
    if (!texture.loadFromFile(imgPath)) {
        throw std::runtime_error("Nie uda³o siê wczytaæ obrazu.");
    }

    sprite.setTexture(texture);
    sprite.setScale(25.0f / texture.getSize().x, 25.0f / texture.getSize().y);

    sprite.setPosition(x, y);
}

void Arrow::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}