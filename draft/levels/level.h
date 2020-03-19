#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H


#include <SFML/Window.hpp>
#include <memory>
#include "../io/input.h"
#include "../io/output.h"

class Level {
protected:
    const int number;
    const std::string dir_name;
    Input &input;
    Output &output;
    using Objects = std::vector<std::unique_ptr<Object>>;
    Objects objects;
public:
    Level(int num, Input &in, Output &out) : number(num), input(in), output(out),
                                             dir_name("../images/level" + std::to_string(number) + '/') {
    }

    virtual void init() = 0;

    virtual void update() {
        for (auto &object : objects) {
            object->update();
        }
    }

    virtual void draw() {
        output.clean();
        for (auto &object : objects) {
            output.draw(*object);
        }
        output.update();
    }

    virtual void run() {
        sf::Clock clock;
        draw();
        while (!is_finished()) {
            sf::Time elapsed;
            do {
                elapsed = clock.getElapsedTime();
            } while (elapsed.asMilliseconds() < 25); //40 fps

            clock.restart();
            input.update();
            update();
            draw();
        }
    }

    virtual bool is_finished() const = 0;


    virtual ~Level() = default;


    auto& get_input() { return input; }
    auto& get_output() { return output; }
    auto& get_objects() { return objects; }


//    friend Object;
//    friend Component;
};


#endif //GAME_LEVEL_H
