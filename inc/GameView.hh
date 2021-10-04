#ifndef GAMEVIEW_HH
#define GAMEVIEW_HH

#include "GameBoard.hh"

class GameView : public sf::Sprite
{
private:
    std::string NamePicture;
    sf::Texture txt;        
public:    
    GameView() : txt() {NamePicture ="brak";}
    GameView(const std::string& NamePictureTemp);
};

#endif