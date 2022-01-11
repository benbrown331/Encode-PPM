#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ppm.h"
#include "EncodeDecode.h"


//Remove the last digit from each pixel, in order
	//to add each binary value afterwards
void removeDigit(pixel_t **data, header_t ppmh){
	for(int i = 0; i < ppmh.height; i++){
	   for(int j = 0; j < ppmh.width; j++){
	   	data[i][j].r = data[i][j].r - data[i][j].r % 10;
		data[i][j].g = data[i][j].g - data[i][j].g % 10;
		data[i][j].b = data[i][j].b - data[i][j].b % 10;
	   }	   
	}	
}//end removeDigit

//This function is primarily responsible for taking a secret message,
	//and encoding it into the given ppm file.
void encodeMsg(FILE* in, FILE* out, char* msg){

	header_t ppmh=readHeader(in);
	pixel_t** data=readPixel(in, ppmh);
	//increments after every 8 bytes
	int charIndex = 0;
	//increments after every binary value
	int bitCounter = 0;
	int lastBytes[9];
	//remove the last digit for each pixel value
	removeDigit(data,ppmh);
	writeHeader(out, ppmh);
	dec2bin(lastBytes,(int)msg[charIndex]);
    int size=strlen(msg);
	while (charIndex<strlen(msg)-1) {
		for (int j=0; j<ppmh.height; j++) {
			for (int k=0; k<ppmh.width; k++) {
				data[j][k].r=data[j][k].r+lastBytes[bitCounter];
				bitCounter++;
				data[j][k].g=data[j][k].g+lastBytes[bitCounter];
				bitCounter++;
				data[j][k].b=data[j][k].b+lastBytes[bitCounter];
				bitCounter++;
				if (bitCounter==9) {
					charIndex++;
                    if(charIndex==size-1) {
                        break;
                    }
                    else {
					dec2bin(lastBytes,(int)msg[charIndex]);
					bitCounter=0;
                    }
				}
			}
			if (charIndex==size-1) {
                break;
            }
		}
	}
	writePixels(out,data,ppmh);
	freeMemory(data,ppmh);
}

//convert the character into a binary number
	//to do this effectively, use an array of integers.
void charToBinary(char c, int* binary){
	
	for(int n = 0; n < 9; n++){
		binary[n]= (c >> n) & 1;
	}
	
}

//convert the given binary array into a decimal number
int bin2dec(int* binary){
	int exp = 0;
	int i;
	int bin = 0;
	for(i = 8 -1; i >=0; i--){
	    bin += binary[i] * pow(2, exp);
	    exp += 1;

	}
	return bin;
		
}

//convert binary aray into ACII char
unsigned char binToCharacter(int* binary){
	//first convert binary to decimal
	 unsigned char c;
        c= (unsigned char)bin2dec(binary);
 	return c; 	 
		
}

//this function is primarily responsible for taking an output file,
	//and decoding the hidden message
void decodeMsg(FILE* in){

	printf("A\n");
	header_t ppmh=readHeader(in);
	pixel_t** data=readPixel(in,ppmh);
	printf("A\n");
	//Get the last digit for each RGB as an int
	unsigned char num;
	int arr[9];
	int index=0;
	printf("A\n");
	for (int i=0; i<ppmh.height; i++) {
		for (int j=0; j<ppmh.width; j++) {
			num=data[i][j].r%10;
			queue(num,arr,&index);
			num=data[i][j].g%10;
			queue(num,arr,&index);
			num=data[i][j].b%10;
			queue(num,arr,&index);
		}
	}
	//freeMemory(data,ppmh);
	printf("B\n");
}

//Add character to binary array if needed.
void queue(int n, int* bin, int* index){

	bin[*index]=n;
	(*index)++;
	if(*index==8) {
		unsigned char c=binToCharacter(bin);
		if (c<256) {
			printf("%c",c);
		}
		*index=0;
	}
}

//convert decimal number to binary
void dec2bin(int* bin, int dec){
 	for(int i = 9; dec > 0; i--){
		bin[i] = dec % 2;
		dec = dec / 2;
	}	
}
