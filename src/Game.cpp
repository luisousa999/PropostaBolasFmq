#include "Game.h"
#include "Bolas.h"

void Game::initVariables()
{
    this->endGame = false;
    this->spawnTimerMax = 10.f;
    this->spawnTimer = this->spawnTimerMax;
    this->maxBolas = 50;
    this->points = 0;
}

void Game::initWindow()
{
    this->videoMode = sf::VideoMode(1280, 720);
    this->window = new sf::RenderWindow(this->videoMode, "Jogo Luis", sf::Style::Resize | sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
}

void Game::initFonts()
{
    if (!this->font.loadFromFile("Fonts/Ubuntu-B.ttf"))
        {
            std::cout << " ! ERROR::GAME::INITFONTS::COULD NOT LOAD Ubuntu-B.ttf" << "\n";
        }
}

void Game::initText()
{
    //Gui text init
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(32);

	//End game text
	this->endGameText.setFont(this->font);
	this->endGameText.setFillColor(sf::Color::Red);
	this->endGameText.setCharacterSize(60);
	this->endGameText.setPosition(sf::Vector2f(20, 100));
	this->endGameText.setString("Regressa ao main menu");
}

//Construtor e Destrutor
Game::Game() 
{
    this->initVariables();
    this->initWindow();
    this->initFonts();
    this->initText();
}

Game::~Game()
{
    delete this->window;
}

const bool & Game::getEndGame() const
{
	return this->endGame;
}

const bool Game::running() const
{
	return this->window->isOpen() /*&& this->endGame == false*/;
}


//Funçoes

void Game::pollEvents()
{
    while (this->window->pollEvent(this->sfmlEvent))
        {
            switch (this->sfmlEvent.type)
            {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
            }
        }
}

void Game::spawnBolas()
{
    //Temporizador
    if (this->spawnTimer < this->spawnTimerMax)
    {
		this->spawnTimer += 1.f;
    }else
	{
		if (this->bolas.size() < this->maxBolas)
		{
			this->bolas.push_back(Bolas(*this->window));

			this->spawnTimer = 0.f;
		}
		else{
			//Bolas::moveShape(*this->window);
		}
	}
}

void Game::updateGui()
{
	std::stringstream ss;
    ss <<"OK";

	this->guiText.setString(ss.str());
}


void Game::update()
{
	this->pollEvents();

	if (this->endGame == false)
	{
		this->spawnBolas();
		this->updateGui();
		
	}
}

void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(this->guiText);
}

void Game::render()
{
	this->window->clear();

	//Render stuff
	//this->player.render(this->window);

	for (auto i : this->bolas)
	{
		i.render(*this->window);
	}

	/* for (auto i : this->bolas)
	{
		i.moveShape(*this->window);
	} */

	//Render gui
	this->renderGui(this->window);

	//Render end text
	if(this->endGame == true)
		this->window->draw(this->endGameText);

	this->window->display();
}
