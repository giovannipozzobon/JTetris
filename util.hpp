#ifndef UTIL_HPP
#define UTIL_HPP

#include <stdio.h>
#include <cstdint>

class Util {
private:

    /* Neo6502 Kernel API control addresses */

    volatile uint8_t* API_COMMAND_ADDR    = ( uint8_t*)0xFF00 ; // function group address
    volatile uint8_t* API_FUNCTION_ADDR   = ( uint8_t*)0xFF01 ; // function address
    volatile uint8_t* API_ERROR_ADDR      = (uint8_t*)0xFF02 ; // function errors
    volatile uint8_t* API_STATUS_ADDR     = (uint8_t*)0xFF03 ; // function errors
    volatile uint8_t* API_PARAMETERS_ADDR = ( uint8_t*)0xFF04 ; // function parameters base address (8 bytes)

    // Functions (Group 1)
    uint8_t API_GROUP_GENERAL       = (uint8_t )0x01 ; // API function group ID
    uint8_t API_FN_DSP_RESET        = (uint8_t )0x00 ; // API function ID
    uint8_t API_FN_TIMER            = (uint8_t )0x01 ; // API function ID
    uint8_t API_FN_KEY_STATUS       = (uint8_t )0x02 ; // API function ID
    uint8_t API_FN_BASIC            = (uint8_t )0x03 ; // API function ID

    uint8_t API_FN_WRITE_CHR_DEBUG  = (uint8_t )0x0A ; // API function ID


public:

    unsigned int nop_delay(unsigned int delay);
    void WriteCharDebug(char ch); 

};

#endif //UTIL_HPP