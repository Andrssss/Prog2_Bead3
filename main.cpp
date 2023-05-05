#include "widgets.hpp"
#include "quizmaster.hpp"
#include "draw.hpp"
#include "widgets.hpp"

///#include <vector>
using namespace std;
using namespace genv;





int main()
{
    int XX = 1000;
    int YY = 1000;
    int oszto = 20;
    Quizmaster quiz(XX,YY,oszto);



    vector<Widget*> matrix;
    for(int j =0; j<XX ; j+=XX/oszto ) /// X rács rajzol
    {

        for(int i =0; i<YY ; i+=YY/oszto ) /// Y rács rajzol
        {
            Widget *k = new Widget(i, j, XX/oszto, YY/oszto, 0); /// 0 azt jelenti, hogy se x, se y nincs benne
            matrix.push_back(k);
        }
    }

    quiz.jatek(matrix);







    return 0;
}
