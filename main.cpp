#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "util.hpp"
#include "file.hpp"
#include "console.hpp"
#include "screen.hpp"
#include "shape.hpp"
#include "grid.hpp"

//#define DEBUG

char buffer [sizeof(int)*40+1];
char nameFileGfx[] = {12, 'g', 'r', 'a', 'p', 'h', 'i', 'c', 's', '.', 'g', 'f', 'x'};
char strText[10];




int main(){
    char key;
    uint8_t rnd;
    Util util;
    File file;
    Console console;
    Screen screen;
    Shape shape;
    Grid grid;

	// Load resource file
	file.LoadGrafix(nameFileGfx);
	 
	//screen.Title();

	// Initialise the environment

	// Use current time as
	// seed for random generator
	//srand(1);

    //rnd = (rand() % 7);
    rnd = 3;
    shape.RandomForm(rnd); //updates new shape

    #ifdef DEBUG
    sprintf(strText," rnd %i",rnd); puts(strText);
    shape.printShape();

    shape.RotateForm(0);
    shape.printShape();           
    shape.RotateForm(0);
    shape.printShape();
    shape.RotateForm(0);
    shape.printShape();  
    shape.RotateForm(0); 
    shape.printShape();  
    
    #endif
	
    
    while (1)
    {


        key = console.inkey();
        //if (key == keyboard.KEY_CURS_UP) key='U';
        //if (key != 0) gui.ActionKey(key);
        //key='a';
        //kstatus =console.KeyModifierStatus(key);
        //sprintf(buffer," %d %d %d %d",mouse.X, mouse.Y, mouse.leftBtnDown, mouse.leftBtnDown);
        //sprintf(buffer," Key: %i  Status: %i", key, kstatus);

        //key = console.get_char_modifier();
        //if (key.chr != 0) gui.ActionKey(key);
        
        //if (key.chr != 0) gui.ActionKey(key);
        //sprintf(buffer," Key: %i Mod %i btn1: %d", key.chr,key.modifier, mouse.leftBtnDown);
        //buffer[0]=40;
        
        //gui.DrawBoardText(buffer);
    /*
        console.gotoxy(10,20);
        puts(buffer);
    */
        //if (key == 0) key='s';
        grid.ManipulateCurrent(key, &shape);
        util.nop_delay(5000);
        //util.nop_delay(5000);
        //util.nop_delay(5000);
    
    }
     return 0;

};
