// from server: 100% by Yeetserama
// roc 2010-06 005e3470  unit: RBX::VModelInstance::?$FilteredSelection  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005e3470
//
// 005e3470  64a100000000         mov eax, dword ptr fs:[0]
// 005e3476  6aff                 push -1
// 005e3478  68a97e9900           push 0x997ea9
// 005e347d  50                   push eax
// 005e347e  64892500000000       mov dword ptr fs:[0], esp
// 005e3485  56                   push esi
// 005e3486  8bf1                 mov esi, ecx
// 005e3488  8b442414             mov eax, dword ptr [esp + 0x14]
// 005e348c  50                   push eax
// 005e348d  83ec1c               sub esp, 0x1c
// 005e3490  8d542438             lea edx, [esp + 0x38]
// 005e3494  8bcc                 mov ecx, esp
// 005e3496  89642434             mov dword ptr [esp + 0x34], esp
// 005e349a  52                   push edx
// 005e349b  c744243000000000     mov dword ptr [esp + 0x30], 0
// 005e34a3  ff150ca49e00         call dword ptr [0x9ea40c]
// 005e34a9  8bce                 mov ecx, esi
// 005e34ab  e850feffff           call 0x5e3300
// 005e34b0  8a442434             mov al, byte ptr [esp + 0x34]
// 005e34b4  8d4c2418             lea ecx, [esp + 0x18]
// 005e34b8  c706b0e4a200         mov dword ptr [esi], 0xa2e4b0
// 005e34be  884624               mov byte ptr [esi + 0x24], al
// 005e34c1  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 005e34c9  ff1500a49e00         call dword ptr [0x9ea400]
// 005e34cf  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005e34d3  8bc6                 mov eax, esi
// 005e34d5  64890d00000000       mov dword ptr fs:[0], ecx
// 005e34dc  5e                   pop esi
// 005e34dd  83c40c               add esp, 0xc
// 005e34e0  c22400               ret 0x24
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