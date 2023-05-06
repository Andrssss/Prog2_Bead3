#include "draw.hpp"
#include "graphics.hpp"

using namespace genv;


 void Draw::palyarajzol(int x,int y)
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
