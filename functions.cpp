#include "class.h"


void Player::loadTextures(){
    sf::Texture player;
    if(!player.loadFromFile("Textures\\Vaus.png")){
        throw("Could not load textures");
    }
    textures.emplace_back(player);
}

void Player::createSprite(){
    this->loadTextures();
    this->setTexture(textures[0]);
    if(is_large == true){
        this->setTextureRect(sf::IntRect(66,0,44,7));
        this->setScale(3,3);
    }
    if(is_medium == true){
        this->setTextureRect(sf::IntRect(34,0,28,7));
        this->setScale(3,3);
    }
    if(is_small == true){
        this->setTextureRect(sf::IntRect(117,0,22,7));
        this->setScale(3,3);
    }
}

void Player::animate(const sf::Time &elapsed){
    if(faster == true){ speed = 450.f;}
    if(normal == true){ speed = 300.f;}
    if(slower == true){ speed = 200.f;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if(swap == true){
            velocity.x = speed*elapsed.asSeconds();
        }else{
            velocity.x = -speed*elapsed.asSeconds();
        }
        move(velocity);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if(swap == true){
            velocity.x = -speed*elapsed.asSeconds();
        }else{
            velocity.x = speed*elapsed.asSeconds();
        }
        move(velocity);
    }

}

void Player::screen_collision(){
    if(this->getPosition().x < 0){this->setPosition(0,this->getPosition().y);}
    if(this->getPosition().x + this->getGlobalBounds().width > 800){
        this->setPosition(800-this->getGlobalBounds().width,this->getPosition().y);}
    if(this->getPosition().y < 0){this->setPosition(this->getPosition().x,0);}
}

void Background::loadTextures(){
    sf::Texture background;
    if(!background.loadFromFile("Textures\\Backgrounds.png")){
        throw("Could not load textures");
    }
    background.setRepeated(true);
    textures.emplace_back(background);
}

void Background::createSprite(){
    this->loadTextures();
    this->setTexture(textures[0]);
    this->setTextureRect(sf::IntRect(0,0,800,600));
}
