//Memory Translation for CS470 @ CWU
//Devan Tatum, Neil Turnley

#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
//for file input-output
using std::ifstream;

int main(int argc, char* arg[]){

	bool inputOk = false;
	string ext = ".txt";
	string input;
	string fOutput;

	//input validation, make sure that it cannot sontinue without a file
	//you spin me right round round right round...
	while (!inputOk){
	    cout << "Enter the name of text file (*.txt): ";
	    cin >> input;
	      
	    if ((input.find(ext) != std::string::npos) ){
	        inputOk = true;
	    }
	} 

	ifstream fRead(input);

	while(!fRead.eof()){
		getline (fRead,fOutput);
		cout << fOutput << std::endl;
	}
	//close the damn reader
	fRead.close();

	std::cout << "Derp Derp Derp";
	return 0;
}

