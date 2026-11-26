// from server: 100% by Xemicl
// roc 2012-06 0096f710  unit: W4_D3DFORMAT::?$EnumDesc  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0096f710
//
// 0096f710  b801000000           mov eax, 1
// 0096f715  8405f87fe500         test byte ptr [0xe57ff8], al
// 0096f71b  751d                 jne 0x96f73a
// 0096f71d  0905f87fe500         or dword ptr [0xe57ff8], eax
// 0096f723  b96074e500           mov ecx, 0xe57460
// 0096f728  e823efffff           call 0x96e650
// 0096f72d  68c014b200           push 0xb214c0
// 0096f732  e8be3a0100           call 0x9831f5
// 0096f737  83c404               add esp, 4
// 0096f73a  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096f741  740b                 je 0x96f74e
// 0096f743  684474e500           push 0xe57444
// 0096f748  ff15b821b200         call dword ptr [0xb221b8]
// 0096f74e  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096f755  56                   push esi
// 0096f756  8b356074e500         mov esi, dword ptr [0xe57460]
// 0096f75c  740b                 je 0x96f769
// 0096f75e  684474e500           push 0xe57444
// 0096f763  ff15b421b200         call dword ptr [0xb221b4]
// 0096f769  8bc6                 mov eax, esi
// 0096f76b  5e                   pop esi
// 0096f76c  c3                   ret 
// copied from an identical function in another client (function ?getRegistryValue@@YAPAXXZ)

// from server: 100% by EspClaude
// roc 2009-06 007141b0
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct CRITICAL_SECTION_ { char data[24]; };
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION_*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION_*);
extern bool g_lockEnabled;
extern CRITICAL_SECTION_ g_cs;
struct ScopedLock {
    ScopedLock() { if (g_lockEnabled) EnterCriticalSection(&g_cs); }
    ~ScopedLock() { if (g_lockEnabled) LeaveCriticalSection(&g_cs); }
};
struct Registry {
    void* value;
    Registry() throw();
    ~Registry();
};
void* getRegistryValue()
{
    static Registry s;
    ScopedLock lock;
    return s.value;
}