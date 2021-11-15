#ifndef MAINWINDOWAPPLICATION_HH
#define MAINWINDOWAPPLICATION_HH

#include "MenuView.hh"

enum ModeE {MenuMode, GameMode};

class MainWindowApplication
{
private:
  sf::RenderWindow WindowApplication;
  sf::Event Happen;
  int Mode;
public: 
  MainWindowApplication(); 
  MainWindowApplication(const sf::VideoMode& VideoModeTemp, const std::string& NameMainWindowTemp); 
  MainWindowApplication(const MainWindowApplication &);
  void MainLoop();
  void inline setBackgroundWindow(const sf::Color& ColorTemp) {WindowApplication.clear(ColorTemp);}
  double actualPositionMouseOX();
  double actualPositionMouseOY();
  void showActualPositionMouseSTDout();
  inline sf::RenderWindow& takeWindowApplication(){return WindowApplication;}
  inline sf::Event& takeHappen(){return Happen;}
  inline void  setGameMode(){Mode = GameMode; }
  inline void setMenuMode(){Mode = MenuMode;}
  inline int takeMode(){return Mode;}
  //inline sf::Vector2f& takePositionMouseOnScene() { return PositionMouseOnScene;}
  //void DetermPositionMouse();
};

#endif