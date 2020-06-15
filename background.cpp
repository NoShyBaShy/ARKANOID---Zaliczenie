#include "background.h"

Background::Background(const sf::Texture &texture) : Object(texture){
    this->sprite.setTextureRect(sf::IntRect(0,0,1120,900));
    this->sprite.setPosition(80,62);
}

void Background::animate(const float &elapsed){}
void Background::update(const float &elapsed){}
