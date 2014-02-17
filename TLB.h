/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

 */

#ifndef TLB_H
#define TLB_H
class TLB{
	public:
		TLB (unsigned int, unsigned int);
		unsigned int getFrameNumber(unsigned int);
	private:
		unsigned int pageNumber;
		unsigned int frameNumber;
};

#endif