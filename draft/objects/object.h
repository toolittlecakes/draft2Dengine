#include <utility>


#ifndef DRAFT_OBJECT_H
#define DRAFT_OBJECT_H

#include "../image.h"
#include "../io/input.h"
#include "../vec2.h"
#include "../component/component_container.h"


class Level;
class Output;



class Object {
protected:
    ComponentContainer components;
    Level& level;
public:
    explicit Object(Level& level) : level(level){}

    virtual void update();


    template <typename T>

    auto get_component() {
        return components.get_component<T>();
    }

    Level& get_level() {
        return level;
    }

    virtual ~Object() = default;
};
#endif //DRAFT_OBJECT_H
