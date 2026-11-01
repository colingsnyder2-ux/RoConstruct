// from server: 100% by colin
// from server: 82% by king_originala
// roc 2008-06 004fdcc0  unit: RBX::ViewNew::CylinderBuilder  size: 197 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004fdcc0
//
// 004fdcc0  83ec08               sub esp, 8
// 004fdcc3  56                   push esi
// 004fdcc4  8b742410             mov esi, dword ptr [esp + 0x10]
// 004fdcc8  d94604               fld dword ptr [esi + 4]
// 004fdccb  57                   push edi
// 004fdccc  d9e1                 fabs 
// 004fdcce  8bf9                 mov edi, ecx
// 004fdcd0  d906                 fld dword ptr [esi]
// 004fdcd2  d9e1                 fabs 
// 004fdcd4  d8d1                 fcom st(1)
// 004fdcd6  dfe0                 fnstsw ax
// 004fdcd8  f6c441               test ah, 0x41
// 004fdcdb  7a3e                 jp 0x4fdd1b
// 004fdcdd  ddd8                 fstp st(0)
// 004fdcdf  d9ee                 fldz 
// 004fdce1  d85604               fcom dword ptr [esi + 4]
// 004fdce4  dfe0                 fnstsw ax
// 004fdce6  f6c444               test ah, 0x44
// 004fdce9  7b3d                 jnp 0x4fdd28
// 004fdceb  8d442408             lea eax, [esp + 8]
// 004fdcef  ddd8                 fstp st(0)
// 004fdcf1  50                   push eax
// 004fdcf2  d95c2418             fstp dword ptr [esp + 0x18]
// 004fdcf6  8bce                 mov ecx, esi
// 004fdcf8  e8d3a80100           call 0x5185d0
// 004fdcfd  d94004               fld dword ptr [eax + 4]
// 004fdd00  d900                 fld dword ptr [eax]
// 004fdd02  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004fdd06  dcc8                 fmul st(0), st(0)
// 004fdd08  d9c1                 fld st(1)
// 004fdd0a  deca                 fmulp st(2)
// 004fdd0c  dec1                 faddp st(1)
// 004fdd0e  d9fa                 fsqrt 
// 004fdd10  d87c2414             fdivr dword ptr [esp + 0x14]
// 004fdd14  d907                 fld dword ptr [edi]
// 004fdd16  d87104               fdiv dword ptr [ecx + 4]
// 004fdd19  eb50                 jmp 0x4fdd6b
// 004fdd1b  ddd9                 fstp st(1)
// 004fdd1d  d9ee                 fldz 
// 004fdd1f  d816                 fcom dword ptr [esi]
// 004fdd21  dfe0                 fnstsw ax
// 004fdd23  f6c444               test ah, 0x44
// 004fdd26  7a16                 jp 0x4fdd3e
// 004fdd28  ddd9                 fstp st(1)
// 004fdd2a  5f                   pop edi
// 004fdd2b  d906                 fld dword ptr [esi]
// 004fdd2d  d8c9                 fmul st(1)
// 004fdd2f  d91e                 fstp dword ptr [esi]
// 004fdd31  d84e04               fmul dword ptr [esi + 4]
// 004fdd34  d95e04               fstp dword ptr [esi + 4]
// 004fdd37  5e                   pop esi
// 004fdd38  83c408               add esp, 8
// 004fdd3b  c21400               ret 0x14
// 004fdd3e  8d542408             lea edx, [esp + 8]
// 004fdd42  ddd8                 fstp st(0)
// 004fdd44  52                   push edx
// 004fdd45  d95c2418             fstp dword ptr [esp + 0x18]
// 004fdd49  8bce                 mov ecx, esi
// 004fdd4b  e880a80100           call 0x5185d0
// 004fdd50  d94004               fld dword ptr [eax + 4]
// 004fdd53  d900                 fld dword ptr [eax]
// 004fdd55  8b442420             mov eax, dword ptr [esp + 0x20]
// 004fdd59  dcc8                 fmul st(0), st(0)
// 004fdd5b  d9c1                 fld st(1)
// 004fdd5d  deca                 fmulp st(2)
// 004fdd5f  dec1                 faddp st(1)
// 004fdd61  d9fa                 fsqrt 
// 004fdd63  d87c2414             fdivr dword ptr [esp + 0x14]
// 004fdd67  d907                 fld dword ptr [edi]
// 004fdd69  d830                 fdiv dword ptr [eax]
// 004fdd6b  d9e8                 fld1 
// 004fdd6d  5f                   pop edi
// 004fdd6e  dee1                 fsubrp st(1)
// 004fdd70  dec9                 fmulp st(1)
// 004fdd72  d906                 fld dword ptr [esi]
// 004fdd74  d8c9                 fmul st(1)
// 004fdd76  d91e                 fstp dword ptr [esi]
// 004fdd78  d84e04               fmul dword ptr [esi + 4]
// 004fdd7b  d95e04               fstp dword ptr [esi + 4]
// 004fdd7e  5e                   pop esi
// 004fdd7f  83c408               add esp, 8
// 004fdd82  c21400               ret 0x14

extern "C" double __cdecl fabs(double);
extern "C" double __cdecl sqrt(double);
#pragma intrinsic(fabs, sqrt)
#pragma float_control(precise, off, push)

struct Vector2 {
    float x, y;
    float length() const;
};

inline float Vector2::length() const
{
    return (float)sqrt(x * x + y * y);
}

struct Vector3 {
    float x, y, z;
    Vector2 xy() const;
};

struct CylinderBuilder {
    float radius;
    void adjust(Vector3& v, int, int, const Vector3& size, int);
};

void CylinderBuilder::adjust(Vector3& v, int, int, const Vector3& size, int)
{
    float scale;
    if (fabs(v.y) >= fabs(v.x)) {
        if (v.y == 0.0f) {
            scale = 0.0f;
        } else {
            float magnitude = (float)fabs(v.y);
            scale = (magnitude / v.xy().length())
                  * (1.0f - radius / size.y);
        }
    } else {
        if (v.x == 0.0f) {
            scale = 0.0f;
        } else {
            float magnitude = (float)fabs(v.x);
            scale = (magnitude / v.xy().length())
                  * (1.0f - radius / size.x);
        }
    }
    v.x *= scale;
    v.y *= scale;
}

#pragma float_control(pop)
