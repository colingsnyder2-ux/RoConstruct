// from server: 100% by EspClaude
// from server: 53% by colin
// roc 2007-08 00447410  unit: VCRenderSettings::?$FactoryProduct  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00447410
//
// 00447410  51                   push ecx
// 00447411  d9442408             fld dword ptr [esp + 8]
// 00447415  56                   push esi
// 00447416  57                   push edi
// 00447417  8bf9                 mov edi, ecx
// 00447419  d987e8000000         fld dword ptr [edi + 0xe8]
// 0044741f  8db7e8000000         lea esi, [edi + 0xe8]
// 00447425  d8d9                 fcomp st(1)
// 00447427  dfe0                 fnstsw ax
// 00447429  f6c441               test ah, 0x41
// 0044742c  750d                 jne 0x44743b
// 0044742e  51                   push ecx
// 0044742f  d91c24               fstp dword ptr [esp]
// 00447432  e839ffffff           call 0x447370
// 00447437  d9442410             fld dword ptr [esp + 0x10]
// 0044743b  d906                 fld dword ptr [esi]
// 0044743d  ded9                 fcompp 
// 0044743f  dfe0                 fnstsw ax
// 00447441  f6c405               test ah, 5
// 00447444  7a04                 jp 0x44744a
// 00447446  8d742410             lea esi, [esp + 0x10]
// 0044744a  d906                 fld dword ptr [esi]
// 0044744c  d95c2410             fstp dword ptr [esp + 0x10]
// 00447450  d905f0fe7800         fld dword ptr [0x78fef0]
// 00447456  d95c2408             fstp dword ptr [esp + 8]
// 0044745a  d9442410             fld dword ptr [esp + 0x10]
// 0044745e  dc1de8fe7800         fcomp qword ptr [0x78fee8]
// 00447464  dfe0                 fnstsw ax
// 00447466  f6c405               test ah, 5
// 00447469  8d442410             lea eax, [esp + 0x10]
// 0044746d  7b04                 jnp 0x447473
// 0044746f  8d442408             lea eax, [esp + 8]
// 00447473  d900                 fld dword ptr [eax]
// 00447475  d95c2410             fstp dword ptr [esp + 0x10]
// 00447479  d9442410             fld dword ptr [esp + 0x10]
// 0044747d  d9c0                 fld st(0)
// 0044747f  d987ec000000         fld dword ptr [edi + 0xec]
// 00447485  dae9                 fucompp 
// 00447487  dfe0                 fnstsw ax
// 00447489  f6c444               test ah, 0x44
// 0044748c  7b18                 jnp 0x4474a6
// 0044748e  686cbc8b00           push 0x8bbc6c
// 00447493  d99fec000000         fstp dword ptr [edi + 0xec]
// 00447499  8bcf                 mov ecx, edi
// 0044749b  e870d2ffff           call 0x444710
// 004474a0  5f                   pop edi
// 004474a1  5e                   pop esi
// 004474a2  59                   pop ecx
// 004474a3  c20400               ret 4
// 004474a6  5f                   pop edi
// 004474a7  ddd8                 fstp st(0)
// 004474a9  5e                   pop esi
// 004474aa  59                   pop ecx
// 004474ab  c20400               ret 4

#include <algorithm>

struct PropertyDescriptor;
extern PropertyDescriptor g_desc_8bbc6c;

struct CRenderSettings {
    char pad[0xe8];
    float field_e8;   // +0xe8
    float field_ec;   // +0xec
    void sub_447370(float);
    void raisePropertyChanged(const PropertyDescriptor&);
    void setAASamples(float value);
};

void CRenderSettings::setAASamples(float value) {
    if (value < field_e8)
        sub_447370(value);
    value = std::max(field_e8, value);
    value = std::min(100.0f, value);
    if (value != field_ec) {
        field_ec = value;
        raisePropertyChanged(g_desc_8bbc6c);
    }
}
