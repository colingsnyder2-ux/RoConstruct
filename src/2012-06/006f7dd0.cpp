// from server: 100% by Yeetserama
// roc 2012-06 006f7dd0  unit: RBX::DuplicateSelectionVerb  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f7dd0
//
// 006f7dd0  64a100000000         mov eax, dword ptr fs:[0]
// 006f7dd6  6aff                 push -1
// 006f7dd8  6889a0ac00           push 0xaca089
// 006f7ddd  50                   push eax
// 006f7dde  64892500000000       mov dword ptr fs:[0], esp
// 006f7de5  56                   push esi
// 006f7de6  8bf1                 mov esi, ecx
// 006f7de8  8b442414             mov eax, dword ptr [esp + 0x14]
// 006f7dec  50                   push eax
// 006f7ded  83ec1c               sub esp, 0x1c
// 006f7df0  8d542438             lea edx, [esp + 0x38]
// 006f7df4  8bcc                 mov ecx, esp
// 006f7df6  89642434             mov dword ptr [esp + 0x34], esp
// 006f7dfa  52                   push edx
// 006f7dfb  c744243000000000     mov dword ptr [esp + 0x30], 0
// 006f7e03  ff154426b200         call dword ptr [0xb22644]
// 006f7e09  8bce                 mov ecx, esi
// 006f7e0b  e800faffff           call 0x6f7810
// 006f7e10  8a442434             mov al, byte ptr [esp + 0x34]
// 006f7e14  8d4c2418             lea ecx, [esp + 0x18]
// 006f7e18  c7062cc7b900         mov dword ptr [esi], 0xb9c72c
// 006f7e1e  884624               mov byte ptr [esi + 0x24], al
// 006f7e21  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 006f7e29  ff153c26b200         call dword ptr [0xb2263c]
// 006f7e2f  8b4c2404             mov ecx, dword ptr [esp + 4]
// 006f7e33  8bc6                 mov eax, esi
// 006f7e35  64890d00000000       mov dword ptr fs:[0], ecx
// 006f7e3c  5e                   pop esi
// 006f7e3d  83c40c               add esp, 0xc
// 006f7e40  c22400               ret 0x24
// copied from an identical function in another client (function ??0ClearBackpack@@QAE@HV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@_N@Z)

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct Base {
    virtual void f();
    char storage[32];
    Base(std::string, int);
};

struct ClearBackpack : Base {
    bool flag;
    virtual void f();
    ClearBackpack(int, std::string, bool);
};

ClearBackpack::ClearBackpack(int value, std::string text, bool enabled)
    : Base(text, value), flag(enabled)
{
}