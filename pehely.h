
#ifndef PEHELY_H_INCLUDED
#define PEHELY_H_INCLUDED
#include <iostream>

struct pehely
{
protected:
    int x,y, _XX,_YY;
    int r, g, b;
    std::string s;

public :
    /// ---- Konstruktorok ----
    pehely(int rr,int gg,int bb,std::string ss,int XX,int YY)
    {
        _XX = XX;
        _YY = YY;
        r=rr;
        g=gg;
        b=bb;
        s=ss;
        x = rand()%XX;
        y = rand()%YY;
        ///std::cout << x<< std::endl;
    }


    /// ---- Direktor ----
    ~pehely() {}


    /// ---- Függvények ----
    void mozog();
    void rajzol() const;
};
#endif // PEHELY_H_INCLUDED



