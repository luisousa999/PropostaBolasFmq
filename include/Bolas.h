#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Bolas
{
private: 
    sf::CircleShape shape;
    //int type;

    void initShape(const sf::RenderWindow& window);

public:
    //Bolas(const sf::RenderWindow& window, int type);
    Bolas(const sf::RenderWindow& window);
    virtual ~Bolas();
    void moveShape(const sf::RenderWindow& window);

    //Access
    const sf::CircleShape getShape() const;
    //const int& getType() const;

    //Funçoes
    void update();
    void render(sf::RenderTarget& target);

};