#include "MainWindowApplication.hh"

int main()
{   
    MainWindowApplication Window(sf::VideoMode(1920, 1080, 32), "NoughtAndCrosses" );

    Window.MainLoop();

    return 0;
}