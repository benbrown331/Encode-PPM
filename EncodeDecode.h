#ifndef ENCODEDECODE_H
#define ENCODEDECODE_H

void removeDigit(pixel_t** , header_t );
void encodeMsg(FILE* in, FILE* out, char* msg);
void charToBinary(char , int *);
unsigned char binToCharacter(int*);
void queue(int, int*,int*);
void dec2bin(int*, int);
int bin2dec(int*);
void decodeMsg(FILE*);

#endif
