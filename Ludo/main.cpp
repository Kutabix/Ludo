#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "GameWrapper.h"

int main()
{
    GameWrapper ludo;
    while (ludo.windowIsOpen())
    {
        ludo.update();
        ludo.render();
    }


    return 0;
}

//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <string>
//
//void animate(sf::Sprite& sprite, sf::Texture textures[], int& currentImage, sf::RenderWindow& window) {
//    sf::Clock clock;
//
//    // P�tla animacji
//    while (currentImage < 5) {
//        // Sprawdzenie czasu od ostatniego prze��czenia obrazu
//        sf::Time elapsed = clock.getElapsedTime();
//
//        // Je�li min�a 1/6 sekundy, prze��cz obraz
//        if (elapsed.asSeconds() >= 1.0/8.0 ) {
//            // Zresetuj zegar
//            std::cout << elapsed.asSeconds() << std::endl;
//            clock.restart();
//            // Prze��cz obraz
//            currentImage++;
//            sprite.setTexture(textures[currentImage]);
//
//            // Wyczyszczenie okna
//            window.clear();
//
//            // Rysowanie sprite'a
//            window.draw(sprite);
//
//            // Wy�wietlenie zawarto�ci okna
//            window.display();
//        }
//            std::cout << elapsed.asSeconds() << std::endl;
//    }
//}
//
//int main() {
//    // Ustawienia okna
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Animacja SFML");
//
//    // Tablica przechowuj�ca nazwy plik�w obraz�w
//    std::string filenames[] = { "1_block.png", "2_block.png", "3_block.png", "4_block.png", "5_block.png", "6_block.png" };
//
//    // Wczytywanie obraz�w do tablicy tekstur
//    sf::Texture textures[6];
//    for (int i = 0; i < 6; ++i) {
//        if (!textures[i].loadFromFile("./images/"+filenames[i])) {
//            std::cerr << "B��d wczytywania pliku " << filenames[i] << std::endl;
//            return -1;
//        }
//
//        // Skalowanie obrazu do rozmiaru 30x30
//        textures[i].setSmooth(true);
//        textures[i].setRepeated(false);
//    }
//
//    // Inicjalizacja sprite'a
//    sf::Sprite sprite;
//    sprite.setTexture(textures[0]);
//    sprite.setScale(sf::Vector2f(60.0f / textures[0].getSize().x, 60.0f / textures[0].getSize().y));
//
//    // Indeks aktualnie wy�wietlanego obrazu
//    int currentImage = 0;
//
//    // G��wna p�tla programu
//    while (window.isOpen()) {
//        // Obs�uga zdarze�
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//                // Je�li lewy przycisk myszy jest naci�ni�ty, rozpocznij animacj�
//                animate(sprite, textures, currentImage, window);
//            }
//        }
//    }
//
//    return 0;
//}
