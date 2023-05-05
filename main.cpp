#include "widgets.hpp"
#include "quizmaster.hpp"
#include "draw.hpp"
#include "widgets.hpp"

///#include <vector>
using namespace std;
using namespace genv;

/*
void event_loop(vector<Widget*>& widgets) {
    /// itt nem lehet leszármazottakra meghívni saját fvg-t csak main- ban
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (Widget * w : widgets) {
            //gout << move_to(0,0) << color(0,0,0) << box(400,400);
            w->draw();
        }
        gout << refresh;
    }
}
*/



///Fun: minden karakter 1 bite, de minden ékezetes karakter 2 bite. Ha levágod az utolsó karaktert, akkor az elrontja esetleg az ékezetes betût.

int main()
{
    int XX = 1000;
    int YY = 1000;
    int oszto = 20;
    Quizmaster quiz(XX,YY,oszto);


    //vector<vector<Widget*>> matrix;

    vector<Widget*> matrix;
    for(int j =0; j<XX ; j+=XX/oszto ) /// X rács rajzol
    {

        for(int i =0; i<YY ; i+=YY/oszto ) /// Y rács rajzol
        {
            Widget *k = new Widget(i, j, XX/oszto, YY/oszto, 0); /// 0 azt jelenti, hogy se x, se y nincs benne
            matrix.push_back(k);
        }
    }


    ///
    /*for(int j =0; j<XX ; j+=XX/15 ) /// X rács rajzol
    {
        vector<Widget*> row;
        for(int i =0; i<YY ; i+=YY/15 ) /// Y rács rajzol
        {
            Widget *k = new Widget(i, j, XX/15, YY/15, 0); /// 0 azt jelenti, hogy se x, se y nincs benne
            matrix.push_back(row);
        }
    }*/




    quiz.jatek(matrix);



/*    gout.open(400,400);
    vector<Widget*> w;
    ExampleCheckBox * b1 = new ExampleCheckBox(10,10,30,30);
    ExampleCheckBox * b2 = new ExampleCheckBox(10,50,40,40);
    Beleiro * st3 = new Beleiro(100,100,100,40,"");
    w.push_back(b1);
    w.push_back(b2);
    w.push_back(st3);

    /// kiirás nem az õsön keresztül !!!!!
    for (Widget * wg : w) {
        wg->draw();
    }
    gout << refresh;
    event_loop(w);*/
    return 0;
}
