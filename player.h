#ifndef PLAYER_H
#define PLAYER_H
#include <object.h>

class Player : public Object
{
private:
    int HP;
    int speed;

    bool small;
    bool normal = true;
    bool big;

public:
    Player(const sf::Texture &texture,const sf::Vector2f &position);

    virtual void update(const float &elapsed);
    virtual void animate(const float &elapsed);

    int changeHP(){return HP-=1;}
    bool smallSize();
};

#endif // PLAYER_H
