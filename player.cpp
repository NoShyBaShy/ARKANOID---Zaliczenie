#include "player.h"

Player::Player(const sf::Texture &texture,const sf::Vector2f &position, int xscale) : Object(texture){

    this->speed = 300;
    this->sprite.setPosition(position);
    this->sprite.setScale(xscale,3);
}

Player::Player(const sf::Texture &texture, int xscale) : Object(texture){
    this->speed = 300;
    this->sprite.setPosition({600,600});
    this->sprite.setScale(xscale,3);
}

Player::Player() : Object(){}

void Player::update(const float &elapsed){
    if(this->getPosition().x < 80){this->setPosition(80,this->getPosition().y);}
    if(this->getPosition().x +this->getBounds().width > 1200){
        this->setPosition(1200-this->getBounds().width,this->getPosition().y);
    }
}

void Player::animate(const float &elapsed){
    sf::Vector2f velocity = {0,0};
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        velocity.x = -speed*elapsed;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        velocity.x = speed*elapsed;
    }
    this->sprite.move(velocity);
}

int Player::mod_ID(){}

int Player::changeSpeed(int sp){
    return this->speed+=sp;
}






