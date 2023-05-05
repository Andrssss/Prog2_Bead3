#include "quizmaster.hpp"
#include "draw.hpp"
#include "widgets.hpp"
#include "graphics.hpp"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace genv;
using std::vector;
using std::cout;
using std::endl;

Quizmaster::Quizmaster(int x, int y,int oszto) : _x(x), _y(y), _oszto(oszto)
{
    genv::gout.open(_x,_y); /// _x és _y a palyameret
                            /// _oszto, pedig az nxn -es pálya felosztás
}




void Quizmaster::jatek(vector<Widget*>& widgets)
{
    event ev;
    int focus = -1;
    ///int oszlop = -1;
    gin.timer(400);
     /// x-poz , y-poz

    /// KI KEZDJEN ------------------------------------------------------------------
    std::srand(std::time(0));
    int kor_szamolo= rand() % 2;
    int mar_vege = -1;

    /// minden mezõbõl csinálok egy widgetet..... NEM HATÁKONY

    ///Widget palya;

    while(gin >> ev && ev.keycode != key_escape ) {
        if(mar_vege == 1) widgets[0]->game_over_screen(1,_x,_y); /// KÖR win
        if(mar_vege == 2) widgets[0]->game_over_screen(2,_x,_y); /// X win
        else if(mar_vege == -1)
        {
                if (ev.button == btn_left && ev.type == ev_mouse){ /// BEILLESZTÉS ----> TÖMB KEZELÉS
                    for (size_t i=0;i<widgets.size();i++) {
                        if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                                focus = i;
                        }
                    }
                    if (widgets[focus]->_tipus == 0 )
                    {
                        if(kor_szamolo%2 ) widgets[focus]->_tipus = 1 ; /// KÖR
                        else              widgets[focus]->_tipus = 2 ; /// X
                        kor_szamolo ++;
                        mar_vege = game_over(widgets,_oszto);

                        ///std::cout << mar_vege<< std::endl;

                        ///for (size_t i=0;i<widgets.size();i++) { std::cout << widgets[i]->_tipus << " " ;}
                        ///std::cout << std::endl;
                    }
                }
                /// TARTALOM KIIRAS
                for (size_t i=0;i<widgets.size();i++) {
                        //std::string s = std::to_string(i);
                    widgets[i]->draw();
                }
                if (ev.type == ev_mouse) {   /// AKTÍV KÖVETÉS---> WIDGET HÍVÁS
                    for (size_t i=0;i<widgets.size();i++) {
                        if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                                focus = i;
                                break;
                        }
                    }
                    for(size_t i=0;i<widgets.size();i++){
                        if(widgets[i]->_x == widgets[focus]->_x || widgets[i]->_y == widgets[focus]->_y)
                        {
                            widgets[i]->szinez(kor_szamolo);
                        }
                    }
                }










                /*if(egy sorban vagy 1 oszlopban 5)
                  /// GAME OVER
                */

                int i = _oszto;

                 gout << refresh;
                Draw draww(i);
                draww.palyarajzol(_x,_y);
        }
    }
}















int Quizmaster::game_over(vector<Widget*>& widget,int oszto)
{
    int return_ertek = -1;

    return_ertek = egyezes_vizsgal(widget, 1, 1); /// 1 - 1
    if(return_ertek != -1) return 1;
    return_ertek = egyezes_vizsgal(widget, 2 , 1);
     // cout << return_ertek;
    if(return_ertek != -1) return 2;
    return_ertek = egyezes_vizsgal(widget, 1 , _oszto); /// OSZTO - 20
    if(return_ertek != -1) return 1;
    return_ertek = egyezes_vizsgal(widget, 2, _oszto);
    if(return_ertek != -1) return 2;
    return_ertek = egyezes_vizsgal(widget, 1, _oszto+1); /// OSZTO+1 - 21
    if(return_ertek != -1) return 1;
    return_ertek = egyezes_vizsgal(widget, 2, _oszto+1);
    if(return_ertek != -1) return 2;
    return_ertek = egyezes_vizsgal(widget, 1, _oszto-1); /// OSZTO-1 - 19
    if(return_ertek != -1) return 1;
    return_ertek = egyezes_vizsgal(widget, 2, _oszto-1);
    if(return_ertek != -1) return 2;

    return -1;
}




int Quizmaster::egyezes_vizsgal(vector<Widget*>& widgets,int tipus,int hozzaad_szoroz)
{
    int egyoszlopban=0;
    std::vector<bool> vizsgalt(widgets.size(), false);

    /// Ronda, DE lineáris ----------------------

    for (size_t i = 0; i < widgets.size(); i++) {
        if (widgets[i]->_tipus == tipus && !vizsgalt[i]) {
            int egyoszlopban = 1;

            std::vector<size_t> egyezesek;

            for (size_t j = i+hozzaad_szoroz; j < widgets.size(); j+=hozzaad_szoroz) {
                   if (widgets[j]->_tipus == tipus && i+(hozzaad_szoroz*egyoszlopban) == j && j - i == hozzaad_szoroz*egyoszlopban) {
                    egyoszlopban++;
                    vizsgalt[j] = true;
                    egyezesek.push_back(j);
                }
                else if (i+(hozzaad_szoroz*egyoszlopban) != j || j - i != hozzaad_szoroz*egyoszlopban) {
                    break;
                }
            }
            if (egyoszlopban >= 5) return tipus ;
        }
    }
    return -1 ;
}

/*
bool Quizmaster::sorellenorzes(vector<Widget*>& widgets,int tipus)
{
    /// LEHET HOGY CSÚNYA, DE!!! LINEÁRIS .. PONT N -
    int egysorban=0;
    //int szamol=0;
    std::vector<bool> vizsgalt(widgets.size(), false);
    for (size_t i = 0; i < widgets.size(); i++) {
        if (widgets[i]->_tipus == tipus && !vizsgalt[i]) { // Csak a nem vizsgált KÖR elemeket vizsgáljuk
            int egysorban = 1; /// AZÉRT JÓ ÍGY, MERT AKKOR A BELSŐ FVG-NEK 1X KEVESEBBSZER KELL LEFUTNIA
            //szamol++;
            std::vector<size_t> egyezesek;
            for (size_t j = i+1; j < widgets.size(); j++) {
                /*if (widgets[j]->_tipus == tipus)
                {
                    //std::cout << "i:"<< i <<" ";
                    //std::cout << "j:"<< j <<" ";
                    //std::cout << i+(20*egyoszlopban)+1 <<  "==" << j << "    " << egyoszlopban << std::endl;
                    //std::cout << j - i <<  "==" << ((20*egyoszlopban)+egyoszlopban) << std::endl;
                }
                //if (widgets[j]->_tipus == tipus && widgets[i]->_y == widgets[j]->_y && j - i == egysorban) {
                if (widgets[j]->_tipus == tipus && i+egysorban == j && j - i == egysorban) {
                    egysorban++;
                    vizsgalt[j] = true; // Jelöljük meg a vizsgált elemet
                    egyezesek.push_back(j); // Az egyező elem indexét hozzáadjuk a vektorhoz
                    szamol++;
                }
                else if (widgets[i]->_y != widgets[j]->_y || j - i != egysorban) {
                    // Ellenőrizzük, hogy van-e legalább egy 5 elemű egyezés
                    /*if (egysorban >= 5) {
                        for (size_t k : egyezesek) {
                            vizsgalt[k] = false; // Az egyező elemeket újra jelöljük megvizsgálatlan állapotba
                        }
                        return true;
                    }
                    break; /// hisz ha nem szomszéd akkor ezt már felesleges tovább vizsgálni
                }
            }
            if (egysorban >= 5) {
                //for (size_t k : egyezesek) {
                 //   vizsgalt[k] = false; // Az egyező elemeket újra jelöljük megvizsgálatlan állapotba
                //}
                return true;
            }
            //if (){
              //  for (size_t i = 0; i < widgets.size(); i++)
            //}
            //std::cout << szamol;
        }
    }
    return false ;
}


bool Quizmaster::oszlopellenorzes(vector<Widget*>& widgets,int tipus)
{
    int egyoszlopban=0;
    std::vector<bool> vizsgalt(widgets.size(), false);

    /// NAGYON FONTOS EZEN MODOSÍTAN A 20-ON !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    for (size_t i = 0; i < widgets.size(); i++) {   /// végig megy az oszlopokon, csak ez nem oldalra, hanem lefele vizsgál
        if (widgets[i]->_tipus == tipus && !vizsgalt[i]) { // Csak a nem vizsgált KÖR elemeket vizsgáljuk
            int egyoszlopban = 1;

            std::vector<size_t> egyezesek; // Ebben a vektorban tároljuk az egyező elemek indexeit

            for (size_t j = i+20; j < widgets.size(); j+=20) {
                if (widgets[j]->_tipus == tipus)
                {
                    //std::cout << "i:"<< i <<" ";
                    //std::cout << "j:"<< j <<" ";
                    ///std::cout << i+(20*egyoszlopban) <<  "==" << j << "    " << egyoszlopban << std::endl;
                    //std::cout << j - i <<  "==" << ((20*egyoszlopban)+egyoszlopban) << std::endl;
                }
                ///if (widgets[j]->_tipus == tipus && widgets[i]->_x == widgets[j]->_x && j - i == 20*egyoszlopban) {
                   if (widgets[j]->_tipus == tipus && i+(20*egyoszlopban) == j && j - i == 20*egyoszlopban) {
                    egyoszlopban++;
                    vizsgalt[j] = true;
                    egyezesek.push_back(j);
                }
                else if (widgets[i]->_x != widgets[j]->_x|| j - i != 20*egyoszlopban) {
                    break;
                }
            }
            if (egyoszlopban >= 5) return true;
        }
    }
    return false ;
}



bool Quizmaster::kereszt_novekvo_ellenorzes(vector<Widget*>& widgets,int tipus)
{
    int egyoszlopban=0;
    std::vector<bool> vizsgalt(widgets.size(), false);

    /// NAGYON FONTOS EZEN MODOSÍTAN A 20-ON !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    for (size_t i = 0; i < widgets.size(); i++) {   /// végig megy az oszlopokon
        if (widgets[i]->_tipus == tipus && !vizsgalt[i]) { // Csak a nem vizsgált KÖR elemeket vizsgáljuk
            //std::cout << widgets[i]->_x << " - ";
            int egyoszlopban = 1;
            std::vector<size_t> egyezesek; // Ebben a vektorban tároljuk az egyező elemek indexeit

            for (size_t j = i+21; j < widgets.size(); j+=21) {
                if (widgets[j]->_tipus == tipus && (i+(20*egyoszlopban)+egyoszlopban) == j && j - i == (20*egyoszlopban)+egyoszlopban) {
                    egyoszlopban++;
                    vizsgalt[j] = true; // Jelöljük meg a vizsgált elemet
                    egyezesek.push_back(j); // Az egyező elem indexét hozzáadjuk a vektorhoz
                }
                else if (i+(20*egyoszlopban)+egyoszlopban) != j || j - i != (20*egyoszlopban)+egyoszlopban) {
                    break;
                }
            }
            if (egyoszlopban >= 5) return true;
        }
    }
    return false ;
}


bool Quizmaster::kereszt_csokkeno_ellenorzes(vector<Widget*>& widgets,int tipus)
{
    int egyoszlopban=0;
    std::vector<bool> vizsgalt(widgets.size(), false);

    /// NAGYON FONTOS EZEN MODOSÍTAN A 20-ON !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    for (size_t i = 0; i < widgets.size(); i++) {   /// végig megy az oszlopokon
        if (widgets[i]->_tipus == tipus && !vizsgalt[i]) { // Csak a nem vizsgált KÖR elemeket vizsgáljuk
            int egyoszlopban = 1;
            std::vector<size_t> egyezesek; // Ebben a vektorban tároljuk az egyező elemek indexeit

            for (size_t j = i+19; j < widgets.size(); j+=19) {
                if (widgets[j]->_tipus == tipus && (i+(20*egyoszlopban)-egyoszlopban) == j && j - i == (20*egyoszlopban)-egyoszlopban) {
                    egyoszlopban++;
                    vizsgalt[j] = true; // Jelöljük meg a vizsgált elemet
                    egyezesek.push_back(j); // Az egyező elem indexét hozzáadjuk a vektorhoz
                }
                else if (i+(20*egyoszlopban)-egyoszlopban) != j   || j - i != (20*egyoszlopban)-egyoszlopban) {
                     break;
                }
            }
            if (egyoszlopban >= 5) return true;
        }
    }
    return false ;
}*/




