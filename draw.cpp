#include "draw.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;


 void Draw::palyarajzol(int x,int y)
{
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

