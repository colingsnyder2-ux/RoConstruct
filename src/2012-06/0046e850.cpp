// from server: 100% by Yeetserama
// roc 2012-06 0046e850  unit: RBX::Security::VContext::?$thread_specific_ptr::delete_data  size: 107 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046e850
//
// 0046e850  6aff                 push -1
// 0046e852  6819e7ab00           push 0xabe719
// 0046e857  64a100000000         mov eax, dword ptr fs:[0]
// 0046e85d  50                   push eax
// 0046e85e  64892500000000       mov dword ptr fs:[0], esp
// 0046e865  51                   push ecx
// 0046e866  56                   push esi
// 0046e867  8bf1                 mov esi, ecx
// 0046e869  83ec1c               sub esp, 0x1c
// 0046e86c  8d442434             lea eax, [esp + 0x34]
// 0046e870  8bcc                 mov ecx, esp
// 0046e872  89642420             mov dword ptr [esp + 0x20], esp
// 0046e876  50                   push eax
// 0046e877  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0046e87f  ff154426b200         call dword ptr [0xb22644]
// 0046e885  8bce                 mov ecx, esi
// 0046e887  e8a4f5ffff           call 0x46de30
// 0046e88c  33c9                 xor ecx, ecx
// 0046e88e  85c0                 test eax, eax
// 0046e890  0f94c1               sete cl
// 0046e893  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0046e89b  8bf1                 mov esi, ecx
// 0046e89d  8d4c2418             lea ecx, [esp + 0x18]
// 0046e8a1  ff153c26b200         call dword ptr [0xb2263c]
// 0046e8a7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0046e8ab  8bc6                 mov eax, esi
// 0046e8ad  64890d00000000       mov dword ptr fs:[0], ecx
// 0046e8b4  5e                   pop esi
// 0046e8b5  83c410               add esp, 0x10
// 0046e8b8  c21c00               ret 0x1c
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