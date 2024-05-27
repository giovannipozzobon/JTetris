#ifndef SCORE_HPP
#define SCORE_HPP

#include <cstdint>


class Score {

private:
    int score;

public:
    //Score Funcrion
    void EraseScore();
    void AddScore(int value);
    int  GetScore();
    void SetScore(int value);

};

#endif //SCORE_HPP