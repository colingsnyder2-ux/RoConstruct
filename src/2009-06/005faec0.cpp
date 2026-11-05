// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005756e0  unit: RBX::ServiceProvider  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005756e0
//
// 005756e0  8b8104020000         mov eax, dword ptr [ecx + 0x20c]
// 005756e6  83ec08               sub esp, 8
// 005756e9  50                   push eax
// 005756ea  51                   push ecx
// 005756eb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005756ef  51                   push ecx
// 005756f0  8d4c240c             lea ecx, [esp + 0xc]
// 005756f4  e827050900           call 0x605c20
// 005756f9  83c408               add esp, 8
// 005756fc  c20400               ret 4

struct S;

struct T {
    unsigned int data[2];
    void __thiscall initialize(void* argument, S* owner, void* value);
};

struct S {
    char padding[0x20c];
    void* value;
    void __thiscall f(void* argument);
};

void S::f(void* argument)
{
    T temporary;
    temporary.initialize(argument, this, value);
}
