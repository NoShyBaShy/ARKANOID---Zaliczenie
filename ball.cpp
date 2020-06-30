#include "ball.h"

Ball::Ball(const sf::Texture &texture) : Object(texture){
    this->is_release=true;
    this->speed=300;
    this->sprite.setTextureRect(sf::IntRect(0,40,4,4));
    this->sprite.setScale(2,2);
    this->velocity = {0,200};
    this->setPosition(640,590);
}

Ball::Ball(const sf::Texture &texture, const float &pos_x) : Object(texture){
    this->is_release=true;
    this->speed=300;
    this->sprite.setTextureRect(sf::IntRect(0,40,4,4));
    this->sprite.setScale(2,2);
    this->velocity = {0,200};
    this->setPosition(pos_x,590);
}

void Ball::update(const float &elapsed){

        // ball release --------------------
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        this->is_release = false;
    }

        //screencollision --------------------
    if(this->is_release==false){
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
         //screencollision --------------------
    if(this->is_release==true){
        if(this->getPosition().x < 132){
            this->setPosition(132,this->getPosition().y);
            velocity.x = this->changeVelocity_x().x;
        }
        if(this->getPosition().x + this->getBounds().width > 1148){
            this->setPosition(1148-this->getBounds().width,this->getPosition().y);
            velocity.x = this->changeVelocity_x().x;
        }
    }

}

void Ball::animate(const float &elapsed){

        // controls --------------------
    if(this->is_release==true){
        sf::Vector2f vel;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            vel.x = -speed*elapsed;
            this->velocity.x = -speed+100;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            vel.x = speed*elapsed;
            this->velocity.x = speed-100;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            vel.y = speed*elapsed;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            vel.y = -speed*elapsed;
        }

        this->sprite.move(vel);

    }else{
        this->sprite.move(velocity*elapsed);
    }

}


int Ball::mod_ID(){}

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
