//
// Created by toolittlecakes on 8/19/19.
//

#include "komet.h"
#include "../levels/level.h"

void KometScript::update(Object &object) {

    auto transform = object.get_component<Transform>();

    auto &objects = object.get_level().get_objects();
    for (auto &another : objects) {
        if (&object != &*another) {
            auto an_transform = another->get_component<Transform>();
            auto direction = an_transform->coords - transform->coords;

            auto an_shape = another->get_component<Draw>()->image.shape;
            auto shape = object.get_component<Draw>()->image.shape;


            speed +=
                direction.norm() / direction.abs() / direction.abs() * an_shape.x * an_shape.y / 10;
            if (direction.abs() < (an_shape.abs() + shape.abs()) / 2 / 1.4) {

                if (speed.dot(direction.norm()) > 0)
                    speed -= direction.norm() * speed.dot(direction.norm()) * 2.f;


            }
        }
    }
    auto last_coords = transform->coords;
    transform->coords += speed;
    for (auto &another : objects) {
        if (&object != &*another) {

            auto an_transform = another->get_component<Transform>();
            auto direction = an_transform->coords - transform->coords;

            auto an_shape = another->get_component<Draw>()->image.shape;
            auto shape = object.get_component<Draw>()->image.shape;


            if (direction.abs() < (an_shape.abs() + shape.abs()) / 2 / 1.4) {
                transform->coords = an_transform->coords + (transform->coords - an_transform->coords).norm() *
                                                           (an_shape.abs() + shape.abs()) / 2 / 1.4;

            }
        }
    }
    speed = transform->coords - last_coords;
    if (transform->coords.y > height && speed.y > 0) {
        speed.y = -speed.y * 0.9f;
    }
    if (transform->coords.x > width && speed.x > 0) {
        speed.x = -speed.x * 0.9f;
    }
    if (transform->coords.y < 0 && speed.y < 0) {
        speed.y = -speed.y * 0.9f;
    }
    if (transform->coords.x < 0 && speed.x < 0) {
        speed.x = -speed.x * 0.9f;
    }

}
