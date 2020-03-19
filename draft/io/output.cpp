//
// Created by toolittlecakes on 4/1/19.
//

#include "output.h"
#include "../component/all_components/draw.h"
#include "../component/all_components/transform.h"

void Output::update() {
    window.display();
}

void Output::clean() {
    window.clear();
    window.draw(background.getSprite());
}

void Output::draw_image(const Image &image, float x, float y) {
    sf::Sprite sprite = image.getSprite();
    int x_shift = static_cast<int>(image.shape.x) / 2;
    int y_shift = static_cast<int>(image.shape.y) / 2;
    sprite.move(x - x_shift, y - y_shift);
    window.draw(sprite);
}

void Output::draw(Object &object) {
    if (object.get_component<Draw>() != nullptr &&
        object.get_component<Transform>() != nullptr) {

        draw_image(object.get_component<Draw>()->image,
                   object.get_component<Transform>()->coords.x,
                   object.get_component<Transform>()->coords.y);
    }
}
