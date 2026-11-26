// from server: 100% by Xemicl
// roc 2012-06 00b214c0  unit: seg_00b20000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b214c0
//
// 00b214c0  e8dbe0e4ff           call 0x96f5a0
// 00b214c5  684474e500           push 0xe57444
// 00b214ca  ff15d821b200         call dword ptr [0xb221d8]
// 00b214d0  c3                   ret 
// copied from an identical function in another client (function ??__Fg_lock_89d@@YAXXZ)

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