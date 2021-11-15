#include "OptionNought.hh"
#include "MainWindowApplication.hh"

/*!
* OptionNought( sf::Vector2i PositionLeftTopCornerTableOfNought,    
*    sf::Vector2i PositionLeftDownCornerTableOfNought,   
*    sf::Vector2i PositionRightTopCornerTableOfNought,    
*    sf::Vector2i PositionRightDownCornerTableOfNought )
*
* OptionNought class template parametric constructor that initializes the OptionNought class object with the appropriate arguments given by the user
* using the initialization list, thanks to the initializer_list template from the standard library
*
* \param [in] rListCoor - Reference to the class template object from the standard initilizer_list library, it allows to initialize the object
* OptionNought class using an initialization list
*
* \pre The number of initialized coordinates cannot exceed (the number of vertices of a given menu options table) * 2
*
* \post The object of the OptionNought class initialized with the values ​​given by the user, if the user provided less than
* The number of vertices of the given menu options table * 2 then the rest of the matrix is ​​initialized as the value 0, it is possible
* is calling the constructor of the default OptionNought [: OptionNought ()] class template with an initialization list before calling our parametric constructor.
*
*/

OptionNought::OptionNought(const std::initializer_list<double> &rListCoor) : OptionNought()
{
    assert(rListCoor.size()<= AMOUNT_CORNERS_TABLE*2);

    int Ind = -1;
    for(double Coor_i : rListCoor)
    {
        ++Ind;
        switch (Ind)
        {
        case 0 : { PositionLeftTopCornerTableOfNought.x = Coor_i; break; }            
        case 1 : { PositionLeftTopCornerTableOfNought.y = Coor_i; break; }            
        case 2 : { PositionLeftDownCornerTableOfNought.x = Coor_i; break; }            
        case 3 : { PositionLeftDownCornerTableOfNought.y = Coor_i; break; }       
        case 4:  { PositionRightTopCornerTableOfNought.x = Coor_i; break; }     
        case 5:  { PositionRightTopCornerTableOfNought.y = Coor_i; break; }     
        case 6:  { PositionRightDownCornerTableOfNought.x = Coor_i; break; }     
        case 7: { PositionRightDownCornerTableOfNought.y = Coor_i; break; }     
        }
    }
}

bool OptionNought::ThePlayerClicksOnTheAreaTableOfNought(sf::Vector2f& PositionMouseOnScene, MainWindowApplication& Window)
{
    if((( int(PositionMouseOnScene.x)> PositionLeftDownCornerTableOfNought.x)
&&(int(PositionMouseOnScene.x) < PositionRightDownCornerTableOfNought.x)
&&( int(PositionMouseOnScene.y)< PositionRightDownCornerTableOfNought.y)
&&((int)PositionMouseOnScene.y > PositionRightTopCornerTableOfNought.y))
&& (Window.takeHappen().type == sf::Event::MouseButtonPressed) && (Window.takeHappen().mouseButton.button == sf::Mouse::Left ))
{
    return true;
}
else 
{
    return false;
}
}