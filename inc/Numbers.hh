#ifndef NUMBERS_HH
#define NUMBERS_HH

#include <SFML/Graphics.hpp>
#include <iostream>

class Numbers : public sf::Sprite
{
private:
    std::string NamePicture;
    sf::Texture txt;            
    sf::Vector2i Position;
public:
    Numbers() : txt() , Position() {NamePicture ="brak";}
    Numbers(const std::string& NamePictureTemp, sf::Vector2i& PositionTemp);
    inline void ChangeParametsObject(const std::string& NamePictureTemp, const sf::Vector2i& PositionTemp) {NamePicture = NamePictureTemp; Position = PositionTemp;}
    sf::Vector2i& takePosition() {return Position;}
};

#endif