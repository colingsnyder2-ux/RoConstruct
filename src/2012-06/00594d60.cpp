// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 007659b0  unit: RBX::Network::$$A6A?AW4FilterResult::?$CallbackDescImpl  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007659b0
//
// 007659b0  6aff                 push -1
// 007659b2  68d810ab00           push 0xab10d8
// 007659b7  64a100000000         mov eax, dword ptr fs:[0]
// 007659bd  50                   push eax
// 007659be  64892500000000       mov dword ptr fs:[0], esp
// 007659c5  51                   push ecx
// 007659c6  8b442428             mov eax, dword ptr [esp + 0x28]
// 007659ca  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007659ce  56                   push esi
// 007659cf  50                   push eax
// 007659d0  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007659d4  8bf1                 mov esi, ecx
// 007659d6  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 007659da  51                   push ecx
// 007659db  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007659df  52                   push edx
// 007659e0  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007659e4  50                   push eax
// 007659e5  8b442428             mov eax, dword ptr [esp + 0x28]
// 007659e9  51                   push ecx
// 007659ea  52                   push edx
// 007659eb  50                   push eax
// 007659ec  89742420             mov dword ptr [esp + 0x20], esi
// 007659f0  e83bffffff           call 0x765930
// 007659f5  50                   push eax
// 007659f6  8bce                 mov ecx, esi
// 007659f8  e803f1ffff           call 0x764b00
// 007659fd  6a10                 push 0x10
// 007659ff  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00765a07  c706ccf3ba00         mov dword ptr [esi], 0xbaf3cc
// 00765a0d  e808c72100           call 0x98211a
// 00765a12  83c404               add esp, 4
// 00765a15  85c0                 test eax, eax
// 00765a17  741b                 je 0x765a34
// 00765a19  57                   push edi
// 00765a1a  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00765a1e  33c9                 xor ecx, ecx
// 00765a20  33d2                 xor edx, edx
// 00765a22  897804               mov dword ptr [eax + 4], edi
// 00765a25  c70064f1ba00         mov dword ptr [eax], 0xbaf164
// 00765a2b  894808               mov dword ptr [eax + 8], ecx
// 00765a2e  89500c               mov dword ptr [eax + 0xc], edx
// 00765a31  5f                   pop edi
// 00765a32  eb02                 jmp 0x765a36
// 00765a34  33c0                 xor eax, eax
// 00765a36  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 00765a39  51                   push ecx
// 00765a3a  89462c               mov dword ptr [esi + 0x2c], eax
// 00765a3d  e8d2c62100           call 0x982114
// 00765a42  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00765a46  83c404               add esp, 4
// 00765a49  8bc6                 mov eax, esi
// 00765a4b  5e                   pop esi
// 00765a4c  64890d00000000       mov dword ptr fs:[0], ecx
// 00765a53  83c410               add esp, 0x10
// 00765a56  c22000               ret 0x20


void* __stdcall make_007659b0(int a, int b, int c, int d, int e, int f, int g);

struct Pair_007659b0 {
    int a;
    int b;
    Pair_007659b0() : a(0), b(0) {}
};

struct Desc_007659b0 {
    virtual void v();
};

struct DescImpl_007659b0 : Desc_007659b0 {
    int m4;
    Pair_007659b0 m8;
    DescImpl_007659b0(int x, const Pair_007659b0& p) : m4(x), m8(p) {}
    virtual void v();
};

struct Base_007659b0 {
    char pad[0x28];
    Desc_007659b0* m2c;
    Base_007659b0(void* p);
    ~Base_007659b0();
    virtual void v();
};

struct Derived_007659b0 : Base_007659b0 {
    Derived_007659b0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
    virtual void v();
};

Derived_007659b0::Derived_007659b0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
    : Base_007659b0(make_007659b0(a1, a3, a4, a5, a7, a8, a6))
{
    Desc_007659b0* p = new DescImpl_007659b0(a2, Pair_007659b0());
    Desc_007659b0* old = m2c;
    m2c = p;
    delete old;
}
