#ifndef CIRCLE_HH
#define CIRCLE_HH

#include <SFML/Graphics.hpp>
#include <iostream>

class circle : public sf::Sprite
{
private:
    std::string NamePicture;
    sf::Texture txt;        
    sf::Vector2i Position;
public:   
    circle() : txt(), Position() {NamePicture ="brak";}
    circle(const std::string& NamePictureTemp, sf::Vector2i& PositionTemp);
    sf::Vector2i& takePosition() {return Position;}
};

#endif