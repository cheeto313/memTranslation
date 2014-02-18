/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

 */

#ifndef TLB_H
#define TLB_H
#include <unordered_map>
#include <queue>

class TLB{
	public:
		TLB ();
		~TLB();
		unsigned int getFrameNumber(unsigned int);
		int getHits();
		bool check(unsigned int);
		void addEntry(int, int);
		void cleanEntries();
	private:
		std::unordered_map <int, int> tlb;
		std::queue<int> track;
		int counter;
};

#endif