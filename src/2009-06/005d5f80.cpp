// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005aae30  unit: RBX::VScriptContext::?$FactoryProduct  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005aae30
//
// 005aae30  64a100000000         mov eax, dword ptr fs:[0]
// 005aae36  6aff                 push -1
// 005aae38  68d8f47b00           push 0x7bf4d8
// 005aae3d  50                   push eax
// 005aae3e  64892500000000       mov dword ptr fs:[0], esp
// 005aae45  8b01                 mov eax, dword ptr [ecx]
// 005aae47  83ec28               sub esp, 0x28
// 005aae4a  85c0                 test eax, eax
// 005aae4c  7516                 jne 0x5aae64
// 005aae4e  8d0c24               lea ecx, [esp]
// 005aae51  e89af0e5ff           call 0x409ef0
// 005aae56  50                   push eax
// 005aae57  c744243400000000     mov dword ptr [esp + 0x34], 0
// 005aae5f  e89cf6e5ff           call 0x40a500
// 005aae64  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005aae68  8b4004               mov eax, dword ptr [eax + 4]
// 005aae6b  52                   push edx
// 005aae6c  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005aae70  52                   push edx
// 005aae71  83c108               add ecx, 8
// 005aae74  51                   push ecx
// 005aae75  ffd0                 call eax
// 005aae77  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 005aae7b  83c40c               add esp, 0xc
// 005aae7e  64890d00000000       mov dword ptr fs:[0], ecx
// 005aae85  83c434               add esp, 0x34
// 005aae88  c20800               ret 8

struct ExceptionObject
{
    unsigned long words[10];
    ExceptionObject();
    ~ExceptionObject();
};

__declspec(noreturn) void __cdecl raise_exception(const void* source);

struct S
{
    unsigned long* table;
    int f(int first, int second);
};

int S::f(int first, int second)
{
    if (!table)
        raise_exception(&ExceptionObject());

    typedef int (__cdecl *Invoker)(void*, int, int);
    return reinterpret_cast<Invoker>(table[1])(
        reinterpret_cast<char*>(this) + 8, first, second);
}
