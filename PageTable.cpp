/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

*/

#include "PageTable.h"
#include "Frame.h"

//constructor and destructor, no trogdor
PageTable::PageTable(){
	this->page_table[256];
	this->counter = 0;
}

PageTable::~PageTable(){}

bool PageTable::checkPageTable(int x){

	for(int j=1; j<257; j++){
		if((page_table[j].getPageNumber()) == x){
			return true;
		} 
	}
	return false;
}

int PageTable::getCounter(){
	return counter;
}

int PageTable::getFrameNumber(int x){
	for (int j=1; j<257; j++){
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
	for(int j=1; j<257; j++){
	  
		if((page_table[j].getPageNumber()) == 0){
		  
			page_table[j] = n;
			//exit the loop
			j = 257;
		}
	}
}

void PageTable::incCounter(){
	counter++;
}
