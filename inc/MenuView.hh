#ifndef MENUVIEW_HH
#define MENUVIEW_HH

#include "GameView.hh"

class MenuView : public sf::Sprite
{
private:
    std::string NamePicture;
    sf::Texture txt;        
public:   
    MenuView() : txt() {NamePicture ="brak";}
    MenuView(const std::string& NamePictureTemp);
};

#endif