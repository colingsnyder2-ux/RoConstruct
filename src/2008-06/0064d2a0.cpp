// from server: 100% by EspClaude
// from server: 94% by colin
// roc 2008-06 0064d2a0  unit: RBX::SimJobStage  size: 87 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064d2a0
//
// 0064d2a0  53                   push ebx
// 0064d2a1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0064d2a5  56                   push esi
// 0064d2a6  8bf1                 mov esi, ecx
// 0064d2a8  57                   push edi
// 0064d2a9  8bcb                 mov ecx, ebx
// 0064d2ab  e8608ef9ff           call 0x5e6110
// 0064d2b0  8bf8                 mov edi, eax
// 0064d2b2  57                   push edi
// 0064d2b3  8bce                 mov ecx, esi
// 0064d2b5  e8c6feffff           call 0x64d180
// 0064d2ba  85ff                 test edi, edi
// 0064d2bc  740a                 je 0x64d2c8
// 0064d2be  8b07                 mov eax, dword ptr [edi]
// 0064d2c0  8b10                 mov edx, dword ptr [eax]
// 0064d2c2  6a01                 push 1
// 0064d2c4  8bcf                 mov ecx, edi
// 0064d2c6  ffd2                 call edx
// 0064d2c8  8bcb                 mov ecx, ebx
// 0064d2ca  e8918ef9ff           call 0x5e6160
// 0064d2cf  50                   push eax
// 0064d2d0  8b06                 mov eax, dword ptr [esi]
// 0064d2d2  8b500c               mov edx, dword ptr [eax + 0xc]
// 0064d2d5  8bce                 mov ecx, esi
// 0064d2d7  ffd2                 call edx
// 0064d2d9  8bc8                 mov ecx, eax
// 0064d2db  e830defaff           call 0x5fb110
// 0064d2e0  8b03                 mov eax, dword ptr [ebx]
// 0064d2e2  8b5008               mov edx, dword ptr [eax + 8]
// 0064d2e5  8bcb                 mov ecx, ebx
// 0064d2e7  ffd2                 call edx
// 0064d2e9  56                   push esi
// 0064d2ea  8bcb                 mov ecx, ebx
// 0064d2ec  e84f85ffff           call 0x645840
// 0064d2f1  5f                   pop edi
// 0064d2f2  5e                   pop esi
// 0064d2f3  5b                   pop ebx
// 0064d2f4  c20400               ret 4

struct Owned { virtual ~Owned(); };
struct Target;
struct Arg {
    virtual void v0(); virtual void v1(); virtual void v2();
    Owned* make();
    int value();
    void attach(void*);
};
struct S_func_005e6110 {
    char pad0[64];
    int m_x;
    Owned* f();
};

struct I_func_005e6160 {
    char pad[160];
    int m_x;
};

struct S_func_005e6160 {
    char pad[28];
    I_func_005e6160* m_p;
    int f();
};

struct Target { void g(int); };
struct Self { virtual void v0(); virtual void v1(); virtual void v2(); virtual Target* get(); };

struct S_func_00645840 {
    int field0;
    int field4;
    void f(int);
};

struct S_func_0064d180 {
    void f(Owned*);
};

struct S_func_0064d2a0 {
    void f(Arg*);
};

void S_func_0064d2a0::f(Arg* a)
{
    Owned* r = a->make();
    ((S_func_0064d180*)this)->f(r);
    delete r;
    ((Self*)this)->get()->g(a->value());
    a->v2();
    a->attach(this);
}
