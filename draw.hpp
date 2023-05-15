#ifndef DRAW_HPP_INCLUDED
#define DRAW_HPP_INCLUDED
#include "graphics.hpp"
#include "pehely.h"
#include <vector>

using namespace std;


class Draw {
    int _oszto;
    vector<pehely*> v;
    int _XX,_YY;



public:
    /// ---- Konstruktorok ----
     Draw(int oszto,int XX,int YY) : _oszto(oszto),_XX(XX),_YY(YY){
            for(int i=0; i < 600; i++)
            {
                pehely *p = new pehely(255,0,0,"X",XX,YY); /// így ez teljesen új címet fog befoglalni ez azért jó, mert nem fog felül íródni
                v.push_back(p);
            }
            for(int i=0; i < 600; i++)
            {

                pehely *p = new pehely(0,0,255,"O",XX,YY); /// így ez teljesen új címet fog befoglalni ez azért jó, mert nem fog felül íródni
                v.push_back(p);
            }
    }
    /// ---- Direktor ----
    ~Draw() {}


    /// ---- Függvények ----
    virtual void game_over_screen(int tipus,int XX,int YY) const;
    virtual int menu(genv::event ev) const;
    virtual void menu_freememory();
    virtual void palyarajzol(int x,int y) const;
};
#endif // DRAW_HPP_INCLUDED




     ///static void game_over_screen(int tipus,int XX,int YY) const;
     /// Függetlenség az objektum példányoktól: Ha egy függvényt static kulcsszóval jelölünk, akkor az nem függ semmilyen objektum példánytól.
     /// Ez azt jelenti, hogy a függvényt közvetlenül az osztályra lehet meghívni, nem pedig egy adott objektumra
