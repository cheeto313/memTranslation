//Memory Translation for CS470 @ CWU

/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "Frame.h"
#include "TLB.h"

//std stuff, because "using namspace std" is just lazy
using std::string;
using std::cout;
using std::cin;
using std::ifstream;
using std::istringstream;
using std::cerr;

#define FRAME_NUM 256
#define TLB_SIZE 16
#define MEM_SIZE 65536
#define P_MASK 0xff00
#define O_MASK 0xff
#define P_SHIFT 8

//0-255, because arrays
const int FRAME_SIZE = 255;
//the index is the page number
Frame page_table[FRAME_SIZE];
//initialize a blank TLB here
TLB workingTLB;

//all the cool kids are shifting
unsigned int getPageNum(unsigned int vaddr){
	return (vaddr & P_MASK) >> P_SHIFT;
}
//...or masking
unsigned int getPageOff(unsigned int vaddr){
	return (vaddr & O_MASK);
}

char getPhysicalAddr(unsigned int x){
	if(workingTLB.check(x)){
		//need more things here, like returning the actual physical address
		return (workingTLB.getFrameNumber(x));
	}
	else if(/* get the page from the page table */) {
		if (/* page fault */){
			/*
			read from backing store
			return to page table
			put it into a frame index
			tlb pulls from page table
			*/
		}
	}
	//diag
	//cout << fOut << std::endl;
}

int main(int argc, char* argv[]){
	size_t pos = 0;
	bool inputOk = false;
	int count = 5;
	string input;
	string fOutput;

	//get the input yo
	if(argc > 1){
		input = argv[1];
	} else {
		cerr << "Failed, usage is memTrans <InputFile> \n";
		exit(EXIT_FAILURE);
	}
	
	ifstream fRead(input);

	while(!fRead.eof()){
		getline(fRead,fOutput);
		istringstream r(fOutput);
		unsigned int fOut;
		r >> fOut;
		//call getPhysical address per laddr read
	}
	//close the damn reader
	fRead.close();
	//output needed statistics
	cout << workingTLB.getHits() << std::endl;
	return 0;
}
