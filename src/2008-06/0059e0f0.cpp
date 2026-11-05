// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 81% by colin
// roc 2008-06 0059e0f0  unit: VCRenderSettings::?$EnumPropDescriptor  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0059e0f0
//
// 0059e0f0  d9ee                 fldz 
// 0059e0f2  56                   push esi
// 0059e0f3  d9442408             fld dword ptr [esp + 8]
// 0059e0f7  8bf1                 mov esi, ecx
// 0059e0f9  d8d1                 fcom st(1)
// 0059e0fb  dfe0                 fnstsw ax
// 0059e0fd  f6c441               test ah, 0x41
// 0059e100  7b11                 jnp 0x59e113
// 0059e102  ddd9                 fstp st(1)
// 0059e104  d9e8                 fld1 
// 0059e106  d8d1                 fcom st(1)
// 0059e108  dfe0                 fnstsw ax
// 0059e10a  f6c441               test ah, 0x41
// 0059e10d  7a04                 jp 0x59e113
// 0059e10f  ddd9                 fstp st(1)
// 0059e111  eb02                 jmp 0x59e115
// 0059e113  ddd8                 fstp st(0)
// 0059e115  d986dc020000         fld dword ptr [esi + 0x2dc]
// 0059e11b  dde9                 fucomp st(1)
// 0059e11d  dfe0                 fnstsw ax
// 0059e11f  f6c444               test ah, 0x44
// 0059e122  7b1f                 jnp 0x59e143
// 0059e124  51                   push ecx
// 0059e125  8d8e28020000         lea ecx, [esi + 0x228]
// 0059e12b  d91c24               fstp dword ptr [esp]
// 0059e12e  e80d950400           call 0x5e7640
// 0059e133  68905f9700           push 0x975f90
// 0059e138  8bce                 mov ecx, esi
// 0059e13a  e8c1f9e6ff           call 0x40db00
// 0059e13f  5e                   pop esi
// 0059e140  c20400               ret 4
// 0059e143  ddd8                 fstp st(0)
// 0059e145  5e                   pop esi
// 0059e146  c20400               ret 4

extern char descriptor;

struct FloatProperty {
    void set(float value);
};

struct Settings {
    void setValue(float value);
    void notify(void* property);
};

void Settings::setValue(float value) {
    float clamped;
    if (value <= 0.0f) {
        clamped = 0.0f;
    } else if (value >= 1.0f) {
        clamped = 1.0f;
    } else {
        clamped = value;
    }

    if (clamped != *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0x2dc)) {
        reinterpret_cast<FloatProperty*>(reinterpret_cast<char*>(this) + 0x228)->set(clamped);
        notify(&descriptor);
    }
}
