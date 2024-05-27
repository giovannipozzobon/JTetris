
#include "util.hpp"

unsigned int Util::nop_delay(unsigned int delay) {
    unsigned int timer;
    for(timer=0; timer<delay*7; timer++) {
        __asm__ ("NOP");
    }
    return timer;
};

void Util::WriteCharDebug(char ch){

    while(*API_COMMAND_ADDR) {}  
    API_PARAMETERS_ADDR[0] = ch;
    *API_FUNCTION_ADDR  = API_FN_WRITE_CHR_DEBUG  ;
    *API_COMMAND_ADDR   = API_GROUP_GENERAL ;   

}
