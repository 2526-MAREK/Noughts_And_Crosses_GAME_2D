#ifndef FIELDOFGAMEBOARD_HH
#define FIELDOFGAMEBOARD_HH

#include "OptionsArea.hh"
#include "crosses.hh"
#include "circle.hh"

class FieldOfGameBoard 
{
private:
    OptionsArea OpArea;
    sf::Vector2i InitialPositionCrosses;
    sf::Vector2i InitialPositionCircle;
    char FieldSymbol; //maybe 'X' or 'O' or 'N' ( empty field)
public:
    FieldOfGameBoard(): OpArea(), InitialPositionCrosses(), InitialPositionCircle() { FieldSymbol = 'N';}
    FieldOfGameBoard(const OptionsArea& OpAreaTemp,const sf::Vector2i& InitialPositionCrossesTemp,
     const sf::Vector2i& InitialPositionCircleTemp);
     inline OptionsArea& takeOpArea() { return OpArea;}
     inline sf::Vector2i& takeInitialPositionCrosses() {return InitialPositionCrosses;}
     inline sf::Vector2i& takeInitialPositionCircle() {return InitialPositionCircle;}
     void ChangeObjectParametr(const OptionsArea& OpAreaTemp,const sf::Vector2i& InitialPositionCrossesTemp, 
     const sf::Vector2i& InitialPositionCircleTemp);
     inline void AddFieldSymbol(char FieldSymbolTemp){FieldSymbol = FieldSymbolTemp;}
     inline char takeFieldSymbol() { return FieldSymbol;}
};

#endif