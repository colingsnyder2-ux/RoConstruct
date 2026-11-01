// from server: 100% by colin
// from server: 88% by colin
// from server: 66% by atomic.potato
// roc 2008-06 0066ed50  unit: RBX::HUMAN::MovingNoPhysicsBase  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066ed50
// 0066ed50  53                   push ebx
// 0066ed51  56                   push esi
// 0066ed52  8bf1                 mov esi, ecx
// 0066ed54  8b86c4000000         mov eax, dword ptr [esi + 0xc4]
// 0066ed5a  57                   push edi
// 0066ed5b  8dbec4000000         lea edi, [esi + 0xc4]
// 0066ed61  8d8828020000         lea ecx, [eax + 0x228]
// 0066ed67  85c9                 test ecx, ecx
// 0066ed69  7407                 je 0x66ed72
// 0066ed6b  6a00                 push 0
// 0066ed6d  e8ce93f7ff           call 0x5e8140
// 0066ed72  8d8ed0000000         lea ecx, [esi + 0xd0]
// 0066ed78  e8b364f2ff           call 0x595230
// 0066ed7d  8bce                 mov ecx, esi
// 0066ed7f  8d9ea0000000         lea ebx, [esi + 0xa0]
// 0066ed85  e8c64f1200           call 0x793d50
// 0066ed8a  8b801c020000         mov eax, dword ptr [eax + 0x21c]
// 0066ed90  53                   push ebx
// 0066ed91  8bc8                 mov ecx, eax
// 0066ed93  e818a6f7ff           call 0x5e93b0
// 0066ed98  8bc8                 mov ecx, eax
// 0066ed9a  e851e4fdff           call 0x64d1f0
// 0066ed9f  8b07                 mov eax, dword ptr [edi]
// 0066eda1  8b8ecc000000         mov ecx, dword ptr [esi + 0xcc]
// 0066eda7  50                   push eax
// 0066eda8  e893a2f7ff           call 0x5e9040
// 0066edad  8bcf                 mov ecx, edi
// 0066edaf  5f                   pop edi
// 0066edb0  5e                   pop esi
// 0066edb1  5b                   pop ebx
// 0066edb2  e9c980deff           jmp 0x456e80
struct Sub5 { int x; };

struct Inner {
    void method(int);
};

struct Holder {
    char pad[0x228];
    Inner inner;
};

struct Ptr {
    Holder* p;
    void reset();
};

struct Sub2 {
    void method();
};

struct Result {
    void method();
};

struct Sub4 {
    Result* method(Sub5*);
};

struct World {
    char pad[0x21c];
    Sub4* sub;
};

struct Sub6 {
    void method(Holder*);
};

struct Base0 {
    char pad0[0xa0];
};

struct MovingNoPhysicsBase : Base0, Sub5 {
    char pad1[0x20];
    Ptr field_c4;
    char pad2[0x4];
    Sub6* field_cc;
    Sub2 field_d0;

    World* getWorld();
    void func();
};

void MovingNoPhysicsBase::func() {
    Holder& h = *field_c4.p;
    if (&h.inner)
        h.inner.method(0);
    field_d0.method();
    Sub5* a = static_cast<Sub5*>(this);
    Sub4* s = getWorld()->sub;
    s->method(a)->method();
    field_cc->method(field_c4.p);
    field_c4.reset();
}
