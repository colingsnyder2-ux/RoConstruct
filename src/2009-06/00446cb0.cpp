// from server: 100% by EspClaude
// roc 2009-06 00446cb0  unit: CBrowserDocManager  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00446cb0
//
// 00446cb0  6aff                 push -1
// 00446cb2  6859788600           push 0x867859
// 00446cb7  64a100000000         mov eax, dword ptr fs:[0]
// 00446cbd  50                   push eax
// 00446cbe  64892500000000       mov dword ptr fs:[0], esp
// 00446cc5  51                   push ecx
// 00446cc6  56                   push esi
// 00446cc7  8bf1                 mov esi, ecx
// 00446cc9  83ec1c               sub esp, 0x1c
// 00446ccc  8d442434             lea eax, [esp + 0x34]
// 00446cd0  8bcc                 mov ecx, esp
// 00446cd2  89642420             mov dword ptr [esp + 0x20], esp
// 00446cd6  50                   push eax
// 00446cd7  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00446cdf  ff15b8e48900         call dword ptr [0x89e4b8]
// 00446ce5  8bce                 mov ecx, esi
// 00446ce7  e884efffff           call 0x445c70
// 00446cec  33c9                 xor ecx, ecx
// 00446cee  85c0                 test eax, eax
// 00446cf0  0f94c1               sete cl
// 00446cf3  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 00446cfb  8bf1                 mov esi, ecx
// 00446cfd  8d4c2418             lea ecx, [esp + 0x18]
// 00446d01  ff15c4e48900         call dword ptr [0x89e4c4]
// 00446d07  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00446d0b  8bc6                 mov eax, esi
// 00446d0d  64890d00000000       mov dword ptr fs:[0], ecx
// 00446d14  5e                   pop esi
// 00446d15  83c410               add esp, 0x10
// 00446d18  c21c00               ret 0x1c
// copied from an identical function in another client (function ?method@CRbxPlayDocTemplate@@QAEHV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct CRbxPlayDocTemplate {
    int method(std::string value);
    int forward(std::string value);
};
int CRbxPlayDocTemplate::method(std::string value)
{
    return !forward(value);
}