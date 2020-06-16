#ifndef PLAYER_H
#define PLAYER_H
#include <object.h>

class Player : public Object
{
private:
    int HP;
    int speed;
    int Points;

    bool small;
    bool normal;
    bool big;

public:
    Player(const sf::Texture &texture,const sf::Vector2f &position);

    virtual void update(const float &elapsed);
    virtual void animate(const float &elapsed);

    int changeHP(int hp);
    int changePoints(int points);
    bool smallSize();
    bool normalSize();
    bool bigSize();
};

#endif // PLAYER_H
