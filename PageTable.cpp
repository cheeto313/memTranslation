/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

*/

#include "PageTable.h"
#include "Frame.h"

//constructor and destructor, no trogdor
PageTable::PageTable(){
	this->page_table[255];
	this->counter = 0;
}

PageTable::~PageTable(){}

bool PageTable::checkPageTable(int x){
	for(int j=0; j<256; j++){
		if((page_table[x].getPageNumber()) == x){
			return true;
		} 
	}
	return false;
}

int PageTable::getCounter(){
	return counter;
}

int PageTable::getPageNumber(int x){
	for (int j=0; j<256; j++){
		if((page_table[j].getPageNumber()) == x){
			return j;
		}
	}
	return -1;
}

signed int PageTable::getValue(int x, unsigned int y){
	return (signed int)(page_table[x].getVal(y));
}

void PageTable::addEntry(Frame n){
	for(int j=0; j<256; j++){
		if((page_table[j].getPageNumber()) == 0){
			page_table[j] = n;
			j = 256;
		}
	}
}

void PageTable::incCoutner(){
	counter++;
}
