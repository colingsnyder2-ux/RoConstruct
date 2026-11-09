// from server: 100% by colin
// roc 2007-08 0055fde0  unit: RBX::VModelInstance::?$FilteredSelection  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055fde0
//
// 0055fde0  64a100000000         mov eax, dword ptr fs:[0]
// 0055fde6  6aff                 push -1
// 0055fde8  68993d7500           push 0x753d99
// 0055fded  50                   push eax
// 0055fdee  64892500000000       mov dword ptr fs:[0], esp
// 0055fdf5  56                   push esi
// 0055fdf6  8bf1                 mov esi, ecx
// 0055fdf8  8b442414             mov eax, dword ptr [esp + 0x14]
// 0055fdfc  50                   push eax
// 0055fdfd  83ec1c               sub esp, 0x1c
// 0055fe00  8d542438             lea edx, [esp + 0x38]
// 0055fe04  8bcc                 mov ecx, esp
// 0055fe06  89642434             mov dword ptr [esp + 0x34], esp
// 0055fe0a  52                   push edx
// 0055fe0b  c744243000000000     mov dword ptr [esp + 0x30], 0
// 0055fe13  ff159ce67700         call dword ptr [0x77e69c]
// 0055fe19  8bce                 mov ecx, esi
// 0055fe1b  e820feffff           call 0x55fc40
// 0055fe20  8a442434             mov al, byte ptr [esp + 0x34]
// 0055fe24  8d4c2418             lea ecx, [esp + 0x18]
// 0055fe28  c70630947a00         mov dword ptr [esi], 0x7a9430
// 0055fe2e  884624               mov byte ptr [esi + 0x24], al
// 0055fe31  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 0055fe39  ff15ace67700         call dword ptr [0x77e6ac]
// 0055fe3f  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0055fe43  8bc6                 mov eax, esi
// 0055fe45  64890d00000000       mov dword ptr fs:[0], ecx
// 0055fe4c  5e                   pop esi
// 0055fe4d  83c40c               add esp, 0xc
// 0055fe50  c22400               ret 0x24
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