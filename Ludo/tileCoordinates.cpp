#include "tileCoordinates.hpp"

std::vector<sf::Color> TileCoordinates::colors = {
	sf::Color(18, 149, 231),
	sf::Color(0, 181, 80),
	sf::Color(232, 20, 36),
	sf::Color(244, 220, 12),
	sf::Color(255, 255, 255)
};

sf::Color blue = TileCoordinates::colors[0];
sf::Color green = TileCoordinates::colors[1];
sf::Color red = TileCoordinates::colors[2];
sf::Color yellow = TileCoordinates::colors[3];
sf::Color white = TileCoordinates::colors[4];

std::vector<ArrowStruct> TileCoordinates::arrows = {
	{ 380+10, 30+10  },
	{ 380+10, 730+10 },
	{ 730+10, 380+10 },
	{ 30+10, 380+10  }
};

std::vector<TileStruct> TileCoordinates::getDataVector() {
    std::vector<TileStruct> dataVector = {
        {332, 30 , white},
		{332, 80 , white},
		{332, 130, white},
		{332, 180, white},
		{332, 230, white},
		{332, 280, white},

		{380, 30, white},
		{380, 80, red},
		{380, 130, red},
		{380, 180, red},
		{380, 230, red},
		{380, 280, red},

		{428, 30, white},
		{428, 80, red},
		{428, 130, white},
		{428, 180, white},
		{428, 230, white},
		{428, 280, white},
		// -----------------------
		{332, 450+30, white},
		{332, 450+80, white},
		{332, 450+130, white},
		{332, 450+180, white},
		{332, 450+230, yellow},
		{332, 450+280, white},

		{380, 450+30, yellow},
		{380, 450+80, yellow},
		{380, 450+130, yellow},
		{380, 450+180, yellow},
		{380, 450+230, yellow},
		{380, 450+280, white},

		{428, 450+30, white},
		{428, 450+80, white},
		{428, 450+130, white},
		{428, 450+180, white},
		{428, 450+230, white},
		{428, 450+280, white},
		// -----------------------
		{30, 332, white},
		{80, 332, blue},
		{130, 332, white},
		{180, 332, white},
		{230, 332, white},
		{280, 332, white},

		{30, 380, white},
		{80, 380, blue},
		{130, 380, blue},
		{180, 380, blue},
		{230, 380, blue},
		{280, 380, blue},

		{30, 428, white},
		{80, 428, white},
		{130, 428, white},
		{180, 428, white},
		{230, 428, white},
		{280, 428, white},
		// -----------------------
		{450+30, 332, white},
		{450+80, 332, white},
		{450+130, 332, white},
		{450+180, 332, white},
		{450+230, 332, white},
		{450+280, 332, white},
		 
		{450+30, 380, green},
		{450+80, 380, green},
		{450+130, 380, green},
		{450+180, 380, green},
		{450+230, 380, green},
		{450+280, 380, white},

		{450+30, 428, white},
		{450+80, 428, white},
		{450+130, 428, white},
		{450+180, 428, white},
		{450+230, 428, green},
		{450+280, 428, white},
    };

    return dataVector;
}
