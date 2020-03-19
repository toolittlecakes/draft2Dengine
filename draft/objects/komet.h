
#ifndef DRAFT_KOMET_H
#define DRAFT_KOMET_H

#include "object.h"
#include "../globals.h"

struct KometScript : public Script {
    Vec2 speed;
    void update(Object &object) override;
};

struct Komet final : public Object {
    explicit Komet(Level& level, Vec2 coords) : Object(level) {
        components.add_component(std::make_shared<Transform>(coords));
        components.add_component(std::make_shared<Draw>(Image{"../images/level1/komet.png"}));
        components.add_component<Script>(std::make_shared<KometScript>());
    }
};


#endif //DRAFT_KOMET_H
