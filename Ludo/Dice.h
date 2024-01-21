#pragma once

#include <SFML/Graphics.hpp>

class Dice
{
public:
    //Dice(const std::string& imagePath, std::vector<sf::Color>colors);
    Dice();
    void draw(sf::RenderTarget& window, int players);
    void checkDiceHover(const sf::Vector2i& mousePosition, sf::RenderWindow& window, bool cleared);
    void handleClick(const sf::Vector2i& mousePosition, sf::RenderWindow& window, bool cleared, int howmanyplayers);
    void animate(int currentImage, sf::RenderTarget& window, sf::RenderWindow& win, int howmanyplayers, int *tab);
    bool checkIfAllInBase();
private:
    std::string imagePath;
    sf::Texture *textures[6];
    sf::Sprite sprites[6];
    sf::Text labelText;
    sf::RectangleShape rectangles[4];
    sf::Font font;
};

