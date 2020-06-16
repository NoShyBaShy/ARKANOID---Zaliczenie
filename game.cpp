#include "game.h"

Game::Game(){
    this->window.create(sf::VideoMode(1280,720), "Arkanoid");
    this->window.setFramerateLimit(120);
    this->loadTextures();
    this->lvl_1();

}
void Game::update(){
        // clock -------------------
    this->elapsed = clock.restart().asSeconds();
        // event --------------------
    while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
    for(unsigned i=0;i<objects.size();i++){

            //objects managment ------------------
        objects[i]->update(elapsed);
        objects[i]->animate(elapsed);
        this->collision(objects);
    }
}

void Game::draw(){

        //draw objects ------------------
    this->window.clear(sf::Color::Black);
    for(auto &el : objects){
        el->draw(this->window);
    }
    this->window.display();
}

void Game::collision(std::vector<Object*> &objects){

    for(unsigned i=0;i<objects.size();i++){

            //Ball next position ----------------------
        sf::FloatRect nextPos = ball->getBounds();
        nextPos.left += ball->getVelocity().x*this->elapsed;
        nextPos.top += ball->getVelocity().y*this->elapsed;

            // Delete ball  ---------------------
        if(dynamic_cast<Ball*>(objects[i])){
            if(objects[i]->getPosition().y > 720){
                this->objects[i]->getDestroyed();
            }
            if(objects[i]->is_destroyed()==true){
                this->objects[i]->del();
                objects.erase(objects.begin()+i);
                this->balls_created--;
                std::cout << "BALLS LEFT: " << this->balls_created << std::endl;
            }
        }

            //Collision with blocks and player------------------
        if(dynamic_cast<Block*>(objects[i]) || dynamic_cast<Player*>(objects[i])){
            if(this->objects[i]->getBounds().intersects(nextPos)==true){

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

                    // delete Block
                if(dynamic_cast<Block*>(objects[i])){
                    if(objects[i]->getBounds().intersects(nextPos)==true){
                        objects[i]->getDestroyed();
                    }
                    if(objects[i]->is_destroyed()==true){
                            // create mod
                        int mod_create = rand()%3;
                        if(mod_create==1){
                            objects.emplace_back(new Mod(Texture[5],objects[i]->getPosition(),rand()%4));
                        }
                        this->objects[i]->del();
                        objects.erase(objects.begin()+i);
                        this->blocks_created--;
                        std::cout << "BLOCKS TO DESTROY: " << this->blocks_created << std::endl;
                    }
                }
            }
        }
    }


}

void Game::loadTextures(){
        //background ---------------------
    if(!texture.loadFromFile("Textures\\Backgrounds.png")){
        throw("Could not load textures");
    }

    this->texture.setRepeated(true);
    this->Texture.emplace_back(texture); //texture[0] --- background
    this->texture.setRepeated(false);

        //player ---------------------
    if(!texture.loadFromFile("Textures\\platform_normal.png")){
        throw("Could not load textures");
    }
    this->Texture.emplace_back(texture); //texture[1] --- player

        //blocks ----------------------
    if(!texture.loadFromFile("Textures\\Block_red.png")){
        throw("Could not load textures");
    }
    this->Texture.emplace_back(texture); //texture[2] --- block_red

    if(!texture.loadFromFile("Textures\\Block_yellow.png")){
        throw("Could not load textures");
    }
    this->Texture.emplace_back(texture); //texture[3] --- block_yellow

    if(!texture.loadFromFile("Textures\\Block_blue.png")){
        throw("Could not load textures");
    }
    this->Texture.emplace_back(texture); //texture[4] --- block_blue

        //mod -----------------
    if(!texture.loadFromFile("Textures\\mods.png")){
        throw("Could not load textures");
    }
    this->Texture.emplace_back(texture); //texture[5] --- mods
}

void Game::lvl_1(){

        // create objects --------------------
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
        //variable value
    this->blocks_created = 42;
    this->balls_created = 1;
}

bool Game::lvl_1_complete(){

        // check all blocks destroyed
    if(this->blocks_created==0){
        return true;
    }
    return false;
}

bool Game::lvl_1_defeat(){

        // check all balls destroyed
    if(this->balls_created==0){
        return true;
    }
    return false;
}

void Game::start(){

        // game loop
    while(window.isOpen()&&lvl_1_complete()!=true&&lvl_1_defeat()!=true){
        this->update();
        this->draw();
    }

        // end game announcement
    if(lvl_1_complete()==true){
        std::cout << "YOU WON!!!" << std::endl;
    }
    if(lvl_1_defeat()==true){
        std::cout << "YOU LOST!!! TRY AGAIN!!!" << std::endl;
    }
}
