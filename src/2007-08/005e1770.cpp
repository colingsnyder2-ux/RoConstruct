// from server: 100% by EspClaude
// from server: 99% by EspClaude
// roc 2007-08 005e1770  unit: RBX::VMotorFeature::?$FactoryProduct  size: 356 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e1770
//
// 005e1770  83ec0c               sub esp, 0xc
// 005e1773  56                   push esi
// 005e1774  8b742418             mov esi, dword ptr [esp + 0x18]
// 005e1778  837e0400             cmp dword ptr [esi + 4], 0
// 005e177c  7547                 jne 0x5e17c5
// 005e177e  f60538d18b0001       test byte ptr [0x8bd138], 1
// 005e1785  751b                 jne 0x5e17a2
// 005e1787  d9ee                 fldz 
// 005e1789  830d38d18b0001       or dword ptr [0x8bd138], 1
// 005e1790  d9152cd18b00         fst dword ptr [0x8bd12c]
// 005e1796  d91530d18b00         fst dword ptr [0x8bd130]
// 005e179c  d91d34d18b00         fstp dword ptr [0x8bd134]
// 005e17a2  8b442414             mov eax, dword ptr [esp + 0x14]
// 005e17a6  d9052cd18b00         fld dword ptr [0x8bd12c]
// 005e17ac  d918                 fstp dword ptr [eax]
// 005e17ae  5e                   pop esi
// 005e17af  d90530d18b00         fld dword ptr [0x8bd130]
// 005e17b5  d95804               fstp dword ptr [eax + 4]
// 005e17b8  d90534d18b00         fld dword ptr [0x8bd134]
// 005e17be  d95808               fstp dword ptr [eax + 8]
// 005e17c1  83c40c               add esp, 0xc
// 005e17c4  c3                   ret 
// 005e17c5  8b0d38d18b00         mov ecx, dword ptr [0x8bd138]
// 005e17cb  d9ee                 fldz 
// 005e17cd  f6c101               test cl, 1
// 005e17d0  7523                 jne 0x5e17f5
// 005e17d2  d9c0                 fld st(0)
// 005e17d4  83c901               or ecx, 1
// 005e17d7  d9152cd18b00         fst dword ptr [0x8bd12c]
// 005e17dd  890d38d18b00         mov dword ptr [0x8bd138], ecx
// 005e17e3  d9c1                 fld st(1)
// 005e17e5  d91530d18b00         fst dword ptr [0x8bd130]
// 005e17eb  d9c2                 fld st(2)
// 005e17ed  d91534d18b00         fst dword ptr [0x8bd134]
// 005e17f3  eb14                 jmp 0x5e1809
// 005e17f5  d90534d18b00         fld dword ptr [0x8bd134]
// 005e17fb  d90530d18b00         fld dword ptr [0x8bd130]
// 005e1801  d9052cd18b00         fld dword ptr [0x8bd12c]
// 005e1807  d9ca                 fxch st(2)
// 005e1809  f6c101               test cl, 1
// 005e180c  d9ca                 fxch st(2)
// 005e180e  d9542404             fst dword ptr [esp + 4]
// 005e1812  d9c9                 fxch st(1)
// 005e1814  d9542408             fst dword ptr [esp + 8]
// 005e1818  d9ca                 fxch st(2)
// 005e181a  d954240c             fst dword ptr [esp + 0xc]
// 005e181e  752d                 jne 0x5e184d
// 005e1820  ddd9                 fstp st(1)
// 005e1822  83c901               or ecx, 1
// 005e1825  ddd9                 fstp st(1)
// 005e1827  890d38d18b00         mov dword ptr [0x8bd138], ecx
// 005e182d  ddd8                 fstp st(0)
// 005e182f  d9c0                 fld st(0)
// 005e1831  d9152cd18b00         fst dword ptr [0x8bd12c]
// 005e1837  d9c1                 fld st(1)
// 005e1839  d91530d18b00         fst dword ptr [0x8bd130]
// 005e183f  d9c2                 fld st(2)
// 005e1841  d91534d18b00         fst dword ptr [0x8bd134]
// 005e1847  d9c9                 fxch st(1)
// 005e1849  d9ca                 fxch st(2)
// 005e184b  d9c9                 fxch st(1)
// 005e184d  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 005e1851  d9c9                 fxch st(1)
// 005e1853  d81a                 fcomp dword ptr [edx]
// 005e1855  dfe0                 fnstsw ax
// 005e1857  f6c444               test ah, 0x44
// 005e185a  7a35                 jp 0x5e1891
// 005e185c  d9c9                 fxch st(1)
// 005e185e  d85a04               fcomp dword ptr [edx + 4]
// 005e1861  dfe0                 fnstsw ax
// 005e1863  f6c444               test ah, 0x44
// 005e1866  7a2b                 jp 0x5e1893
// 005e1868  d85a08               fcomp dword ptr [edx + 8]
// 005e186b  dfe0                 fnstsw ax
// 005e186d  f6c444               test ah, 0x44
// 005e1870  7a23                 jp 0x5e1895
// 005e1872  ddd8                 fstp st(0)
// 005e1874  8b442414             mov eax, dword ptr [esp + 0x14]
// 005e1878  d9442404             fld dword ptr [esp + 4]
// 005e187c  d918                 fstp dword ptr [eax]
// 005e187e  5e                   pop esi
// 005e187f  d9442404             fld dword ptr [esp + 4]
// 005e1883  d95804               fstp dword ptr [eax + 4]
// 005e1886  d9442408             fld dword ptr [esp + 8]
// 005e188a  d95808               fstp dword ptr [eax + 8]
// 005e188d  83c40c               add esp, 0xc
// 005e1890  c3                   ret 
// 005e1891  ddd9                 fstp st(1)
// 005e1893  ddd8                 fstp st(0)
// 005e1895  f6c101               test cl, 1
// 005e1898  751d                 jne 0x5e18b7
// 005e189a  d9152cd18b00         fst dword ptr [0x8bd12c]
// 005e18a0  83c901               or ecx, 1
// 005e18a3  d91530d18b00         fst dword ptr [0x8bd130]
// 005e18a9  890d38d18b00         mov dword ptr [0x8bd138], ecx
// 005e18af  d91d34d18b00         fstp dword ptr [0x8bd134]
// 005e18b5  eb02                 jmp 0x5e18b9
// 005e18b7  ddd8                 fstp st(0)
// 005e18b9  8b442420             mov eax, dword ptr [esp + 0x20]
// 005e18bd  50                   push eax
// 005e18be  8d4c2408             lea ecx, [esp + 8]
// 005e18c2  51                   push ecx
// 005e18c3  52                   push edx
// 005e18c4  682cd18b00           push 0x8bd12c
// 005e18c9  56                   push esi
// 005e18ca  e861fdffff           call 0x5e1630
// 005e18cf  83c414               add esp, 0x14
// 005e18d2  eba0                 jmp 0x5e1874

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
// roc-cl: 50727
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
