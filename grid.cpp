
#include "grid.hpp"


void Grid::WriteToTable(Form form){
	int i, j;
	for(i = 0; i < form.width ;i++){
		for(j = 0; j < form.width ; j++){
			if(form.array[i][j])
				grid[form.row+i][form.col+j] = form.array[i][j];
		}
	}
}

uint8_t Grid::DeleteRows(){
	int i, j, sum, score=0;

	for(i=0;i<ROWS;i++){
		sum = 0;
		for(j=0;j< COLS;j++) {
			sum+=grid[i][j];
		}
		if(sum==COLS){
			score++;
			int l, k;
			for(k = i;k >=1;k--)
				for(l=0;l<COLS;l++)
					grid[k][l]=grid[k-1][l];
			for(l=0;l<COLS;l++)
				grid[k][l]=0;
		}
	}
	// return count of rows to calculate the score
	return score;
}

void Grid::ManipulateCurrent(uint8_t key, Shape shape, uint8_t){
	Form temp = shape.GetCurrentTempForm(); 
	Form current = shape.GetCurrentForm(); 
	srand(1);


	switch(key){
		case 's':
		case 'S':
			temp.row++;  //move down
			if(CheckPosition(temp))
				current.row++;
			else {
				WriteToTable(current);
				DeleteRows();
                shape.RandomForm(rand()%7);
			}
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
			shape.RotateFormTemp(); // rotate clockwise
			if(CheckPosition(temp))
				shape.CopyTempToArray();
			break;
	}
	PrintGrid();
}

void Grid::PrintGrid(){

}

int Grid::CheckPosition(Form form){ 
//Check the position of a form
char **array = form.array;
	int i, j;
	for(i = 0; i < form.width;i++) {
		for(j = 0; j < form.width ;j++){
			if((form.col+j < 0 || form.col+j >= COLS || form.row+i >= ROWS)){ //Out of borders
				if(array[i][j]) //but is it just a phantom?
					return 0;
				
			}
			else if(grid[form.row+i][form.col+j] && array[i][j])
				return 0;
		}
	}
	return 1;
}