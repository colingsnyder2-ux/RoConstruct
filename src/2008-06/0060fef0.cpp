// from server: 100% by colin
// from server: 98% by king_originala
// roc 2008-06 0060fef0  unit: RBX::BlockBlockContact  size: 132 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0060fef0
//
// 0060fef0  f60550f0960001       test byte ptr [0x96f050], 1
// 0060fef7  751b                 jne 0x60ff14
// 0060fef9  d9ee                 fldz 
// 0060fefb  830d50f0960001       or dword ptr [0x96f050], 1
// 0060ff02  d91544f09600         fst dword ptr [0x96f044]
// 0060ff08  d91548f09600         fst dword ptr [0x96f048]
// 0060ff0e  d91d4cf09600         fstp dword ptr [0x96f04c]
// 0060ff14  d90544f09600         fld dword ptr [0x96f044]
// 0060ff1a  53                   push ebx
// 0060ff1b  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0060ff1f  d81b                 fcomp dword ptr [ebx]
// 0060ff21  dfe0                 fnstsw ax
// 0060ff23  f6c444               test ah, 0x44
// 0060ff26  7a20                 jp 0x60ff48
// 0060ff28  d90548f09600         fld dword ptr [0x96f048]
// 0060ff2e  d85b04               fcomp dword ptr [ebx + 4]
// 0060ff31  dfe0                 fnstsw ax
// 0060ff33  f6c444               test ah, 0x44
// 0060ff36  7a10                 jp 0x60ff48
// 0060ff38  d9054cf09600         fld dword ptr [0x96f04c]
// 0060ff3e  d85b08               fcomp dword ptr [ebx + 8]
// 0060ff41  dfe0                 fnstsw ax
// 0060ff43  f6c444               test ah, 0x44
// 0060ff46  7b2a                 jnp 0x60ff72
// 0060ff48  56                   push esi
// 0060ff49  57                   push edi
// 0060ff4a  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0060ff4e  33f6                 xor esi, esi
// 0060ff50  397704               cmp dword ptr [edi + 4], esi
// 0060ff53  7e1b                 jle 0x60ff70
// 0060ff55  8b07                 mov eax, dword ptr [edi]
// 0060ff57  8b04b0               mov eax, dword ptr [eax + esi*4]
// 0060ff5a  50                   push eax
// 0060ff5b  e820a0f8ff           call 0x599f80
// 0060ff60  53                   push ebx
// 0060ff61  50                   push eax
// 0060ff62  e8d9e8ffff           call 0x60e840
// 0060ff67  46                   inc esi
// 0060ff68  83c40c               add esp, 0xc
// 0060ff6b  3b7704               cmp esi, dword ptr [edi + 4]
// 0060ff6e  7ce5                 jl 0x60ff55
// 0060ff70  5f                   pop edi
// 0060ff71  5e                   pop esi
// 0060ff72  5b                   pop ebx
// 0060ff73  c3                   ret 

#pragma float_control(precise, off)

struct PartInstance;

struct GetSetImpl
{
    static PartInstance* get(PartInstance* p);
};

struct Vector
{
    float x, y, z;
    Vector(float a, float b, float c);
};

inline Vector::Vector(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

struct PartList
{
    PartInstance** data;
    int count;
};

void __cdecl apply(PartInstance* part, const Vector* value);

void __cdecl update(PartList* parts, const Vector* value)
{
    static Vector zero(0.0f, 0.0f, 0.0f);

    if (value->x != zero.x ||
        value->y != zero.y ||
        value->z != zero.z)
    {
        for (int i = 0; i < parts->count; ++i)
        {
            PartInstance* dataCopy = parts->data[i];
            PartInstance* part = GetSetImpl::get(dataCopy);
            apply(part, value);
        }
    }
}
