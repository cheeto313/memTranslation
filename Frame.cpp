/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

*/

#include "Frame.h"

//blank constructor, yo
Frame::Frame(){
	//initialize to 0 so it can checked
	this->val[255];
	this->pagenum = 0;
}

//destructor, yo
Frame::~Frame(){}

//getters and setters, yay!
int Frame::getPageNumber(){
	return this->pagenum;
}

signed int Frame::getVal(unsigned int x){
	return this->val[x];
}

void Frame::setVal(signed int x[]){
	//copy the array to the frame char array
	for (int j=0; j<256; j++){
		this->val[j] = x[j];
	}	
}

void Frame::setPageNumber(int x){
	this->pagenum = x;
}