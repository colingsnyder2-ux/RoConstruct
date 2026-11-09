// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 77% by king_originala
// roc 2008-06 00598710  unit: RBX::Decal  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00598710
//
// 00598710  d9442404             fld dword ptr [esp + 4]
// 00598714  d8916c010000         fcom dword ptr [ecx + 0x16c]
// 0059871a  dfe0                 fnstsw ax
// 0059871c  f6c444               test ah, 0x44
// 0059871f  7b1e                 jnp 0x59873f
// 00598721  d9ee                 fldz 
// 00598723  d8d9                 fcomp st(1)
// 00598725  dfe0                 fnstsw ax
// 00598727  f6c405               test ah, 5
// 0059872a  7a13                 jp 0x59873f
// 0059872c  d9996c010000         fstp dword ptr [ecx + 0x16c]
// 00598732  c7442404685f9700     mov dword ptr [esp + 4], 0x975f68
// 0059873a  e9c153e7ff           jmp 0x40db00
// 0059873f  ddd8                 fstp st(0)
// 00598741  c20400               ret 4

struct Decal {
    char padding[0x16c];
    float value;
    void setValue(float v);
    void notify(const void* property);
};

void Decal::setValue(float v)
{
    if (value != v && v > 0.0f) {
        value = v;
        notify((const void*)0x975f68);
    }
}
