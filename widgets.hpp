#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED
#include <string>

class Widget {
protected:
    int  _size_x, _size_y;


public:
    const int _x, _y;
    int _tipus;

    /// ---- Konstruktorok ----
    Widget(int x, int y, int sx, int sy, int tipus );


    /// ---- Direktor ----
    ~Widget() {}


    /// ---- Függvények ----
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void szinez(int korszamolo) const;
    virtual void draw() const;
    virtual void szoveg_kozepre_irat(std::string s) const;
};

// Én plusz pontot kérek :)

#endif // WIDGETS_HPP_INCLUDED
