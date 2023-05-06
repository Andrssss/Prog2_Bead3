#include "quizmaster.hpp"
#include "draw.hpp"
#include "widgets.hpp"






int main()
{
    /// pálya beállyítások -------------------
    int XX = 1000;
    int YY = 1000;
    int oszto = 20;
    Quizmaster quiz(XX,YY,oszto);

    quiz.jatek();


    return 0;
}
