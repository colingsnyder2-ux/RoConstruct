// from server: 86% by EspClaude
// from server: 75% by colin
// roc 2007-08 00447370  unit: VCRenderSettings::?$FactoryProduct  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00447370
//
// 00447370  51                   push ecx
// 00447371  d9442408             fld dword ptr [esp + 8]
// 00447375  56                   push esi
// 00447376  57                   push edi
// 00447377  8bf9                 mov edi, ecx
// 00447379  d987ec000000         fld dword ptr [edi + 0xec]
// 0044737f  8db7ec000000         lea esi, [edi + 0xec]
// 00447385  d8d9                 fcomp st(1)
// 00447387  dfe0                 fnstsw ax
// 00447389  f6c405               test ah, 5
// 0044738c  7a0d                 jp 0x44739b
// 0044738e  51                   push ecx
// 0044738f  d91c24               fstp dword ptr [esp]
// 00447392  e879000000           call 0x447410
// 00447397  d9442410             fld dword ptr [esp + 0x10]
// 0044739b  d906                 fld dword ptr [esi]
// 0044739d  ded9                 fcompp 
// 0044739f  dfe0                 fnstsw ax
// 004473a1  f6c441               test ah, 0x41
// 004473a4  7504                 jne 0x4473aa
// 004473a6  8d742410             lea esi, [esp + 0x10]
// 004473aa  d906                 fld dword ptr [esi]
// 004473ac  d95c2410             fstp dword ptr [esp + 0x10]
// 004473b0  d9ee                 fldz 
// 004473b2  d95c2408             fstp dword ptr [esp + 8]
// 004473b6  d9442410             fld dword ptr [esp + 0x10]
// 004473ba  dc1de0fe7800         fcomp qword ptr [0x78fee0]
// 004473c0  dfe0                 fnstsw ax
// 004473c2  f6c441               test ah, 0x41
// 004473c5  8d442410             lea eax, [esp + 0x10]
// 004473c9  7404                 je 0x4473cf
// 004473cb  8d442408             lea eax, [esp + 8]
// 004473cf  d900                 fld dword ptr [eax]
// 004473d1  d95c2410             fstp dword ptr [esp + 0x10]
// 004473d5  d9442410             fld dword ptr [esp + 0x10]
// 004473d9  d9c0                 fld st(0)
// 004473db  d987e8000000         fld dword ptr [edi + 0xe8]
// 004473e1  dae9                 fucompp 
// 004473e3  dfe0                 fnstsw ax
// 004473e5  f6c444               test ah, 0x44
// 004473e8  7b18                 jnp 0x447402
// 004473ea  6850bc8b00           push 0x8bbc50
// 004473ef  d99fe8000000         fstp dword ptr [edi + 0xe8]
// 004473f5  8bcf                 mov ecx, edi
// 004473f7  e814d3ffff           call 0x444710
// 004473fc  5f                   pop edi
// 004473fd  5e                   pop esi
// 004473fe  59                   pop ecx
// 004473ff  c20400               ret 4
// 00447402  5f                   pop edi
// 00447403  ddd8                 fstp st(0)
// 00447405  5e                   pop esi
// 00447406  59                   pop ecx
// 00447407  c20400               ret 4

template<class T> inline const T& minRef(const T& left, const T& right)
{
    return (right < left) ? right : left;
}

template<class T> inline const T& maxRef(const T& left, const T& right)
{
    return (left < right) ? right : left;
}

struct PropertyDescriptor;
extern PropertyDescriptor changedProperty;

struct CRenderSettings {
    char pad[0xe8];
    float field_e8;
    float field_ec;
    void sub_447410(float);
    void sub_444710(const PropertyDescriptor&);
    void setSomething(float);
};

void CRenderSettings::setSomething(float value)
{
    if (value > field_ec)
        sub_447410(value);
    value = minRef(field_ec, value);
    value = maxRef(value, 0.0f);
    if (value != field_e8) {
        field_e8 = value;
        sub_444710(changedProperty);
    }
}
