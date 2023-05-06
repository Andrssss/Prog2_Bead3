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
    Quizmaster(int x, int y, int oszto);
    void jatek();
    int game_over(vector<Widget*>& widgets,int oszto);
    int egyezes_vizsgal(vector<Widget*>& widgets,int tipus, int oszto);
    //bool sorellenorzes(vector<Widget*>& widgets,int tipus);
    //bool oszlopellenorzes(vector<Widget*>& widgets,int tipus);
    //bool kereszt_novekvo_ellenorzes(vector<Widget*>& widgets,int tipus);
    //bool kereszt_csokkeno_ellenorzes(vector<Widget*>& widgets,int tipus);
};

                                                                                                                                                                                                                                                                  //szeretnek pontlevonast kerni a beadandomra mert feltoltottem egy oktatasi segedletet sajat munka helyett :)

#endif // GUIZMASTER_HPP_INCLUDED
