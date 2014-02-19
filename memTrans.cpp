//Memory Translation for CS470 @ CWU

/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
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
#define FILENAME "BACKING_STORE"

//0-255, because arrays
const int FRAME_SIZE = 255;

//initialize a blank TLB here
TLB working_tlb;
PageTable ptable;

//all the cool kids are shifting
unsigned int getPageNum(unsigned int vaddr){	
	return (vaddr & P_MASK) >> P_SHIFT;
}
//...or masking
unsigned int getPageOff(unsigned int vaddr){
	return (vaddr & O_MASK);
}

//gets the array of values to put into the page table
signed int *getFrameDat(unsigned int x){
	std::ifstream infile;
	infile.open(FILENAME, std::ifstream::binary);
	if(infile.is_open()){
		char value[255];
		signed int v[255];
		// go to the page where info is stored
		infile.seekg(((x-1)*256));
		infile.read(value,256);

		infile.close();
		//this is a shameless hack, implicit casting ftw
		for(int j=0;j<256;j++){
			v[j] = value[j];
		}
		return v;	
	} else {
		return NULL;
	}
}

signed int getValue(unsigned int x){
  
	unsigned int pageNum = getPageNum(x) + 1;
	unsigned int offset = getPageOff(x);

 	//cout << pageNum;
	if(working_tlb.check(pageNum)){
		//need more things here, like returning the actual physical address
		return (ptable.getValue(working_tlb.getFrameNumber(pageNum), offset));
	}
	else if(ptable.checkPageTable(pageNum)){
		//if in the page table, return the physical address
		working_tlb.addEntry(pageNum, ptable.getFrameNumber(pageNum));
		return (ptable.getValue(ptable.getFrameNumber(pageNum), offset));
	}
	else if((!(ptable.checkPageTable(pageNum)) && !(working_tlb.check(pageNum)))){
		//up the page fault counter
		Frame f;
		f.setVal(getFrameDat(pageNum));
		f.setPageNumber(pageNum);
		ptable.addEntry(f);
		ptable.incCounter();
		working_tlb.addEntry(pageNum, ptable.getFrameNumber(pageNum));
		return (ptable.getValue(ptable.getFrameNumber(pageNum), offset));
	}
}
		

int getPhysicalAddr(unsigned int x){

	unsigned int pageNum = getPageNum(x) + 1;
	unsigned int offset = getPageOff(x);

	return ((ptable.getFrameNumber(pageNum)-1) * 256) + offset;
}

int main(int argc, char* argv[]){
	size_t pos = 0;
	int count = 0;

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

		if(fOut != 0){
		    count++;
			signed int value = getValue(fOut);

			cout << "Virtual address: " << fOut << " ";
			cout << "Physical address: " << getPhysicalAddr(fOut) << " ";
			cout << "Value: " << value << std::endl;
		}
		fOut = 0;
	}

	//close the damn reader
	fRead.close();
	//output needed statistics
	cout << "Number of Translated Addresses = " << count << std::endl;
	cout << "Page faults = " << ptable.getCounter() << std::endl;
	cout << "Page Fault Rate = " << ((double)ptable.getCounter()/(double)count) << std::endl;
	cout << "TLB hits = " << working_tlb.getHits() << std::endl;
	cout << "TLB Hit Rate = = " << ((double)working_tlb.getHits()/(double)count) << std::endl;
	
	//cout << "All Done <(^_^)^" << std::endl;
	return 0;
  }

