// from server: 98% by EspClaude
// from server: 87% by EspClaude
// roc 2007-08 005aafe0  unit: RBX::World  size: 581 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005aafe0
//
// 005aafe0  83ec6c               sub esp, 0x6c
// 005aafe3  d9ee                 fldz 
// 005aafe5  53                   push ebx
// 005aafe6  55                   push ebp
// 005aafe7  d95c240c             fstp dword ptr [esp + 0xc]
// 005aafeb  8b6c247c             mov ebp, dword ptr [esp + 0x7c]
// 005aafef  83c8ff               or eax, 0xffffffff
// 005aaff2  56                   push esi
// 005aaff3  57                   push edi
// 005aaff4  89442418             mov dword ptr [esp + 0x18], eax
// 005aaff8  89442410             mov dword ptr [esp + 0x10], eax
// 005aaffc  33db                 xor ebx, ebx
// 005aaffe  8d7c2458             lea edi, [esp + 0x58]
// 005ab002  53                   push ebx
// 005ab003  8d442444             lea eax, [esp + 0x44]
// 005ab007  50                   push eax
// 005ab008  8bcd                 mov ecx, ebp
// 005ab00a  e831e6f5ff           call 0x509640
// 005ab00f  33f6                 xor esi, esi
// 005ab011  8d4c244c             lea ecx, [esp + 0x4c]
// 005ab015  56                   push esi
// 005ab016  51                   push ecx
// 005ab017  e8e4f4f5ff           call 0x50a500
// 005ab01c  8bc8                 mov ecx, eax
// 005ab01e  e81de6f5ff           call 0x509640
// 005ab023  d94004               fld dword ptr [eax + 4]
// 005ab026  d84c2444             fmul dword ptr [esp + 0x44]
// 005ab02a  d94008               fld dword ptr [eax + 8]
// 005ab02d  d84c2448             fmul dword ptr [esp + 0x48]
// 005ab031  dec1                 faddp st(1)
// 005ab033  d900                 fld dword ptr [eax]
// 005ab035  d84c2440             fmul dword ptr [esp + 0x40]
// 005ab039  dec1                 faddp st(1)
// 005ab03b  d917                 fst dword ptr [edi]
// 005ab03d  d9c0                 fld st(0)
// 005ab03f  d9e1                 fabs 
// 005ab041  d9442414             fld dword ptr [esp + 0x14]
// 005ab045  d9e1                 fabs 
// 005ab047  ded9                 fcompp 
// 005ab049  dfe0                 fnstsw ax
// 005ab04b  f6c405               test ah, 5
// 005ab04e  7a0e                 jp 0x5ab05e
// 005ab050  d95c2414             fstp dword ptr [esp + 0x14]
// 005ab054  895c2418             mov dword ptr [esp + 0x18], ebx
// 005ab058  89742410             mov dword ptr [esp + 0x10], esi
// 005ab05c  eb02                 jmp 0x5ab060
// 005ab05e  ddd8                 fstp st(0)
// 005ab060  83c601               add esi, 1
// 005ab063  83c704               add edi, 4
// 005ab066  83fe03               cmp esi, 3
// 005ab069  7ca6                 jl 0x5ab011
// 005ab06b  83c301               add ebx, 1
// 005ab06e  83fb03               cmp ebx, 3
// 005ab071  7c8f                 jl 0x5ab002
// 005ab073  8b542410             mov edx, dword ptr [esp + 0x10]
// 005ab077  52                   push edx
// 005ab078  8d442420             lea eax, [esp + 0x20]
// 005ab07c  50                   push eax
// 005ab07d  e87ef4f5ff           call 0x50a500
// 005ab082  8bc8                 mov ecx, eax
// 005ab084  e8b7e5f5ff           call 0x509640
// 005ab089  d9ee                 fldz 
// 005ab08b  d8542414             fcom dword ptr [esp + 0x14]
// 005ab08f  dfe0                 fnstsw ax
// 005ab091  d9056c647900         fld dword ptr [0x79646c]
// 005ab097  f6c441               test ah, 0x41
// 005ab09a  751e                 jne 0x5ab0ba
// 005ab09c  d944241c             fld dword ptr [esp + 0x1c]
// 005ab0a0  d8c9                 fmul st(1)
// 005ab0a2  d95c241c             fstp dword ptr [esp + 0x1c]
// 005ab0a6  d9442420             fld dword ptr [esp + 0x20]
// 005ab0aa  d8c9                 fmul st(1)
// 005ab0ac  d95c2420             fstp dword ptr [esp + 0x20]
// 005ab0b0  d84c2424             fmul dword ptr [esp + 0x24]
// 005ab0b4  d95c2424             fstp dword ptr [esp + 0x24]
// 005ab0b8  eb02                 jmp 0x5ab0bc
// 005ab0ba  ddd8                 fstp st(0)
// 005ab0bc  83cbff               or ebx, 0xffffffff
// 005ab0bf  d9542414             fst dword ptr [esp + 0x14]
// 005ab0c3  83cdff               or ebp, 0xffffffff
// 005ab0c6  33c9                 xor ecx, ecx
// 005ab0c8  8d54245c             lea edx, [esp + 0x5c]
// 005ab0cc  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005ab0d0  3bcf                 cmp ecx, edi
// 005ab0d2  7467                 je 0x5ab13b
// 005ab0d4  8b742410             mov esi, dword ptr [esp + 0x10]
// 005ab0d8  85f6                 test esi, esi
// 005ab0da  741b                 je 0x5ab0f7
// 005ab0dc  d942fc               fld dword ptr [edx - 4]
// 005ab0df  d9e1                 fabs 
// 005ab0e1  d9c1                 fld st(1)
// 005ab0e3  d9e1                 fabs 
// 005ab0e5  ded9                 fcompp 
// 005ab0e7  dfe0                 fnstsw ax
// 005ab0e9  f6c405               test ah, 5
// 005ab0ec  7a09                 jp 0x5ab0f7
// 005ab0ee  ddd8                 fstp st(0)
// 005ab0f0  8bd9                 mov ebx, ecx
// 005ab0f2  d942fc               fld dword ptr [edx - 4]
// 005ab0f5  33ed                 xor ebp, ebp
// 005ab0f7  83fe01               cmp esi, 1
// 005ab0fa  741c                 je 0x5ab118
// 005ab0fc  d902                 fld dword ptr [edx]
// 005ab0fe  d9e1                 fabs 
// 005ab100  d9c1                 fld st(1)
// 005ab102  d9e1                 fabs 
// 005ab104  ded9                 fcompp 
// 005ab106  dfe0                 fnstsw ax
// 005ab108  f6c405               test ah, 5
// 005ab10b  7a0b                 jp 0x5ab118
// 005ab10d  ddd8                 fstp st(0)
// 005ab10f  8bd9                 mov ebx, ecx
// 005ab111  d902                 fld dword ptr [edx]
// 005ab113  bd01000000           mov ebp, 1
// 005ab118  83fe02               cmp esi, 2
// 005ab11b  741e                 je 0x5ab13b
// 005ab11d  d94204               fld dword ptr [edx + 4]
// 005ab120  d9e1                 fabs 
// 005ab122  d9c1                 fld st(1)
// 005ab124  d9e1                 fabs 
// 005ab126  ded9                 fcompp 
// 005ab128  dfe0                 fnstsw ax
// 005ab12a  f6c405               test ah, 5
// 005ab12d  7a0c                 jp 0x5ab13b
// 005ab12f  ddd8                 fstp st(0)
// 005ab131  8bd9                 mov ebx, ecx
// 005ab133  d94204               fld dword ptr [edx + 4]
// 005ab136  bd02000000           mov ebp, 2
// 005ab13b  83c101               add ecx, 1
// 005ab13e  83c20c               add edx, 0xc
// 005ab141  83f903               cmp ecx, 3
// 005ab144  7c86                 jl 0x5ab0cc
// 005ab146  8d4c2428             lea ecx, [esp + 0x28]
// 005ab14a  d95c2414             fstp dword ptr [esp + 0x14]
// 005ab14e  55                   push ebp
// 005ab14f  51                   push ecx
// 005ab150  e8abf3f5ff           call 0x50a500
// 005ab155  8bc8                 mov ecx, eax
// 005ab157  e8e4e4f5ff           call 0x509640
// 005ab15c  d9ee                 fldz 
// 005ab15e  d85c2414             fcomp dword ptr [esp + 0x14]
// 005ab162  dfe0                 fnstsw ax
// 005ab164  f6c441               test ah, 0x41
// 005ab167  7524                 jne 0x5ab18d
// 005ab169  d9442428             fld dword ptr [esp + 0x28]
// 005ab16d  d9056c647900         fld dword ptr [0x79646c]
// 005ab173  dcc9                 fmul st(1), st(0)
// 005ab175  d9c9                 fxch st(1)
// 005ab177  d95c2428             fstp dword ptr [esp + 0x28]
// 005ab17b  d944242c             fld dword ptr [esp + 0x2c]
// 005ab17f  d8c9                 fmul st(1)
// 005ab181  d95c242c             fstp dword ptr [esp + 0x2c]
// 005ab185  d84c2430             fmul dword ptr [esp + 0x30]
// 005ab189  d95c2430             fstp dword ptr [esp + 0x30]
// 005ab18d  be03000000           mov esi, 3
// 005ab192  2bf3                 sub esi, ebx
// 005ab194  2bf7                 sub esi, edi
// 005ab196  bf03000000           mov edi, 3
// 005ab19b  2bfd                 sub edi, ebp
// 005ab19d  2b7c2410             sub edi, dword ptr [esp + 0x10]
// 005ab1a1  8d542434             lea edx, [esp + 0x34]
// 005ab1a5  57                   push edi
// 005ab1a6  52                   push edx
// 005ab1a7  e854f3f5ff           call 0x50a500
// 005ab1ac  8bc8                 mov ecx, eax
// 005ab1ae  e88de4f5ff           call 0x509640
// 005ab1b3  d9ee                 fldz 
// 005ab1b5  8d0477               lea eax, [edi + esi*2]
// 005ab1b8  03c6                 add eax, esi
// 005ab1ba  d85c8458             fcomp dword ptr [esp + eax*4 + 0x58]
// 005ab1be  dfe0                 fnstsw ax
// 005ab1c0  f6c441               test ah, 0x41
// 005ab1c3  7524                 jne 0x5ab1e9
// 005ab1c5  d9442434             fld dword ptr [esp + 0x34]
// 005ab1c9  d9056c647900         fld dword ptr [0x79646c]
// 005ab1cf  dcc9                 fmul st(1), st(0)
// 005ab1d1  d9c9                 fxch st(1)
// 005ab1d3  d95c2434             fstp dword ptr [esp + 0x34]
// 005ab1d7  d9442438             fld dword ptr [esp + 0x38]
// 005ab1db  d8c9                 fmul st(1)
// 005ab1dd  d95c2438             fstp dword ptr [esp + 0x38]
// 005ab1e1  d84c243c             fmul dword ptr [esp + 0x3c]
// 005ab1e5  d95c243c             fstp dword ptr [esp + 0x3c]
// 005ab1e9  8b542418             mov edx, dword ptr [esp + 0x18]
// 005ab1ed  8bbc2480000000       mov edi, dword ptr [esp + 0x80]
// 005ab1f4  8d4c241c             lea ecx, [esp + 0x1c]
// 005ab1f8  51                   push ecx
// 005ab1f9  52                   push edx
// 005ab1fa  8bcf                 mov ecx, edi
// 005ab1fc  e85fe4f5ff           call 0x509660
// 005ab201  8d442428             lea eax, [esp + 0x28]
// 005ab205  50                   push eax
// 005ab206  53                   push ebx
// 005ab207  8bcf                 mov ecx, edi
// 005ab209  e852e4f5ff           call 0x509660
// 005ab20e  8d4c2434             lea ecx, [esp + 0x34]
// 005ab212  51                   push ecx
// 005ab213  56                   push esi
// 005ab214  8bcf                 mov ecx, edi
// 005ab216  e845e4f5ff           call 0x509660
// 005ab21b  8bc7                 mov eax, edi
// 005ab21d  5f                   pop edi
// 005ab21e  5e                   pop esi
// 005ab21f  5d                   pop ebp
// 005ab220  5b                   pop ebx
// 005ab221  83c46c               add esp, 0x6c
// 005ab224  c3                   ret 

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <math.h>
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    float dot(const Vector3& r) const { return x * r.x + y * r.y + z * r.z; }
    Vector3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
};
class Matrix3 {
public:
    float elt[3][3];
    Matrix3() {}
    float* operator[](int r) { return elt[r]; }
    const float* operator[](int r) const { return elt[r]; }
    Vector3 getColumn(int c) const;
    void setColumn(int c, const Vector3& v);
    static const Matrix3& identity();
};
}
namespace RBX {
class Math {
public:
    static G3D::Matrix3 snapToAxes(const G3D::Matrix3& align);
};

G3D::Matrix3 Math::snapToAxes(const G3D::Matrix3& align)
{
    G3D::Matrix3 unkMat;
    float aBest = 0.0f;
    int bestV = -1;
    int second = -1;

    for (int i = 0; i < 3; i++)
    {
        G3D::Vector3 loopColumn = align.getColumn(i);
        for (int j = 0; j < 3; j++)
        {
            float dotProd = G3D::Matrix3::identity().getColumn(j).dot(loopColumn);
            unkMat[i][j] = dotProd;
            if (fabs(dotProd) > fabs(aBest))
            {
                bestV = i;
                second = j;
                aBest = dotProd;
            }
        }
    }

    G3D::Vector3 myColumn = G3D::Matrix3::identity().getColumn(second);
    if (aBest < 0.0f)
    {
        myColumn *= -1.0f;
    }

    int v10 = -1;
    int v11 = -1;
    float v9 = 0.0f;

    for (int i = 0; i < 3; i++)
    {
        if (i != bestV)
        {
            for (int j = 0; j < 3; j++)
            {
                if (j != second)
                {
                    if (fabs(unkMat[i][j]) > fabs(v9))
                    {
                        v9 = unkMat[i][j];
                        v10 = i;
                        v11 = j;
                    }
                }
            }
        }
    }

    G3D::Vector3 myColumn2 = G3D::Matrix3::identity().getColumn(v11);
    if (v9 < 0.0f)
    {
        myColumn2 *= -1.0f;
    }

    int v15 = 3 - v10 - bestV;
    int calcColmTemp = 3 - v11 - second;
    G3D::Vector3 myColumn3 = G3D::Matrix3::identity().getColumn(calcColmTemp);
    if (unkMat[v15][calcColmTemp] < 0.0f)
    {
        myColumn3 *= -1.0f;
    }

    G3D::Matrix3 result;
    result.setColumn(bestV, myColumn);
    result.setColumn(v10, myColumn2);
    result.setColumn(v15, myColumn3);
    return result;
}
}
