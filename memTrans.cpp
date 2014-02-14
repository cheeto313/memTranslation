//Memory Translation for CS470 @ CWU
//Devan Tatum, Neil Turnley

#include <iostream>
#include <fstream>
#include <sstream>

//std stuff, because "using namspace std" is just lazy
using std::string;
using std::cout;
using std::cin;
using std::ifstream;
using std::istringstream;
using std::cerr;

#define FRAME_NUM 256
#define FRAME_SIZE 256
#define TLB_SIZE 16
#define MEM_SIZE 65536
#define P_MASK 0xff00
#define O_MASK 0xff
#define P_SHIFT 8

//all the cool kids are shifting
unsigned int getPageNum(unsigned int vaddr){
	return (vaddr & P_MASK) >> P_SHIFT;
}

unsigned int getPageOff(unsigned int vaddr){
	return (vaddr & O_MASK);
}

int main(int argc, char* argv[]){

	size_t pos = 0;
	bool inputOk = false;
	int count = 5;
	string input;
	string fOutput;

	//input validation, make sure that it cannot sontinue without a file
	//you spin me right round round right round...
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
		cout << fOut << std::endl;
	}
	//close the damn reader
	fRead.close();
	return 0;
}
