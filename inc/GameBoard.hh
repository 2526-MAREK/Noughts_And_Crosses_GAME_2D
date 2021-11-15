#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include "crosses.hh"
#include "circle.hh"
#include <list>
#include "FieldOfGameBoard.hh"

#define NUMBER_OF_HALF_THE_BOARD 9

class GameBoard : public sf::Sprite
{
private:
    std::string NamePicture;
    sf::Texture txt;  
    std::list<std::list<circle>::iterator> IteratorToLstCircle;
    std::list<std::list<crosses>::iterator> IteratorToLstCrosses;
    std::list<crosses> croLst;
    std::list<circle> cirLst;
    FieldOfGameBoard Field[NUMBER_OF_HALF_THE_BOARD];
public:
    GameBoard();
    GameBoard(const std::string& NamePictureTemp);//, const crosses& croTemp, const circle& cirTemp );
    bool CheckIfThePlayerClickedInAnyField(sf::Vector2f& PositionMouseOnScene, MainWindowApplication& Window);
    int TheNumberOfTheFieldInWhichThePlayerClicked(sf::Vector2f& PositionMouseOnScene, MainWindowApplication& Window);
    bool DrawCrossesOnTheField(MainWindowApplication& Window, const std::string& NamePictureCrosses);
    bool DrawCircleOnTheField(MainWindowApplication& Window, const std::string& NamePictureCircle);
    void DrawAllCrosses(MainWindowApplication& Window);
    void DrawAllCircle(MainWindowApplication& Window);
    FieldOfGameBoard& takeField(int NumberOfField){assert((NumberOfField>=0) &&(NumberOfField<=8)); return Field[NumberOfField];}
    std::list<crosses>& TakecroLst() { return croLst;}
    std::list<circle>& TakecirLst() { return cirLst;}
    /*void DrawCrosses(MainWindowApplication& Window);
    void DrawCircle(MainWindowApplication& Window);*/
};

#endif