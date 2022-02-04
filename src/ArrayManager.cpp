#include "ArrayManager.h"

#include <algorithm>
#include <chrono>
#include <thread>
#include <random>

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

const sf::Color READ_COL = sf::Color::Red;
const sf::Color WRITE_COL = sf::Color::Yellow;
const sf::Color STD_COL = sf::Color::Blue;
const sf::Color END_COL = sf::Color::Green;

ArrayManager::ArrayManager(sf::RenderWindow& win, size_t len, uint16_t delay) : mWin(win)
{
    setSize(len);
    mDelay = delay;
}

void ArrayManager::shuffle()
{
    std::shuffle(mArr.begin(), mArr.end(), std::mt19937{});
}

void ArrayManager::start()
{
    shuffle();
    for(auto& c : mCols)
        c = STD_COL;
    mSine.play();
    mIsSorting = true;
}

arr_type ArrayManager::get(size_t idx)
{
    mCols[idx] = READ_COL;
    mSine.setFreq(map(mArr[idx], 0, mArr.size(), 50, 1500));
    std::this_thread::sleep_for(std::chrono::milliseconds(mDelay));
    mCols[idx] = STD_COL;
    return mArr[idx];
}

void ArrayManager::set(size_t idx, arr_type val)
{
    mCols[idx] = WRITE_COL;
    std::this_thread::sleep_for(std::chrono::milliseconds(mDelay));
    mCols[idx] = STD_COL;
    mArr[idx] = val;
}

void ArrayManager::swap(size_t a, size_t b)
{
    mCols[a] = WRITE_COL;
    mCols[b] = WRITE_COL;
    std::this_thread::sleep_for(std::chrono::milliseconds(mDelay));
    mCols[b] = STD_COL;
    mCols[a] = STD_COL;
    arr_type tmp = mArr[a];
    mArr[a] = mArr[b];
    mArr[b] = tmp;
}

void ArrayManager::finish()
{
    for (size_t i = 0; i < mArr.size(); i++) {
        get(i);
        mCols[i] = END_COL;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    mSine.stop();
    mIsSorting = false;
}

void ArrayManager::renderArray() const
{
    const float barSizeX = float(mWin.getSize().x) / float(mArr.size());

    static sf::RectangleShape bar;
    for (std::size_t i = 0; i < mArr.size(); i++) {
        const float barSizeY = float(map(mArr[i], 0, mArr.size(), 0, mWin.getSize().y));
        bar.setSize({barSizeX, barSizeY});
        bar.setPosition({i * barSizeX, float(mWin.getSize().y) - barSizeY});
        bar.setFillColor(mCols[i]);
        mWin.draw(bar);
    }
}

void ArrayManager::setSize(size_t len)
{
    mArr.resize(len);
    for (std::size_t i = 0; i < len; i++)
        mArr[i] = i + 1;

    mCols.resize(mArr.size());
    for (auto& c : mCols)
        c = STD_COL;
}

arr_type ArrayManager::map(arr_type x, arr_type in_min, arr_type in_max, arr_type out_min,
                           arr_type out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}