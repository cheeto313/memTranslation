/*
Devan Tatum
TLB Class, but you already knew that...so why are you here?
Meant to simulate the TLB and physical memory, NEED to add the functionality of RAF.cpp
for this to work 
*/

/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

*/

#include <unordered_map>
#include "TLB.h"

typedef std::unordered_map<>

//blank constructor
TLB::TLB (){
	int counter = 0;
	unordered_map <unsigned int, unsigned int> tlb;
}

unsigned int getFrameNumber(unsigned x){
	return tlb[x];
}

int getHits(){
	return counter;
}

void addEntry(unsigned int pnum, unsigned int fnum){
	tlb[pnum] = fnum;
}

bool check(unsigned int pnum){
	if(tlb[pnum] != NULL){
		//increment counter and return true! It is here!
		counter++;
		return true;
	} else {
		return false;
	}
}
