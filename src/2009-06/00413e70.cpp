// from server: 100% by EspClaude
// roc 2009-06 00413e70  unit: CutVerb  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00413e70
//
// 00413e70  6aff                 push -1
// 00413e72  68a9798600           push 0x8679a9
// 00413e77  64a100000000         mov eax, dword ptr fs:[0]
// 00413e7d  50                   push eax
// 00413e7e  64892500000000       mov dword ptr fs:[0], esp
// 00413e85  51                   push ecx
// 00413e86  56                   push esi
// 00413e87  8bf1                 mov esi, ecx
// 00413e89  83ec1c               sub esp, 0x1c
// 00413e8c  8d44243c             lea eax, [esp + 0x3c]
// 00413e90  8bcc                 mov ecx, esp
// 00413e92  89642420             mov dword ptr [esp + 0x20], esp
// 00413e96  50                   push eax
// 00413e97  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00413e9f  ff15b8e48900         call dword ptr [0x89e4b8]
// 00413ea5  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00413ea9  8b542434             mov edx, dword ptr [esp + 0x34]
// 00413ead  51                   push ecx
// 00413eae  52                   push edx
// 00413eaf  8bce                 mov ecx, esi
// 00413eb1  e8faa21f00           call 0x60e1b0
// 00413eb6  8d4c2420             lea ecx, [esp + 0x20]
// 00413eba  c70618f78a00         mov dword ptr [esi], 0x8af718
// 00413ec0  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00413ec8  ff15c4e48900         call dword ptr [0x89e4c4]
// 00413ece  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00413ed2  8bc6                 mov eax, esi
// 00413ed4  64890d00000000       mov dword ptr fs:[0], ecx
// 00413edb  5e                   pop esi
// 00413edc  83c410               add esp, 0x10
// 00413edf  c22400               ret 0x24
// copied from an identical function in another client (function ??0CutVerb@@QAE@HHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Base {
    Base(int, int, std::string);
    virtual void execute();
};

struct CutVerb : Base {
    CutVerb(int, int, std::string);
    virtual void execute();
};

CutVerb::CutVerb(int a, int b, std::string name)
    : Base(a, b, name)
{
}