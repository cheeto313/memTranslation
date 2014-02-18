/*
 * RAF.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: janvik@cs2k3.cwu.edu
 */

#include <iostream>
#include <cstdlib>
#include <fstream>

#define FILENAME "BACKING_STORE"

int main(int argc, char **argv) {
	if(argc < 2){
		std::cout << "Usage: raf <integer>" << std::endl;
		exit(EXIT_FAILURE);
	}

	int num = atoi(argv[1]);

	std::ifstream infile;
	infile.open(FILENAME, std::ifstream::binary);
	if(infile.is_open()){

		char value[256];
		// read from byte 100
		infile.seekg((num*256));
		infile.read(value,256);

		for (int n=0; n<256; n++) {
   		 // output value
		printf("Offset %d = ", n);
		printf("%d\n", ((signed int)value[n]));

		}

		infile.close();
	}
	
//virtua address to get the physical address

}



