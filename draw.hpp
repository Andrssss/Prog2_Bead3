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
                pehely *p = new pehely(255,0,0,"X",XX,YY); /// �gy ez teljesen �j c�met fog befoglalni ez az�rt j�, mert nem fog fel�l �r�dni
                v.push_back(p);
            }
            for(int i=0; i < 600; i++)
            {

                pehely *p = new pehely(0,0,255,"O",XX,YY); /// �gy ez teljesen �j c�met fog befoglalni ez az�rt j�, mert nem fog fel�l �r�dni
                v.push_back(p);
            }
    }
    /// ---- Direktor ----
    ~Draw() {}


    /// ---- F�ggv�nyek ----
    virtual void game_over_screen(int tipus,int XX,int YY) const;
    virtual int menu(genv::event ev) const;
    virtual void menu_freememory();
    virtual void palyarajzol(int x,int y) const;
};
#endif // DRAW_HPP_INCLUDED




     ///static void game_over_screen(int tipus,int XX,int YY) const;
     /// F�ggetlens�g az objektum p�ld�nyokt�l: Ha egy f�ggv�nyt static kulcssz�val jel�l�nk, akkor az nem f�gg semmilyen objektum p�ld�nyt�l.
     /// Ez azt jelenti, hogy a f�ggv�nyt k�zvetlen�l az oszt�lyra lehet megh�vni, nem pedig egy adott objektumra
