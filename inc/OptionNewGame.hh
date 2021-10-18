#ifndef OPTIONNEWGAME_HH
#define OPTIONNEWGAME_HH

#include <SFML/Graphics.hpp>
#include <assert.h>

#define AMOUNT_CORNERS_TABLE 4

class OptionNewGame 
{
private:
    sf::Vector2i PositionLeftTopCornerTableOfNewGame;    
    sf::Vector2i PositionLeftDownCornerTableOfNewGame;   
    sf::Vector2i PositionRightTopCornerTableOfNewGame;    
    sf::Vector2i PositionRightDownCornerTableOfNewGame;  
public:   
    OptionNewGame() : PositionLeftTopCornerTableOfNewGame(), PositionLeftDownCornerTableOfNewGame(), 
    PositionRightTopCornerTableOfNewGame(), PositionRightDownCornerTableOfNewGame() {}
/*!
  * \brief A parametric constructor of the OptionNewGame class
  */
    OptionNewGame(const std::initializer_list<double> &rListCoor);
    inline sf::Vector2i& TakePositionLeftTopCornerTableOfNewGame() { return PositionLeftTopCornerTableOfNewGame;}    
    inline sf::Vector2i& TakePositionLeftDownCornerTableOfNewGame() { return PositionLeftTopCornerTableOfNewGame;}    
    inline sf::Vector2i& TakePositionRightTopCornerTableOfNewGame() { return PositionLeftTopCornerTableOfNewGame;}    
    inline sf::Vector2i& TakePositionRightDownCornerTableOfNewGame() { return PositionLeftTopCornerTableOfNewGame;}    
};

#endif