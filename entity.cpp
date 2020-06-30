#include "entity.h"

Entity::Entity(const sf::Texture &texture): sprite(texture){
    this->destroy = false;
}

sf::FloatRect Entity::getBounds(){
    return this->sprite.getGlobalBounds();
}

sf::Vector2f Entity::getPosition(){
    return this->sprite.getPosition();
}

void Entity::setPosition(float x,float y){
    this->sprite.setPosition(x,y);
}

void Entity::del(){
    delete this;
}

void Entity::draw(sf::RenderTarget &render_target){
    render_target.draw(this->sprite);
}
