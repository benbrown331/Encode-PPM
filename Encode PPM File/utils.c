#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

//This function should make sure the user entered
	//the proper number of command line args
void checkArgs(int argc, int b){
	if(argc != b)
		printf("Not valid number of arguments! Only 2 ppm files required");
	exit(0);
	
}

//This function should check to see if the 
	//file opened correctly
void checkFile(FILE* infile){
	if(infile == NULL)
		fprintf(stderr, "[ERROR]: file pointer is NULL");
	exit(0);
}	

