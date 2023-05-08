#include "draw.hpp"
#include "graphics.hpp"
#include <vector>

using namespace genv;


 void Draw::palyarajzol(int x,int y)
{
    for (pehely* p : v) {
        delete p;
    }
    v.clear();



    gout << refresh;
    /// H�TT�R ------------------------------------
    gout << move_to(0,0) << color(0,0,0) << box(x,y);

    /// P�LYA ------------------------------------
    int i_lepes = x/_oszto;
    int j_lepes = y/_oszto;
    ///std::cout << i_lepes << " " << j_lepes << std::endl;

    gout << color(255,255,255);
    for(int i = i_lepes; i<x ; i+=i_lepes ) /// X r�cs rajzol
    {
        gout << move_to(i,0) << line_to(i,y);

    }
    for(int j = j_lepes; j<y ; j+=j_lepes ) /// Y r�cs rajzol
    {
        gout << move_to(0,j) << line_to(x,j);
    }
    /// T�MB ELEMEK ------------------------------------
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






int Draw::menu(genv::event ev)
{
    gout << move_to(0,0) << color(0,0,0) << box(_XX,_YY);
    for(pehely *p : v) /// range alap� for nagyon k�nyelmes, de csak akkor reag�l megv�ltoztat�sra, mert belem�solja p-be v-t
    {
        if(p){ p->mozog(); }
        if(p){ p->rajzol(); }

    }

    gout << font("LiberationSans-Regular.ttf",35);

        std::string s = "--- To start press left key ---";
        gout << color(255, 255, 255);
        gout << move_to(_XX/2-gout.twidth(s)/2,
                        _YY/2-(gout.cascent()+gout.cdescent())/2)
             << text(s);



    gout << refresh;
}


