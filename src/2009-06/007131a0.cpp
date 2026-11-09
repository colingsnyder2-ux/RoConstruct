// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CRITICAL_SECTION { int d[6]; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION*);
namespace G3D {
extern bool threadSafe;
extern CRITICAL_SECTION criticalSection;
class Lock {
public:
    Lock() { if (threadSafe) EnterCriticalSection(&criticalSection); }
    ~Lock() { if (threadSafe) LeaveCriticalSection(&criticalSection); }
};
struct Big { char pad[0x994]; int value; };
Big& instance();
int* getValue()
{
    Big& b = instance();
    Lock lock;
    return &b.value;
}
}
