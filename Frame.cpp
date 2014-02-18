/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

*/

#include "Frame.h";

//blank constructor, yo
Frame::Frame(){}

//destructor, yo
Frame::~Frame(){
	delete[];
}

//getters and setters, yay!
int Frame::getPageNumber(){
	return size;
}

char Frame::getVal(){
	return val;
}

void setVal(){
	val = initVal;
}

void setSize(){
	size = initSize;
}