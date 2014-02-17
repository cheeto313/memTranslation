/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

 */

#ifndef TLB_H
#define TLB_H
class TLB{
	public:
		TLB ();
		unsigned int getFrameNumber(unsigned int);
		bool check(unsigned int);
		void addEntry(unsigned int);
	private:
		unordered_map <unsigned int, unsigned int> tlb;
};

#endif