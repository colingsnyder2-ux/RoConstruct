// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /arch:SSE2 /fp:fast
struct RTL_CS_89d { void* a; long b; long c; void* d; void* e; unsigned long f; };
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(RTL_CS_89d*);
void __cdecl shutdown_714070();
struct Lock_89d {
    RTL_CS_89d cs;
    ~Lock_89d() { shutdown_714070(); DeleteCriticalSection(&cs); }
};
Lock_89d g_lock_89d;
