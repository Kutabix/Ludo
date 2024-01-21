// StartMenu.cpp
#include "StartMenu.h"
#include <iostream>

StartMenu::StartMenu() {

    if (!font.loadFromFile("./fonts/FiraSans.ttf")) {
        throw std::runtime_error("Failed to load font.");
    }

    for (int i = 0; i < 4; i++) {
        buttons[i].setSize(sf::Vector2f(255.0f, 75.0f));
        buttons[i].setFillColor((i == 3) ? sf::Color(195, 195, 195) : sf::Color(11, 221, 58));
        buttons[i].setOutlineColor(sf::Color::Black);
        buttons[i].setOutlineThickness(1.0f);
        buttons[i].setPosition(815.0f, 100.0f + i * 96.0f);
    }
}

void StartMenu::draw(sf::RenderTarget& window) {
    if (this->cleared)return;
    sf::Text labelText("Wybierz liczbe graczy:", font, 26);
    labelText.setFillColor(sf::Color::Black);
    labelText.setPosition(815.0f, 50.0f);
    window.draw(labelText);


    for (int i = 0; i < 4; i++) {
        window.draw(buttons[i]);

        buttonTexts[i].setFont(font);
        buttonTexts[i].setCharacterSize(22);
        buttonTexts[i].setFillColor(sf::Color::Black);
        buttonTexts[i].setString((i == 3) ? "Start" : std::to_string(i + 2) + " graczy");
        buttonTexts[i].setPosition((i == 3) ? buttons[i].getPosition().x + 100 : buttons[i].getPosition().x + 80.0f, buttons[i].getPosition().y + 22.0f);

        window.draw(buttonTexts[i]);
        
    }
}

void StartMenu::checkHover(const sf::Vector2i& mousePosition, sf::RenderWindow& window) {
    if (!this->cleared) {
        sf::Cursor cursor;
        int offsetX = window.getPosition().x + 8;
        int offsetY = window.getPosition().y + 31;

        for (int i = 0; i < 4; ++i) {
            if (buttons[i].getGlobalBounds().contains(static_cast<int>(mousePosition.x) - offsetX, static_cast<int>(mousePosition.y) - offsetY)) {
                if (cursor.loadFromSystem(sf::Cursor::Hand))
                    window.setMouseCursor(cursor);
                return;
            }
        }
        if (cursor.loadFromSystem(sf::Cursor::Arrow))
            window.setMouseCursor(cursor);
    }
}

void StartMenu::handleClick(const sf::Vector2i& mousePosition, sf::RenderWindow& window) {
    if (this->cleared) return;
    int offsetX = window.getPosition().x + 8;
    int offsetY = window.getPosition().y + 31;
    for (int i = 0; i < 3; ++i) {
        if (buttons[i].getGlobalBounds().contains(
            static_cast<float>(mousePosition.x) - offsetX,
            static_cast<float>(mousePosition.y) - offsetY
        )) {
            for (int j = 0; j < 3; j++) {
                buttons[j].setFillColor(sf::Color(11, 221, 58));
            }
            buttons[i].setFillColor(sf::Color(1, 180, 38));
            howManyPlayers = i + 2;

        }
    }
    if (buttons[3].getGlobalBounds().contains(
        static_cast<float>(mousePosition.x) - offsetX,
        static_cast<float>(mousePosition.y) - offsetY
    )
        && howManyPlayers > 0
) {
        this->cleared = true;
        sf::Cursor cursor;
        if (cursor.loadFromSystem(sf::Cursor::Arrow))
            window.setMouseCursor(cursor);

    }
}
