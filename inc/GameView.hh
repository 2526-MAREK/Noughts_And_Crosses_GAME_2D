#ifndef GAMEVIEW_HH
#define GAMEVIEW_HH

#include "GameBoard.hh"
#include "WindowSelectionCrossOrNought.hh"
#include "Numbers.hh"

#define QUANTITY_OF_NUMBER 10
class MainWindowApplication;

enum PlayerIsE {Crosses, Nought, NotSelected};
enum WinnerE {Player, Opponent,Draw,BeginGame};
enum DoneE {Yes, No};

class GameView 
{
private:
    /*std::string NameGameViewPicture;
    std::string NameSelectionWindowCrossesOrNoughtPicture;*/
    //sf::Texture txt;   
    GameBoard GBoard;
    WindowSelectionCrossOrNought WinSelCrOrNou; 
    bool ThePlayerChoose;
    int PlayerIs;
    int Winner;
    int OpponentPoints;
    int PlayerPoints;
    int Turn;
    Numbers PunctationOpponents[QUANTITY_OF_NUMBER];
    Numbers PunctationPlayers[QUANTITY_OF_NUMBER];
public:    
    GameView() : GBoard(), WinSelCrOrNou(), PunctationOpponents(), PunctationPlayers()
     {ThePlayerChoose = false; Turn = Player; PlayerIs = NotSelected; Winner = BeginGame; OpponentPoints = 0; PlayerPoints =0;}//txt(), TableOptionChooseCrosses() //{NameGameViewPicture ="brak"; NameSelectionWindowCrossesOrNoughtPicture = "brak";}
    GameView(const GameBoard& GameBoardTemp,const WindowSelectionCrossOrNought& WinSelCrOrNouTemp);
    void ChooseCrossOrNought(MainWindowApplication& Window);
    void DrawGameBoard(MainWindowApplication& Window);
    void PlayerTurn(MainWindowApplication& Window);
    void OpponentTurn(MainWindowApplication& Window);
    void TheCourseOfTheGame(MainWindowApplication& Window);
    bool SomeoneWon();
    bool FullBoard();
    void DetermineWhoWin(char FieldChar);
    bool takeThePlayerChoose(){return ThePlayerChoose;}
    void DrawPointsPlayers(MainWindowApplication& Window);
    void DrawNumbersOpponents( MainWindowApplication& Window , int NumberPunctation);
    void DrawNumbersPlayers( MainWindowApplication& Window , int NumberPunctation);
    void DrawOpponentPoints(MainWindowApplication& Window);
    void DrawPlayerPoints(MainWindowApplication& Window);
    void NewGame();
    void ClearBoard();
    void ClearGame();
};                                                 

#endif