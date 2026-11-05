// from server: 100% by Yeetserama
// roc 2012-06 006f8770  unit: RBX::VInstance::?$FilteredSelection  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f8770
//
// 006f8770  64a100000000         mov eax, dword ptr fs:[0]
// 006f8776  6aff                 push -1
// 006f8778  6819e7ab00           push 0xabe719
// 006f877d  50                   push eax
// 006f877e  64892500000000       mov dword ptr fs:[0], esp
// 006f8785  56                   push esi
// 006f8786  8bf1                 mov esi, ecx
// 006f8788  8b442430             mov eax, dword ptr [esp + 0x30]
// 006f878c  50                   push eax
// 006f878d  83ec1c               sub esp, 0x1c
// 006f8790  8d542434             lea edx, [esp + 0x34]
// 006f8794  8bcc                 mov ecx, esp
// 006f8796  89642450             mov dword ptr [esp + 0x50], esp
// 006f879a  52                   push edx
// 006f879b  c744243000000000     mov dword ptr [esp + 0x30], 0
// 006f87a3  ff154426b200         call dword ptr [0xb22644]
// 006f87a9  8bce                 mov ecx, esi
// 006f87ab  e860f0ffff           call 0x6f7810
// 006f87b0  8d4c2414             lea ecx, [esp + 0x14]
// 006f87b4  c70664c8b900         mov dword ptr [esi], 0xb9c864
// 006f87ba  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 006f87c2  ff153c26b200         call dword ptr [0xb2263c]
// 006f87c8  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006f87cc  8bc6                 mov eax, esi
// 006f87ce  64890d00000000       mov dword ptr fs:[0], ecx
// 006f87d5  5e                   pop esi
// 006f87d6  83c40c               add esp, 0xc
// 006f87d9  c22000               ret 0x20
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