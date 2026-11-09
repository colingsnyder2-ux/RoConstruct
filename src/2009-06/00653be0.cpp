// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005c73e0  unit: RBX::FillTool  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005c73e0
//
// 005c73e0  6aff                 push -1
// 005c73e2  683bf47b00           push 0x7bf43b
// 005c73e7  64a100000000         mov eax, dword ptr fs:[0]
// 005c73ed  50                   push eax
// 005c73ee  64892500000000       mov dword ptr fs:[0], esp
// 005c73f5  51                   push ecx
// 005c73f6  56                   push esi
// 005c73f7  57                   push edi
// 005c73f8  6a24                 push 0x24
// 005c73fa  8bf9                 mov edi, ecx
// 005c73fc  e81f950d00           call 0x6a0920
// 005c7401  8bf0                 mov esi, eax
// 005c7403  83c404               add esp, 4
// 005c7406  89742408             mov dword ptr [esp + 8], esi
// 005c740a  33c0                 xor eax, eax
// 005c740c  89442414             mov dword ptr [esp + 0x14], eax
// 005c7410  3bf0                 cmp esi, eax
// 005c7412  741a                 je 0x5c742e
// 005c7414  8b4718               mov eax, dword ptr [edi + 0x18]
// 005c7417  50                   push eax
// 005c7418  8bce                 mov ecx, esi
// 005c741a  e871effeff           call 0x5b6390
// 005c741f  c7066c988300         mov dword ptr [esi], 0x83986c
// 005c7425  c7460454988300       mov dword ptr [esi + 4], 0x839854
// 005c742c  8bc6                 mov eax, esi
// 005c742e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005c7432  5f                   pop edi
// 005c7433  5e                   pop esi
// 005c7434  64890d00000000       mov dword ptr fs:[0], ecx
// 005c743b  83c410               add esp, 0x10
// 005c743e  c3                   ret 

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Object
{
    unsigned int table0;
    unsigned int table1;
    unsigned char storage[28];

    Object(void*);
};

struct Derived : Object
{
    Derived(void*);
};

inline Derived::Derived(void* argument) : Object(argument)
{
    table0 = 0x83986c;
    table1 = 0x839854;
}

struct S
{
    unsigned char storage[24];
    void* argument;

    Object* f();
};

Object* S::f()
{
    return new Derived(argument);
}
