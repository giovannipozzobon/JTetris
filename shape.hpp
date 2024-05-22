#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cstdint>
#include <stdlib.h>
#include "costant.hpp"
#include "console.hpp"

typedef struct {
    char **array;
    int width, row, col;
} Form;

class Shape {

private:

Console console;
char strText[40];

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

void CopyFormToForm(uint8_t tmp);


void RandomForm(uint8_t rnd);

void RotateFormArray();

void RotateForm(uint8_t tmp);

Form * GetCurrentForm();

Form * GetCurrentTempForm();

void printShape();

void incColTemp();
void incRowTemp();

void incColArray();
void incRowArray();

void decColTemp();
void decRowTemp();

void decColArray();
void decRowArray();

};

#endif //SHAPE_HPP