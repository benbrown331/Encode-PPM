#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ppm.h"
#include "utils.h"
#include "EncodeDecode.h"

/*
    * Benjamin Brown
    * This program should take a message from the user
    *   and encode the message into a ppm image, by manipulating each pixel value
    * 
    * The program should also be able to read a ppm file,
    *   and decode the secret message.
    * 
*/


int main(int argc, char* argv[]) {

    //check command line args
    checkArgs(argc, 3);

    //open Input and output file, check for validity
    FILE* in = fopen(argv[1], "r");
    checkFile(in);
    
    FILE* out = fopen(argv[2], "w");
    checkFile(out);

    //This is my test message.  It can be something different /* 
    char* msg = "I hope this works!";   
    encodeMsg(in, out, msg);
    
   FILE* dec = fopen("output.ppm", "r");
    //checkFile(dec);
    decodeMsg(dec);
    fclose(in);
    fclose(out);
    fclose(dec);

    return EXIT_SUCCESS;
}


