#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Home
{
	private:
		sf::ConvexShape t1;
		sf::ConvexShape t2;
		sf::ConvexShape t3;
		sf::ConvexShape t4;
		std::vector<std::vector<sf::Color>> colors;
	public:
		Home(sf::RenderTarget& window, std::vector<sf::Color> colors);
		void initShape(std::vector<sf::Color> colors);
		void drawHome(sf::RenderTarget& window);
};

