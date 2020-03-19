//
// Created by toolittlecakes on 12/17/18.
//

#ifndef DRAFT_LEVEL1_H
#define DRAFT_LEVEL1_H

#include "level.h"
#include "../objects/player.h"

class Level1 : public Level {

public:
    Level1(Input &in, Output &out) : Level(1, in, out) {

    }

    void init() override;

    bool is_finished() const override;

};

#endif //DRAFT_LEVEL1_H
