// from server: 100% by EspClaude
// from server: 54% by colin
// roc 2007-08 00447520  unit: VCRenderSettings::?$FactoryProduct  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00447520
//
// 00447520  51                   push ecx
// 00447521  d905f0fe7800         fld dword ptr [0x78fef0]
// 00447527  8d91f0000000         lea edx, [ecx + 0xf0]
// 0044752d  d91c24               fstp dword ptr [esp]
// 00447530  d902                 fld dword ptr [edx]
// 00447532  d9442408             fld dword ptr [esp + 8]
// 00447536  ded9                 fcompp 
// 00447538  dfe0                 fnstsw ax
// 0044753a  f6c441               test ah, 0x41
// 0044753d  7504                 jne 0x447543
// 0044753f  8d542408             lea edx, [esp + 8]
// 00447543  d902                 fld dword ptr [edx]
// 00447545  dc1de8fe7800         fcomp qword ptr [0x78fee8]
// 0044754b  dfe0                 fnstsw ax
// 0044754d  f6c405               test ah, 5
// 00447550  7b03                 jnp 0x447555
// 00447552  8d1424               lea edx, [esp]
// 00447555  d902                 fld dword ptr [edx]
// 00447557  d95c2408             fstp dword ptr [esp + 8]
// 0044755b  d9442408             fld dword ptr [esp + 8]
// 0044755f  d9c0                 fld st(0)
// 00447561  d981f4000000         fld dword ptr [ecx + 0xf4]
// 00447567  dae9                 fucompp 
// 00447569  dfe0                 fnstsw ax
// 0044756b  f6c444               test ah, 0x44
// 0044756e  7b16                 jnp 0x447586
// 00447570  d999f4000000         fstp dword ptr [ecx + 0xf4]
// 00447576  83c404               add esp, 4
// 00447579  c7442404a4bc8b00     mov dword ptr [esp + 4], 0x8bbca4
// 00447581  e98ad1ffff           jmp 0x444710
// 00447586  ddd8                 fstp st(0)
// 00447588  59                   pop ecx
// 00447589  c20400               ret 4

struct PropDesc { int dummy; };
extern PropDesc desc_8bbca4;

struct CRenderSettings {
    char pad[0xf0];
    float minValue;
    float value;
    void raisePropertyChanged(const PropDesc& d);
    void setValue(float);
};

void CRenderSettings::setValue(float v)
{
    float hi = 100.0f;
    float* p = &minValue;
    if (*p < v)
        p = &v;
    if (!(*p < 100.0))
        p = &hi;
    float result = *p;
    if (result != value) {
        value = result;
        raisePropertyChanged(desc_8bbca4);
    }
}
