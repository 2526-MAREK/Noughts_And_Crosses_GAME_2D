#ifndef MAINWINDOWAPPLICATION_HH
#define MAINWINDOWAPPLICATION_HH

#include "MenuView.hh"

class MainWindowApplication
{
private:
  sf::RenderWindow WindowApllication;
  sf::Event happen;
public: 
  MainWindowApplication() : WindowApllication(), happen() {}   
  MainWindowApplication(const sf::VideoMode& VideoModeTemp, const std::string& NameMainWindowTemp); 
  void MainLoop();
  void inline setBackgroundWindow(const sf::Color& ColorTemp) {WindowApllication.clear(ColorTemp);}
  double actualPositionMouseOX();
  double actualPositionMouseOY();
  void showActualPositionMouseSTDout();
};

#endif