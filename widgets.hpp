#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED
#include "graphics.hpp"
#include <string>
#include "graphics.hpp"
using namespace genv;
class Widget {
public:
    int _tipus;

public:
    int _x, _y, _size_x, _size_y;

    Widget(int x, int y, int sx, int sy, int tipus );
    virtual bool is_selected(int mouse_x, int mouse_y);
    void szinez(int korszamolo);
    void game_over_screen(int tipus,int XX,int YY);
    void draw(/*std::string s*/ );
    ///virtual bool felette()
    //virtual void draw() = 0;
    //virtual void handle(genv::event ev) = 0;
    //virtual bool contains(int x, int y) = 0;
    //virtual bool is_checked() {};
};

                                                                                                                                                                                                                                                                  //szeretnek pontlevonast kerni a beadandomra mert feltoltottem egy oktatasi segedletet sajat munka helyett :)

#endif // WIDGETS_HPP_INCLUDED
