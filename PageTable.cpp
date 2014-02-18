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

PageTable::~PageTable(){
	//delete[];
}

bool PageTable::checkPageTable(int x){
	if((page_table[x].getVal()) != '0'){
		return true;
	} else {
		return false;
	}
}

int PageTable::getCounter(){
	return counter;
}

char PageTable::getVal(int x){
	return (page_table[x].getVal());
}

void PageTable::addEntry(){
	//add shit here
}

void PageTable::incCoutner(){
	counter++;
}
