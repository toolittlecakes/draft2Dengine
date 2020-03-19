
#ifndef GAME_OUTPUT_H
#define GAME_OUTPUT_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../image.h"
#include "../objects/object.h"

class Output {
    sf::RenderWindow &window;
    Image background{"../images/background.png"};

public:
    explicit Output(sf::RenderWindow &new_window) : window(new_window) {}

    void update();

    void clean();

    void draw_image(const Image &image, float x, float y);

    void draw(Object &object);


};

#endif //GAME_OUTPUT_H
