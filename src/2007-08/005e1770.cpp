// from server: 99% by EspClaude
// from server: 100% by EspClaude
// roc 2008-06 006106c0  unit: RBX::BlockBlockContact  size: 356 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006106c0
//
// 006106c0  83ec0c               sub esp, 0xc
// 006106c3  56                   push esi
// 006106c4  8b742418             mov esi, dword ptr [esp + 0x18]
// 006106c8  837e0400             cmp dword ptr [esi + 4], 0
// 006106cc  7547                 jne 0x610715
// 006106ce  f60550f0960001       test byte ptr [0x96f050], 1
// 006106d5  751b                 jne 0x6106f2
// 006106d7  d9ee                 fldz 
// 006106d9  830d50f0960001       or dword ptr [0x96f050], 1
// 006106e0  d91544f09600         fst dword ptr [0x96f044]
// 006106e6  d91548f09600         fst dword ptr [0x96f048]
// 006106ec  d91d4cf09600         fstp dword ptr [0x96f04c]
// 006106f2  8b442414             mov eax, dword ptr [esp + 0x14]
// 006106f6  d90544f09600         fld dword ptr [0x96f044]
// 006106fc  d918                 fstp dword ptr [eax]
// 006106fe  5e                   pop esi
// 006106ff  d90548f09600         fld dword ptr [0x96f048]
// 00610705  d95804               fstp dword ptr [eax + 4]
// 00610708  d9054cf09600         fld dword ptr [0x96f04c]
// 0061070e  d95808               fstp dword ptr [eax + 8]
// 00610711  83c40c               add esp, 0xc
// 00610714  c3                   ret 
// 00610715  8b0d50f09600         mov ecx, dword ptr [0x96f050]
// 0061071b  d9ee                 fldz 
// 0061071d  f6c101               test cl, 1
// 00610720  7523                 jne 0x610745
// 00610722  d9c0                 fld st(0)
// 00610724  83c901               or ecx, 1
// 00610727  d91544f09600         fst dword ptr [0x96f044]
// 0061072d  890d50f09600         mov dword ptr [0x96f050], ecx
// 00610733  d9c1                 fld st(1)
// 00610735  d91548f09600         fst dword ptr [0x96f048]
// 0061073b  d9c2                 fld st(2)
// 0061073d  d9154cf09600         fst dword ptr [0x96f04c]
// 00610743  eb14                 jmp 0x610759
// 00610745  d9054cf09600         fld dword ptr [0x96f04c]
// 0061074b  d90548f09600         fld dword ptr [0x96f048]
// 00610751  d90544f09600         fld dword ptr [0x96f044]
// 00610757  d9ca                 fxch st(2)
// 00610759  d9ca                 fxch st(2)
// 0061075b  d9542404             fst dword ptr [esp + 4]
// 0061075f  d9c9                 fxch st(1)
// 00610761  d9542408             fst dword ptr [esp + 8]
// 00610765  d9ca                 fxch st(2)
// 00610767  d954240c             fst dword ptr [esp + 0xc]
// 0061076b  f6c101               test cl, 1
// 0061076e  752d                 jne 0x61079d
// 00610770  ddd9                 fstp st(1)
// 00610772  83c901               or ecx, 1
// 00610775  ddd9                 fstp st(1)
// 00610777  890d50f09600         mov dword ptr [0x96f050], ecx
// 0061077d  ddd8                 fstp st(0)
// 0061077f  d9c0                 fld st(0)
// 00610781  d91544f09600         fst dword ptr [0x96f044]
// 00610787  d9c1                 fld st(1)
// 00610789  d91548f09600         fst dword ptr [0x96f048]
// 0061078f  d9c2                 fld st(2)
// 00610791  d9154cf09600         fst dword ptr [0x96f04c]
// 00610797  d9c9                 fxch st(1)
// 00610799  d9ca                 fxch st(2)
// 0061079b  d9c9                 fxch st(1)
// 0061079d  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006107a1  d9c9                 fxch st(1)
// 006107a3  d81a                 fcomp dword ptr [edx]
// 006107a5  dfe0                 fnstsw ax
// 006107a7  f6c444               test ah, 0x44
// 006107aa  7a35                 jp 0x6107e1
// 006107ac  d9c9                 fxch st(1)
// 006107ae  d85a04               fcomp dword ptr [edx + 4]
// 006107b1  dfe0                 fnstsw ax
// 006107b3  f6c444               test ah, 0x44
// 006107b6  7a2b                 jp 0x6107e3
// 006107b8  d85a08               fcomp dword ptr [edx + 8]
// 006107bb  dfe0                 fnstsw ax
// 006107bd  f6c444               test ah, 0x44
// 006107c0  7a23                 jp 0x6107e5
// 006107c2  ddd8                 fstp st(0)
// 006107c4  8b442414             mov eax, dword ptr [esp + 0x14]
// 006107c8  d9442404             fld dword ptr [esp + 4]
// 006107cc  d918                 fstp dword ptr [eax]
// 006107ce  5e                   pop esi
// 006107cf  d9442404             fld dword ptr [esp + 4]
// 006107d3  d95804               fstp dword ptr [eax + 4]
// 006107d6  d9442408             fld dword ptr [esp + 8]
// 006107da  d95808               fstp dword ptr [eax + 8]
// 006107dd  83c40c               add esp, 0xc
// 006107e0  c3                   ret 
// 006107e1  ddd9                 fstp st(1)
// 006107e3  ddd8                 fstp st(0)
// 006107e5  f6c101               test cl, 1
// 006107e8  751d                 jne 0x610807
// 006107ea  d91544f09600         fst dword ptr [0x96f044]
// 006107f0  83c901               or ecx, 1
// 006107f3  d91548f09600         fst dword ptr [0x96f048]
// 006107f9  890d50f09600         mov dword ptr [0x96f050], ecx
// 006107ff  d91d4cf09600         fstp dword ptr [0x96f04c]
// 00610805  eb02                 jmp 0x610809
// 00610807  ddd8                 fstp st(0)
// 00610809  8b442420             mov eax, dword ptr [esp + 0x20]
// 0061080d  50                   push eax
// 0061080e  8d4c2408             lea ecx, [esp + 8]
// 00610812  51                   push ecx
// 00610813  52                   push edx
// 00610814  6844f09600           push 0x96f044
// 00610819  56                   push esi
// 0061081a  e861fdffff           call 0x610580
// 0061081f  83c414               add esp, 0x14
// 00610822  eba0                 jmp 0x6107c4

// from server: 91% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector
{
    float x, y, z;

    Vector(float, float, float);
    Vector(const Vector&);
    bool operator!=(const Vector&) const;
    static const Vector& zero();
};

inline Vector::Vector(float a, float b, float c)
    : x(a), y(b), z(c)
{
}

inline Vector::Vector(const Vector& v)
    : x(v.x), y(v.y), z(v.z)
{
}

inline bool Vector::operator!=(const Vector& v) const
{
    return x != v.x || y != v.y || z != v.z;
}

inline const Vector& Vector::zero()
{
    static const Vector value(0.0f, 0.0f, 0.0f);
    return value;
}

struct Data
{
    unsigned int unused;
    unsigned int count;
};

extern void __cdecl calculate(
    Data*, const Vector*, const Vector*, Vector*, unsigned int);

Vector __cdecl reconstruct(
    Data* data, const Vector& target, unsigned int parameter)
{
    if (data->count == 0)
        return Vector::zero();

    Vector result(Vector::zero());
    if (target != Vector::zero())
        calculate(data, &Vector::zero(), &target, &result, parameter);

    return result;
}
