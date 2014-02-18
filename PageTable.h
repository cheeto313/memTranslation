/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

*/

#ifndef PAGETABLE_H
#define PAGETABLE_H
#include "Frame.h"

class PageTable{
	public:
		PageTable();
		~PageTable();
		bool checkPageTable(int x);
		int getCounter();
		char getVal(int);
		void addEntry();
		void incCoutner();
	private:
		//the index is the page number
		Frame page_table[255];
		int counter = 0;
};

#endif