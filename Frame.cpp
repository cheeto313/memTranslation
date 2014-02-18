/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

*/

#include "Frame.h"

//blank constructor, yo
Frame::Frame(){
	//initialize to 0 so it can checked
	this->val = 0;
	this->size = 0;
}

//destructor, yo
Frame::~Frame(){
	//delete[];
}

//getters and setters, yay!
int Frame::getPageNumber(){
	return this->size;
}

char Frame::getVal(){
	return this->val;
}

void Frame::setVal(char x){
	val = x;
}

void Frame::setSize(int x){
	size = x;
}