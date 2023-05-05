#include "widgets.hpp"
#include "graphics.hpp"
#include <iostream>
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy, int tipus) : _x(x), _y(y), _size_x(sx), _size_y(sy), _tipus(tipus) {}




bool Widget::is_selected(int mouse_x, int mouse_y){
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}





void Widget::szinez(int korszamolo)
{
    if(korszamolo%2)   gout << color(255,51,51) << move_to(_x,_y) << box(_size_x,_size_y);  /// KÖR ---> piros
    else               gout << color(51,51,255) << move_to(_x,_y) << box(_size_x,_size_y);  /// X   ---> kék


    std::string s;
    gout << color(255,255,255);

    if(_tipus == 1)
    {
        s = "O";
        gout << move_to(2+_x+_size_x/2-gout.twidth(s)/2,2+_y+_size_y/2-(gout.cascent()+gout.cdescent())/2)<< text(s);
    }
    if(_tipus == 2)
    {
        s = "X";
        gout << move_to(2+_x+_size_x/2-gout.twidth(s)/2,2+_y+_size_y/2-(gout.cascent()+gout.cdescent())/2)<< text(s);
    }
}




void Widget::game_over_screen(int tipus,int XX,int YY)
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


void Widget::draw()
{
        std::string s;
        gout << color(255, 255, 255);
        if(_tipus == 1)
        {
            gout << color(255,51,51);
            s="O";
        }
        if(_tipus == 2)
        {
            gout << color(51,51,255);
            s="X";
        }
        gout << move_to(2+_x+_size_x/2-gout.twidth(s)/2,
                        2+_y+_size_y/2-(gout.cascent()+gout.cdescent())/2)
             << text(s);
}













