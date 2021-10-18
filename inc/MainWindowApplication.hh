#ifndef MAINWINDOWAPPLICATION_HH
#define MAINWINDOWAPPLICATION_HH

#include "MenuView.hh"

class MainWindowApplication
{
private:
  sf::RenderWindow WindowApllication;
  sf::Event Happen;
public: 
  MainWindowApplication() : WindowApllication(), Happen() {}   
  MainWindowApplication(const sf::VideoMode& VideoModeTemp, const std::string& NameMainWindowTemp); 
  MainWindowApplication(const MainWindowApplication &);
  void MainLoop();
  void inline setBackgroundWindow(const sf::Color& ColorTemp) {WindowApllication.clear(ColorTemp);}
  double actualPositionMouseOX();
  double actualPositionMouseOY();
  void showActualPositionMouseSTDout();
  inline sf::RenderWindow& takeWindowApplication(){return WindowApllication;}
  inline sf::Event& takeHappen(){return Happen;}
};

#endif