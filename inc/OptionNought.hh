#ifndef OPTIONNOUGHT_HH
#define OPTIONNOUGHT_HH

#include <SFML/Graphics.hpp>
#include <iostream>
#include <assert.h>

#define AMOUNT_CORNERS_TABLE 4

class MainWindowApplication;

class OptionNought
{
private:
    sf::Vector2i PositionLeftTopCornerTableOfNought;    
    sf::Vector2i PositionLeftDownCornerTableOfNought;   
    sf::Vector2i PositionRightTopCornerTableOfNought;    
    sf::Vector2i PositionRightDownCornerTableOfNought;  
public:   
    OptionNought() : PositionLeftTopCornerTableOfNought(), PositionLeftDownCornerTableOfNought(), 
    PositionRightTopCornerTableOfNought(), PositionRightDownCornerTableOfNought() {}
/*!
  * \brief A parametric constructor of the OptionNought class
  */
    OptionNought(const std::initializer_list<double> &rListCoor);
    inline sf::Vector2i& TakePositionLeftTopCornerTableOfNought() { return PositionLeftTopCornerTableOfNought;}    
    inline sf::Vector2i& TakePositionLeftDownCornerTableOfNought() { return PositionLeftDownCornerTableOfNought;}    
    inline sf::Vector2i& TakePositionRightTopCornerTableOfNought() { return PositionRightTopCornerTableOfNought;}    
    inline sf::Vector2i& TakePositionRightDownCornerTableOfNought() { return PositionRightDownCornerTableOfNought;} 
    bool ThePlayerClicksOnTheAreaTableOfNought(sf::Vector2f& PositionMouseOnScene, MainWindowApplication& Window);   
};

#endif