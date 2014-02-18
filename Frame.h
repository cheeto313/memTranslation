/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

 */

#ifndef FRAME_H
#define FRAME_H
class Frame{
	public:
		Frame();
		~Frame();
		int getPageNumber();
		signed int getVal(unsigned int);
		void setVal(signed int[]);
		void setPageNumber(int);
	private:
		signed int val[255];
		int pagenum;
};

#endif