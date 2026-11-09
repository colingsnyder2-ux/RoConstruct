// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CRITICAL_SECTION { void* d; long l; long r; void* o; void* s; unsigned long sp; };
extern "C" __declspec(dllimport) int __stdcall InitializeCriticalSectionAndSpinCount(CRITICAL_SECTION*, unsigned long);
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError();
#include <stdexcept>
#include <map>
namespace RBX {
std::runtime_error runtime_error(const char* fmt, ...);
class mutex {
	CRITICAL_SECTION cs;
public:
	mutex()
	{
		if (!InitializeCriticalSectionAndSpinCount(&cs, 4000))
			throw RBX::runtime_error("failed to initialize CRITICAL_SECTION. Err: %x", GetLastError());
	}
	~mutex() { DeleteCriticalSection(&cs); }
};
namespace Tasks {
class __declspec(novtable) Coordinator {
public:
	virtual ~Coordinator() {}
	virtual bool isInhibited() = 0;
};
class Barrier : public Coordinator {
	int a;
	int b;
	mutex m;
	std::map<void*, int> counts;
public:
	Barrier();
	virtual bool isInhibited();
};
Barrier::Barrier() : a(0), b(0)
{
}
}
}
