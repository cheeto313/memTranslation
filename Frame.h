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
		char getVal();
		void setVal(char);
		void setSize(int);
	private:
		char val;
		int size;
};

#endif