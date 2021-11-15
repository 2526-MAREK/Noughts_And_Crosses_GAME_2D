#ifndef CROSSES_HH
#define CROSSES_HH

#include <SFML/Graphics.hpp>
#include <iostream>

class crosses : public sf::Sprite
{
private:
    std::string NamePicture;
    sf::Texture txt;            
    sf::Vector2i Position;
public:
    crosses() : txt() , Position() {NamePicture ="brak";}
    crosses(const std::string& NamePictureTemp, sf::Vector2i& PositionTemp);
    sf::Vector2i& takePosition() {return Position;}
};

#endif