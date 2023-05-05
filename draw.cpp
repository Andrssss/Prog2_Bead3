#include "draw.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;


 void Draw::palyarajzol(int x,int y)
{
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

