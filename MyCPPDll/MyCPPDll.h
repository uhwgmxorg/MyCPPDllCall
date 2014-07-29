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
