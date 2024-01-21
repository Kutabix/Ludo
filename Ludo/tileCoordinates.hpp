#pragma once

#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

struct TileStruct {
    int x;
    int y;
    sf::Color col;
};

struct ArrowStruct {
    int x;
    int y;
};


class TileCoordinates {
public:
    static std::vector<TileStruct> getDataVector();
    static std::vector<ArrowStruct> arrows;
    static std::vector<sf::Color> colors;
};

