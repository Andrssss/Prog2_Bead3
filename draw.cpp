#include "draw.hpp"
#include "graphics.hpp"
//#include <vector>

using namespace genv;

/*Draw::Draw(oszto, XX, YY) {
            _oszto=oszto;
            _XX=XX;
            _YY=YY;
            for(int i=0; i < 50; i++)
            {
                pehely *p = new pehely(255,0,0,"X",XX,YY); /// így ez teljesen új címet fog befoglalni ez azért jó, mert nem fog felül íródni
                v.push_back(p);
            }
            for(int i=0; i < 50; i++)
            {
                pehely *p = new pehely(0,0,255,"O",XX,YY); /// így ez teljesen új címet fog befoglalni ez azért jó, mert nem fog felül íródni
                v.push_back(p);
            }
}*/



 void Draw::palyarajzol(int x,int y) const
{
    gout << refresh;



    /// HÁTTÉR ------------------------------------
    gout << move_to(0,0) << color(0,0,0) << box(x,y);

    /// PÁLYA ------------------------------------
    int i_lepes = x/_oszto;
    int j_lepes = y/_oszto;
    ///std::cout << i_lepes << " " << j_lepes << std::endl;

    gout << color(255,255,255);
    for(int i = i_lepes; i<x ; i+=i_lepes ) /// X rács rajzol
    {
        gout << move_to(i,0) << line_to(i,y);

    }
    for(int j = j_lepes; j<y ; j+=j_lepes ) /// Y rács rajzol
    {
        gout << move_to(0,j) << line_to(x,j);
    }
    /// TÖMB ELEMEK ------------------------------------
}



void Draw::game_over_screen(int tipus,int XX,int YY)
{
    gout << font("LiberationSans-Regular.ttf",100);
    if(tipus == 1)
    {
        std::string s = "RED WIN";
        gout << color(255,51,51) << move_to(0,0) << box(XX,YY);
        gout << color(255, 255, 255);
        gout << move_to(XX/2-gout.twidth(s)/2,
                        YY/2-(gout.cascent()+gout.cdescent())/2)
             << text(s)
             << refresh;
    }
    if(tipus == 2)
    {
        gout << color(51,51,255) << move_to(0,0) << box(XX,YY);
        std::string s = "BLUE WIN";
        gout << color(255, 255, 255);
        gout << move_to(XX/2-gout.twidth(s)/2,
                        YY/2-(gout.cascent()+gout.cdescent())/2)
             << text(s)
             << refresh;
    }
}






int Draw::menu(genv::event ev) const
{
    gout << move_to(0,0) << color(0,0,0) << box(_XX,_YY);
    genv::gout << genv::font("LiberationSans-Regular.ttf",25);

    for(pehely *p : v) /// range alapú for nagyon kényelmes, de csak akkor reagál megváltoztatásra, mert belemásolja p-be v-t
    {
        if(p){ p->mozog(); }
        if(p){ p->rajzol(); }

    }

    gout << font("LiberationSans-Regular.ttf",60);

        std::string s = "--- To start press left key ---";
        gout << color(255, 255, 255);
        gout << move_to(_XX/2-gout.twidth(s)/2,
                        _YY/2-(gout.cascent()+gout.cdescent())/2)
             << text(s);
    gout << refresh;
}


