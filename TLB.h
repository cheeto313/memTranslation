/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

 */

#ifndef TLB_H
#define TLB_H
#include <unordered_map>

class TLB{
	public:
		TLB ();
		unsigned int getFrameNumber(unsigned int);
		int getHits();
		bool check(unsigned int);
		void addEntry(unsigned int);
	private:
		std::unordered_map <unsigned int, unsigned int> tlb;
};

#endif