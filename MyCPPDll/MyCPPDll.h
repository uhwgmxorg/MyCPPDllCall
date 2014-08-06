// MyCPPDll.h
//

namespace MyCPPDll
{
	class ClassI
	{
	private:
		char* Version;
	public:
		__declspec(dllexport) ClassI();
		__declspec(dllexport) char* GetVersion();
	};
}

// Functions for using in managed code
//
extern "C" __declspec(dllexport) MyCPPDll::ClassI* __cdecl ClassICrate();
extern "C" __declspec(dllexport) char* __cdecl ClassIGetVersion(MyCPPDll::ClassI* pClassI);
extern "C" __declspec(dllexport) void __cdecl ClassIDelete(MyCPPDll::ClassI* pClassI);
