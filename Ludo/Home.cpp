#include "Home.h"

Home::Home(sf::RenderTarget& window, std::vector<sf::Color> colors) {
    this->initShape(colors);
	this->drawHome(window);
}
//sf::Color(18, 149, 231),b
//sf::Color(232, 20, 36),r
//sf::Color(0, 181, 80),g
//sf::Color(244, 220, 12)y

void Home::initShape(std::vector<sf::Color> colors) {
    t1.setPointCount(3);
    t1.setPoint(0, sf::Vector2f(332, 332));
    t1.setPoint(1, sf::Vector2f(478, 332));
    t1.setPoint(2, sf::Vector2f(404, 404));
    t1.setFillColor(colors[2]);

    t2.setPointCount(3);
    t2.setPoint(0, sf::Vector2f(332, 332));
    t2.setPoint(1, sf::Vector2f(404, 404));
    t2.setPoint(2, sf::Vector2f(332, 478));
    t2.setFillColor(colors[0]);

    t3.setPointCount(3);
    t3.setPoint(0, sf::Vector2f(332, 478));
    t3.setPoint(1, sf::Vector2f(404, 404));
    t3.setPoint(2, sf::Vector2f(478, 478));
    t3.setFillColor(colors[3]);

    t4.setPointCount(3);
    t4.setPoint(0, sf::Vector2f(478, 332));
    t4.setPoint(1, sf::Vector2f(404, 404));
    t4.setPoint(2, sf::Vector2f(478, 478));
    t4.setFillColor(colors[1]);


    t1.setOutlineColor(sf::Color::Black);
    t1.setOutlineThickness(2);

    t2.setOutlineColor(sf::Color::Black);
    t2.setOutlineThickness(2);

    t3.setOutlineColor(sf::Color::Black);
    t3.setOutlineThickness(2);

    t4.setOutlineColor(sf::Color::Black);
    t4.setOutlineThickness(2);

 /*   t1.setPoint(0, sf::Vector2f(330, 330));
    t1.setPoint(1, sf::Vector2f(480, 330));
    t1.setPoint(2, sf::Vector2f(405, 405));
    t1.setFillColor(sf::Color::Red);

    t1.setPoint(0, sf::Vector2f(330, 330));
    t1.setPoint(1, sf::Vector2f(480, 330));
    t1.setPoint(2, sf::Vector2f(405, 405));
 */  // t1.setFillColor(sf::Color::Red);
}

void Home::drawHome(sf::RenderTarget& window) {
    window.draw(this->t1);
    window.draw(this->t2);
    window.draw(this->t3);
    window.draw(this->t4);
}