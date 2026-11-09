// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 83% by king_originala
// roc 2008-06 005986d0  unit: RBX::Decal  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005986d0
//
// 005986d0  d9442404             fld dword ptr [esp + 4]
// 005986d4  d89168010000         fcom dword ptr [ecx + 0x168]
// 005986da  dfe0                 fnstsw ax
// 005986dc  f6c444               test ah, 0x44
// 005986df  7b1e                 jnp 0x5986ff
// 005986e1  d9ee                 fldz 
// 005986e3  d8d9                 fcomp st(1)
// 005986e5  dfe0                 fnstsw ax
// 005986e7  f6c405               test ah, 5
// 005986ea  7a13                 jp 0x5986ff
// 005986ec  d99968010000         fstp dword ptr [ecx + 0x168]
// 005986f2  c7442404305f9700     mov dword ptr [esp + 4], 0x975f30
// 005986fa  e90154e7ff           jmp 0x40db00
// 005986ff  ddd8                 fstp st(0)
// 00598701  c20400               ret 4

extern char property;

struct Decal {
    char padding[0x168];
    float value;

    void notify(const char*);
    void setValue(float);
};

void Decal::setValue(float v)
{
    if (value != v && v > 0.0f) {
        value = v;
        notify(&property);
    }
}
