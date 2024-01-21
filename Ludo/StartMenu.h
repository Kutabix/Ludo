#pragma once
// StartMenu.hpp

#include "StartMenu.h"
#include <SFML/Graphics.hpp>
#include <vector>

class StartMenu {
public:
    StartMenu();

    void draw(sf::RenderTarget& window);
    void checkHover(const sf::Vector2i& mousePosition, sf::RenderWindow& window);
    void handleClick(const sf::Vector2i& mousePosition, sf::RenderWindow& window);
    int howManyPlayers = 0;
    bool cleared = false;
private:
    sf::Font font;
    sf::Text buttonTexts[4];
    sf::RectangleShape buttons[4];

};


