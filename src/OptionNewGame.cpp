#include "OptionNewGame.hh"

/*!
* OptionNewGame( sf::Vector2i PositionLeftTopCornerTableOfNewGame,    
*    sf::Vector2i PositionLeftDownCornerTableOfNewGame,   
*    sf::Vector2i PositionRightTopCornerTableOfNewGame,    
*    sf::Vector2i PositionRightDownCornerTableOfNewGame )
*
* OptionNewGame class template parametric constructor that initializes the OptionNewGame class object with the appropriate arguments given by the user
* using the initialization list, thanks to the initializer_list template from the standard library
*
* \param [in] rListCoor - Reference to the class template object from the standard initilizer_list library, it allows to initialize the object
* OptionNewGame class using an initialization list
*
* \pre The number of initialized coordinates cannot exceed (the number of vertices of a given menu options table) * 2
*
* \post The object of the OptionNewGame class initialized with the values ​​given by the user, if the user provided less than
* The number of vertices of the given menu options table * 2 then the rest of the matrix is ​​initialized as the value 0, it is possible
* is calling the constructor of the default OptionNewGame [: OptionNewGame ()] class template with an initialization list before calling our parametric constructor.
*
*/

OptionNewGame::OptionNewGame(const std::initializer_list<double> &rListCoor) : OptionNewGame()
{
    assert(rListCoor.size()<= AMOUNT_CORNERS_TABLE*2);

    int Ind = -1;
    for(double Coor_i : rListCoor)
    {
        ++Ind;
        switch (Ind)
        {
        case 0 :
        {
            PositionLeftTopCornerTableOfNewGame.x = Coor_i;
            PositionLeftTopCornerTableOfNewGame.y = Coor_i;
            break;
        }            
        case 1 :
        {   
            PositionLeftDownCornerTableOfNewGame.x = Coor_i;
            PositionLeftDownCornerTableOfNewGame.y = Coor_i;
            break;
        }            
        case 2 :
        {   
            PositionRightTopCornerTableOfNewGame.x = Coor_i;
            PositionRightTopCornerTableOfNewGame.y = Coor_i;
            break;
        }            
        case 3 :
        {        
            PositionRightDownCornerTableOfNewGame.x = Coor_i;
            PositionRightDownCornerTableOfNewGame.y = Coor_i;
            break;
        }            
        }
    }
}