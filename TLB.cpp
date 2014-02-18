/*
Devan Tatum
TLB Class, but you already knew that...so why are you here?

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

*/

#include <unordered_map>
#include "TLB.h"
//diag
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;
//typedef std::unordered_map<>
using std::unordered_map;

//blank constructor
TLB::TLB(){
	int counter = 0;
	unordered_map <int, int> tlb;
	tlb.reserve(16);
}

TLB::~TLB(){}

unsigned int TLB::getFrameNumber(unsigned int x){
	//increment counter and return true! It is here!
	counter++;
	return tlb[x];
}

int TLB::getHits(){
	return counter;
}

//implements FIFO, checks the size and erases the last one if limit is exceeded
void TLB::addEntry(int pnum, int fnum){
	if(tlb.size() < 16){
		tlb[pnum] = fnum;
		cout << "add" << tlb.size() << endl;
	} else {
		this->tlb.erase(tlb.begin());
		cout << "erase" << tlb.size() << endl;
		tlb[pnum] = fnum;
	}
}

bool TLB::check(unsigned int pnum){
	if(tlb[pnum] != 0){
		return true;
	} else {
		return false;
	}
}
