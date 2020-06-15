#include "block.h"

Block::Block(const sf::Texture &texture, const sf::Vector2f &pos) : Object(texture){
    this->sprite.setScale(4,4);
    this->sprite.setPosition(pos);
}
void Block::animate(const float &elapsed){}
void Block::update(const float &elapsed){}
