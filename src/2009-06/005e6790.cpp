// from server: 100% by EspClaude
// roc 2009-06 005e6790  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 57 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e6790
//
// 005e6790  56                   push esi
// 005e6791  8d44240c             lea eax, [esp + 0xc]
// 005e6795  8bf1                 mov esi, ecx
// 005e6797  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005e679b  50                   push eax
// 005e679c  51                   push ecx
// 005e679d  e85e4b0600           call 0x64b300
// 005e67a2  83c408               add esp, 8
// 005e67a5  84c0                 test al, al
// 005e67a7  741a                 je 0x5e67c3
// 005e67a9  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005e67ac  8b11                 mov edx, dword ptr [ecx]
// 005e67ae  8b520c               mov edx, dword ptr [edx + 0xc]
// 005e67b1  8d44240c             lea eax, [esp + 0xc]
// 005e67b5  50                   push eax
// 005e67b6  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005e67ba  50                   push eax
// 005e67bb  ffd2                 call edx
// 005e67bd  b001                 mov al, 1
// 005e67bf  5e                   pop esi
// 005e67c0  c20800               ret 8
// 005e67c3  32c0                 xor al, al
// 005e67c5  5e                   pop esi
// 005e67c6  c20800               ret 8
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
