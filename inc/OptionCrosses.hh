#ifndef OPTIONCROSSES_HH
#define OPTIONCROSSES_HH

#include <SFML/Graphics.hpp>
#include <iostream>
#include <assert.h>

#define AMOUNT_CORNERS_TABLE 4

class MainWindowApplication;

class OptionCrosses
{
private:
    sf::Vector2i PositionLeftTopCornerTableOfCrosses;    
    sf::Vector2i PositionLeftDownCornerTableOfCrosses;   
    sf::Vector2i PositionRightTopCornerTableOfCrosses;    
    sf::Vector2i PositionRightDownCornerTableOfCrosses;  
public:   
    OptionCrosses() : PositionLeftTopCornerTableOfCrosses(), PositionLeftDownCornerTableOfCrosses(), 
    PositionRightTopCornerTableOfCrosses(), PositionRightDownCornerTableOfCrosses() {}
/*!
  * \brief A parametric constructor of the OptionCrosses class
  */
    OptionCrosses(const std::initializer_list<double> &rListCoor);
    inline sf::Vector2i& TakePositionLeftTopCornerTableOfCrosses() { return PositionLeftTopCornerTableOfCrosses;}    
    inline sf::Vector2i& TakePositionLeftDownCornerTableOfCrosses() { return PositionLeftDownCornerTableOfCrosses;}    
    inline sf::Vector2i& TakePositionRightTopCornerTableOfCrosses() { return PositionRightTopCornerTableOfCrosses;}    
    inline sf::Vector2i& TakePositionRightDownCornerTableOfCrosses() { return PositionRightDownCornerTableOfCrosses;}    
    bool ThePlayerClicksOnTheAreaTableOfCrosses(sf::Vector2f& PositionMouseOnScene, MainWindowApplication& Window);
};

#endif