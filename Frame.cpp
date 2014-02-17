/*
Devan Tatum
Frame Object class
*/
#include "Frame.h";

int counter = 0;
//constructor
Frame::Frame(int initSize, char initVal){
	val = initVal;
	size = initSize;
}

//destructor
Frame::~Frame(){
	delete[];
}

int Frame::getPageNumber(){
	return size;
}

char Frame::getVal(){
	return val;
}