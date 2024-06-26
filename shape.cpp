#include "shape.hpp"


void Shape::RandomForm(uint8_t rnd){ //updates new shape

    currentForm = rnd;
    //formArray[currentForm].col = rand()%(COLS-formArray[currentForm].width+1);
	formArray[currentForm].col = 5;
    formArray[currentForm].row = 0;
	tempArray[currentForm].col = formArray[currentForm].col;
    tempArray[currentForm].row = 0;

}

void Shape::RotateFormArray(){ //rotates clockwise
	uint8_t i, j, k, width;
	width = formArray[currentForm].width;
	for(i = 0; i < width ; i++){
		for(j = 0, k = width-1; j < width ; j++, k--){
				formArray[currentForm].array[i][j] = tempArray[currentForm].array[k][i];
		}
	}
}

// If tmp = 1 then rotate formArray 
// If tmp = 0 then rotate tempArray
void Shape::RotateForm(uint8_t tmp){ //rotates clockwise tempForm or ArrayForm 
	uint8_t i, j, k, width;
	Form *tmp1, *tmp2;

	if (tmp == 1){
		tmp1 = formArray;
		tmp2 = tempArray;
	}
	else {
		tmp1 = tempArray;
		tmp2 = formArray;

	}
	CopyFormToForm(tmp);
	width = tmp1[currentForm].width;
	for(i = 0; i < width ; i++){
		for(j = 0, k = width-1; j < width ; j++, k--){
				tmp1[currentForm].array[i][j] = tmp2[currentForm].array[k][i];
		}
	}
}

// If tmp = 0 then copy from Temp to Array 
// If tmp = 1 then copy from  Array to Temp 
void Shape::CopyFormToForm(uint8_t tmp){
    uint8_t i, j;
	Form *tmp1, *tmp2;

	// Copy from Temp to Array
	if (tmp == 0){
		tmp1 = formArray;
		tmp2 = tempArray;
	}
	else { // Copy from Array to Temp
		tmp1 = tempArray;
		tmp2 = formArray;

	}
    for(i = 0; i < tmp1[currentForm].width; i++){
		for(j=0; j < tmp1[currentForm].width; j++) {
			tmp1[currentForm].array[i][j] = tmp2[currentForm].array[i][j];
		}
    }

}

Form * Shape::GetCurrentForm(){ return &formArray[currentForm];}

Form * Shape::GetCurrentTempForm(){ return &tempArray[currentForm];}

void Shape::printShape(){
	sprintf(strText,"shape CU %i W %i ", currentForm, formArray[currentForm].width); puts(strText); 
	sprintf(strText,"shape C %i R %i ", formArray[currentForm].col, formArray[currentForm].row); puts(strText); 

	for(uint8_t i = 0; i < formArray[currentForm].width ;i++){
		for(uint8_t j = 0; j < formArray[currentForm].width ; j++){
			//sprintf(strText,"%c ", (const char *)grid[3+j*ROWS+i]); puts(strText); 
			//sprintf(strText,"%c", formArray[currentForm].array[i][j]+48); puts(strText);
			console.cputc(formArray[currentForm].array[i][j]+48);
		}
		//puts(" ");
	}

}
	
void Shape::incColTemp(){tempArray[currentForm].col++;}
void Shape::incRowTemp(){tempArray[currentForm].row++;}

void Shape::incColArray(){formArray[currentForm].col++;}
void Shape::incRowArray(){formArray[currentForm].row++;}

void Shape::decColTemp(){tempArray[currentForm].col--;}
void Shape::decRowTemp(){tempArray[currentForm].row--;}

void Shape::decColArray(){formArray[currentForm].col--;}
void Shape::decRowArray(){formArray[currentForm].row--;}
