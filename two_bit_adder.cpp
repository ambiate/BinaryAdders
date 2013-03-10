/*
 *    Title:         2-bit Unsigned Binary Adder With Carry-In.  
 *    Author:        Jonathan Drouillard
 *    Description:
 *        This application creates a function that simulates a
 *        2-bit unsigned integer adder with carry-in
 */

#include <iostream>

/* Prototypes */

void TwoBitAdder (int C0, int A1, int A0, int B1, int B0, int &S2, int &S1, int &S0);
void Show_Row (int C0, int A1, int A0, int B1, int B0, int S2, int S1, int S0);
    
using namespace std;

int main()
{
    
    cout << "Unsigned Two Bit Adder" << endl;
    cout << "| C0 | A1 | A0 | B1 | B0 || S2 | S1 | S0 |" << endl;
    cout << "|----|----|----|----|----||----|----|----|" << endl;
    
    int S2, S1, S0;
    
    //Loop through each iteration of the 5 inputs
    for (int C0=0; C0 < 2; C0++)
        for (int A1=0; A1 <2; A1++)
            for (int A0=0; A0 < 2; A0++)
                for (int B1=0; B1 < 2; B1++)
                    for (int B0=0; B0 < 2; B0++) {
                        //Call functions on the current set of inputs.
                        TwoBitAdder(C0, A1, A0, B1, B0, S2, S1, S0);
                        Show_Row(C0, A1, A0, B1, B0, S2, S1, S0);
                    };
    cin.get(); cin.get();
    return 0;
}

/*The values derived from our truth table for inputs and outputs for the two bit adder*/
void TwoBitAdder (int C0, int A1, int A0, int B1, int B0, int &S2, int &S1, int &S0)
{
    //Contents of each of the outputs from the truth table.
    static int S2_Table [2] [2] [2] [2] [2] = {0,0,0,0,0,0,0,1,0,0,1,1,0,1,1,1,0,0,0,1,0,0,1,1,0,1,1,1,1,1,1,1};
    static int S1_Table [2] [2] [2] [2] [2] = {0,0,1,1,0,1,1,0,1,1,0,0,1,0,0,1,0,1,1,0,1,1,0,0,1,0,0,1,0,0,1,1};
    static int S0_Table [2] [2] [2] [2] [2] = {0,1,0,1,1,0,1,0,0,1,0,1,1,0,1,0,1,0,1,0,0,1,0,1,1,0,1,0,0,1,0,1};
    
    //Change the referenced values.
    S2 = S2_Table [C0] [A1] [A0] [B1] [B0];
    S1 = S1_Table [C0] [A1] [A0] [B1] [B0];
    S0 = S0_Table [C0] [A1] [A0] [B1] [B0];
}

/*Displays a row's contents*/
void Show_Row( int C0, int A1, int A0, int B1, int B0, int S2, int S1, int S0)
{
    cout << "|  " << C0 << " |  " << A1 << " |  " << A0 << " |  " << B1 << " |  " << B0;
    cout << " ||  " << S2 << " ||  " << S1 << " |  " << S0 << " |" << endl;
}



