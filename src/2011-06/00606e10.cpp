// from server: 100% by Yeetserama
// roc 2011-06 00606e10  unit: RBX::VModelInstance::?$FilteredSelection  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00606e10
//
// 00606e10  64a100000000         mov eax, dword ptr fs:[0]
// 00606e16  6aff                 push -1
// 00606e18  68c912a000           push 0xa012c9
// 00606e1d  50                   push eax
// 00606e1e  64892500000000       mov dword ptr fs:[0], esp
// 00606e25  56                   push esi
// 00606e26  8bf1                 mov esi, ecx
// 00606e28  8b442414             mov eax, dword ptr [esp + 0x14]
// 00606e2c  50                   push eax
// 00606e2d  83ec1c               sub esp, 0x1c
// 00606e30  8d542438             lea edx, [esp + 0x38]
// 00606e34  8bcc                 mov ecx, esp
// 00606e36  89642434             mov dword ptr [esp + 0x34], esp
// 00606e3a  52                   push edx
// 00606e3b  c744243000000000     mov dword ptr [esp + 0x30], 0
// 00606e43  ff15c804a400         call dword ptr [0xa404c8]
// 00606e49  8bce                 mov ecx, esi
// 00606e4b  e830fdffff           call 0x606b80
// 00606e50  8a442434             mov al, byte ptr [esp + 0x34]
// 00606e54  8d4c2418             lea ecx, [esp + 0x18]
// 00606e58  c706c832a900         mov dword ptr [esi], 0xa932c8
// 00606e5e  884624               mov byte ptr [esi + 0x24], al
// 00606e61  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 00606e69  ff15d004a400         call dword ptr [0xa404d0]
// 00606e6f  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00606e73  8bc6                 mov eax, esi
// 00606e75  64890d00000000       mov dword ptr fs:[0], ecx
// 00606e7c  5e                   pop esi
// 00606e7d  83c40c               add esp, 0xc
// 00606e80  c22400               ret 0x24
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