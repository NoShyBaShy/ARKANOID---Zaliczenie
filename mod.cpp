#include "mod.h"

Mod::Mod(const sf::Texture &texture, const sf::Vector2f &pos) : Object(texture){
    this->setPosition(pos.x,pos.y);
    this->speed=200;
    this->sprite.setScale(2,2);
    int mod_number=rand()%21;
    if(mod_number==0||mod_number==1||mod_number==2){
        this->sprite.setTextureRect(sf::IntRect(0,0,11,11));
        this->mod_identity=mod_number;
    }
    else if(mod_number==3){
        this->sprite.setTextureRect(sf::IntRect(12,0,11,11));
        this->mod_identity=mod_number;
    }
    else if(mod_number==4 || mod_number==5 || mod_number==6 ){
        this->sprite.setTextureRect(sf::IntRect(24,0,11,11));
        this->mod_identity=mod_number;
    }
    else if(mod_number==7||mod_number==8||mod_number==9){
        this->sprite.setTextureRect(sf::IntRect(0,12,11,11));
        this->mod_identity=mod_number;
    }
    else if(mod_number==10||mod_number==11||mod_number==12){
        this->sprite.setTextureRect(sf::IntRect(12,12,11,11));
        this->mod_identity=mod_number;
    }
    else if(mod_number==13||mod_number==14||mod_number==15){
        this->sprite.setTextureRect(sf::IntRect(36,12,11,11));
        this->mod_identity=mod_number;
    }
    else if(mod_number==16){
        this->sprite.setTextureRect(sf::IntRect(36,0,11,11));
        this->mod_identity=mod_number;
    }
    else if(mod_number==17 || mod_number==18){
        this->sprite.setTextureRect(sf::IntRect(48,0,11,11));
        this->mod_identity=mod_number;
    }
    else if(mod_number==19 || mod_number==20){
        this->sprite.setTextureRect(sf::IntRect(48,12,11,11));
        this->mod_identity=mod_number;
    }
}


void Mod::animate(const float &elapsed){
    this->sprite.move(0,speed*elapsed);
}



int Mod::mod_ID(){
    return this->mod_identity;
}


void Mod::update(const float &elapsed){}
