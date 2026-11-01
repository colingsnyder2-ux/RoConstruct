// from server: 100% by Espeon
// from server: 89% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 79% by colin
// roc 2008-06 00449060  unit: CRenderSettings  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00449060
//
// 00449060  51                   push ecx
// 00449061  d9ee                 fldz 
// 00449063  56                   push esi
// 00449064  d9542404             fst dword ptr [esp + 4]
// 00449068  8d74240c             lea esi, [esp + 0xc]
// 0044906c  d85c240c             fcomp dword ptr [esp + 0xc]
// 00449070  dfe0                 fnstsw ax
// 00449072  f6c405               test ah, 5
// 00449075  7b04                 jnp 0x44907b
// 00449077  8d742404             lea esi, [esp + 4]
// 0044907b  d98150010000         fld dword ptr [ecx + 0x150]
// 00449081  8d9150010000         lea edx, [ecx + 0x150]
// 00449087  d81e                 fcomp dword ptr [esi]
// 00449089  dfe0                 fnstsw ax
// 0044908b  f6c441               test ah, 0x41
// 0044908e  7502                 jne 0x449092
// 00449090  8bd6                 mov edx, esi
// 00449092  d902                 fld dword ptr [edx]
// 00449094  5e                   pop esi
// 00449095  d9814c010000         fld dword ptr [ecx + 0x14c]
// 0044909b  dde9                 fucomp st(1)
// 0044909d  dfe0                 fnstsw ax
// 0044909f  f6c444               test ah, 0x44
// 004490a2  7b16                 jnp 0x4490ba
// 004490a4  d9994c010000         fstp dword ptr [ecx + 0x14c]
// 004490aa  83c404               add esp, 4
// 004490ad  c744240480d49600     mov dword ptr [esp + 4], 0x96d480
// 004490b5  e9464afcff           jmp 0x40db00
// 004490ba  ddd8                 fstp st(0)
// 004490bc  59                   pop ecx
// 004490bd  c20400               ret 4

struct CRenderSettings {
    char padding[0x14c];
    volatile float value14c;
    volatile float value150;
    void setValue(float);
    void notifyChange(void*);
};



void CRenderSettings::setValue(float v)
{
    float zero = 0.0f;
    float* src;
    if (zero < v)
        src = &v;
    else
        src = &zero;

    volatile float* chosen = &value150;
    if (value150 > *src)
        chosen = src;

    float result = *chosen;
    if (result != value14c) {
        value14c = result;
        notifyChange(reinterpret_cast<void*>(0x96d480));
    }
}
