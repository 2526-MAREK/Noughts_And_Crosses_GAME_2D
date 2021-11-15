#ifndef WINDOWSELECTIONCROSSORNOUGHT_HH
#define WINDOWSELECTIONCROSSORNOUGHT_HH

#include "crosses.hh"
#include "circle.hh"
#include "OptionCrosses.hh"
#include "OptionNought.hh"

class WindowSelectionCrossOrNought : public sf::Sprite
{
private:
    std::string NamePicture;
    sf::Texture txt;        
    OptionCrosses TableOptionChooseCrosses;  
    OptionNought TableOptionChooseNought;
public:
    WindowSelectionCrossOrNought() : txt(), TableOptionChooseCrosses(), TableOptionChooseNought() {NamePicture ="brak";}
    WindowSelectionCrossOrNought(const std::string& NamePictureTemp, const OptionCrosses& TableOptionChooseCrossesTemp,
     const OptionNought& TableOptionChooseNoughtTemp);
    OptionCrosses& TakeTableOptionChooseCrosses(){return TableOptionChooseCrosses;}
    OptionNought& TakeTableOptionChooseNought(){return TableOptionChooseNought;}
};

#endif