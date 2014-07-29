// MyCPPDllCall.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;

// including the MyCPPDll for Classes
#include "MyCPPDll.h"
using namespace MyCPPDll;
// including the MyCDll for C-Funktions
#include "MyCDll.h"

int _tmain(int argc, _TCHAR* argv[])
{

	const int FWAVELENGTH_SIZE = 20;

	cout << "Programm MyCPPDllCall" << endl << endl;


	// MyCPPDll.dll
	ClassI MyCPPDllOpj;
	cout << "The version of MyCPPDll.dll (C++ classes) is:" << endl;
	cout << MyCPPDllOpj.GetVersion() << endl << endl;

	// MyCDll.dll
	cout << "The version of MyCDll.dll (C functions) is:" << endl;
	cout << GetDllVersion() << endl;
	cout << "and other functions from MyCDll.dll" << endl;
	OpenCWSProject("Data.dat");

	double FWavelength[FWAVELENGTH_SIZE]; for (int i = 0; i<FWAVELENGTH_SIZE; i++){ FWavelength[i] = i + 850; }
	double FY[FWAVELENGTH_SIZE]; srand(time(0)); for (int i = 0; i < FWAVELENGTH_SIZE; i++){ FY[i] = ((double) rand() / (RAND_MAX)); }
	short FFlags[3];
	double FResults[3];

	PredictSample_C("PLS_Sub_1", FWAVELENGTH_SIZE, FWavelength, FY, 0, FFlags, FResults);
	cout << FFlags[0] << " " << FFlags[1] << " " << FFlags[2] << endl;
	cout << FResults[0] << " " << FResults[1] << " " << FResults[2] << endl;
 	CloseDatabase();

	// Uncomment to print all colors, if you want.
	//PrintAllColors();


	cout << endl << endl << "Hit any key to exit" << endl;
	while (!_kbhit());
	return 0;
}

