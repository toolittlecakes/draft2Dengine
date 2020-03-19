
#include "object.h"
#include "../io/output.h"
#include "../levels/level.h"


void Object::update() {
    components.update_all(*this);
}
