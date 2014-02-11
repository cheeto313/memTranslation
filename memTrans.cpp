//Memory Translation for CS470 @ CWU
//Devan Tatum, Neil Turnley

#include <iostream>
#include <fstream>

//std stuff, because "using namspace std" is just lazy
using std::string;
using std::cout;
using std::cin;
using std::ifstream;

int main(int argc, char* arg[]){

	size_t pos = 0;
	bool inputOk = false;
	int count = 5;
	string ext = ".txt";
	string input;
	string fOutput;
	string temp;

	//input validation, make sure that it cannot sontinue without a file
	//you spin me right round round right round...
	while (!inputOk){
	    cout << "Enter the name of text file (*.txt) w/ the goods yo: ";
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

	//herp
	system("PAUSE");
	return 0;
}

