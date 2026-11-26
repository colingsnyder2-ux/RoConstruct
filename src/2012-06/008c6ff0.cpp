// from server: 100% by Xemicl
// roc 2012-06 008c6ff0  unit: RBX::VirtualUser  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008c6ff0
//
// 008c6ff0  6aff                 push -1
// 008c6ff2  6819e7ab00           push 0xabe719
// 008c6ff7  64a100000000         mov eax, dword ptr fs:[0]
// 008c6ffd  50                   push eax
// 008c6ffe  64892500000000       mov dword ptr fs:[0], esp
// 008c7005  51                   push ecx
// 008c7006  56                   push esi
// 008c7007  8bf1                 mov esi, ecx
// 008c7009  83ec1c               sub esp, 0x1c
// 008c700c  8d442434             lea eax, [esp + 0x34]
// 008c7010  8bcc                 mov ecx, esp
// 008c7012  89642420             mov dword ptr [esp + 0x20], esp
// 008c7016  50                   push eax
// 008c7017  c744243000000000     mov dword ptr [esp + 0x30], 0
// 008c701f  ff154426b200         call dword ptr [0xb22644]
// 008c7025  8bce                 mov ecx, esi
// 008c7027  e824feffff           call 0x8c6e50
// 008c702c  83ec1c               sub esp, 0x1c
// 008c702f  8d542434             lea edx, [esp + 0x34]
// 008c7033  8bcc                 mov ecx, esp
// 008c7035  89642420             mov dword ptr [esp + 0x20], esp
// 008c7039  52                   push edx
// 008c703a  ff154426b200         call dword ptr [0xb22644]
// 008c7040  8bce                 mov ecx, esi
// 008c7042  e8d9feffff           call 0x8c6f20
// 008c7047  8d4c2418             lea ecx, [esp + 0x18]
// 008c704b  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 008c7053  ff153c26b200         call dword ptr [0xb2263c]
// 008c7059  8b4c2408             mov ecx, dword ptr [esp + 8]
// 008c705d  64890d00000000       mov dword ptr fs:[0], ecx
// 008c7064  5e                   pop esi
// 008c7065  83c410               add esp, 0x10
// 008c7068  c21c00               ret 0x1c
// copied from an identical function in another client (function ?f@S@RBX@@QAEXV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class S {
public:
    void a(std::string s);
    void b(std::string s);
    void f(std::string s);
};
void S::f(std::string s) { a(s); b(s); }
}