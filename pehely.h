#ifndef PEHELY_H_INCLUDED
#define PEHELY_H_INCLUDED
#include <iostream>

struct pehely
{
public : /// hogy át tudjuk alakítani széppé
    int x,y, _XX,_YY;
    int r, g, b;
    std::string s;
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


    void mozog();
    void rajzol();
    ///bool bent();
};

#endif // PEHELY_H_INCLUDED

