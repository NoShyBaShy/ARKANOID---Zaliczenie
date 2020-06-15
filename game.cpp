#include "game.h"

Game::Game(){
    this->window.create(sf::VideoMode(1280,720), "Arkanoid");
    this->window.setFramerateLimit(120);
    this->loadTextures();
    this->lvl_1();
}
void Game::update(){
    this->elapsed = clock.restart().asSeconds();

    while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
    for(unsigned i=0;i<objects.size();i++){
        objects[i]->update(elapsed);
        objects[i]->animate(elapsed);
        this->collision(objects);
        if(dynamic_cast<Block*>(objects[i])){
            if(objects[i]->is_destroyed()==true){
                this->objects[i]->del();
                objects.erase(objects.begin()+i);
                this->blocks_created--;
                std::cout << this->blocks_created << std::endl;
            }
        }
    }
}

void Game::draw(){
    this->window.clear(sf::Color::Black);
    for(auto &el : objects){
        el->draw(this->window);
    }
    this->window.display();
}

void Game::collision(std::vector<Object*> &objects){
    for(unsigned i=0;i<objects.size();i++){
        sf::FloatRect nextPos = ball->getBounds();
        nextPos.left += ball->getVelocity().x*this->elapsed;
        nextPos.top += ball->getVelocity().y*this->elapsed;

        if(dynamic_cast<Block*>(objects[i]) || dynamic_cast<Player*>(objects[i])){
            if(this->objects[i]->getBounds().intersects(nextPos)==true){
                if(dynamic_cast<Block*>(objects[i])){
                    if(objects[i]->getBounds().intersects(nextPos)==true){
                        objects[i]->getDestroyed();
                    }
                }
                //Bottom collision
                if(this->ball->getBounds().top < this->objects[i]->getBounds().top
                    && this->ball->getBounds().top + this->ball->getBounds().height < this->objects[i]->getBounds().top + this->objects[i]->getBounds().height
                    && this->ball->getBounds().left < this->objects[i]->getBounds().left + this->objects[i]->getBounds().width
                    && this->ball->getBounds().left + this->ball->getBounds().width > this->objects[i]->getBounds().left)
                {
                   ball->changeVelocity_y();
                   this->ball->setPosition(this->ball->getBounds().left,this->objects[i]->getBounds().top-this->ball->getBounds().height);

                }
                //Top collision
                if(this->ball->getBounds().top > this->objects[i]->getBounds().top
                        && this->ball->getBounds().top + this->ball->getBounds().height > this->objects[i]->getBounds().top + this->objects[i]->getBounds().height
                        && this->ball->getBounds().left < this->objects[i]->getBounds().left + this->objects[i]->getBounds().width
                        && this->ball->getBounds().left + this->ball->getBounds().width > this->objects[i]->getBounds().left)
                {
                   this->ball->setPosition(this->ball->getBounds().left,this->objects[i]->getBounds().top+this->objects[i]->getBounds().height);
                   ball->changeVelocity_y();
                }
                //Right collision
                if(this->ball->getBounds().left < this->objects[i]->getBounds().left
                    && this->ball->getBounds().left + this->ball->getBounds().width < this->objects[i]->getBounds().left + this->objects[i]->getBounds().width
                    && this->ball->getBounds().top < this->objects[i]->getBounds().top + this->objects[i]->getBounds().height
                    && this->ball->getBounds().top + this->ball->getBounds().height > this->objects[i]->getBounds().top)
                {
                    ball->changeVelocity_x();
                    this->ball->setPosition(this->objects[i]->getBounds().left-this->ball->getBounds().width,this->ball->getBounds().top);

                }
                //Left collision
                if(this->ball->getBounds().left > this->objects[i]->getBounds().left
                    && this->ball->getBounds().left + this->ball->getBounds().width > this->objects[i]->getBounds().left + this->objects[i]->getBounds().width
                    && this->ball->getBounds().top < this->objects[i]->getBounds().top + this->objects[i]->getBounds().height
                    && this->ball->getBounds().top + this->ball->getBounds().width > this->objects[i]->getBounds().top)
                {
                   this->ball->setPosition(this->objects[i]->getPosition().x+this->objects[i]->getBounds().width,this->ball->getPosition().y);
                   ball->changeVelocity_x();
                }
            }
        }
    }


}

void Game::loadTextures(){
    //background
    if(!texture.loadFromFile("Textures\\Backgrounds.png")){
        throw("Could not load textures");
    }

    this->texture.setRepeated(true);
    this->Texture.emplace_back(texture);
    this->texture.setRepeated(false);

        //player
    if(!texture.loadFromFile("Textures\\platform_normal.png")){
        throw("Could not load textures");
    }
    this->Texture.emplace_back(texture);

        //blocks
    if(!texture.loadFromFile("Textures\\Block_red.png")){
        throw("Could not load textures");
    }
    this->Texture.emplace_back(texture);

    if(!texture.loadFromFile("Textures\\Block_yellow.png")){
        throw("Could not load textures");
    }
    this->Texture.emplace_back(texture);

    if(!texture.loadFromFile("Textures\\Block_blue.png")){
        throw("Could not load textures");
    }
    this->Texture.emplace_back(texture);
}

void Game::lvl_1(){
    this->objects.emplace_back(this ->background = new Background(this->Texture[0]));
    sf::Vector2f initial_pos = {600,600};
    this->objects.emplace_back(this->player = new Player(this->Texture[1], initial_pos));
    this->objects.emplace_back(this->ball = new Ball(this->Texture[1]));

    //blocks
    for(unsigned i=0;i<14;i++){
        sf::Vector2f new_pos = {80.f+80.f*i,100.f};
        this->objects.emplace_back(this->block = new Block(this->Texture[4],new_pos));
    }
    for(unsigned i=0;i<14;i++){
        sf::Vector2f new_pos = {80.f+80.f*i,100.f+40.f};
        this->objects.emplace_back(this->block = new Block(this->Texture[3],new_pos));
    }
    for(unsigned i=0;i<14;i++){
        sf::Vector2f new_pos = {80.f+80.f*i,100.f+200.f};
        this->objects.emplace_back(this->block = new Block(this->Texture[2],new_pos));
    }
    this->blocks_created = 42;
}

bool Game::lvl_1_complete(){
    if(this->blocks_created==0){
        return true;
    }
    return false;
}

void Game::start(){
    while(window.isOpen()&&lvl_1_complete()!=true){
        this->update();
        this->draw();
    }
    if(lvl_1_complete()==true){
        std::cout << "WINNER!!!" << std::endl;
    }
}
