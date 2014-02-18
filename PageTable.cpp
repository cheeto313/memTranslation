/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

class PageTable{
	public:
		PageTable();
		~PageTable();
		bool checkPageTable(int x);
		int getCounter();
		void addEntry();
		void incCoutner();
	private:
		//the index is the page number
		Frame page_table[255];
		int counter = 0;
};

#endif

*/

#include "PageTable.h"
#include "Frame.h"

//constructor and destructor, no trogdor
PageTable::PageTable(){}

PageTable::~PageTable(){}

bool PageTable::checkPageTable(int x){
	for(int j=0; j<=255; j++){
		if((page_table[x].getPageNumber()) == x){
			return true;
		} else {
			return false;
		}
	}
}

int PageTable::getCounter(){
	return counter;
}

int PageTable::getPageNumber(int x){
	for (int j=0; j<=255; j++){
		if((page_table[j].getVal()) == x){
			return j;
		}
	}
}

void PageTable::addEntry(Frame n){
	for(int j=0; j<=255; j++){
		if((page_table[j].getPageNumber()) == 0){
			page_table[j] = n;
		}
	}
}

void PageTable::incCoutner(){
	counter++;
}
