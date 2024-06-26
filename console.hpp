#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include <stdio.h>
#include <cstdint>
#include <stdlib.h>

typedef struct key_with_Modifier
{
    char chr = 0;
    char modifier;
    
} key_with_Modifier;

class Console {
private:

    /* Neo6502 Kernel API control addresses */

    volatile uint8_t* API_COMMAND_ADDR    = ( uint8_t*)0xFF00 ; // function group address
    volatile uint8_t* API_FUNCTION_ADDR   = ( uint8_t*)0xFF01 ; // function address
    volatile uint8_t* API_ERROR_ADDR      = (uint8_t*)0xFF02 ; // function errors
    volatile uint8_t* API_STATUS_ADDR     = (uint8_t*)0xFF03 ; // function errors
    volatile uint8_t* API_PARAMETERS_ADDR = ( uint8_t*)0xFF04 ; // function parameters base address (8 bytes)

    // Console functions (Group 2)
    uint8_t API_GROUP_CONSOLE       = (uint8_t )0x02 ; // API function group Console
    uint8_t API_FN_WRITE_CHAR       = (uint8_t )0x00 ; // API function Write Char
    uint8_t API_FN_READ_CHAR        = (uint8_t )0x01 ; // API function Read Char
    uint8_t API_FN_CHECK_STATUS     = (uint8_t )0x02 ; // API function Check Status
    uint8_t API_FN_READ_LINE        = (uint8_t )0x03 ; // API function Read Line    
    uint8_t API_FN_WRITE_CHAR_CURS  = (uint8_t )0x06 ; // API function Write Char Curs
    uint8_t API_FN_CURSOR_POS       = (uint8_t )0x07 ; // API function Cursor Pos
    uint8_t API_FN_CLEAR_SCREEN     = (uint8_t )0x0C ; // API function Clear Screen
    uint8_t API_FN_SET_COLOR_TEXT   = (uint8_t )0x0F ; // API function Clear Screen

    // System functions (Group 1)
    uint8_t API_GROUP_SYSTEM        = (uint8_t )0x01 ; // API function group System
    uint8_t API_FN_KEY_STATUS       = (uint8_t )0x02 ; // API function Key Status


public:

    const uint8_t KEY_CURS_LEFT		= 1	;		// Cursor Left
    const uint8_t KEY_CURS_RIGHT	= 4	;		// Cursor Right
    const uint8_t KEY_INSERT  		= 5	;		// Insertion Mode
    const uint8_t KEY_PAGE_DOWN		= 6	;		// Cursor Page Down
    const uint8_t KEY_END  			= 7	;		// Cursor Line End
    const uint8_t KEY_BACKSPACE  	= 8	;		// Delete Character Left 
    const uint8_t KEY_TAB  			= 9	;		// Tab Character
    const uint8_t KEY_LINE_FEED 	= 10;		// Line Feed
    const uint8_t KEY_CLS_SCREEN 	= 12;		// Clear Screen
    const uint8_t KEY_ENTER 		= 13;		// Carriage Return (Accept Line)
    const uint8_t KEY_PAGE_UP 		= 18;		// Cursor Page Up
    const uint8_t KEY_CURS_DOWN 	= 19;		// Cursor Down
    const uint8_t KEY_HOME 			= 20;		// Cursor Line Begin
    const uint8_t KEY_DWN_8LINES 	= 22;		// Cursor Down (8 Lines)
    const uint8_t KEY_CURS_UP 		= 23;		// Cursor Up
    const uint8_t KEY_CUR_COL_INV 	= 24;		// Cursor Color Inverse
    const uint8_t KEY_DELETE 		= 26;		// Delete Character Right
    const uint8_t KEY_ESCAPE 		= 27;		// Exit
    const uint8_t KEY_SPACE 		= 32;		// Space

    const uint8_t KEY_CTRL 		    = 17;		// Control  Control
    const uint8_t KEY_SHIFT 		= 34;		// Shift    Shift
    const uint8_t KEY_ALT 		    =  4;		// Alt      Option SX
    const uint8_t KEY_ALT_GR 		= 64;		// Alt Grt  Option DX


    key_with_Modifier key_mod;

    // Get character from keyboard
    char inkey();

    char cgetc();

    key_with_Modifier get_char_modifier();

    // Position cursor (API Group 2, Function 7)
    void gotoxy(uint8_t sx, uint8_t sy);

    void SetCursorPosition(uint8_t x_pos , uint8_t y_pos);

    void ClearScreen();

    char CheckKeyboardArray();

    // write to conole a string with lengh count
    void write (const unsigned char* buf, unsigned count);

    // Put a character
    void cputc(char ch);

    // Put a character at screen coord
    void cputcxy(int sx, int sy, char ch);

    // Clear screen
    void clrscr();

    void ClearKeyboardArray();

    uint8_t KeyModifierStatus(uint8_t chr);

    void ReadLine(int line_read);

    void ReadString(char * str);

    int ReadNumber(char * str, int len);

    void SetColorText(uint8_t colorText, uint8_t colorBackground);

};


#endif //CONSOLE_HPP