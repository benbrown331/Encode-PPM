#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ppm.h"


	

//reads in the header of a ppm file
 header_t readHeader(FILE* infile){
	header_t ppmh;

	//work in progress
	//ckws_comments(infile);	
	fscanf(infile, "%s %d%d%d ", ppmh.magicNum, &ppmh.width, &ppmh.height, &ppmh.maxVal);
	
       return ppmh;	

 }//end readHeader	


//reads in values of the pixels inside the ppm image and dynamically allocates memory for a 2D array
 pixel_t** readPixel(FILE* infile, header_t ppmh){

	pixel_t** data = memoryAllocation(ppmh);
	for (int i=0; i<ppmh.height;i++) {	
	    for(int j = 0; j < ppmh.width; j++){
		fscanf(infile, "%c%c%c", &data[i][j].r, &data[i][j].g, &data[i][j].b);
	    }
	}
	return data;	
 }//end readPixel	 


//writes the header to the output ppm file
void writeHeader(FILE* outfile, header_t ppmh){
	fprintf(outfile, "%s\n%d %d %d\n", ppmh.magicNum, ppmh.width, ppmh.height, ppmh.maxVal);
}	


void writePixels(FILE* outfile, pixel_t** data, header_t ppmh){
	for(int i = 0; i < ppmh.height; i++){
	   for(int j = 0; j < ppmh.width; j++){
	      fprintf(outfile, "%c%c%c", data[i][j].r, data[i][j].g, data[i][j].b);
	   }
	}
	//freeMemory(data,ppmh);	
}	

void freeMemory(pixel_t** data, header_t ppmh){
	/*
	for(int i = 0; i < ppmh.height; i++){
	   for(int j = 0; j < ppmh.width; j++){
	   	free(&data[i][j].r);
	  	free(&data[i][j].g);
	        free(&data[i][j].b);	
	   }
	}
	*/
	for (int i=0; i<ppmh.height; i++) {
		free(data[i]);
	}
	free(data);
}

pixel_t** memoryAllocation(header_t ppmh) {

	pixel_t** data = (pixel_t**)malloc(sizeof(pixel_t*) * ppmh.height);
	for(int i = 0; i < ppmh.height; i++){
		data[i] = (pixel_t*)malloc(sizeof(pixel_t) * ppmh.width);
	}

	return data;
}
//needs tweaking
/*
void ckws_comments(FILE* infile){
	char c;
	c = getc(infile);
	while(c == '#'){
             do{
		c = getc(infile);
	     }while(c != '\n');
	    c = getc(infile);	     
	}
	ungetc(c, infile);
}*/
