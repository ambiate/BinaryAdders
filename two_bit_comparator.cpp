/*
 *	Title: 		Compares two bits pairs.
*/

#include <iostream>

/* Prototypes */

void OneBitAdder (int Ci, int A0, int B0, int Co, int &S0);
void Show_Row (int Ci, int A0, int B0, int Co, int S0);
	
using namespace std;

int main()
{
	cout << "Unsigned One Bit Adder" << endl;
	cout << "|EDC |EDS |TDC ||TDS |DIFF|" << endl;
	cout << "|----|----|----||----|----|" << endl;
	
	int Diff;
	
	for (int EDC=0; EDC < 2; EDC++)
		for (int EDS=0; EDS < 2; EDS++)
			for (int TDC=0; TDC < 2; TDC++)
				for( int TDS=0; TDS < 2; TDS++)
				{
					OneBitAdder(EDC, EDS, TDC, TDS, Diff);
					Show_Row(EDC, EDS, TDC, TDS, Diff);
				};
	cin.get(); cin.get();
	return 0;
}

void OneBitAdder (int EDC, int EDS, int TDC, int TDS, int &Diff)
{
	static int Pass_Table [2] [2] [2] [2] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
	
	//Pass = Pass_Table [EDC] [EDS] [TDC] [TDS];
	Diff = (EDC^TDC)|(EDS^TDS);
}

void Show_Row( int EDC, int EDS, int TDC, int TDS, int Diff)
{
	cout << "|  " << EDC << " |  " << EDS << " |  " << TDC;
	cout << " ||  " << TDS << " |  " << Diff << " |" << endl;
}



