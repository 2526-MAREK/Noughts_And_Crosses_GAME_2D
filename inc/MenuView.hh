#ifndef MENUVIEW_HH
#define MENUVIEW_HH

#include "GameView.hh"
#include "OptionNewGame.hh"

class MainWindowApplication;

class MenuView : public sf::Sprite
{
private:
    std::string NamePicture;
    sf::Texture txt;   
    OptionNewGame TableOptionNewGame;
public:   
    MenuView() : txt(), TableOptionNewGame() {NamePicture ="brak";}
    MenuView(const std::string& NamePictureTemp,const OptionNewGame& TableOptionNewGameTemp);
    void ChooseOptionNewGame(MainWindowApplication Window,  GameView GameV);
};

#endif