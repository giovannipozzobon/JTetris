
#include "grid.hpp"




Grid::Grid(){
	grid[0] = 1;
	grid[1] = ROWS;
	grid[2] = COLS;

}

void Grid::WriteToGrid(Form form){
	int i, j;
	//sprintf(strText," wg %i", form.width); puts(strText); 
	//util.nop_delay(5000);
	for(i = 0; i < form.width ;i++){
		for(j = 0; j < form.width ; j++){
			
			if(form.array[i][j]) {
				//sprintf(strText," wg %i", form.array[i][j]); puts(strText); 
				//util.nop_delay(5000);
				grid[3+(form.row+i)+(form.col+j)*ROWS] = form.array[i][j];
			}
		}
	}
	//sprintf(strText," wg-2"); puts(strText); 
}

uint8_t Grid::DeleteRows(){
	int i, j, sum, score=0;

	for(i=0;i<ROWS;i++){
		sum = 0;
		for(j=0;j< COLS;j++) {
			sum+=grid[3+j*ROWS+i];
		}
		if(sum==COLS){
			score++;
			int l, k;
			for(k = i;k >=1;k--)
				for(l=0;l<COLS;l++)
					grid[3+k*l]=grid[3+((k-1)*l)];
			for(l=0;l<COLS;l++)
				grid[3+k*l]=0;
		}
	}
	// return count of rows to calculate the score
	return score;
}

void Grid::ManipulateCurrent(uint8_t key, Shape shape){
	
	//sprintf(strText," MC-1"); puts(strText); 
	Form temp = shape.GetCurrentTempForm(); 
	Form current = shape.GetCurrentForm(); 
	srand(1);
	//sprintf(strText," MC-2"); puts(strText); 

	switch(key){
		case 's':
		case 'S':
			//sprintf(strText," s-1"); puts(strText); 
			temp.row++;  //move down
			if(CheckPosition(temp))
				current.row++;
			else {
				//WriteToGrid(current);
				//DeleteRows();
                //shape.RandomForm(rand()%7);
				//sprintf(strText,"manipulate s-1");
				//DrawBoardText(strText);
			}
			//sprintf(strText," s-2"); puts(strText);
			//strText[0]=3;
			//DrawBoardText(strText);

			current.row++;
			WriteToGrid(current);
			//sprintf(strText,"manipulate s-3"); puts(strText); 
			//DrawBoardText(strText);
			break;
		case 'd':
		case 'D':
			temp.col++;  //move right
			if(CheckPosition(temp))
				current.col++;
			break;
		case 'a':
		case 'A':
			temp.col--;  //move left
			if(CheckPosition(temp))
				current.col--;
			break;
		case 'w':
		case 'W':
			shape.RotateForm(1); // rotate clockwise temp
			if(CheckPosition(temp))
				shape.CopyFormToForm(0); // copy temp to Array
			break;
	}
	DrawGrid();
}

void Grid::DrawGrid(){
	
	//sprintf(strText," DG-1"); puts(strText); 
	//graphic.SetCurrentTileMap((unsigned char *)&grid[0], 0,0);
	//graphic.DrawTileMap(0, 0, COLS*16, ROWS*16);

	for(int i = 0; i < ROWS ;i++){
		for(int j = 0; j < COLS ; j++){
			//sprintf(strText,"%c ", (const char *)grid[3+j*ROWS+i]); puts(strText); 
			console.cputc(grid[3+j*ROWS+i]+48);
		}
		puts(" ");
	}


}

int Grid::CheckPosition(Form form){ 
//Check the position of a form
char **array = form.array;
	int i, j;
	for(i = 0; i < form.width;i++) {
			//sprintf(strText," p-1"); puts(strText);
			//strText[0]=3;
			//DrawBoardText(strText);
		for(j = 0; j < form.width ;j++){
			//sprintf(strText," p-2");
			//DrawBoardText(strText);
			if((form.col+j < 0 || form.col+j >= COLS || form.row+i >= ROWS)){ //Out of borders
				sprintf(strText," p-3"); puts(strText);
				//strText[0]=3;
				//DrawBoardText(strText);
				if(array[i][j]) 
					return 0;
				
			}
			else if(grid[3+(form.row+i)*(form.col+j)] && array[i][j])
				return 0;
		}
	}
	return 1;
}


void Grid::DrawBoardText(char * str){

    graphic.SetSolidFlag(1);
    graphic.SetColor(COLOR_WHITE);
    graphic.Gfx_DrawString(290,1,str);

}