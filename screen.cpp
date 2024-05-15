#include "screen.hpp"





void Screen::Title()
{
	uint8_t key, t, i = 1;

	// Clear screen
	console.clrscr();
	// Draw frame
	for (t = 0; t <= 20; t++)
	{
		graphic.DrawImage(t * 16, 16, 0);
	};
	for (t = 0; t <= 20; t++)
	{
		graphic.DrawImage(t * 16, 200, 16);
	};

	// Draw Clouds
	//DrawImage(160,160,26); DrawImage(176,160,27);

	console.cputcxy(10, 10, 32);

	puts("      Neo6502  JTETRIS\n");
	util.nop_delay(DELAY_SCREEN);
	console.cputc(143);
	console.gotoxy(40, 30);
	puts("                   by @Jobond");
	console.gotoxy(8, 14);
	console.cputc(135);
	puts("     Inserisci il tuo nome: \n");
	console.gotoxy(31,14);
	
    // replace with new routine to input string
    key = console.cgetc();
	while ((key != 13) && (i < 15))
	{
		console.cputc(key);
		//playerName[i] = key;
		key = console.cgetc();
		i++;
	}
	util.nop_delay(DELAY_SCREEN);
	console.cputc(0x81);
	console.gotoxy(20, 18);
	puts("Let's start!");
	console.cputc(0x87);
    console.gotoxy(16, 21);
	puts("PRESS RETURN OR FIRE");
	//while ((console.cgetc() != 13) && (checkFire()==0)); 
    while ((console.cgetc() != 13)); 

	util.nop_delay(DELAY_SCREEN);
	console.clrscr();
}