/*
 *	Title: 		1-bit Unsigned Binary Adder With Carry-In.  
 *	Author:		Jonathan Drouillard <jonathan_drouillard@baylor.edu>
 *	Description:
 *		This application creates a function that simulates a 1-bit unsigned integer adder
 *		with carry-in.
 */

#include <iostream>


void OneBitAdder (int Ci, int A0, int B0, int &Co, int &S0);
void Show_Row (int Ci, int A0, int B0, int Co, int S0);
	
using namespace std;

int main()
{
	cout << "Unsigned One Bit Adder" << endl;
	cout << "| Ci | A0 | B0 || Co | S0 |" << endl;
	cout << "|----|----|----||----|----|" << endl;
	
	int Co, S0;
	
	for (int Ci=0; Ci < 2; Ci++)
		for (int A0=0; A0 < 2; A0++)
			for (int B0=0; B0 < 2; B0++)
			{
				OneBitAdder(Ci, A0, B0, Co, S0);
				Show_Row(Ci, A0, B0, Co, S0);
			};
	cin.get(); cin.get();
	return 0;
}

void OneBitAdder (int Ci, int A0, int B0, int &Co, int &S0)
{
	//static int Co_Table [2] [2] [2] = {0,0,0,1,0,1,1,1};
	//static int S0_Table [2] [2] [2] = {0,1,1,0,1,0,0,1};
	
	//Co = Co_Table [Ci] [A0] [B0];
	//S0 = S0_Table [Ci] [A0] [B0];
	//Co = 2;
	Co = (A0&B0)|(Ci&B0)|(Ci&A0);
	S0 = (A0^B0)^(Ci);
}

void Show_Row( int Ci, int A0, int B0, int Co, int S0)
{
	cout << "|  " << Ci << " |  " << A0 << " |  " << B0;
	cout << " ||  " << Co << " |  " << S0 << " |" << endl;
}



