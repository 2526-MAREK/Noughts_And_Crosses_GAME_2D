#ifndef CIRCLE_HH
#define CIRCLE_HH

#include <SFML/Graphics.hpp>
#include <iostream>

class circle : public sf::Sprite
{
private:
    std::string NamePicture;
    sf::Texture txt;        
public:   
    circle() : txt() {NamePicture ="brak";}
    circle(const std::string& NamePictureTemp);
};

#endif