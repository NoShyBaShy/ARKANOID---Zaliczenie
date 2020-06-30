#include "block.h"

Block::Block(const sf::Texture &texture, const sf::Vector2f &pos, int hp) : Object(texture){
    this->sprite.setScale(4,4);
    this->sprite.setPosition(pos);
    this->HP = hp;
}
void Block::animate(const float &elapsed){}


int Block::mod_ID(){}
void Block::update(const float &elapsed){}
