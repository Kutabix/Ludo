#include "Dice.h"
#include <iostream>
#include <set>
#include "pawnCoordinates.hpp"
#include "tileCoordinates.hpp"

int activePlayer = 0;
int alfa = 255;
bool playerTurn = true;

std::vector<sf::Color> colors = {
    sf::Color(18, 149, 231),
    sf::Color(0, 181, 80),
    sf::Color(232, 20, 36),
    sf::Color(244, 220, 12),
    sf::Color(255, 255, 255)
};

int* random() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int* result = new int[6];
    std::set<int> unique;  

    for (int i = 0; i < 6; ++i) {
        int randomN;
        do {
            randomN = std::rand() % 6;
        } while (unique.count(randomN) > 0);

        result[i] = randomN;
        unique.insert(randomN);
    }

    return result;
}

Dice::Dice() {
    this->imagePath = "./images/5_block.png";
    
    float targetWidth = 55.0f;
    float targetHeight = 55.0f;
    if (!font.loadFromFile("./fonts/FiraSans.ttf")) {
        throw std::runtime_error("Failed to load font.");
    }

    const sf::Vector2f rectangleSize(135, 135);
    const sf::Vector2f diceSize(targetWidth, targetHeight);
    const int order[4] = { 3, 0, 2, 1 };
    for (int j = 0; j < 6; j++) {
        textures[j] = new sf::Texture;
        textures[j]->loadFromFile("./images/" + std::to_string(j+1) + "_block.png");
    }

    for (int i = 0; i < 4; ++i)
    {
        rectangles[i].setSize(rectangleSize);
        rectangles[i].setPosition(835, 110+i*135 + i*25);
        
        rectangles[i].setFillColor(colors[order[i]]);


        sprites[i].setTexture(*textures[4]);
        sprites[i].setScale(diceSize.x / 1370, diceSize.y / 768);
        sprites[i].setPosition(835 + 135 / 2 - targetWidth / 2, 110 + i * 135 + i * 25 + 135/2 - targetHeight/2);
    }
}

void Dice::draw(sf::RenderTarget& window, int players) {
    int p[4];
    std::string playerNames[4];
    int twoPlayers[2] = { 0, 2 };
    int threePlayers[3] = { 0, 1, 2 };
    int fourPlayers[4] = { 3, 0, 2, 1 };
    if (players == 2) {
        for (int i = 0; i < players; i++) {
            p[i] = twoPlayers[i];
            rectangles[p[i]].setPosition(835, 110 + i * 160);
            sprites[p[i]].setPosition(875, 150 + i * 160);
        }
        playerNames[0] = "zolty";
        playerNames[1] = "czerwony";
    }
    else if (players == 3) {
        for (int i = 0; i < players; i++) {
            p[i] = threePlayers[i];
            rectangles[p[i]].setPosition(835, 110 + i * 160);
            sprites[p[i]].setPosition(875, 150 + i * 160);

        }
        playerNames[0] = "zolty";
        playerNames[1] = "niebieski";
        playerNames[2] = "czerowny";
    }
    else {
        for (int i = 0; i < players; i++) p[i] = fourPlayers[i];
        playerNames[0] = "zolty";
        playerNames[1] = "niebieski";
        playerNames[2] = "czerwony";
        playerNames[3] = "zielony";
    }

    this->labelText = sf::Text("Aktywny gracz: " + playerNames[activePlayer], font, 26);
    labelText.setFillColor(sf::Color::Black);
    labelText.setPosition(800.0f, 50.0f);
    window.draw(labelText);

    if (playerTurn == true) {
        sf::Color x = rectangles[0].getFillColor();
        x.a = alfa;
        alfa -= 5;
        if (alfa < 0) alfa = 255;
        rectangles[0].setFillColor(x);
    }
    for (int i = 0; i < players; ++i)
    {
        window.draw(rectangles[p[i]]);
        window.draw(sprites[p[i]]);
        
    }
}

void Dice::checkDiceHover(const sf::Vector2i& mousePosition, sf::RenderWindow& window, bool cleared) {
    if (playerTurn && cleared) {
        sf::Cursor cursor;
        int offsetX = window.getPosition().x + 8;
        int offsetY = window.getPosition().y + 31;

        if (rectangles[0].getGlobalBounds().contains(static_cast<int>(mousePosition.x) - offsetX, static_cast<int>(mousePosition.y) - offsetY)) {
            if (cursor.loadFromSystem(sf::Cursor::Hand))
                window.setMouseCursor(cursor);
                return;
            }
        
        if (cursor.loadFromSystem(sf::Cursor::Arrow))
            window.setMouseCursor(cursor);
    }
}

void Dice::animate(int currentImage, sf::RenderTarget& window, sf::RenderWindow& win, int players, int* tab) {
    sf::Clock clock;
    sf::Cursor cursor;

    int i = 0;
    while (i < 6) {

        sf::Time elapsed = clock.getElapsedTime();
        if (cursor.loadFromSystem(sf::Cursor::Arrow))
            win.setMouseCursor(cursor);

        if (elapsed.asSeconds() >= 1.0f/7.0f) {
            clock.restart();
            
            sprites[0].setTexture(*textures[tab[i]]);
            i++;
            if (i >= 6) break;
            this->draw(window, players);

            win.display();
        }
    }
}

bool Dice::checkIfAllInBase() {

    std::vector<std::vector<int>> initialPawnCoordinates = {
        // 0 - r
        // 1 - g
        // 2 - b
        // 3 - y
        {150, 150, 2, 0},
        {210, 150, 2, 1},
        {150, 210, 2, 2},
        {210, 210, 2, 3},
        {150, 660, 3, 4},
        {210, 660, 3, 5},
        {150, 600, 3, 6},
        {210, 600, 3, 7},
        {660, 150, 0, 8},
        {660, 210, 0, 9},
        {600, 150, 0, 10},
        {600, 210, 0, 11},
        {660, 660, 1, 12},
        {600, 660, 1, 13},
        {600, 600, 1, 14},
        {660, 600, 1, 15}
    };
    for (int i = 0; i < pawnCoordinates.size(); i++) {
        if (pawnCoordinates[i][2] == activePlayer-1) {
            int j = i;
            while (j < 4) {
                if(
                    pawnCoordinates[i+j][0] != initialPawnCoordinates[j][0] 
                    || 
                    pawnCoordinates[i+j][1] != initialPawnCoordinates[j][1]
                  ) {
                    return false;
                
                }
                j += 1;
            }
            return true;
        }
    }
}

void Dice::handleClick(const sf::Vector2i& mousePosition, sf::RenderWindow& window, bool cleared, int players) {
    std::vector<TileStruct> tCoords = TileCoordinates::getDataVector();
    if (!cleared || !playerTurn) return;
    int offsetX = window.getPosition().x + 8;
    int offsetY = window.getPosition().y + 31;
    int currentImage = 0;
    if (rectangles[0].getGlobalBounds().contains(
        static_cast<float>(mousePosition.x) - offsetX,
        static_cast<float>(mousePosition.y) - offsetY
    )) {
        int* tab = random();
        animate(currentImage, window, window, players, tab);
        activePlayer = (activePlayer + 1) % 4;
        sf::Color x = rectangles[0].getFillColor();
        x.a = 255;
        rectangles[0].setFillColor(x);
        if(tab[5] + 1 == 6 && checkIfAllInBase()) {
            pawnCoordinates[4][0] = tCoords[22].x+25;
            pawnCoordinates[4][1] = tCoords[22].y+25;
            std::cout << activePlayer << std::endl;
            std::cout << checkIfAllInBase() << std::endl;
        } 
        playerTurn = false;
    }
   
}
