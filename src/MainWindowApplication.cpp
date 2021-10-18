#include "MainWindowApplication.hh"

MainWindowApplication::MainWindowApplication(const sf::VideoMode& VideoModeTemp, const std::string& NameMainWindowTemp) :
 WindowApllication(VideoModeTemp, NameMainWindowTemp) , Happen()
{

}

MainWindowApplication::MainWindowApplication(MainWindowApplication const&)
{

}

void MainWindowApplication::MainLoop()
{
    OptionNewGame TabOptNewG = {1340, 571,1340,665,1760,571,1760,665 };
    MenuView Menu("MenuView.png", TabOptNewG );
    GameView GameV("GameView.png");

    while(WindowApllication.isOpen()) //main loop program
    {
        while(WindowApllication.pollEvent(Happen))
        {
            showActualPositionMouseSTDout();
            Menu.ChooseOptionNewGame(*this, GameV);

            if(((Happen.type == sf::Event::Closed) || (Happen.type == sf::Event::KeyPressed)) && (Happen.key.code == sf::Keyboard::Escape))
                WindowApllication.close();
        }
        WindowApllication.display();
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