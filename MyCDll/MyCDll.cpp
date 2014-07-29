// MyCDll.cpp : Definiert die exportierten Funktionen für die DLL-Anwendung.
//

#include "stdafx.h"

#include <iostream>

#include "MyCDll.h"

void SetConsoleColor(int c);

// GetVersion
// shows how to return a string
char* __stdcall GetDllVersion()
{
	return Version;
}

// OpenCWSProject
// shows how to give a string as parameter
short __stdcall OpenCWSProject(char* filename)
{
	SetConsoleColor(2);

	std::cout << "From OpenCWSProject: ";
	std::cout << filename << std::endl;

	SetConsoleColor(7);
	return 0;
}

// PredictSample_C
// shows how to give and get back some complicated structs
short __stdcall PredictSample_C(char * CalibName, int nArraySize, double * fWavelength, double * fY, short fTypeY, short * fFlags, double * fResults)
{
	SetConsoleColor(3);

	std::cout << "From PredictSample_C: ";
	std::cout << CalibName << std::endl;

	std::cout << "nArraySize:" << nArraySize << std::endl;
	std::cout << "fWavelength:" << std::endl;
	for (int i = 0; i < nArraySize; i++)
		std::cout << fWavelength[i] << " ";

	std::cout << std::endl << "fY:" << std::endl;
	for (int i = 0; i < nArraySize; i++)
		std::cout << fY[i] << " ";

	std::cout << std::endl << "Seting fFlags and fResults" << std::endl;
	fFlags[0] = 1;
	fFlags[1] = 2;
	fFlags[2] = 3;
	fResults[0] = 1.1;
	fResults[1] = 2.2;
	fResults[2] = 3.3;

	SetConsoleColor(7);
	return 0;
}

// CloseDatabase
// just a simple call
void __stdcall CloseDatabase()
{
	SetConsoleColor(4);

	std::cout << "From CloseDatabase: ";
	std::cout << std::endl;

	SetConsoleColor(7);
}

// PrintAllColors
void PrintAllColors()
{
	for (int i = 0; i < 255; i++)
	{
		SetConsoleColor(i);
		std::cout << "Color is: " << i << std::endl;
	}
}

// SetConsoleColor
void SetConsoleColor(int c)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, c);
}
