//
// Created by toolittlecakes on 8/21/19.
//

#ifndef DRAFT_COMPONENT_H
#define DRAFT_COMPONENT_H

#include <vector>
#include "../io/input.h"

class Object;

class Component {
public:
    virtual void update(Object &object) {}
    virtual ~Component() = default;
};


#endif //DRAFT_COMPONENT_H
