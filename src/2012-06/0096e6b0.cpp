// from server: 100% by Xemicl
// roc 2012-06 0096e6b0  unit: W4_D3DFORMAT::?$EnumDesc  size: 58 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0096e6b0
//
// 0096e6b0  56                   push esi
// 0096e6b1  e8ba0f0000           call 0x96f670
// 0096e6b6  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096e6bd  8bf0                 mov esi, eax
// 0096e6bf  740b                 je 0x96e6cc
// 0096e6c1  684474e500           push 0xe57444
// 0096e6c6  ff15b821b200         call dword ptr [0xb221b8]
// 0096e6cc  81c694090000         add esi, 0x994
// 0096e6d2  803d281ce00000       cmp byte ptr [0xe01c28], 0
// 0096e6d9  740b                 je 0x96e6e6
// 0096e6db  684474e500           push 0xe57444
// 0096e6e0  ff15b421b200         call dword ptr [0xb221b4]
// 0096e6e6  8bc6                 mov eax, esi
// 0096e6e8  5e                   pop esi
// 0096e6e9  c3                   ret 
// copied from an identical function in another client (function ?getValue@G3D@@YAPAHXZ)

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