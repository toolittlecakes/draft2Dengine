//
// Created by toolittlecakes on 8/22/19.
//

#ifndef DRAFT_DRAW_H
#define DRAFT_DRAW_H

#include "../component.h"
#include "../../image.h"

class Draw final : public Component {
public:
    Image image;

    explicit Draw(Image _image) : image(std::move(_image)){}
};

#endif //DRAFT_DRAW_H
