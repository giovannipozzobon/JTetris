#include "score.hpp"


    void Score::EraseScore() {score =0;}

    void Score::AddScore(int value){ score += value; }

    int  Score::GetScore(){ return score;}

    void Score::SetScore(int value){ score = value;}