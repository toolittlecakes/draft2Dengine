//
// Created by toolittlecakes on 12/17/18.
//

#include "player.h"
#include "../levels/level.h"
void PlayerScript::update(Object &object) {
    auto& input = object.get_level().get_input();
    object.get_component<Transform>()->coords += Vec2{input.getAxisX(), input.getAxisY()}.norm() * 3.f;
}
