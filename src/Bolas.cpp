#include "Bolas.h"

void Bolas::initShape(const sf::RenderWindow& window)
{
    
    //Vai definir um raio aleatorio
    this->shape.setRadius(static_cast<float>(rand()%10+10));

    //Vai dar uma cor aleatoria
    this->shape.setFillColor(sf::Color(rand()%255+1, rand()%255+1, rand()%255+1, rand()%255+1));

    //Vai fazer spawn numa loc aleatoria
    this->shape.setPosition(
        sf::Vector2f(
            static_cast<float>(rand()% window.getSize().x - this->shape.getGlobalBounds().width),
            static_cast<float>(rand()% window.getSize().y - this->shape.getGlobalBounds().height)
        )
    );

}

void Bolas::moveShape(const sf::RenderWindow& window)
{
    this->shape.setPosition(
        sf::Vector2f(
            static_cast<float>(this->shape.getPosition().x + 1.0f),
            static_cast<float>(this->shape.getPosition().y + 1.0f))
    );
}

Bolas::Bolas(const sf::RenderWindow& window)
{
    this->initShape(window);
    //this->moveShape(window);
}

Bolas::~Bolas()
{

}

const sf::CircleShape Bolas::getShape() const
{
    return this->shape;
}

void Bolas::update()
{
}

void Bolas::render(sf::RenderTarget & target)
{
	target.draw(this->shape);
}
