// from server: 76% by EspClaude
// from server: 74% by tajop
// roc 2007-08 004eadf0  unit: SphereBuilder  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004eadf0
//
// 004eadf0  83ec08               sub esp, 8
// 004eadf3  56                   push esi
// 004eadf4  8b742410             mov esi, dword ptr [esp + 0x10]
// 004eadf8  d94604               fld dword ptr [esi + 4]
// 004eadfb  d9e1                 fabs 
// 004eadfd  d95c2410             fstp dword ptr [esp + 0x10]
// 004eae01  d906                 fld dword ptr [esi]
// 004eae03  d9e1                 fabs 
// 004eae05  d95c2404             fstp dword ptr [esp + 4]
// 004eae09  d9442410             fld dword ptr [esp + 0x10]
// 004eae0d  d9442404             fld dword ptr [esp + 4]
// 004eae11  d8d1                 fcom st(1)
// 004eae13  dfe0                 fnstsw ax
// 004eae15  f6c441               test ah, 0x41
// 004eae18  7a57                 jp 0x4eae71
// 004eae1a  ddd8                 fstp st(0)
// 004eae1c  d9ee                 fldz 
// 004eae1e  d85604               fcom dword ptr [esi + 4]
// 004eae21  dfe0                 fnstsw ax
// 004eae23  f6c444               test ah, 0x44
// 004eae26  7a07                 jp 0x4eae2f
// 004eae28  ddd9                 fstp st(1)
// 004eae2a  e98f000000           jmp 0x4eaebe
// 004eae2f  8d442404             lea eax, [esp + 4]
// 004eae33  ddd8                 fstp st(0)
// 004eae35  50                   push eax
// 004eae36  d95c2414             fstp dword ptr [esp + 0x14]
// 004eae3a  8bce                 mov ecx, esi
// 004eae3c  e8cf010200           call 0x50b010
// 004eae41  d94004               fld dword ptr [eax + 4]
// 004eae44  d900                 fld dword ptr [eax]
// 004eae46  d9442410             fld dword ptr [esp + 0x10]
// 004eae4a  dd5c2404             fstp qword ptr [esp + 4]
// 004eae4e  dcc8                 fmul st(0), st(0)
// 004eae50  d9c1                 fld st(1)
// 004eae52  deca                 fmulp st(2)
// 004eae54  dec1                 faddp st(1)
// 004eae56  d95c2410             fstp dword ptr [esp + 0x10]
// 004eae5a  d9442410             fld dword ptr [esp + 0x10]
// 004eae5e  e8a95f1400           call 0x630e0c
// 004eae63  d95c2410             fstp dword ptr [esp + 0x10]
// 004eae67  d9442410             fld dword ptr [esp + 0x10]
// 004eae6b  dc7c2404             fdivr qword ptr [esp + 4]
// 004eae6f  eb4d                 jmp 0x4eaebe
// 004eae71  ddd9                 fstp st(1)
// 004eae73  d9ee                 fldz 
// 004eae75  d816                 fcom dword ptr [esi]
// 004eae77  dfe0                 fnstsw ax
// 004eae79  f6c444               test ah, 0x44
// 004eae7c  7baa                 jnp 0x4eae28
// 004eae7e  8d4c2404             lea ecx, [esp + 4]
// 004eae82  ddd8                 fstp st(0)
// 004eae84  51                   push ecx
// 004eae85  d95c2414             fstp dword ptr [esp + 0x14]
// 004eae89  8bce                 mov ecx, esi
// 004eae8b  e880010200           call 0x50b010
// 004eae90  d94004               fld dword ptr [eax + 4]
// 004eae93  d900                 fld dword ptr [eax]
// 004eae95  d9442410             fld dword ptr [esp + 0x10]
// 004eae99  dd5c2404             fstp qword ptr [esp + 4]
// 004eae9d  dcc8                 fmul st(0), st(0)
// 004eae9f  d9c1                 fld st(1)
// 004eaea1  deca                 fmulp st(2)
// 004eaea3  dec1                 faddp st(1)
// 004eaea5  d95c2410             fstp dword ptr [esp + 0x10]
// 004eaea9  d9442410             fld dword ptr [esp + 0x10]
// 004eaead  e85a5f1400           call 0x630e0c
// 004eaeb2  d95c2410             fstp dword ptr [esp + 0x10]
// 004eaeb6  d9442410             fld dword ptr [esp + 0x10]
// 004eaeba  dc7c2404             fdivr qword ptr [esp + 4]
// 004eaebe  d95c2410             fstp dword ptr [esp + 0x10]
// 004eaec2  d906                 fld dword ptr [esi]
// 004eaec4  d9442410             fld dword ptr [esp + 0x10]
// 004eaec8  d9c0                 fld st(0)
// 004eaeca  deca                 fmulp st(2)
// 004eaecc  d9c9                 fxch st(1)
// 004eaece  d91e                 fstp dword ptr [esi]
// 004eaed0  d84e04               fmul dword ptr [esi + 4]
// 004eaed3  d95e04               fstp dword ptr [esi + 4]
// 004eaed6  5e                   pop esi
// 004eaed7  83c408               add esp, 8
// 004eaeda  c3                   ret 

extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl fabs(double);

inline float sqrtf_g3d(float v) { return (float)sqrt(v); }

struct Vector2 {
    float x, y;
    float length() const { return sqrtf_g3d(x * x + y * y); }
};

struct Vector3 {
    float x, y, z;
    Vector2 xy() const;
};

struct SphereBuilder {
    static void squareCircle(Vector3& v);
};

void SphereBuilder::squareCircle(Vector3& v)
{
    float ay = (float)fabs(v.y);
    float ax = (float)fabs(v.x);
    float s;
    if (ay >= ax) {
        if (0.0f == v.y) {
            s = 0.0f;
        } else {
            s = ay / v.xy().length();
        }
    } else {
        if (0.0f == v.x) {
            s = 0.0f;
        } else {
            s = ax / v.xy().length();
        }
    }
    v.x = v.x * s;
    v.y = v.y * s;
}
