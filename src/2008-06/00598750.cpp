// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 77% by king_originala
// roc 2008-06 00598750  unit: RBX::Decal  size: 52 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00598750
//
// 00598750  d9442404             fld dword ptr [esp + 4]
// 00598754  d89170010000         fcom dword ptr [ecx + 0x170]
// 0059875a  dfe0                 fnstsw ax
// 0059875c  f6c444               test ah, 0x44
// 0059875f  7b1e                 jnp 0x59877f
// 00598761  d9ee                 fldz 
// 00598763  d8d9                 fcomp st(1)
// 00598765  dfe0                 fnstsw ax
// 00598767  f6c405               test ah, 5
// 0059876a  7a13                 jp 0x59877f
// 0059876c  d99970010000         fstp dword ptr [ecx + 0x170]
// 00598772  c74424044c5f9700     mov dword ptr [esp + 4], 0x975f4c
// 0059877a  e98153e7ff           jmp 0x40db00
// 0059877f  ddd8                 fstp st(0)
// 00598781  c20400               ret 4

struct S {
    char padding[0x170];
    float value;
    void changed(const void*);
    void setValue(float);
};

void S::setValue(float v)
{
    if (value != v && v > 0.0f) {
        value = v;
        changed(reinterpret_cast<const void*>(0x975f4c));
    }
}
