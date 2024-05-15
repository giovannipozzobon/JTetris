#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "util.hpp"
#include "file.hpp"
#include "console.hpp"
#include "screen.hpp"
#include "shape.hpp"


char buffer [sizeof(int)*40+1];
char nameFileGfx[] = {12, 'g', 'r', 'a', 'p', 'h', 'i', 'c', 's', '.', 'g', 'f', 'x'};

int main(){
    Util util;
    File file;
    Console console;
    key_with_Modifier key;
    Screen screen;
    Shape shape;

	// Load resource file
	file.LoadGrafix(nameFileGfx);
	 
	screen.Title();

	// Use current time as
	// seed for random generator
	srand(1);

    shape.RandomForm(rand()%7); //updates new shape



	// Initialise the environment
	
    
    while (1)
    {


        //key = console.inkey();
        //if (key == keyboard.KEY_CURS_UP) key='U';
        //if (key != 0) gui.ActionKey(key);
        //key='a';
        //kstatus =console.KeyModifierStatus(key);
        //sprintf(buffer," %d %d %d %d",mouse.X, mouse.Y, mouse.leftBtnDown, mouse.leftBtnDown);
        //sprintf(buffer," Key: %i  Status: %i", key, kstatus);

        key = console.get_char_modifier();
        //if (key.chr != 0) gui.ActionKey(key);
        
        //if (key.chr != 0) gui.ActionKey(key);
        //sprintf(buffer," Key: %i Mod %i btn1: %d", key.chr,key.modifier, mouse.leftBtnDown);
        //buffer[0]=40;
        
        //gui.DrawBoardText(buffer);
    /*
        console.gotoxy(10,20);
        puts(buffer);
    */
        util.nop_delay(5000);
    
    }
     return 0;

};
