/*

This work is solely and completely our own original work. 

{Devan Tatum}

{Neil Turnley}

 */

#ifndef FRAME_H
#define FRAME_H
class Frame{
	public:
		Frame (int, char);
		~Frame();
		char getPageNumber(int);
		int getVal(char);
	private:
		char val;
		int size;
};

#endif