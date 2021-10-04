#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include "crosses.hh"
#include "circle.hh"

class GameBoard : public sf::Sprite
{
private:
    std::string NamePicture;
    sf::Texture txt;        
public:
    GameBoard() : txt() {NamePicture ="brak";}
    GameBoard(const std::string& NamePictureTemp);
};

#endif