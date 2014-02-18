//Memory Translation for CS470 @ CWU

/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

 */

#include <iostream>
#include <fstream>
#include <sstream>
//our classes
#include "Frame.h"
#include "TLB.h"
#include "PageTable.h"

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

//uncomment if no class for page table
//the index is the page number
//Frame page_table[FRAME_SIZE];

//initialize a blank TLB here
TLB working_tlb;
PageTable page_table;

//all the cool kids are shifting
unsigned int getPageNum(unsigned int vaddr){
	return (vaddr & P_MASK) >> P_SHIFT;
}
//...or masking
unsigned int getPageOff(unsigned int vaddr){
	return (vaddr & O_MASK);
}

char getPhysicalAddr(unsigned int x){
	if(working_tlb.check(x)){
		//need more things here, like returning the actual physical address
		return (working_tlb.getFrameNumber(x));
	}
	else if(page_table.checkPageTable(x)) {
		//if in the page table, return the physical address
		return (page_table.getVal(x));
	} else {
		//up the page fault counter
		
		/*
		read from backing store
		return to page table
		put it into a frame index
		tlb pulls from page table
		*/
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
	cout << "TLB Hit Count is: " << working_tlb.getHits() << std::endl;
	cout << "Page Fault Count is: " << page_table.getCounter() << std::endl;

	return 0;
}
