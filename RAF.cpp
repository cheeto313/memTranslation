/*
 * RAF.cpp
 *
 *  Created on: Feb 11, 2014
 *      Author: janvik@cs2k3.cwu.edu
 */

#include <iostream>
#include <cstdlib>
#include <fstream>

#define FILENAME "RAFFILE"

int main(int argc, char **argv) {
	if(argc < 2){
		std::cout << "Usage: raf <integer>" << std::endl;
		exit(EXIT_FAILURE);
	}

	int num = atoi(argv[1]);

	std::ofstream outFile;
	outFile.open(FILENAME, std::ofstream::binary);
	if(outFile.is_open()){

		// seek to byte 100
		outFile.seekp(100);

		// write number to file
		outFile.write(reinterpret_cast<const char *>(&num), sizeof(num));

		outFile.close();
	}


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


}



