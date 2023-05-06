#ifndef DRAW_HPP_INCLUDED
#define DRAW_HPP_INCLUDED

class Draw {
    int _oszto;


public:
     Draw(int oszto) : _oszto(oszto){}
     void palyarajzol(int x,int y);
     static void game_over_screen(int tipus,int XX,int YY);

};

                                                                                                                                                                                                                                                                  //szeretnek pontlevonast kerni a beadandomra mert feltoltottem egy oktatasi segedletet sajat munka helyett :)

#endif // DRAW_HPP_INCLUDED
