#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED
#include <string>

class Widget {
protected:
    int  _size_x, _size_y;

public:
    int _x, _y, _tipus;

    Widget(int x, int y, int sx, int sy, int tipus );


    virtual bool is_selected(int mouse_x, int mouse_y);


    int string_to_middle_x(std::string s);
    int string_to_middle_y();


    virtual void szinez(int korszamolo);
    virtual void draw();
    virtual void szoveg_kozepre_irat(std::string s);
};
#endif // WIDGETS_HPP_INCLUDED
