#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cstdint>
#include <stdlib.h>
#include "costant.hpp"

typedef struct {
    char **array;
    int width, row, col;
} Form;

class Shape {

private:


uint8_t currentForm;

Form formArray[7]= {
	{(char *[]){(char []){0,1,1},(char []){1,1,0}, (char []){0,0,0}}, 3},                              
	{(char *[]){(char []){1,1,0},(char []){0,1,1}, (char []){0,0,0}}, 3},                             
	{(char *[]){(char []){0,1,0},(char []){1,1,1}, (char []){0,0,0}}, 3},                               
	{(char *[]){(char []){0,0,1},(char []){1,1,1}, (char []){0,0,0}}, 3},                               
	{(char *[]){(char []){1,0,0},(char []){1,1,1}, (char []){0,0,0}}, 3},                              
	{(char *[]){(char []){1,1},(char []){1,1}}, 2},                                                 
	{(char *[]){(char []){0,0,0,0}, (char []){1,1,1,1}, (char []){0,0,0,0}, (char []){0,0,0,0}}, 4}
};

Form tempArray[7]= {
	{(char *[]){(char []){0,1,1},(char []){1,1,0}, (char []){0,0,0}}, 3},                              
	{(char *[]){(char []){1,1,0},(char []){0,1,1}, (char []){0,0,0}}, 3},                             
	{(char *[]){(char []){0,1,0},(char []){1,1,1}, (char []){0,0,0}}, 3},                               
	{(char *[]){(char []){0,0,1},(char []){1,1,1}, (char []){0,0,0}}, 3},                               
	{(char *[]){(char []){1,0,0},(char []){1,1,1}, (char []){0,0,0}}, 3},                              
	{(char *[]){(char []){1,1},(char []){1,1}}, 2},                                                 
	{(char *[]){(char []){0,0,0,0}, (char []){1,1,1,1}, (char []){0,0,0,0}, (char []){0,0,0,0}}, 4}
};


public:

void CopyArrayToTemp();

void CopyTempToArray();

void RandomForm(uint8_t rnd);

void RotateFormArray();

void RotateFormTemp();

Form GetCurrentForm();

Form GetCurrentTempForm();


};

#endif //SHAPE_HPP