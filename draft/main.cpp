#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include "io/output.h"
#include "io/input.h"
#include "levels/level.h"
#include "levels/level1.h"
#include "globals.h"



class Game {
    sf::RenderWindow window;
    Input input;
    Output output;
    std::vector<std::unique_ptr<Level>> levels;

public:
    Game(): input(window), output(window) {
        window.create(sf::VideoMode(width, height), "Game");
        levels.emplace_back(std::make_unique<Level1>(input, output));
    }
    void run() {
        try {
            for (auto &level : levels) {
                level->init();
                level->run();
            }
        }
        catch (std::logic_error&) {}
        window.close();
    }
};


int main() {
    Game game;
    game.run();

    return 0;
}