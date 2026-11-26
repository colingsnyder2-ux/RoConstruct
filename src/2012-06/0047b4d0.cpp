// from server: 100% by Xemicl
// roc 2012-06 0047b4d0  unit: VCWorkspace::?$CComObject  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0047b4d0
//
// 0047b4d0  6aff                 push -1
// 0047b4d2  681311aa00           push 0xaa1113
// 0047b4d7  64a100000000         mov eax, dword ptr fs:[0]
// 0047b4dd  50                   push eax
// 0047b4de  64892500000000       mov dword ptr fs:[0], esp
// 0047b4e5  51                   push ecx
// 0047b4e6  56                   push esi
// 0047b4e7  8bf1                 mov esi, ecx
// 0047b4e9  89742404             mov dword ptr [esp + 4], esi
// 0047b4ed  8d4e38               lea ecx, [esi + 0x38]
// 0047b4f0  c744241001000000     mov dword ptr [esp + 0x10], 1
// 0047b4f8  ff153c26b200         call dword ptr [0xb2263c]
// 0047b4fe  8d4e1c               lea ecx, [esi + 0x1c]
// 0047b501  c644241000           mov byte ptr [esp + 0x10], 0
// 0047b506  ff153c26b200         call dword ptr [0xb2263c]
// 0047b50c  8bce                 mov ecx, esi
// 0047b50e  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0047b516  ff153c26b200         call dword ptr [0xb2263c]
// 0047b51c  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0047b520  5e                   pop esi
// 0047b521  64890d00000000       mov dword ptr fs:[0], ecx
// 0047b528  83c410               add esp, 0x10
// 0047b52b  c3                   ret 
// copied from an identical function in another client (function ??1Triple@@QAE@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct Triple {
    std::string first;
    std::string second;
    std::string third;
    ~Triple();
};
Triple::~Triple() {}