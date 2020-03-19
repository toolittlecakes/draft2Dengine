
#ifndef DRAFT_TRANSFORM_H
#define DRAFT_TRANSFORM_H

#include "../component.h"
#include "../../vec2.h"

class Transform final : public Component {
public:
    Vec2 coords;

    explicit Transform(Vec2 coords = Vec2{0, 0}) : coords(coords) {}
};

#endif //DRAFT_TRANSFORM_H
