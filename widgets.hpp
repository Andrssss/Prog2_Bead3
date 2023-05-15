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


    /// ---- F�ggv�nyek ----
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void szinez(int korszamolo) const;
    virtual void draw() const;
    virtual void szoveg_kozepre_irat(std::string s) const;
};

// �n plusz pontot k�rek :)

#endif // WIDGETS_HPP_INCLUDED
