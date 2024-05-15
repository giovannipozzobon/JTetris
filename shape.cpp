#include "shape.hpp"


void Shape::RandomForm(uint8_t rnd){ //updates new shape

    currentForm = rnd;
    formArray[currentForm].col = rand()%(COLS-formArray[currentForm].width+1);
    formArray[currentForm].row = 0;

}

void Shape::RotateFormArray(){ //rotates clockwise
	int i, j, k, width;
	width = formArray[currentForm].width;
	for(i = 0; i < width ; i++){
		for(j = 0, k = width-1; j < width ; j++, k--){
				formArray[currentForm].array[i][j] = tempArray[currentForm].array[k][i];
		}
	}
}

void Shape::RotateFormTemp(){ //rotates clockwise
	int i, j, k, width;
	width = formArray[currentForm].width;
	for(i = 0; i < width ; i++){
		for(j = 0, k = width-1; j < width ; j++, k--){
				tempArray[currentForm].array[i][j] = formArray[currentForm].array[k][i];
		}
	}
}

void Shape::CopyArrayToTemp(){
    int i, j;
    for(i = 0; i < formArray[currentForm].width; i++){
		for(j=0; j < formArray[currentForm].width; j++) {
			tempArray[currentForm].array[i][j] = formArray[currentForm].array[i][j];
		}
    }

}

void Shape::CopyTempToArray(){
    int i, j;
    for(i = 0; i < formArray[currentForm].width; i++){
		for(j=0; j < formArray[currentForm].width; j++) {
			formArray[currentForm].array[i][j] = tempArray[currentForm].array[i][j];
		}
    }

}

Form Shape::GetCurrentForm(){ return formArray[currentForm];}

Form Shape::GetCurrentTempForm(){ return tempArray[currentForm];}
