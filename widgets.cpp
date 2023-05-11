#include "widgets.hpp"
#include "graphics.hpp"
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy, int tipus) : _x(x), _y(y), _size_x(sx), _size_y(sy), _tipus(tipus) {}




bool Widget::is_selected(int mouse_x, int mouse_y) const
{
    return mouse_x>_x && mouse_x<_x+_size_x && mouse_y>_y && mouse_y<_y+_size_y;
}

void Widget::szoveg_kozepre_irat(std::string s) const
{
    gout << move_to(2+_x+_size_x/2-gout.twidth(s)/2,
                    2+_y+_size_y/2-(gout.cascent()+gout.cdescent())/2)<< text(s);
}





void Widget::szinez(int korszamolo) const/// Ez színezi a mozgó egér mögött a hátteret
{
    /// Háttér ---------------------------
    if(korszamolo%2)   gout << color(255,51,51) << move_to(_x,_y) << box(_size_x,_size_y);  /// KÖR ---> piros
    else               gout << color(51,51,255) << move_to(_x,_y) << box(_size_x,_size_y);  /// X   ---> kék

    /// Szöveg ---------------------------
    std::string s;
    gout << color(255,255,255);

    if(_tipus == 1) s = "O";
    if(_tipus == 2) s = "X";

    szoveg_kozepre_irat(s);
}




void Widget::draw() const
{
        gout << font("LiberationSans-Regular.ttf",35);

        std::string s;
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

        szoveg_kozepre_irat(s);
}













