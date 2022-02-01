#include <thread>

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include "SFML/Window/Keyboard.hpp"
#include "imgui-SFML.h"
#include "imgui.h"

#include "ArrayManager.h"
#include "Sorter.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 900), "SortingVisualizer");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    ArrayManager arrMan{window, 150, 1};
    arrMan.shuffle();
    std::thread t{Sorter::cocktail_shaker_sort, std::ref(arrMan)};
    t.detach();

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        if(t.joinable())
            puts("asdf");

        window.clear();

        arrMan.renderArray();

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}