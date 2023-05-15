#ifndef GUIZMASTER_HPP_INCLUDED
#define GUIZMASTER_HPP_INCLUDED
#include "draw.hpp"
#include "widgets.hpp"
#include <vector>

using std::vector;





class Quizmaster {
protected:
    int _x, _y, _oszto;

public:
    /// ---- Konstruktorok ----
    Quizmaster(int x, int y, int oszto);


    /// ---- Direktor ---
    ~Quizmaster() {}


    /// ---- Függvények ----
    void jatek();
    int game_over(vector<Widget*>& widgets,int oszto) const;
    int egyezes_vizsgal(vector<Widget*>& widgets,int tipus, int oszto) const;
    //bool sorellenorzes(vector<Widget*>& widgets,int tipus);
    //bool oszlopellenorzes(vector<Widget*>& widgets,int tipus);
    //bool kereszt_novekvo_ellenorzes(vector<Widget*>& widgets,int tipus);
    //bool kereszt_csokkeno_ellenorzes(vector<Widget*>& widgets,int tipus);
};
#endif // GUIZMASTER_HPP_INCLUDED
