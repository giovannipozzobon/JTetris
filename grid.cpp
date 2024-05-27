
#include "grid.hpp"


//#define DEBUG

Grid::Grid(){

	//map initial configuration
	map[0] = 1;
	map[1] = WIDTH;
	map[2] = HEIGHT;

	//erase the score
	score.EraseScore();

}


void Grid::EraseMap(){
	uint8_t i, j;

	for(i = 0; i < HEIGHT ;i++){
		for(j = 0; j < WIDTH; j++){
			map[3+i*WIDTH+j] = 0;
		}
	}

 }

 void Grid::EraseGrid(){
	uint8_t i, j;

	for(i = 0; i < HEIGHT ;i++){
		for(j = 0; j < WIDTH; j++){
			grid[i][j] = 0;
		}
	}

 }

  void Grid::EraseTmpGrid(){
	uint8_t i, j;

	for(i = 0; i < HEIGHT ;i++){
		for(j = 0; j < WIDTH; j++){
			tmpGrid[i][j] = 0;
		}
	}

 }

void Grid::WriteToGrid(Shape *shape){
	uint8_t i, j;
	//sprintf(strText," wg %i", form.width); puts(strText); 
	//util.nop_delay(5000);
	//EraseGrid();
	
	Form *form = shape->GetCurrentForm();
	for(i = 0; i < form->width ;i++){
		for(j = 0; j < form->width ; j++){
			
			if(form->array[i][j]==1) {
				sprintf(strText," wg %i, %i, %i", form->row, form->col, form->width); puts(strText); 
				//util.nop_delay(5000);
				grid[form->row+i][form->col+j] = (form->array[i][j]==1 || grid[form->row+i][form->col+j]==1);
				//console.gotoxy(20+i*2,5+j);sprintf(strText,"%i", (uint8_t)form->array[i][j]); puts(strText);
				console.gotoxy(20+i*2,5+j);console.cputc((char)(form->array[i][j]));
			}
			//else grid[3+(form->row+i)*COLS+(form->col+j)] = 0;
		}
	}
	
	//sprintf(strText," wg-2"); puts(strText); 
}

 void Grid::DeleteShapedFromGrid(Form *form){
	uint8_t i, j;

	for(i = 0; i < form->width ;i++){
		for(j = 0; j < form->width ; j++){
			
				grid[form->row+i][form->col+j] = 0;
			}			
		}
	}



uint8_t Grid::CheckPosition(Form *form){ 
//Check the position of a form
char **array = form->array;
	uint8_t i, j;

	for(i = 0; i < form->width;i++) {
			//sprintf(strText," p-1"); puts(strText);
			//strText[0]=3;
			//DrawBoardText(strText);
		for(j = 0; j < form->width ;j++){
			//sprintf(strText," p-2");
			//DrawBoardText(strText);
			//sprintf(strText," wg %i, %i, %i", form->row, form->col, form->width); puts(strText); 

			if((form->col+j < 0 || form->col+j >= WIDTH || form->row+i >= HEIGHT)){ //Out of borders
				//console.gotoxy(20,0);sprintf(strText," CK %i %i ", form->col+j,form->row+i  ); puts(strText);
				//strText[0]=3;
				//DrawBoardText(strText);
				if(array[i][j]==1) 
					return 0;
				
			}
			else if((grid[form->row+i][form->col+j]==1) && (array[i][j]==1)){
				sprintf(strText," wg - if %i, %i, %i, %i, %i, %i", grid[form->row+i][form->col+j], array[i][j],i,j, form->row+i, form->col+j); puts(strText); 
				return 0;
			}
		}
	}
	return 1;
}

void Grid::DeleteRows(){
	uint8_t i, j, sum, pt=0;

	for(i=0;i<HEIGHT;i++){
		sum = 0;
		for(j=0;j< WIDTH;j++) {
			sum+=grid[i][j];
		}
		if(sum==WIDTH){
			pt++;
			int l, k;
			for(k = i;k >=1;k--)
				for(l=0;l<WIDTH;l++)
					grid[k][l]=grid[k-1][l];
			for(l=0;l<WIDTH;l++)
				grid[k][l]=0;
		}
	}
	// return count of rows to calculate the score
	score.AddScore(pt);
}

void Grid::ManipulateCurrent(uint8_t key, Shape *shape){
	
	Form *temp = shape->GetCurrentTempForm(); 
	Form *current = shape->GetCurrentForm(); 
	
	//srand(1);
	//sprintf(strText," MC-2"); puts(strText); 

	// delete the current shape from grid
	//DeleteShapedFromGrid(current);

	switch(key){
		case 's':
		case 'S':
			//sprintf(strText," s-1"); puts(strText); 
			shape->incRowTemp();  //move down
			console.gotoxy(25,10);console.cputc('s');
			if(CheckPosition(temp)) {
				shape->incRowArray();
				console.gotoxy(25,10);console.cputc('S');
				//shape->CopyFormToForm(0);
			}
			else {
				shape->decRowTemp(); 

				WriteToGrid(shape);
				DeleteRows();
				int rnd = 3;
    			shape->RandomForm(rnd); //updates new shape	
				//WriteToGrid(shape);
				//DrawGrid();
				//return;
				//WriteToGrid(current);
				//DeleteRows();
                //shape.RandomForm(rand()%7);
				//sprintf(strText,"manipulate s-1");
				//DrawBoardText(strText);
			}
			//sprintf(strText," s-2"); puts(strText);
			//strText[0]=3;
			//DrawBoardText(strText);

			//current.row++;
			//WriteToGrid(current);
			//sprintf(strText,"manipulate s-3"); puts(strText); 
			//DrawBoardText(strText);
			break;
		case 'd':
		case 'D':
			shape->incColTemp();   //move right
			console.gotoxy(25,10);console.cputc('d');
			if(CheckPosition(temp)){
				shape->incColArray();
				console.gotoxy(25,10);console.cputc('D');
				//sprintf(strText," col %i",shape->GetCurrentForm()->col); puts(strText);
				//shape.CopyFormToForm(0);
				//WriteToGrid(current);
			}
			else shape->decColTemp(); 
			break;
		case 'a':
		case 'A':
			shape->decColTemp(); //move left
			console.gotoxy(25,10);console.cputc('a');
			if(CheckPosition(temp)){
				shape->decColArray();
				console.gotoxy(25,10);console.cputc('A');
				//shape.CopyFormToForm(0);
				//WriteToGrid(current);
			} 
			else shape->incColTemp(); 
			
			break;
		case 'w':
		case 'W':
			shape->RotateForm(0); // rotate clockwise temp
			console.gotoxy(25,10);console.cputc('w');
			if(CheckPosition(temp)){
				shape->RotateForm(1); 
				console.gotoxy(25,10);console.cputc('W');
			}
			shape->CopyFormToForm(1);
			break;
	}
	//shape.CopyFormToForm(1);
	//WriteToGrid(shape);
	DrawGrid(shape);
}

void Grid::DrawGrid(Shape *shape){
	int width, col, row;
	char ** array;
	uint8_t i, j;

	width = shape->GetCurrentForm()->width;
	col = shape->GetCurrentForm()->col;
	row = shape->GetCurrentForm()->row;
	array = shape->GetCurrentForm()->array;

	
	EraseMap();
	EraseTmpGrid();

	for(i = 0; i < width ;i++){
		for(j = 0; j < width ; j++){
			if(array[i][j]==1)
				tmpGrid[row+i][col+j] = array[i][j];
		}
	}

	for(i = 0; i < HEIGHT ;i++){
		for(j = 0; j < WIDTH ; j++){
				map[3+(row+i)*WIDTH+col+j] = grid[row+i][col+j] || tmpGrid[row+i][col+j];
		}
	}

	#ifdef DEBUG
	console.gotoxy(0,0);
	for(i = 0; i < HEIGHT ;i++){
		for(j = 0; j < WIDTH ; j++){
			//sprintf(strText,"%c ", (const char *)grid[3+j*ROWS+i]); puts(strText); 
			console.cputc(map[3+i*WIDTH+j]+48);
		}
		console.cputc('\r');
	}
	sprintf(strText," Score:  %i00", score.GerScore()); puts(strText); 
	#else
	graphic.SetCurrentTileMap((unsigned char *)&map[0], 0,0);
	graphic.DrawTileMap(0, 0, WIDTH*16, HEIGHT*16);

	#endif

}



void Grid::DrawBoardText(char * str){

    graphic.SetSolidFlag(1);
    graphic.SetColor(COLOR_WHITE);
    graphic.Gfx_DrawString(290,1,str);

}
