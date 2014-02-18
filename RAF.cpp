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

		char value[sizeof(num)];
		// read from byte 100
		infile.seekg(100);
		infile.read(value,sizeof(num));

		// output value
		printf("%02d\n", ((const unsigned char*)value)[0]&0xff);

		infile.close();
	}
	
//virtua address to get the physical address

}



