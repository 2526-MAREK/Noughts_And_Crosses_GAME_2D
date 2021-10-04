#include "MainWindowApplication.hh"

MainWindowApplication::MainWindowApplication(const sf::VideoMode& VideoModeTemp, const std::string& NameMainWindowTemp) :
 WindowApllication(VideoModeTemp, NameMainWindowTemp) , happen()
{

}

void MainWindowApplication::MainLoop()
{

    MenuView Menu("MenuView.png");
    GameView GameV("GameView.png");

    while(WindowApllication.isOpen()) //main loop program
    {
        while(WindowApllication.pollEvent(happen))
        {
            showActualPositionMouseSTDout();

            if(((happen.mouseMove.x> 1340)&&(happen.mouseMove.x< 1760)&&(happen.mouseMove.y>571)&&(happen.mouseMove.y<665))&&(sf::Mouse::isButtonPressed(sf::Mouse::Left)))
            {
                setBackgroundWindow(sf::Color::Black);
                WindowApllication.draw(GameV);
            }                
            else
            {
                setBackgroundWindow(sf::Color::Black);
                WindowApllication.draw(Menu);                                    
            }                

            if((happen.type == sf::Event::Closed) || (happen.type == sf::Event::KeyPressed && happen.key.code == sf::Keyboard::Escape))
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
    return happen.mouseMove.x;
}

double MainWindowApplication::actualPositionMouseOY()
{
    return happen.mouseMove.y;
}