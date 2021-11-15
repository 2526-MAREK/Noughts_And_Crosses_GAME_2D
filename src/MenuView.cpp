#include "MenuView.hh"
#include "MainWindowApplication.hh"

MenuView::MenuView(const std::string& NamePictureTemp,const OptionNewGame& TableOptionNewGameTemp) :  NamePicture(NamePictureTemp) , 
txt(), TableOptionNewGame(TableOptionNewGameTemp)
{
    if(!txt.loadFromFile(NamePicture))
        std::cerr<<"Program nie może znaleźć pliku o nazwie: "<<NamePicture<<"w głównym katalogu gry !!!"<<std::endl;
    setTexture(txt);      
}

void MenuView::ChooseOptionNewGame(MainWindowApplication& Window,  GameView& GameV)
{
     // Window.setBackgroundWindow(sf::Color::Black);
    //Window.takeWindowApplication().draw(*this);  
  /* std::cout<<"LDCx: "<<TableOptionNewGame.TakePositionLeftDownCornerTableOfNewGame().x<<"RDCx: "<<TableOptionNewGame.TakePositionRightDownCornerTableOfNewGame().x
    <<"RDCy: "<<TableOptionNewGame.TakePositionRightDownCornerTableOfNewGame().y<<" RTPy: "<< TableOptionNewGame.TakePositionRightTopCornerTableOfNewGame().y<<std::endl;*/
//    std::cout<<sf::Mouse::getPosition(Window.takeWindowApplication()).x <<" "<< sf::Mouse::getPosition(Window.takeWindowApplication()).y<<std::endl;
/*int PositionMouseRespectWindowX = sf::Mouse::getPosition(Window.takeWindowApplication()).x;
int PositionMouseRespectWindowY = sf::Mouse::getPosition(Window.takeWindowApplication()).y;*/

sf::Vector2i PositionMouseRespectWindow = sf::Mouse::getPosition(Window.takeWindowApplication());
sf::Vector2f PositionMouseOnScene = Window.takeWindowApplication().mapPixelToCoords(PositionMouseRespectWindow);
//std::cout<<int(PositionMouseOnScene.x) <<" "<<int(PositionMouseOnScene.y)<<std::endl;

if(TableOptionNewGame.ThePlayerClicksOnTheAreaTableOfNewGame(PositionMouseOnScene, Window) && (Window.takeMode() != GameMode))
            {
                Window.setGameMode();
            }                
    if(Window.takeMode() == GameMode)    // if Game Mode                  
    {
        GameV.DrawGameBoard(Window);
    }

    if(Window.takeMode() == MenuMode) //if Menu Mode
    {
        this->DrawMenuView(Window);
    }
}

void MenuView::DrawMenuView(MainWindowApplication& Window)
{
    Window.setBackgroundWindow(sf::Color::Black);
    Window.takeWindowApplication().draw(*this);  
}