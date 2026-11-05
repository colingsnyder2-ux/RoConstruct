// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef struct HINSTANCE__* HMODULE;
extern "C" __declspec(dllimport) HMODULE __stdcall GetModuleHandleA(const char*);
extern "C" __declspec(dllimport) HMODULE __stdcall LoadLibraryA(const char*);
template<class T> class ImpStr { public: __declspec(noinline) operator const T*() const { return p; } T* p; };
extern template class __declspec(dllimport) ImpStr<char>;
typedef ImpStr<char> CStringA;
class ModuleLoader {
public:
	virtual ~ModuleLoader();
	HMODULE get();
	HMODULE hModule;
	bool loaded;
	CStringA name;
};
HMODULE ModuleLoader::get()
{
	if (hModule == 0) {
		hModule = GetModuleHandleA(name);
		if (hModule == 0) {
			hModule = LoadLibraryA(name);
			loaded = hModule != 0;
		}
	}
	return hModule;
}
