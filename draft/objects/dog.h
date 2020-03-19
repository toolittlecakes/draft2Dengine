
#ifndef DRAFT_BOX_H
#define DRAFT_BOX_H

#include "object.h"
#include "player.h"


//class Dog final : public Object {
//public:
//    Dog(float x, float y, Image image) : Object(x, y, std::move(image)) {}
//
//    void update(const Input &input, std::vector<std::unique_ptr<Object>> &objects) override {
//        for (auto &object : objects) {
//            if (typeid(*object) == typeid(Player)) {
//                coords += (object->coords - coords).norm()  / sqrtf((object->coords - coords).abs()/100);
//            }
//            if ((coords - object->coords).abs() < (object->image.shape.abs() + image.shape.abs()) / 2 / 1.4) {
//                coords = object->coords + (coords - object->coords).norm() *
//                                          (object->image.shape.abs() + image.shape.abs()) / 2 / 1.4;
//            }
//        }
//
//
//    }
//};

#endif //DRAFT_BOX_H
