#include "object.h"

bool Object::is_destroyed(){
    return this->destroy;
}

Object::Object(const sf::Texture &texture): sprite(texture){
    this->destroy = false;
}

sf::FloatRect Object::getBounds(){
    return this->sprite.getGlobalBounds();
}

sf::Vector2f Object::getPosition(){
    return this->sprite.getPosition();
}

void Object::setPosition(float x,float y){
    this->sprite.setPosition(x,y);
}

void Object::del(){
    delete this;
}

void Object::draw(sf::RenderTarget &render_target){
    render_target.draw(this->sprite);
}

bool Object::getDestroyed(){
    return this->destroy = true;
}
