#ifndef CROSSES_HH
#define CROSSES_HH

#include <SFML/Graphics.hpp>
#include <iostream>

class crosses : public sf::Sprite
{
private:
    std::string NamePicture;
    sf::Texture txt;            
public:
    crosses() : txt() {NamePicture ="brak";}
    crosses(const std::string& NamePictureTemp);
};

#endif