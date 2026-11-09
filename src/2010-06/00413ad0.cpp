// from server: 100% by Yeetserama
// roc 2010-06 00413ad0  unit: CutVerb  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00413ad0
//
// 00413ad0  6aff                 push -1
// 00413ad2  68799d9800           push 0x989d79
// 00413ad7  64a100000000         mov eax, dword ptr fs:[0]
// 00413add  50                   push eax
// 00413ade  64892500000000       mov dword ptr fs:[0], esp
// 00413ae5  51                   push ecx
// 00413ae6  56                   push esi
// 00413ae7  8bf1                 mov esi, ecx
// 00413ae9  83ec1c               sub esp, 0x1c
// 00413aec  8d44243c             lea eax, [esp + 0x3c]
// 00413af0  8bcc                 mov ecx, esp
// 00413af2  89642420             mov dword ptr [esp + 0x20], esp
// 00413af6  50                   push eax
// 00413af7  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00413aff  ff150ca49e00         call dword ptr [0x9ea40c]
// 00413b05  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00413b09  8b542434             mov edx, dword ptr [esp + 0x34]
// 00413b0d  51                   push ecx
// 00413b0e  52                   push edx
// 00413b0f  8bce                 mov ecx, esi
// 00413b11  e85a081d00           call 0x5e4370
// 00413b16  8d4c2420             lea ecx, [esp + 0x20]
// 00413b1a  c706582fa000         mov dword ptr [esi], 0xa02f58
// 00413b20  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00413b28  ff1500a49e00         call dword ptr [0x9ea400]
// 00413b2e  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00413b32  8bc6                 mov eax, esi
// 00413b34  64890d00000000       mov dword ptr fs:[0], ecx
// 00413b3b  5e                   pop esi
// 00413b3c  83c410               add esp, 0x10
// 00413b3f  c22400               ret 0x24
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