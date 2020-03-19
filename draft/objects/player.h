
#ifndef DRAFT_PLAYER_H
#define DRAFT_PLAYER_H

#include "object.h"


struct PlayerScript : public Script {
    void update(Object &object) override;
};

struct Player final : public Object {
    explicit Player(Level& level) : Object(level) {
        components.add_component(std::make_shared<Transform>());
        components.add_component(std::make_shared<Draw>(Image{"../images/level1/player.png"}));
        components.add_component<Script>(std::make_shared<PlayerScript>());
    }
};

#endif //DRAFT_PLAYER_H
