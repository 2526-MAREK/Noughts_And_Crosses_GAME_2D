#include "MenuView.hh"

MenuView::MenuView(const std::string& NamePictureTemp) :  NamePicture(NamePictureTemp) , txt()
{
    if(!txt.loadFromFile(NamePicture))
        std::cerr<<"Program nie może znaleźć pliku o nazwie: "<<NamePicture<<"w głównym katalogu gry !!!"<<std::endl;
    setTexture(txt);                
}
