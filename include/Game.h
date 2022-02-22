#include<iostream>
#include<ctime>
#include<vector>
#include<sstream>

#include "Bolas.h"

class Game{
private:
    sf::VideoMode videoMode;
    sf::RenderWindow* window;
    bool endGame;
    sf::Event sfmlEvent;

    int points;

    sf::Font font;
    sf::Text guiText;
    sf::Text endGameText;
    
    std::vector<Bolas> bolas;
	float spawnTimerMax;
	float spawnTimer;
	int maxBolas;

    void initVariables();
	void initWindow();
	void initFonts();
	void initText();

public:
    //Construtor e Destrutor
    Game();
    ~Game();

    //Access
    const bool& getEndGame() const;

    //Funçoes
    const bool running() const;
	void pollEvents();

	void spawnBolas();
	//const int randBallType() const;
	//void updatePlayer();
	//void updateCollision();
	void updateGui();
	void update();

	void renderGui(sf::RenderTarget* target);
	void render();

};