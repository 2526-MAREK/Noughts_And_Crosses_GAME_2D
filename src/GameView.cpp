#include "GameView.hh"
#include "MainWindowApplication.hh"

/*GameView::GameView(const std::string& NameGameViewPictureTemp,const std::string& NameSelectionWindowCrossesOrNoughtPictureTemp, const OptionCrosses& TableOptionChooseCrossesTemp) : NameGameViewPicture(NameGameViewPictureTemp),
NameSelectionWindowCrossesOrNoughtPicture(NameSelectionWindowCrossesOrNoughtPictureTemp), txt(), TableOptionChooseCrosses()
{
    if(!txt.loadFromFile(NameGameViewPicture))
        std::cerr<<"Program nie może znaleźć pliku o nazwie: "<<NameGameViewPicture<<"w głównym katalogu gry !!!"<<std::endl;
    setTexture(txt);                

    if(!txt.loadFromFile(NameSelectionWindowCrossesOrNoughtPictureTemp))
        std::cerr<<"Program nie może znaleźć pliku o nazwie: "<<NameSelectionWindowCrossesOrNoughtPictureTemp<<"w głównym katalogu gry !!!"<<std::endl;
    setTexture(txt);                
}*/
GameView::GameView(const GameBoard& GameBoardTemp,const WindowSelectionCrossOrNought& WinSelCrOrNouTemp) : GBoard(GameBoardTemp)
, WinSelCrOrNou(WinSelCrOrNouTemp)
{
    ThePlayerChoose = false;
    PlayerIs = NotSelected;
    Winner = BeginGame;    
    OpponentPoints = 0; 
    PlayerPoints =0;
    Turn = Player;

     sf::Vector2i VTemp= {514, 133};
     Numbers NumTemp("0.png", VTemp);
     PunctationPlayers[0] = NumTemp;
     NumTemp.ChangeParametsObject("1.png",VTemp);
     PunctationPlayers[1] = NumTemp;
     NumTemp.ChangeParametsObject("2.png",VTemp);
     PunctationPlayers[2] = NumTemp;
     NumTemp.ChangeParametsObject("3.png",VTemp);
     PunctationPlayers[3] = NumTemp;
     NumTemp.ChangeParametsObject("4.png",VTemp);
     PunctationPlayers[4] = NumTemp;
     NumTemp.ChangeParametsObject("5.png",VTemp);
     PunctationPlayers[5] = NumTemp;
     NumTemp.ChangeParametsObject("6.png",VTemp);
     PunctationPlayers[6] = NumTemp;
     NumTemp.ChangeParametsObject("7.png",VTemp);
     PunctationPlayers[7] = NumTemp;
     NumTemp.ChangeParametsObject("8.png",VTemp);
     PunctationPlayers[8] = NumTemp;
     NumTemp.ChangeParametsObject("9.png",VTemp);
     PunctationPlayers[9] = NumTemp;

    VTemp= {693, 30};
     NumTemp.ChangeParametsObject("0.png", VTemp);
     PunctationOpponents[0] = NumTemp;
     NumTemp.ChangeParametsObject("1.png",VTemp);
     PunctationOpponents[1] = NumTemp;
     NumTemp.ChangeParametsObject("2.png",VTemp);
     PunctationOpponents[2] = NumTemp;
     NumTemp.ChangeParametsObject("3.png",VTemp);
     PunctationOpponents[3] = NumTemp;
     NumTemp.ChangeParametsObject("4.png",VTemp);
     PunctationOpponents[4] = NumTemp;
     NumTemp.ChangeParametsObject("5.png",VTemp);
     PunctationOpponents[5] = NumTemp;
     NumTemp.ChangeParametsObject("6.png",VTemp);
     PunctationOpponents[6] = NumTemp;
     NumTemp.ChangeParametsObject("7.png",VTemp);
     PunctationOpponents[7] = NumTemp;
     NumTemp.ChangeParametsObject("8.png",VTemp);
     PunctationOpponents[8] = NumTemp;
     NumTemp.ChangeParametsObject("9.png",VTemp);
     PunctationOpponents[9] = NumTemp;
}
void GameView::DrawGameBoard(MainWindowApplication& Window)
{
    Window.setBackgroundWindow(sf::Color::Black);
    Window.takeWindowApplication().draw(GBoard);
}
void GameView::ChooseCrossOrNought(MainWindowApplication& Window)
{
     sf::Vector2i PositionMouseRespectWindow = sf::Mouse::getPosition(Window.takeWindowApplication());
     sf::Vector2f PositionMouseOnScene = Window.takeWindowApplication().mapPixelToCoords(PositionMouseRespectWindow);

    //std::cout<<int(PositionMouseOnScene.x) <<" "<<int(PositionMouseOnScene.y)<<std::endl;

    if(!ThePlayerChoose)
    {
    Window.setBackgroundWindow(sf::Color::Black);
    Window.takeWindowApplication().draw(WinSelCrOrNou);
    }

    if(WinSelCrOrNou.TakeTableOptionChooseCrosses().ThePlayerClicksOnTheAreaTableOfCrosses(PositionMouseOnScene, Window) && PlayerIs !=Crosses)
{
    PlayerIs = Crosses;
    ThePlayerChoose = true;
}
else if(WinSelCrOrNou.TakeTableOptionChooseNought().ThePlayerClicksOnTheAreaTableOfNought(PositionMouseOnScene, Window) && PlayerIs !=Nought)
{
    PlayerIs = Nought;
    ThePlayerChoose = true;
}

if(ThePlayerChoose)
    {
        DrawGameBoard(Window);
    }
}

void GameView::PlayerTurn(MainWindowApplication& Window)
{
    int Done = No;
    if(PlayerIs == Nought)
    {
        if(GBoard.DrawCircleOnTheField(Window, "circle.png"))
        {
          Done = Yes;
        }
        else
        {
            Done = No;        
        }
    }
    else if(PlayerIs == Crosses)
    {
       if(GBoard.DrawCrossesOnTheField(Window, "cross.png"))
       {  
         Done = Yes;
       }
        else
        {
            Done = No;     
        }            
    }
    if(Done == Yes)
    {
        Turn = Opponent;
    }
}

void GameView::OpponentTurn(MainWindowApplication& Window)
{
    int Done = No;
    if(PlayerIs == Nought)
    {
        if(GBoard.DrawCrossesOnTheField(Window, "cross.png")) 
        {
            Done = Yes;
        }
        else
        {
            Done = No;   
        }                    
       
    }
    else if(PlayerIs == Crosses)
    {
        if(GBoard.DrawCircleOnTheField(Window, "circle.png"))
        {
             Done = Yes;
        }
        else
        {
            Done = No;            
        }
    }
    if(Done == Yes)
    {
        Turn = Player;
    }
}

void GameView::DrawNumbersOpponents(MainWindowApplication& Window , int NumberPunctation)
{   
    assert((NumberPunctation>=0)&&(NumberPunctation<=9));
            PunctationOpponents[NumberPunctation].setPosition(PunctationOpponents[NumberPunctation].takePosition().x, PunctationOpponents[NumberPunctation].takePosition().y );
            Window.takeWindowApplication().draw(PunctationOpponents[NumberPunctation]);
}

void GameView::DrawNumbersPlayers(MainWindowApplication& Window , int NumberPunctation)
{
    assert((NumberPunctation>=0)&&(NumberPunctation<=9));
            PunctationPlayers[NumberPunctation].setPosition(PunctationPlayers[NumberPunctation].takePosition().x, PunctationPlayers[NumberPunctation].takePosition().y );
            Window.takeWindowApplication().draw(PunctationPlayers[NumberPunctation]);
}

void GameView::DrawPlayerPoints(MainWindowApplication& Window)
{
    switch (PlayerPoints)
    {
    case 0 :
        {
           DrawNumbersPlayers(Window, 0);
        break;
        }
    case 1 :
        {
            DrawNumbersPlayers(Window, 1);
        break;
        }
    case 2 :
        {
            DrawNumbersPlayers(Window, 2);
        break;
        }
    case 3 :
        {
            DrawNumbersPlayers(Window, 3);
        break;
        }
    case 4 :
        {
            DrawNumbersPlayers(Window, 4);
        break;
        }
    case 5 :
        {
            DrawNumbersPlayers(Window, 5);
        break;
        }
    case 6 :
        {
            DrawNumbersPlayers(Window, 6);
        break;
        }
    case 7 :
        {
            DrawNumbersPlayers(Window, 7);
        break;
        }
    case 8 :
        {
            DrawNumbersPlayers(Window, 8);
        break;
        }
    case 9 :
        {
            DrawNumbersPlayers(Window, 9);
        break;
        }     
        default:
        {
            std::cout<<"Nie ma takiej liczby na liscie"<<std::endl;
        }                                                                        
    }    
}

void GameView::DrawOpponentPoints(MainWindowApplication& Window)
{
switch (PlayerPoints)
    {
    case 0 :
        {
           DrawNumbersOpponents(Window, 0);
        break;
        }
    case 1 :
        {
            DrawNumbersOpponents(Window, 1);
        break;
        }
    case 2 :
        {
            DrawNumbersOpponents(Window, 2);
        break;
        }
    case 3 :
        {
            DrawNumbersOpponents(Window, 3);
        break;
        }
    case 4 :
        {
            DrawNumbersOpponents(Window, 4);
        break;
        }
    case 5 :
        {
            DrawNumbersOpponents(Window, 5);
        break;
        }
    case 6 :
        {
            DrawNumbersOpponents(Window, 6);
        break;
        }
    case 7 :
        {
            DrawNumbersOpponents(Window, 7);
        break;
        }
    case 8 :
        {
            DrawNumbersOpponents(Window, 8);
        break;
        }
    case 9 :
        {
            DrawNumbersOpponents(Window, 9);
        break;
        }     
        default:
        {
            std::cout<<"Nie ma takiej liczby na liscie"<<std::endl;
        }                                                                        
    }    
}
void GameView::DrawPointsPlayers(MainWindowApplication& Window)
{
    DrawOpponentPoints(Window);
    DrawPlayerPoints(Window);
}

void GameView::ClearGame()
{
    GBoard.TakecroLst().clear();
    GBoard.TakecirLst().clear();

    for(int i = 0; i<NUMBER_OF_HALF_THE_BOARD; ++i)
    {
        GBoard.takeField(i).AddFieldSymbol('N');
    }

      ThePlayerChoose = false;
      PlayerIs = NotSelected;
    Winner = BeginGame;    
    OpponentPoints = 0; 
    PlayerPoints =0;
    Turn = Player;
}

void GameView::NewGame()
{
    GBoard.TakecroLst().clear();
    GBoard.TakecirLst().clear();

    for(int i = 0; i<NUMBER_OF_HALF_THE_BOARD; ++i)
    {
        GBoard.takeField(i).AddFieldSymbol('N');
    }

      ThePlayerChoose = false;
    PlayerIs = NotSelected;
    Winner = BeginGame;    
    OpponentPoints = 0; 
    PlayerPoints =0;
    Turn = Player;
}

void GameView::ClearBoard()
{
    GBoard.TakecroLst().clear();
    GBoard.TakecirLst().clear();

    for(int i = 0; i<NUMBER_OF_HALF_THE_BOARD; ++i)
    {
        GBoard.takeField(i).AddFieldSymbol('N');
    }    
}
void GameView::TheCourseOfTheGame(MainWindowApplication& Window)
{
    //std::cout<<"ELO1"<<std::endl;
            //std::cout<<"ELO3"<<std::endl;
            /*while(!(SomeoneWon()||FullBoard()))
            {*/
            DrawPointsPlayers(Window);
                if(Window.takeMode() == GameMode)
                {
                    if(Turn == Player)
                    {
                        PlayerTurn(Window);
                    }
                    if(Turn == Opponent)
                    {
                        OpponentTurn(Window);
                    }     
                    GBoard.DrawAllCircle(Window);    
                    GBoard.DrawAllCrosses(Window);   
                }  

                if(SomeoneWon())
                {
                    ClearBoard();
                    std::cout<<"Opponent Points: "<<OpponentPoints<< " "<<"Player Points: "<<PlayerPoints<<std::endl;                   
                }
                if(FullBoard())    
                {
                    //draw
                    ++OpponentPoints;
                    ++PlayerPoints;
                    ClearBoard();
                    std::cout<<"Opponent Points: "<<OpponentPoints<< " "<<"Player Points: "<<PlayerPoints<<std::endl;                   
                }

                /*sf::Vector2i PositionMouseRespectWindow = sf::Mouse::getPosition(Window.takeWindowApplication());
     sf::Vector2f PositionMouseOnScene = Window.takeWindowApplication().mapPixelToCoords(PositionMouseRespectWindow);

    std::cout<<int(PositionMouseOnScene.x) <<" "<<int(PositionMouseOnScene.y)<<std::endl;*/

                if((PlayerPoints==9)||(OpponentPoints==9))
                {
                    ClearGame();
                }

                      /*for(int i = 0; i<9;++i)
                      {
                        std::cout<<GBoard.takeField(i).takeFieldSymbol()<<std::endl;
                      }*/
           // }                    
}

bool GameView::SomeoneWon()
{
    if(((GBoard.takeField(0).takeFieldSymbol()) == (GBoard.takeField(4).takeFieldSymbol()))&&
    ((GBoard.takeField(0).takeFieldSymbol()) == (GBoard.takeField(8).takeFieldSymbol()))&&(GBoard.takeField(0).takeFieldSymbol()!='N'))
    {
       DetermineWhoWin(GBoard.takeField(0).takeFieldSymbol());
        return true;
    }
    if( ((GBoard.takeField(6).takeFieldSymbol()) == (GBoard.takeField(4).takeFieldSymbol()))&&
    (((GBoard.takeField(6).takeFieldSymbol()) == (GBoard.takeField(2).takeFieldSymbol())))&&(GBoard.takeField(6).takeFieldSymbol()!='N'))
    {
       DetermineWhoWin(GBoard.takeField(6).takeFieldSymbol());       
        return true;
    }
    if(((GBoard.takeField(1).takeFieldSymbol()) == (GBoard.takeField(4).takeFieldSymbol()))&&
    ((GBoard.takeField(1).takeFieldSymbol()) == (GBoard.takeField(7).takeFieldSymbol()))&&(GBoard.takeField(1).takeFieldSymbol()!='N'))
    {
       DetermineWhoWin((GBoard.takeField(1).takeFieldSymbol()));
        return true;
    }
    if(((GBoard.takeField(2).takeFieldSymbol()) == (GBoard.takeField(5).takeFieldSymbol()))&&
 ((GBoard.takeField(2).takeFieldSymbol()) == (GBoard.takeField(8).takeFieldSymbol()))&&(GBoard.takeField(2).takeFieldSymbol()!='N'))
    {
       DetermineWhoWin((GBoard.takeField(2).takeFieldSymbol()));
        return true;
    }
    if(((GBoard.takeField(0).takeFieldSymbol()) == (GBoard.takeField(3).takeFieldSymbol()))&&
     ((GBoard.takeField(0).takeFieldSymbol())== (GBoard.takeField(6).takeFieldSymbol()))&&(GBoard.takeField(0).takeFieldSymbol()!='N'))
    {
       DetermineWhoWin((GBoard.takeField(0).takeFieldSymbol()));
        return true;
    }
    if(((GBoard.takeField(0).takeFieldSymbol()) == (GBoard.takeField(1).takeFieldSymbol()))&&
     ((GBoard.takeField(0).takeFieldSymbol())      == (GBoard.takeField(2).takeFieldSymbol()))&&(GBoard.takeField(0).takeFieldSymbol()!='N'))
    {
       DetermineWhoWin((GBoard.takeField(0).takeFieldSymbol()));
        return true;
    }
    if(((GBoard.takeField(3).takeFieldSymbol()) == (GBoard.takeField(4).takeFieldSymbol()))&&
     ((GBoard.takeField(3).takeFieldSymbol()) == (GBoard.takeField(5).takeFieldSymbol()))&&(GBoard.takeField(3).takeFieldSymbol()!='N'))
    {
       DetermineWhoWin((GBoard.takeField(3).takeFieldSymbol()));
        return true;
    }
    if(((GBoard.takeField(6).takeFieldSymbol()) == (GBoard.takeField(7).takeFieldSymbol()))&&
    ((GBoard.takeField(6).takeFieldSymbol()) == (GBoard.takeField(8).takeFieldSymbol()))&&(GBoard.takeField(6).takeFieldSymbol()!='N'))
    {
       DetermineWhoWin((GBoard.takeField(6).takeFieldSymbol()));
        return true;
    }

        return false;
}

void GameView::DetermineWhoWin(char FieldChar)
{
       if((PlayerIs == Crosses)&&(FieldChar=='X'))
        {
            Winner = Player;
            ++PlayerPoints;
        }
        else if((PlayerIs == Nought)&&(FieldChar=='O'))
        {
            Winner = Player;
            ++PlayerPoints;
        }
        else
        {
            Winner = Opponent; 
            ++OpponentPoints;               
        }
}

bool GameView::FullBoard()
{
    if((GBoard.TakecroLst().size()+GBoard.TakecirLst().size()) == NUMBER_OF_HALF_THE_BOARD)
        return true;

    return false;

}