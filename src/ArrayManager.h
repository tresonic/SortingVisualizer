#pragma once

#include <array>

#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

#include "Sine.h"

using arr_type = uint32_t;

class ArrayManager {
public:
    ArrayManager(sf::RenderWindow& win, size_t len, uint16_t delay);

    void start();

    void shuffle();

    arr_type get(size_t idx);
    void set(size_t idx, arr_type val);
    void swap(size_t a, size_t b);
    void finish();

    void renderArray() const;

    size_t getSize() { return mArr.size(); }
    void setSize(size_t len);

    uint16_t getDelay() { return mDelay; }
    void setDelay(uint16_t delay) { mDelay = delay; };

    bool isSorting() { return mIsSorting; }

private:
    static arr_type map(arr_type x, arr_type in_min, arr_type in_max, arr_type out_min,
                        arr_type out_max);
    sf::RenderWindow& mWin;
    std::vector<arr_type> mArr;
    std::vector<sf::Color> mCols;
    Sine mSine;

    uint16_t mDelay = 300;
    bool mIsSorting = false;
};