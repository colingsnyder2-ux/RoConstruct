// from server: 100% by EspClaude
// roc 2009-06 0044fce0  unit: CRobloxDoc  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044fce0
//
// 0044fce0  6aff                 push -1
// 0044fce2  68f8148500           push 0x8514f8
// 0044fce7  64a100000000         mov eax, dword ptr fs:[0]
// 0044fced  50                   push eax
// 0044fcee  64892500000000       mov dword ptr fs:[0], esp
// 0044fcf5  83ec08               sub esp, 8
// 0044fcf8  56                   push esi
// 0044fcf9  8bf1                 mov esi, ecx
// 0044fcfb  89742408             mov dword ptr [esp + 8], esi
// 0044fcff  e82e902c00           call 0x718d32
// 0044fd04  8d442407             lea eax, [esp + 7]
// 0044fd08  50                   push eax
// 0044fd09  8d4c240b             lea ecx, [esp + 0xb]
// 0044fd0d  51                   push ecx
// 0044fd0e  8d4e54               lea ecx, [esi + 0x54]
// 0044fd11  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0044fd19  c7063c888b00         mov dword ptr [esi], 0x8b883c
// 0044fd1f  e8bc851a00           call 0x5f82e0
// 0044fd24  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044fd28  8bc6                 mov eax, esi
// 0044fd2a  5e                   pop esi
// 0044fd2b  64890d00000000       mov dword ptr fs:[0], ecx
// 0044fd32  83c414               add esp, 0x14
// 0044fd35  c3                   ret 
// copied from an identical function in another client (function ??0CRobloxDoc@@QAE@XZ)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
struct Base {
    virtual void vfunc();
    char padding[80];
    Base();
    ~Base();
};
struct CRobloxDoc : Base {
    std::map<int,int> member;
    virtual void vfunc();
    CRobloxDoc();
};
CRobloxDoc::CRobloxDoc() : Base()
{
}