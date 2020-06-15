#include "ball.h"

Ball::Ball(const sf::Texture &texture) : Object(texture){
    this->sprite.setTextureRect(sf::IntRect(0,40,5,4));
    this->sprite.setScale(2,2);
    this->velocity = {200,-200};
    this->setPosition(400,250);
}

void Ball::update(const float &elapsed){
    //screencollision
    if(this->getPosition().x < 80){
        this->setPosition(80,this->getPosition().y);
        velocity.x = this->changeVelocity_x().x;
    }
    if(this->getPosition().x + this->getBounds().width > 1200){
         this->setPosition(1200-this->getBounds().width,this->getPosition().y);
        velocity.x = this->changeVelocity_x().x;
    }
    if(this->getPosition().y < 62){
        this->setPosition(this->getPosition().x,62);
        velocity.y = this->changeVelocity_y().y;
    }
}

void Ball::animate(const float &elapsed){
    this->sprite.move(velocity*elapsed);
//    sf::Vector2f velocity;
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
//        velocity.x = -speed*elapsed;
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
//        velocity.x = speed*elapsed;
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
//        velocity.y = speed*elapsed;
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
//        velocity.y = -speed*elapsed;
//    }
//    this->sprite.move(velocity);
}

sf::Vector2f Ball::getVelocity(){
    return velocity;
}

sf::Vector2f Ball::changeVelocity_x(){
   this->velocity.x = -velocity.x;
   return velocity;
}
sf::Vector2f Ball::changeVelocity_y(){
   this->velocity.y = -velocity.y;
   return velocity;
}
