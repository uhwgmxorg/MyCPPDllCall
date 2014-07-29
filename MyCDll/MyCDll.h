// MyCDll.h
//

char* Version = "1.0.0.0";

extern "C" __declspec(dllexport) char* __stdcall GetDllVersion();
extern "C" __declspec(dllexport) short __stdcall OpenCWSProject(char* filename);
extern "C" __declspec(dllexport) short __stdcall PredictSample_C(char * CalibName, int nArraySize, double * fWavelength, double * fY, short fTypeY, short * fFlags, double * fResults);
extern "C" __declspec(dllexport) void __stdcall CloseDatabase();

extern "C" __declspec(dllexport) void PrintAllColors();
