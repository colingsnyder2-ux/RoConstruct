// from server: 100% by Yeetserama
// roc 2011-06 006073d0  unit: RBX::VModelInstance::?$FilteredSelection  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006073d0
//
// 006073d0  64a100000000         mov eax, dword ptr fs:[0]
// 006073d6  6aff                 push -1
// 006073d8  68e9819e00           push 0x9e81e9
// 006073dd  50                   push eax
// 006073de  64892500000000       mov dword ptr fs:[0], esp
// 006073e5  56                   push esi
// 006073e6  8bf1                 mov esi, ecx
// 006073e8  8b442430             mov eax, dword ptr [esp + 0x30]
// 006073ec  50                   push eax
// 006073ed  83ec1c               sub esp, 0x1c
// 006073f0  8d542434             lea edx, [esp + 0x34]
// 006073f4  8bcc                 mov ecx, esp
// 006073f6  89642450             mov dword ptr [esp + 0x50], esp
// 006073fa  52                   push edx
// 006073fb  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00607403  ff15c804a400         call dword ptr [0xa404c8]
// 00607409  8bce                 mov ecx, esi
// 0060740b  e870f7ffff           call 0x606b80
// 00607410  8d4c2414             lea ecx, [esp + 0x14]
// 00607414  c7066833a900         mov dword ptr [esi], 0xa93368
// 0060741a  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 00607422  ff15d004a400         call dword ptr [0xa404d0]
// 00607428  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0060742c  8bc6                 mov eax, esi
// 0060742e  64890d00000000       mov dword ptr fs:[0], ecx
// 00607435  5e                   pop esi
// 00607436  83c40c               add esp, 0xc
// 00607439  c22000               ret 0x20
// copied from an identical function in another client (function ??0S@@QAE@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Base {
    Base(std::string, int);
    virtual ~Base();
};
struct S : Base {
    S(std::string, int);
    virtual ~S();
};
S::S(std::string text, int value) : Base(text, value) {}