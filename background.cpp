#include "background.h"

Background::Background(const sf::Texture &texture,const sf::IntRect &rect,const sf::Vector2f &pos) : Object(texture){
    this->sprite.setTextureRect(sf::IntRect(rect));
    this->sprite.setPosition(pos);
}

void Background::animate(const float &elapsed){}


int Background::mod_ID(){}
void Background::update(const float &elapsed){}
