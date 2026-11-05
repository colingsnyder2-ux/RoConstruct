// from server: 100% by EspClaude
// roc 2009-06 005e6920  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e6920
//
// 005e6920  56                   push esi
// 005e6921  8d44240c             lea eax, [esp + 0xc]
// 005e6925  8bf1                 mov esi, ecx
// 005e6927  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005e692b  50                   push eax
// 005e692c  51                   push ecx
// 005e692d  e89e4a0600           call 0x64b3d0
// 005e6932  83c408               add esp, 8
// 005e6935  84c0                 test al, al
// 005e6937  741a                 je 0x5e6953
// 005e6939  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005e693c  8b11                 mov edx, dword ptr [ecx]
// 005e693e  8b520c               mov edx, dword ptr [edx + 0xc]
// 005e6941  8d44240c             lea eax, [esp + 0xc]
// 005e6945  50                   push eax
// 005e6946  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005e694a  50                   push eax
// 005e694b  ffd2                 call edx
// 005e694d  b001                 mov al, 1
// 005e694f  5e                   pop esi
// 005e6950  c20800               ret 8
// 005e6953  32c0                 xor al, al
// 005e6955  5e                   pop esi
// 005e6956  c20800               ret 8
// copied from an identical function in another client (function ?f@S@ns_ROCX000002@@QAE_NPAX0@Z)

namespace ns_ROCX000002 {
extern "C" bool __cdecl convert(void* value, void** result);

struct Setter {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void set(void* instance, void** value);
};

struct S {
    char padding[24];
    Setter* setter;

    bool f(void* instance, void* value);
};

bool S::f(void* instance, void* value)
{
    if (convert(value, &value)) {
        setter->set(instance, &value);
        return true;
    }
    return false;
}
}
