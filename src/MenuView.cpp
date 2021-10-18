#include "MenuView.hh"
#include "MainWindowApplication.hh"

MenuView::MenuView(const std::string& NamePictureTemp,const OptionNewGame& TableOptionNewGameTemp) :  NamePicture(NamePictureTemp) , 
txt(), TableOptionNewGame(TableOptionNewGameTemp)
{
    if(!txt.loadFromFile(NamePicture))
        std::cerr<<"Program nie może znaleźć pliku o nazwie: "<<NamePicture<<"w głównym katalogu gry !!!"<<std::endl;
    setTexture(txt);      
}

void MenuView::ChooseOptionNewGame(MainWindowApplication Window,  GameView GameV)
{
if(((sf::Mouse::getPosition(Window.takeWindowApplication()).x > TableOptionNewGame.TakePositionLeftDownCornerTableOfNewGame().x)
&&(sf::Mouse::getPosition(Window.takeWindowApplication()).x < TableOptionNewGame.TakePositionRightDownCornerTableOfNewGame().x)
&&(sf::Mouse::getPosition(Window.takeWindowApplication()).y > TableOptionNewGame.TakePositionRightDownCornerTableOfNewGame().y)
&&(sf::Mouse::getPosition(Window.takeWindowApplication()).y < TableOptionNewGame.TakePositionRightTopCornerTableOfNewGame().y))
&&(sf::Mouse::isButtonPressed(sf::Mouse::Left)))
            {
                Window.setBackgroundWindow(sf::Color::Black);
                Window.takeWindowApplication().draw(GameV);
            }                
            else
            {
                Window.setBackgroundWindow(sf::Color::Black);
                Window.takeWindowApplication().draw(*this);                                    
            }                
}