#include "MainWindowApplication.hh"

MainWindowApplication::MainWindowApplication() : WindowApplication(), Happen()
{ 
    Mode = MenuMode;
}   

MainWindowApplication::MainWindowApplication(const sf::VideoMode& VideoModeTemp, const std::string& NameMainWindowTemp) :
 WindowApplication(VideoModeTemp, NameMainWindowTemp) , Happen()
{
}

MainWindowApplication::MainWindowApplication(MainWindowApplication const& MainWinApp)
{
    Happen = MainWinApp.Happen;
    //WindowApplication = MainWinApp.WindowApplication;
}

/*void MainWindowApplication::DetermPositionMouse()
{
}*/

void MainWindowApplication::MainLoop()
{
    /*
    sf::Vector2i PositionLeftTopCornerTableOfNewGame,    
*    sf::Vector2i PositionLeftDownCornerTableOfNewGame,   
*    sf::Vector2i PositionRightTopCornerTableOfNewGame,    
*    sf::Vector2i PositionRightDownCornerTableOfNewGame 
*/
    OptionNewGame TabOptNewGInMenuView = {1330, 560,1330,660,1765,560,1765,660}; //set position Table New Game In MenuView
    MenuView Menu("MenuView.png", TabOptNewGInMenuView );
    
    /*crosses cro("crosses.png");
    circle cir("circle.png");*/

    GameBoard GBoard("GameView.png");
    OptionCrosses TabWinSelectionCrosses = {14, 480,14, 610,414,480,414,610};
    OptionNought TabWinSelectionNought ={573, 470,573, 610,1015,470,1015,610};
    WindowSelectionCrossOrNought WinSelCrOrNou("ChooseCrossOrNought.png", TabWinSelectionCrosses, TabWinSelectionNought);
    GameView GameV(GBoard,WinSelCrOrNou);
    /*sf::Vector2i rf = {573, 470};
    crosses cr("cross.png",rf );*/

    while(WindowApplication.isOpen()) //main loop program
    {
        while(WindowApplication.pollEvent(Happen))
        {
            //setBackgroundWindow(sf::Color::Black);
            //takeWindowApplication().draw(Menu);  
            //showActualPositionMouseSTDout();
            //std::cout<<sf::Mouse::getPosition(WindowApplication).x <<" "<< sf::Mouse::getPosition(WindowApplication).y<<std::endl;
            Menu.ChooseOptionNewGame(*this, GameV);
            if(Mode == GameMode){
                GameV.ChooseCrossOrNought(*this);
            }
            if(GameV.takeThePlayerChoose())     
            {
                GameV.TheCourseOfTheGame(*this);
            }
            //GameV.DrawPointsPlayers(*this);
            //WindowApplication.draw(cr);                

            if(((Happen.type == sf::Event::Closed) || (Happen.type == sf::Event::KeyPressed)) && (Happen.key.code == sf::Keyboard::Escape))
                WindowApplication.close();
        }
        WindowApplication.display();
    }        
}

void MainWindowApplication::showActualPositionMouseSTDout()
{
    std::cout<<"OX: "<<actualPositionMouseOX()<< " OY: "<<actualPositionMouseOY()<<std::endl;
}

double MainWindowApplication::actualPositionMouseOX()
{
    return Happen.mouseMove.x;
}

double MainWindowApplication::actualPositionMouseOY()
{
    return Happen.mouseMove.y;
}