// from server: 100% by Yeetserama
// roc 2010-06 005e37c0  unit: RBX::VModelInstance::?$FilteredSelection  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005e37c0
//
// 005e37c0  64a100000000         mov eax, dword ptr fs:[0]
// 005e37c6  6aff                 push -1
// 005e37c8  6839ff9900           push 0x99ff39
// 005e37cd  50                   push eax
// 005e37ce  64892500000000       mov dword ptr fs:[0], esp
// 005e37d5  56                   push esi
// 005e37d6  8bf1                 mov esi, ecx
// 005e37d8  8b442430             mov eax, dword ptr [esp + 0x30]
// 005e37dc  50                   push eax
// 005e37dd  83ec1c               sub esp, 0x1c
// 005e37e0  8d542434             lea edx, [esp + 0x34]
// 005e37e4  8bcc                 mov ecx, esp
// 005e37e6  89642450             mov dword ptr [esp + 0x50], esp
// 005e37ea  52                   push edx
// 005e37eb  c744243000000000     mov dword ptr [esp + 0x30], 0
// 005e37f3  ff150ca49e00         call dword ptr [0x9ea40c]
// 005e37f9  8bce                 mov ecx, esi
// 005e37fb  e800fbffff           call 0x5e3300
// 005e3800  8d4c2414             lea ecx, [esp + 0x14]
// 005e3804  c70628e5a200         mov dword ptr [esi], 0xa2e528
// 005e380a  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 005e3812  ff1500a49e00         call dword ptr [0x9ea400]
// 005e3818  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005e381c  8bc6                 mov eax, esi
// 005e381e  64890d00000000       mov dword ptr fs:[0], ecx
// 005e3825  5e                   pop esi
// 005e3826  83c40c               add esp, 0xc
// 005e3829  c22000               ret 0x20
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