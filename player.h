#ifndef PLAYER_H
#define PLAYER_H
#include <object.h>

class Player : virtual public Object
{
private:    
    int speed;
    sf::Vector2f initial_pos;
public:
    Player(const sf::Texture &texture,const sf::Vector2f &position,int xscale);
    Player(const sf::Texture &texture,int xscale);
    Player();

    virtual void update(const float &elapsed);
    virtual void animate(const float &elapsed);
    virtual int mod_ID();
    int changeSpeed(int sp);
};

#endif // PLAYER_H
