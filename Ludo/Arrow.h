#pragma once

#include <SFML/Graphics.hpp>

class Arrow {
public:
    Arrow(const std::string& imgPath, float x, float y);

    void draw(sf::RenderWindow& window);

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

