#ifndef SCREEN_HPP
#define SCREEN_HPP

#include "graphic.hpp"
#include "console.hpp"
#include "util.hpp"

#define DELAY_SCREEN 2000

class Screen {

private:
    Graphic graphic;
    Console console;
    Util util;

public:

    void Title();

};

#endif //SCREEN_HPP