/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

*/

#include "Frame.h";

//constructor, yo
Frame::Frame(int initSize, char initVal){
	val = initVal;
	size = initSize;
}

//destructor, yo
Frame::~Frame(){
	delete[];
}

int Frame::getPageNumber(){
	return size;
}

char Frame::getVal(){
	return val;
}