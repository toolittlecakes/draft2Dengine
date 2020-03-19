#include "image.h"

Image::Image(const std::string &filename) {
    texture.loadFromFile(filename);
    texture.setSmooth(true);
    shape.x = texture.getSize().x;
    shape.y = texture.getSize().y;
}

const sf::Texture &Image::getTexture() const {
    return texture;
}

sf::Sprite Image::getSprite() const {
    sf::Sprite sprite(texture);
    return sprite;
}