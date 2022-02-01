#pragma once

#include <array>

#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

class ArrayManager {
public:
    ArrayManager(sf::RenderWindow& win, uint32_t len);

    void renderArray();

private:
    static uint32_t map(uint32_t x, uint32_t in_min, uint32_t in_max, uint32_t out_min,
                        uint32_t out_max);
    sf::RenderWindow& mWin;
    std::vector<uint32_t> mArr;
    std::vector<sf::Color> mCols;
};