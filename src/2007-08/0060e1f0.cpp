// from server: 100% by colin
// roc 2007-08 0060e1f0  unit: RBX::Ball  size: 348 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060e1f0
//
// 0060e1f0  d9058c2f7c00         fld dword ptr [0x7c2f8c]
// 0060e1f6  8b542404             mov edx, dword ptr [esp + 4]
// 0060e1fa  53                   push ebx
// 0060e1fb  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0060e1ff  56                   push esi
// 0060e200  8b742410             mov esi, dword ptr [esp + 0x10]
// 0060e204  57                   push edi
// 0060e205  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0060e209  d91f                 fstp dword ptr [edi]
// 0060e20b  d905882f7c00         fld dword ptr [0x7c2f88]
// 0060e211  d91b                 fstp dword ptr [ebx]
// 0060e213  d901                 fld dword ptr [ecx]
// 0060e215  d822                 fsub dword ptr [edx]
// 0060e217  d94104               fld dword ptr [ecx + 4]
// 0060e21a  d86204               fsub dword ptr [edx + 4]
// 0060e21d  d94108               fld dword ptr [ecx + 8]
// 0060e220  d86208               fsub dword ptr [edx + 8]
// 0060e223  d906                 fld dword ptr [esi]
// 0060e225  decb                 fmulp st(3)
// 0060e227  d9c9                 fxch st(1)
// 0060e229  d84e04               fmul dword ptr [esi + 4]
// 0060e22c  dec2                 faddp st(2)
// 0060e22e  d84e08               fmul dword ptr [esi + 8]
// 0060e231  dec1                 faddp st(1)
// 0060e233  d9542418             fst dword ptr [esp + 0x18]
// 0060e237  d817                 fcom dword ptr [edi]
// 0060e239  dfe0                 fnstsw ax
// 0060e23b  f6c405               test ah, 5
// 0060e23e  8d442418             lea eax, [esp + 0x18]
// 0060e242  7b02                 jnp 0x60e246
// 0060e244  8bc7                 mov eax, edi
// 0060e246  d900                 fld dword ptr [eax]
// 0060e248  d91f                 fstp dword ptr [edi]
// 0060e24a  d81b                 fcomp dword ptr [ebx]
// 0060e24c  dfe0                 fnstsw ax
// 0060e24e  f6c441               test ah, 0x41
// 0060e251  8d442418             lea eax, [esp + 0x18]
// 0060e255  7402                 je 0x60e259
// 0060e257  8bc3                 mov eax, ebx
// 0060e259  d900                 fld dword ptr [eax]
// 0060e25b  d91b                 fstp dword ptr [ebx]
// 0060e25d  d9410c               fld dword ptr [ecx + 0xc]
// 0060e260  d822                 fsub dword ptr [edx]
// 0060e262  d94110               fld dword ptr [ecx + 0x10]
// 0060e265  d86204               fsub dword ptr [edx + 4]
// 0060e268  d94114               fld dword ptr [ecx + 0x14]
// 0060e26b  d86208               fsub dword ptr [edx + 8]
// 0060e26e  d906                 fld dword ptr [esi]
// 0060e270  decb                 fmulp st(3)
// 0060e272  d9c9                 fxch st(1)
// 0060e274  d84e04               fmul dword ptr [esi + 4]
// 0060e277  dec2                 faddp st(2)
// 0060e279  d84e08               fmul dword ptr [esi + 8]
// 0060e27c  dec1                 faddp st(1)
// 0060e27e  d9542418             fst dword ptr [esp + 0x18]
// 0060e282  d817                 fcom dword ptr [edi]
// 0060e284  dfe0                 fnstsw ax
// 0060e286  f6c405               test ah, 5
// 0060e289  8d442418             lea eax, [esp + 0x18]
// 0060e28d  7b02                 jnp 0x60e291
// 0060e28f  8bc7                 mov eax, edi
// 0060e291  d900                 fld dword ptr [eax]
// 0060e293  d91f                 fstp dword ptr [edi]
// 0060e295  d81b                 fcomp dword ptr [ebx]
// 0060e297  dfe0                 fnstsw ax
// 0060e299  f6c441               test ah, 0x41
// 0060e29c  8d442418             lea eax, [esp + 0x18]
// 0060e2a0  7402                 je 0x60e2a4
// 0060e2a2  8bc3                 mov eax, ebx
// 0060e2a4  d900                 fld dword ptr [eax]
// 0060e2a6  d91b                 fstp dword ptr [ebx]
// 0060e2a8  d94118               fld dword ptr [ecx + 0x18]
// 0060e2ab  d822                 fsub dword ptr [edx]
// 0060e2ad  d9411c               fld dword ptr [ecx + 0x1c]
// 0060e2b0  d86204               fsub dword ptr [edx + 4]
// 0060e2b3  d94120               fld dword ptr [ecx + 0x20]
// 0060e2b6  d86208               fsub dword ptr [edx + 8]
// 0060e2b9  d906                 fld dword ptr [esi]
// 0060e2bb  decb                 fmulp st(3)
// 0060e2bd  d9c9                 fxch st(1)
// 0060e2bf  d84e04               fmul dword ptr [esi + 4]
// 0060e2c2  dec2                 faddp st(2)
// 0060e2c4  d84e08               fmul dword ptr [esi + 8]
// 0060e2c7  dec1                 faddp st(1)
// 0060e2c9  d9542418             fst dword ptr [esp + 0x18]
// 0060e2cd  d817                 fcom dword ptr [edi]
// 0060e2cf  dfe0                 fnstsw ax
// 0060e2d1  f6c405               test ah, 5
// 0060e2d4  8d442418             lea eax, [esp + 0x18]
// 0060e2d8  7b02                 jnp 0x60e2dc
// 0060e2da  8bc7                 mov eax, edi
// 0060e2dc  d900                 fld dword ptr [eax]
// 0060e2de  d91f                 fstp dword ptr [edi]
// 0060e2e0  d81b                 fcomp dword ptr [ebx]
// 0060e2e2  dfe0                 fnstsw ax
// 0060e2e4  f6c441               test ah, 0x41
// 0060e2e7  8d442418             lea eax, [esp + 0x18]
// 0060e2eb  7402                 je 0x60e2ef
// 0060e2ed  8bc3                 mov eax, ebx
// 0060e2ef  d900                 fld dword ptr [eax]
// 0060e2f1  d91b                 fstp dword ptr [ebx]
// 0060e2f3  d94124               fld dword ptr [ecx + 0x24]
// 0060e2f6  d822                 fsub dword ptr [edx]
// 0060e2f8  d94128               fld dword ptr [ecx + 0x28]
// 0060e2fb  d86204               fsub dword ptr [edx + 4]
// 0060e2fe  d9412c               fld dword ptr [ecx + 0x2c]
// 0060e301  d86208               fsub dword ptr [edx + 8]
// 0060e304  d906                 fld dword ptr [esi]
// 0060e306  decb                 fmulp st(3)
// 0060e308  d9c9                 fxch st(1)
// 0060e30a  d84e04               fmul dword ptr [esi + 4]
// 0060e30d  dec2                 faddp st(2)
// 0060e30f  d84e08               fmul dword ptr [esi + 8]
// 0060e312  dec1                 faddp st(1)
// 0060e314  d9542418             fst dword ptr [esp + 0x18]
// 0060e318  d817                 fcom dword ptr [edi]
// 0060e31a  dfe0                 fnstsw ax
// 0060e31c  f6c405               test ah, 5
// 0060e31f  8d442418             lea eax, [esp + 0x18]
// 0060e323  7b02                 jnp 0x60e327
// 0060e325  8bc7                 mov eax, edi
// 0060e327  d900                 fld dword ptr [eax]
// 0060e329  d91f                 fstp dword ptr [edi]
// 0060e32b  d81b                 fcomp dword ptr [ebx]
// 0060e32d  dfe0                 fnstsw ax
// 0060e32f  f6c441               test ah, 0x41
// 0060e332  750e                 jne 0x60e342
// 0060e334  8d442418             lea eax, [esp + 0x18]
// 0060e338  d900                 fld dword ptr [eax]
// 0060e33a  5f                   pop edi
// 0060e33b  5e                   pop esi
// 0060e33c  d91b                 fstp dword ptr [ebx]
// 0060e33e  5b                   pop ebx
// 0060e33f  c21000               ret 0x10
// 0060e342  d903                 fld dword ptr [ebx]
// 0060e344  5f                   pop edi
// 0060e345  5e                   pop esi
// 0060e346  d91b                 fstp dword ptr [ebx]
// 0060e348  5b                   pop ebx
// 0060e349  c21000               ret 0x10
// copied from an identical function in another client (function ?minMax@Face@RBX@@QBEXABVVector3@G3D@@0AAM1@Z)

// from server: 96% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast

namespace std {
template <class T> inline const T& min(const T& l, const T& r) { return r < l ? r : l; }
template <class T> inline const T& max(const T& l, const T& r) { return l < r ? r : l; }
}

namespace G3D {
template <class T> inline T min(const T& x, const T& y) { return std::min<T>(x, y); }
template <class T> inline T max(const T& x, const T& y) { return std::max<T>(x, y); }

class Vector3 {
public:
    float x, y, z;
    inline Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    inline Vector3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {}
    inline Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    inline Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    inline float dot(const Vector3& v) const { float r = x * v.x; r += y * v.y; r += z * v.z; return r; }
};
}

namespace RBX {
class Face {
public:
    G3D::Vector3 c0, c1, c2, c3;
    const G3D::Vector3& operator[](int i) const { return (&c0)[i]; }
    void minMax(const G3D::Vector3& point, const G3D::Vector3& normal, float& min, float& max) const;
};

void Face::minMax(const G3D::Vector3& point, const G3D::Vector3& normal, float& min, float& max) const
{
    min = 1.0e10;
    max = -1.0e10;
    for (int i = 0; i < 4; ++i)
    {
        const G3D::Vector3& v = (*this)[i];
        float temp = (v - point).dot(normal);
        min = G3D::min(min, temp);
        max = G3D::max(max, temp);
    }
}
}