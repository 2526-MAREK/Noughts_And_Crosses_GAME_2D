#ifndef OPTIONSAREA_HH
#define OPTIONSAREA_HH

#include <SFML/Graphics.hpp>
#include <iostream>
#include <assert.h>

#define AMOUNT_CORNERS_TABLE 4

class MainWindowApplication;

class OptionsArea 
{
private:
    sf::Vector2i PositionLeftTopCornerOfOptionsArea;    
    sf::Vector2i PositionLeftDownCornerOfOptionsArea;   
    sf::Vector2i PositionRightTopCornerOfOptionsArea;    
    sf::Vector2i PositionRightDownCornerOfOptionsArea;  
public:   
    OptionsArea() : PositionLeftTopCornerOfOptionsArea(), PositionLeftDownCornerOfOptionsArea(), 
    PositionRightTopCornerOfOptionsArea(), PositionRightDownCornerOfOptionsArea() {}
/*!
  * \brief A parametric constructor of the OptionOptionsArea class
  */
    OptionsArea(const std::initializer_list<double> &rListCoor);
    inline sf::Vector2i& TakePositionLeftTopCornerOfOptionsArea() { return PositionLeftTopCornerOfOptionsArea;}    
    inline sf::Vector2i& TakePositionLeftDownCornerOfOptionsArea() { return PositionLeftDownCornerOfOptionsArea;}    
    inline sf::Vector2i& TakePositionRightTopCornerOfOptionsArea() { return PositionRightTopCornerOfOptionsArea;}    
    inline sf::Vector2i& TakePositionRightDownCornerOfOptionsArea() { return PositionRightDownCornerOfOptionsArea;}  
    bool ThePlayerClicksOnTheOptionsArea(sf::Vector2f& PositionMouseOnScene, MainWindowApplication& Window);     
};

#endif