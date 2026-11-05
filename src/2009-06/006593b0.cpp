// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 005cbe70  unit: RBX::ControllerService  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005cbe70
//
// 005cbe70  d94104               fld dword ptr [ecx + 4]
// 005cbe73  d901                 fld dword ptr [ecx]
// 005cbe75  dcc8                 fmul st(0), st(0)
// 005cbe77  d9c1                 fld st(1)
// 005cbe79  deca                 fmulp st(2)
// 005cbe7b  dec1                 faddp st(1)
// 005cbe7d  d9e8                 fld1 
// 005cbe7f  dde9                 fucomp st(1)
// 005cbe81  dfe0                 fnstsw ax
// 005cbe83  f6c444               test ah, 0x44
// 005cbe86  7b17                 jnp 0x5cbe9f
// 005cbe88  d9fa                 fsqrt 
// 005cbe8a  56                   push esi
// 005cbe8b  8b742408             mov esi, dword ptr [esp + 8]
// 005cbe8f  51                   push ecx
// 005cbe90  d91c24               fstp dword ptr [esp]
// 005cbe93  56                   push esi
// 005cbe94  e897ddf3ff           call 0x509c30
// 005cbe99  8bc6                 mov eax, esi
// 005cbe9b  5e                   pop esi
// 005cbe9c  c20400               ret 4
// 005cbe9f  8b442404             mov eax, dword ptr [esp + 4]
// 005cbea3  ddd8                 fstp st(0)
// 005cbea5  d901                 fld dword ptr [ecx]
// 005cbea7  d918                 fstp dword ptr [eax]
// 005cbea9  d94104               fld dword ptr [ecx + 4]
// 005cbeac  d95804               fstp dword ptr [eax + 4]
// 005cbeaf  c20400               ret 4

#pragma float_control(precise, off)

extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)

struct Vector2 {
    float x;
    float y;

    Vector2(const float& a, const float& b) : x(a), y(b) {}
    Vector2 __thiscall operator/(float divisor) const;
    Vector2 __thiscall direction() const;
};

Vector2 Vector2::direction() const {
    float squaredLength = x * x + y * y;
    if (squaredLength != 1.0f)
        return *this / (float)sqrt(squaredLength);
    return Vector2(x, y);
}
