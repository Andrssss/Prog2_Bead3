#include "pehely.h"
#include "graphics.hpp"

using namespace genv;


void pehely::mozog() /// HOESÉS--------------
{
        y +=rand()%5-1;
        x +=rand()%5-2;
        if(y>=_YY) y=0;
        if(x>=_XX) x=0;
        if(x<0) x=_XX-1;
        if(y<0) y=_YY-1;
}
void pehely::rajzol() const
{
    gout << move_to(x,y) << color(r,g,b)  << text(s);
}

