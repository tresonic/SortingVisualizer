#include "ArrayManager.h"

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"

ArrayManager::ArrayManager(sf::RenderWindow &win, uint32_t len) : mWin(win) {
  mArr.resize(len);
  for (std::size_t i = 0; i < len; i++)
    mArr[i] = i + 1;

  mCols.resize(mArr.size());
  for (auto &c : mCols)
    c = sf::Color::Red;
}

void ArrayManager::renderArray() {
  const float barSizeX = float(mWin.getSize().x) / float(mArr.size());

  static sf::RectangleShape bar;
  for (std::size_t i = 0; i < mArr.size(); i++) {
    const float barSizeY =
        float(map(mArr[i], 0, mArr.size(), 0, mWin.getSize().y));
    bar.setSize({barSizeX, barSizeY});
    bar.setPosition({i * barSizeX, float(mWin.getSize().y) - barSizeY});
    bar.setFillColor(mCols[i]);
    mWin.draw(bar);
  }
}

uint32_t ArrayManager::map(uint32_t x, uint32_t in_min, uint32_t in_max,
                           uint32_t out_min, uint32_t out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}