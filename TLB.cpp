/*
Devan Tatum
TLB Class, but you already knew that...so why are you here?

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

*/

#include <unordered_map>
#include <queue>
#include "TLB.h"

using namespace std;

using std::unordered_map;

//blank constructor
TLB::TLB(){
	int counter = 0;
	unordered_map <int, int> tlb;
	queue<int> track;
}

TLB::~TLB(){}

unsigned int TLB::getFrameNumber(unsigned int x){
	//increment counter and return true! It is here!
  
	//shameless hack
	if(counter == 0){
	  counter++;
	}
	counter++;
	return tlb[x];
}

int TLB::getHits(){
	return counter;
}

void TLB::cleanEntries(){
  		
	while(tlb.size() > 16){
		tlb.erase(track.front());
		track.pop();
	}
}

bool TLB::check(unsigned int pnum){
  
	if(tlb[pnum] != 0){
		return true;
	} else {
		return false;
	}
}

//implements FIFO, checks the size and erases the last one if limit is exceeded
void TLB::addEntry(int pnum, int fnum){

	if(!check(pnum)){
	  
		tlb[pnum] = fnum;
		track.push(pnum);
		cleanEntries();

	}
}

/*

*/

