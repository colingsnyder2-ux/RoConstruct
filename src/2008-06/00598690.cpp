// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 83% by king_originala
// roc 2008-06 00598690  unit: RBX::Decal  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00598690
//
// 00598690  d9442404             fld dword ptr [esp + 4]
// 00598694  d89164010000         fcom dword ptr [ecx + 0x164]
// 0059869a  dfe0                 fnstsw ax
// 0059869c  f6c444               test ah, 0x44
// 0059869f  7b1e                 jnp 0x5986bf
// 005986a1  d9ee                 fldz 
// 005986a3  d8d9                 fcomp st(1)
// 005986a5  dfe0                 fnstsw ax
// 005986a7  f6c441               test ah, 0x41
// 005986aa  7a13                 jp 0x5986bf
// 005986ac  d99964010000         fstp dword ptr [ecx + 0x164]
// 005986b2  c7442404f85e9700     mov dword ptr [esp + 4], 0x975ef8
// 005986ba  e94154e7ff           jmp 0x40db00
// 005986bf  ddd8                 fstp st(0)
// 005986c1  c20400               ret 4

extern char property;

struct Decal {
    char padding[0x164];
    float value;

    void setValue(float v);
    void notify(const void* descriptor);
};

void Decal::setValue(float v)
{
    if (value != v && v >= 0.0f) {
        value = v;
        notify(&property);
    }
}
