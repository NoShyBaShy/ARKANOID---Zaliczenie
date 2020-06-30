#include "game.h"

Game::Game(){

    this->window.create(sf::VideoMode(1280,720), "Arkanoid");
    this->window.setFramerateLimit(120);
    this->loadMusic();
    this->loadTextures();
    this->loadFont();
    this->Points=0;
    this->HP=1;
    this->lvl_started=false;
    this->LVL=1;

}
void Game::update(){

        // SCORE -------------------
    this->setFont();
        // CLOCK -------------------
    this->elapsed = clock.restart().asSeconds();

        // EVENT --------------------
    while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }

        //PLAYER MANAGMENT -----------------
    this->player->update(elapsed);
    this->player->animate(elapsed);

        //COLLISION -----------------
    this->collision(objects);


        //OBJECTS MANAGMENT ------------------
    for(unsigned i=0;i<objects.size();i++){          
        objects[i]->update(elapsed);
        objects[i]->animate(elapsed);
    }
}

void Game::draw(){

        //DRAW OBJECTS ------------------
    this->window.clear(sf::Color::Black);
    for(auto &el : objects){
        el->draw(this->window);
    }
    this->player->draw(this->window);
    this->window.draw(score);
    this->window.draw(Health);
    this->window.draw(level);
    this->window.display();
}

void Game::collision(std::vector<Object*> &objects){

    for(unsigned i=0;i<objects.size();i++){

            //BALL NEXT POSITION ----------------------
        sf::FloatRect nextPos = ball->getBounds();
        nextPos.left += ball->getVelocity().x*this->elapsed;
        nextPos.top += ball->getVelocity().y*this->elapsed;

            // DELETE BALL  ---------------------
        if(dynamic_cast<Ball*>(objects[i])){
            if(objects[i]->getPosition().y > 720){
                this->objects[i]->getDestroyed();
                    //HITSOUND
                this->sound_lose.play();
            }
            if(objects[i]->is_destroyed()==true){
                objects.erase(objects.begin()+i);                
                this->balls_created--;
                std::cout << "BALLS LEFT: " << this->balls_created << std::endl;
                if(this->balls_created>0){
                    delete ball;
                    objects.emplace_back(this->ball = new Ball(Texture[1],this->player->getPosition().x+this->player->getBounds().width*0.5));
                }
            }
        }


            // SET AND DELETE MOD -------------------
        if(dynamic_cast<Mod*>(objects[i])){
            if(this->player->getBounds().intersects(this->objects[i]->getBounds())){
                    //HITSOUND
                this->sound_powerup.play();

                this->setMod(objects);
                this->objects[i]->getDestroyed();
            }
            if(objects[i]->getPosition().y > 720){
                this->objects[i]->getDestroyed();
            }
            if(objects[i]->is_destroyed()==true){
                this->objects[i]->del();
                objects.erase(objects.begin()+i);
                this->mod_created = false;
            }
        }
            // COLLISION WITH PLAYERS -------------------
        if(this->player->getBounds().intersects(nextPos)==true){

                //HITSOUND
            this->sound_player.play();

            //BOTTOM COLLISION -------------------
            if(this->ball->getBounds().top < this->player->getBounds().top
                && this->ball->getBounds().top + this->ball->getBounds().height < this->player->getBounds().top + this->player->getBounds().height
                && this->ball->getBounds().left < this->player->getBounds().left + this->player->getBounds().width
                && this->ball->getBounds().left + this->ball->getBounds().width > this->player->getBounds().left)
            {
               ball->changeVelocity_y();
               this->ball->setPosition(this->ball->getBounds().left,this->player->getBounds().top-this->ball->getBounds().height);
            }
            //TOP COLLISION -------------------
            if(this->ball->getBounds().top > this->player->getBounds().top
                    && this->ball->getBounds().top + this->ball->getBounds().height > this->player->getBounds().top + this->player->getBounds().height
                    && this->ball->getBounds().left < this->player->getBounds().left + this->player->getBounds().width
                    && this->ball->getBounds().left + this->ball->getBounds().width > this->player->getBounds().left)
            {
               this->ball->setPosition(this->ball->getBounds().left,this->player->getBounds().top+this->player->getBounds().height);
               ball->changeVelocity_y();
            }
            //RIGHT COLLISION -------------------
            if(this->ball->getBounds().left < this->player->getBounds().left
                && this->ball->getBounds().left + this->ball->getBounds().width < this->player->getBounds().left + this->player->getBounds().width
                && this->ball->getBounds().top < this->player->getBounds().top + this->player->getBounds().height
                && this->ball->getBounds().top + this->ball->getBounds().height > this->player->getBounds().top)
            {
                ball->changeVelocity_x();
                this->ball->setPosition(this->player->getBounds().left-this->ball->getBounds().width,this->ball->getBounds().top);

            }
            //LEFT COLLISION -------------------
            if(this->ball->getBounds().left > this->objects[i]->getBounds().left
                && this->ball->getBounds().left + this->ball->getBounds().width > this->player->getBounds().left + this->player->getBounds().width
                && this->ball->getBounds().top < this->objects[i]->getBounds().top + this->player->getBounds().height
                && this->ball->getBounds().top + this->ball->getBounds().width > this->player->getBounds().top)
            {
               this->ball->setPosition(this->player->getPosition().x+this->player->getBounds().width,this->ball->getPosition().y);
               ball->changeVelocity_x();
            }
        }

            //COLLISION WITH BLOCKS ------------------
        if(dynamic_cast<Block*>(objects[i])){

            if(this->objects[i]->getBounds().intersects(nextPos)==true){

                    //HITSOUND
                this->sound_block.play();;

                //BOTTOM COLLISION -------------------
                if(this->ball->getBounds().top < this->objects[i]->getBounds().top
                    && this->ball->getBounds().top + this->ball->getBounds().height < this->objects[i]->getBounds().top + this->objects[i]->getBounds().height
                    && this->ball->getBounds().left < this->objects[i]->getBounds().left + this->objects[i]->getBounds().width
                    && this->ball->getBounds().left + this->ball->getBounds().width > this->objects[i]->getBounds().left)
                {
                   ball->changeVelocity_y();
                   this->ball->setPosition(this->ball->getBounds().left,this->objects[i]->getBounds().top-this->ball->getBounds().height);
                }
                //TOP COLLISION -------------------
                if(this->ball->getBounds().top > this->objects[i]->getBounds().top
                        && this->ball->getBounds().top + this->ball->getBounds().height > this->objects[i]->getBounds().top + this->objects[i]->getBounds().height
                        && this->ball->getBounds().left < this->objects[i]->getBounds().left + this->objects[i]->getBounds().width
                        && this->ball->getBounds().left + this->ball->getBounds().width > this->objects[i]->getBounds().left)
                {
                   this->ball->setPosition(this->ball->getBounds().left,this->objects[i]->getBounds().top+this->objects[i]->getBounds().height);
                   ball->changeVelocity_y();
                }
                //RIGHT COLLISION -------------------
                if(this->ball->getBounds().left < this->objects[i]->getBounds().left
                    && this->ball->getBounds().left + this->ball->getBounds().width < this->objects[i]->getBounds().left + this->objects[i]->getBounds().width
                    && this->ball->getBounds().top < this->objects[i]->getBounds().top + this->objects[i]->getBounds().height
                    && this->ball->getBounds().top + this->ball->getBounds().height > this->objects[i]->getBounds().top)
                {
                    ball->changeVelocity_x();
                    this->ball->setPosition(this->objects[i]->getBounds().left-this->ball->getBounds().width,this->ball->getBounds().top);

                }
                //LEFT COLLISION -------------------
                if(this->ball->getBounds().left > this->objects[i]->getBounds().left
                    && this->ball->getBounds().left + this->ball->getBounds().width > this->objects[i]->getBounds().left + this->objects[i]->getBounds().width
                    && this->ball->getBounds().top < this->objects[i]->getBounds().top + this->objects[i]->getBounds().height
                    && this->ball->getBounds().top + this->ball->getBounds().width > this->objects[i]->getBounds().top)
                {
                   this->ball->setPosition(this->objects[i]->getPosition().x+this->objects[i]->getBounds().width,this->ball->getPosition().y);
                   ball->changeVelocity_x();
                }

                    // DELETE BLOCK -------------------
                if(dynamic_cast<Block*>(objects[i])){
                    if(objects[i]->getBounds().intersects(nextPos)==true){
                        objects[i]->changeHP(-1);
                        if(objects[i]->changeHP(-1)<=0){
                           objects[i]->getDestroyed();
                        }
                    }
                    if(objects[i]->is_destroyed()==true){

                            // create mod -------------------
                        int mod_create = 1;
                        if(mod_create==1&&this->mod_created==false){
                            this->mod_created = true;
                            objects.emplace_back(new Mod(Texture[5],objects[i]->getPosition()));
                        }
                        this->objects[i]->del();
                        objects.erase(objects.begin()+i);
                        this->blocks_created--;
                        this->changePoints(100);
                        std::cout << "+100 POINTS: " << this->Points << std::endl;
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

        //PLAYER ---------------------
    if(!texture.loadFromFile("Textures\\platform_normal.png")){
        throw("Could not load textures");
    }
    this->Texture.emplace_back(texture); //texture[1] --- player

        //BLOCKS ----------------------
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

void Game::loadMusic(){

        //PLAYER HIT
    if(!buffer_player.loadFromFile("Music\\player.ogg")){
        throw("Could not load sound");
    }
    sound_player.setBuffer(buffer_player);

        //BLOCK HIT
    if(!buffer_block.loadFromFile("Music\\block.ogg")){
        throw("Could not load sound");
    }
    sound_block.setBuffer(buffer_block);

        //POWER UP PICK
    if(!buffer_powerup.loadFromFile("Music\\powerup.ogg")){
        throw("Could not load sound");
    }
    sound_powerup.setBuffer(buffer_powerup);

        //WIN
    if(!buffer_win.loadFromFile("Music\\win.ogg")){
        throw("Could not load sound");
    }
    sound_win.setBuffer(buffer_win);

        //LOSE
    if(!buffer_lose.loadFromFile("Music\\lose.ogg")){
        throw("Could not load sound");
    }
    sound_lose.setBuffer(buffer_lose);

    sound_player.setVolume(10);
    sound_block.setVolume(10);
    sound_powerup.setVolume(10);
    sound_win.setVolume(10);
    sound_lose.setVolume(10);

}

void Game::loadFont(){
    if(!font.loadFromFile("Font//New Athletic M54.ttf")){
        throw("Could not load font");
    }

    Health.setFont(font);
    Health.setCharacterSize(40);

    score.setFont(font);
    score.setCharacterSize(40);
    score.setPosition(550,0);

    level.setFont(font);
    level.setCharacterSize(40);
    level.setPosition(1200,0);
}

void Game::setFont(){
    std::ostringstream ssScore;
    ssScore << "Score: " << this->Points;
    score.setString(ssScore.str());

    std::ostringstream ssHP;
    ssHP << "HP: " << this->balls_created;
    Health.setString(ssHP.str());

    std::ostringstream sslevel;
    sslevel << "LVL: " << this->LVL;
    level.setString(sslevel.str());
}

void Game::lvl_1(){

        //VARIABLE VALUE -------------------
    this->blocks_created = 42;
    this->balls_created = 2;
    this->xScale = 4;

        // CREATE OBJECT --------------------
    this->objects.emplace_back(this ->background = new Background(this->Texture[0],sf::IntRect(0,0,1120,900),{80,62}));
    this->player = new Player(this->Texture[1],this->xScale);
    this->objects.emplace_back(this->ball = new Ball(this->Texture[1]));

        //blocks -------------------
    for(unsigned i=0;i<14;i++){
        sf::Vector2f new_pos = {80.f+80.f*i,100.f};
        this->objects.emplace_back(this->block = new Block(this->Texture[4],new_pos,6));
    }
    for(unsigned i=0;i<14;i++){
        sf::Vector2f new_pos = {80.f+80.f*i,100.f+40.f};
        this->objects.emplace_back(this->block = new Block(this->Texture[3],new_pos,4));
    }
    for(unsigned i=0;i<14;i++){
        sf::Vector2f new_pos = {80.f+80.f*i,100.f+200.f};
        this->objects.emplace_back(this->block = new Block(this->Texture[2],new_pos,2));
    }


}

void Game::lvl_2(){


        //VARIABLE VALUE -------------------
    this->blocks_created = 84;
    this->xScale = 4;

        //BLOCKS -------------------
    for(unsigned i=0;i<8;i++){
        sf::Vector2f new_pos = {320.f+80.f*i,100.f};
        this->objects.emplace_back(this->block = new Block(this->Texture[4],new_pos,4));
    }
    for(unsigned i=0;i<10;i++){
        sf::Vector2f new_pos = {240.f+80.f*i,140.f};
        if(i==0 || i==9){
            this->objects.emplace_back(this->block = new Block(this->Texture[4],new_pos,4));
        }else{
            this->objects.emplace_back(this->block = new Block(this->Texture[3],new_pos,6));
        }

    }
    for(unsigned i=0;i<12;i++){
        for(unsigned j=0;j<4;j++){
            sf::Vector2f new_pos = {160.f+80.f*i,180.f+40.f*j};
            if(i==0 || i==11){
                this->objects.emplace_back(this->block = new Block(this->Texture[4],new_pos,4));
            }else if(i==1 || i==10){
                this->objects.emplace_back(this->block = new Block(this->Texture[3],new_pos,6));
            }else{
                this->objects.emplace_back(this->block = new Block(this->Texture[2],new_pos,2));
            }
        }
    }
    for(unsigned i=0;i<10;i++){
        sf::Vector2f new_pos = {240.f+80.f*i,340.f};
        if(i==0 || i==9){
            this->objects.emplace_back(this->block = new Block(this->Texture[4],new_pos,4));
        }else{
            this->objects.emplace_back(this->block = new Block(this->Texture[2],new_pos,2));
        }
    }
    for(unsigned i=0;i<8;i++){
        sf::Vector2f new_pos = {320.f+80.f*i,380.f};
        this->objects.emplace_back(this->block = new Block(this->Texture[2],new_pos,2));
    }
}

int Game::lvl_complete(){
    if(this->blocks_created==0){
        this->lvl_started=false;
        std::cout << "LVL COMPLETE!! NEXT LVL: " << LVL+1 << std::endl;
            //  HITSOUND
        this->sound_win.play();
        return this->LVL+=1;
    }
    if(this->balls_created==0){
            return this->LVL =3;
    }
    return this->LVL;

}

int Game::change_xScale(int xscale){
    this->xScale=xscale;
    std::cout << "SCALE: " << this->xScale << std::endl;
    return this->xScale;
}

int Game::changeHP(int hp){
    return this->HP+=hp;
}

int Game::changePoints(int points){
    return this->Points+=points;
}


void Game::setMod(std::vector<Object*> &objects){
    for(unsigned i=0;i<objects.size();i++){
        if(objects[i]->mod_ID()==0 || objects[i]->mod_ID()==1 || objects[i]->mod_ID()==2){
            this->change_xScale(8);
            player = new Player(this->Texture[1],this->player->getPosition(),this->xScale);
        }
        else if(objects[i]->mod_ID()==3){
            this->change_xScale(2);
            player = new Player(this->Texture[1],this->player->getPosition(),this->xScale);
        }
        else if(objects[i]->mod_ID()==4 ||objects[i]->mod_ID()==5 || objects[i]->mod_ID()==6){
            this->change_xScale(4);
            player = new Player(this->Texture[1],this->player->getPosition(),this->xScale);
        }
        else if(objects[i]->mod_ID()==7|| objects[i]->mod_ID()==8 || objects[i]->mod_ID()==9){
            this->changePoints(1000);
            std::cout << "+1000 POINTS: " << this->Points << std::endl;
        }
        else if(objects[i]->mod_ID()==10 || objects[i]->mod_ID()==11 || objects[i]->mod_ID()==12){
            this->changePoints(-1000);
            std::cout << "-1000 POINTS: " << this->Points << std::endl;
        }
        else if(objects[i]->mod_ID()==13 || objects[i]->mod_ID()==14 || objects[i]->mod_ID()==15){
           this->balls_created--;
            std::cout << "-1 HP: " << this->balls_created << std::endl;
        }
        else if(objects[i]->mod_ID()==16){
            this->balls_created++;
            std::cout << "+1 HP: " << this->balls_created << std::endl;
        }
        else if(objects[i]->mod_ID()==17 || objects[i]->mod_ID()==18){
            this->player->changeSpeed(100);
            std::cout << "Player's speed - INCREASE! "<< std::endl;
        }
        else if(objects[i]->mod_ID()==19 || objects[i]->mod_ID()==20){
            this->player->changeSpeed(-100);
            std::cout << "Player's speed - DECREASE! "<< std::endl;
        }
    }

}

void Game::reset(){
    objects.clear();
    delete ball;
    delete player;
    this->objects.emplace_back(this ->background = new Background(this->Texture[0],sf::IntRect(0,0,1120,900),{80,62}));
    this->player = new Player(this->Texture[1],this->xScale);
    this->objects.emplace_back(this->ball = new Ball(this->Texture[1],this->player->getPosition().x+this->player->getBounds().width*0.5));

    this->mod_created=false;
}




void Game::start(){

        // GAME LOOP -------------------
    while(window.isOpen()&&LVL!=3){
        if(this->LVL==1&&this->lvl_started==false){
            lvl_started=true;
            this->lvl_1();
        }
        if(this->LVL==2&&this->lvl_started==false){
            lvl_started=true;
            this->reset();
            this->lvl_2();
        }

        this->update();
        this->draw();
        this->lvl_complete();

    }

        // END GAME ANNOUNCEMENT -------------------
    if(this->LVL==3&&balls_created>0){
        std::cout << "YOU WON!!!" << "  TOTAL POINTS: " << this->Points << std::endl;       
    }
    if(this->balls_created==0){
        std::cout << "YOU LOST!!! TRY AGAIN!!!" << std::endl;
    }
}
