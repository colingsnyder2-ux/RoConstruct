// from server: 100% by EspClaude
// roc 2009-06 00458880  unit: CRobloxView  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00458880
//
// 00458880  6aff                 push -1
// 00458882  68b82b8500           push 0x852bb8
// 00458887  64a100000000         mov eax, dword ptr fs:[0]
// 0045888d  50                   push eax
// 0045888e  64892500000000       mov dword ptr fs:[0], esp
// 00458895  83ec08               sub esp, 8
// 00458898  56                   push esi
// 00458899  8bf1                 mov esi, ecx
// 0045889b  89742408             mov dword ptr [esp + 8], esi
// 0045889f  e86c0b2c00           call 0x719410
// 004588a4  8d442407             lea eax, [esp + 7]
// 004588a8  50                   push eax
// 004588a9  8d4c240b             lea ecx, [esp + 0xb]
// 004588ad  51                   push ecx
// 004588ae  8d4e58               lea ecx, [esi + 0x58]
// 004588b1  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 004588b9  c706549b8b00         mov dword ptr [esi], 0x8b9b54
// 004588bf  e81cfa1900           call 0x5f82e0
// 004588c4  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004588c8  8bc6                 mov eax, esi
// 004588ca  5e                   pop esi
// 004588cb  64890d00000000       mov dword ptr fs:[0], ecx
// 004588d2  83c414               add esp, 0x14
// 004588d5  c3                   ret 
// copied from an identical function in another client (function ??0CRobloxView@@QAE@XZ)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
struct Base {
    virtual void vfunc();
    char padding[84];
    Base();
    ~Base();
};
struct CRobloxView : Base {
    std::map<int,int> member;
    virtual void vfunc();
    CRobloxView();
};
CRobloxView::CRobloxView() : Base()
{
}