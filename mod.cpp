#include "mod.h"

Mod::Mod(const sf::Texture &texture, const sf::Vector2f &pos, int mod_number) : Object(texture){
    this->setPosition(pos.x,pos.y);
    this->speed=200;
    this->sprite.setScale(2,2);
    this->mod_identity=mod_number;
    if(mod_number==0){
        this->sprite.setTextureRect(sf::IntRect(0,0,11,11));
    }
    else if(mod_number==1){
        this->sprite.setTextureRect(sf::IntRect(12,0,11,11));
    }
    else if(mod_number==2){
        this->sprite.setTextureRect(sf::IntRect(24,0,11,11));
    }
    else if(mod_number==3){
        this->sprite.setTextureRect(sf::IntRect(0,12,11,11));
    }
    else if(mod_number==4){
        this->sprite.setTextureRect(sf::IntRect(12,12,11,11));
    }
}
void Mod::animate(const float &elapsed){
    this->sprite.move(0,speed*elapsed);
}

int Mod::mod_ID(){
    return this->mod_identity;
}


void Mod::update(const float &elapsed){}
