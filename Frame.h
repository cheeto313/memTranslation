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
		char getVal(unsigned int);
		void setVal(char[]);
		void setPageNumber(int);
	private:
		char val[255] = {0};
		int pagenum;
};

#endif