// from server: 100% by EspClaude
// from server: 45% by colin
// roc 2007-08 004eb780  unit: CylinderBuilder  size: 280 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004eb780
//
// 004eb780  83ec08               sub esp, 8
// 004eb783  56                   push esi
// 004eb784  8b742410             mov esi, dword ptr [esp + 0x10]
// 004eb788  d94604               fld dword ptr [esi + 4]
// 004eb78b  57                   push edi
// 004eb78c  d9e1                 fabs 
// 004eb78e  8bf9                 mov edi, ecx
// 004eb790  d95c2414             fstp dword ptr [esp + 0x14]
// 004eb794  d906                 fld dword ptr [esi]
// 004eb796  d9e1                 fabs 
// 004eb798  d95c2408             fstp dword ptr [esp + 8]
// 004eb79c  d9442414             fld dword ptr [esp + 0x14]
// 004eb7a0  d9442408             fld dword ptr [esp + 8]
// 004eb7a4  d8d1                 fcom st(1)
// 004eb7a6  dfe0                 fnstsw ax
// 004eb7a8  f6c441               test ah, 0x41
// 004eb7ab  7a68                 jp 0x4eb815
// 004eb7ad  ddd8                 fstp st(0)
// 004eb7af  d9ee                 fldz 
// 004eb7b1  d85604               fcom dword ptr [esi + 4]
// 004eb7b4  dfe0                 fnstsw ax
// 004eb7b6  f6c444               test ah, 0x44
// 004eb7b9  7a07                 jp 0x4eb7c2
// 004eb7bb  ddd9                 fstp st(1)
// 004eb7bd  e9b6000000           jmp 0x4eb878
// 004eb7c2  8d442408             lea eax, [esp + 8]
// 004eb7c6  ddd8                 fstp st(0)
// 004eb7c8  50                   push eax
// 004eb7c9  d95c2418             fstp dword ptr [esp + 0x18]
// 004eb7cd  8bce                 mov ecx, esi
// 004eb7cf  e83cf80100           call 0x50b010
// 004eb7d4  d94004               fld dword ptr [eax + 4]
// 004eb7d7  d900                 fld dword ptr [eax]
// 004eb7d9  d9442414             fld dword ptr [esp + 0x14]
// 004eb7dd  dd5c2408             fstp qword ptr [esp + 8]
// 004eb7e1  dcc8                 fmul st(0), st(0)
// 004eb7e3  d9c1                 fld st(1)
// 004eb7e5  deca                 fmulp st(2)
// 004eb7e7  dec1                 faddp st(1)
// 004eb7e9  d95c2414             fstp dword ptr [esp + 0x14]
// 004eb7ed  d9442414             fld dword ptr [esp + 0x14]
// 004eb7f1  e816561400           call 0x630e0c
// 004eb7f6  d95c2414             fstp dword ptr [esp + 0x14]
// 004eb7fa  d9442414             fld dword ptr [esp + 0x14]
// 004eb7fe  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004eb802  dc7c2408             fdivr qword ptr [esp + 8]
// 004eb806  d95c2414             fstp dword ptr [esp + 0x14]
// 004eb80a  d9442414             fld dword ptr [esp + 0x14]
// 004eb80e  d907                 fld dword ptr [edi]
// 004eb810  d87104               fdiv dword ptr [ecx + 4]
// 004eb813  eb5d                 jmp 0x4eb872
// 004eb815  ddd9                 fstp st(1)
// 004eb817  d9ee                 fldz 
// 004eb819  d816                 fcom dword ptr [esi]
// 004eb81b  dfe0                 fnstsw ax
// 004eb81d  f6c444               test ah, 0x44
// 004eb820  7b99                 jnp 0x4eb7bb
// 004eb822  8d542408             lea edx, [esp + 8]
// 004eb826  ddd8                 fstp st(0)
// 004eb828  52                   push edx
// 004eb829  d95c2418             fstp dword ptr [esp + 0x18]
// 004eb82d  8bce                 mov ecx, esi
// 004eb82f  e8dcf70100           call 0x50b010
// 004eb834  d94004               fld dword ptr [eax + 4]
// 004eb837  d900                 fld dword ptr [eax]
// 004eb839  d9442414             fld dword ptr [esp + 0x14]
// 004eb83d  dd5c2408             fstp qword ptr [esp + 8]
// 004eb841  dcc8                 fmul st(0), st(0)
// 004eb843  d9c1                 fld st(1)
// 004eb845  deca                 fmulp st(2)
// 004eb847  dec1                 faddp st(1)
// 004eb849  d95c2414             fstp dword ptr [esp + 0x14]
// 004eb84d  d9442414             fld dword ptr [esp + 0x14]
// 004eb851  e8b6551400           call 0x630e0c
// 004eb856  d95c2414             fstp dword ptr [esp + 0x14]
// 004eb85a  d9442414             fld dword ptr [esp + 0x14]
// 004eb85e  8b442420             mov eax, dword ptr [esp + 0x20]
// 004eb862  dc7c2408             fdivr qword ptr [esp + 8]
// 004eb866  d95c2414             fstp dword ptr [esp + 0x14]
// 004eb86a  d9442414             fld dword ptr [esp + 0x14]
// 004eb86e  d907                 fld dword ptr [edi]
// 004eb870  d830                 fdiv dword ptr [eax]
// 004eb872  d9e8                 fld1 
// 004eb874  dee1                 fsubrp st(1)
// 004eb876  dec9                 fmulp st(1)
// 004eb878  d95c2420             fstp dword ptr [esp + 0x20]
// 004eb87c  5f                   pop edi
// 004eb87d  d906                 fld dword ptr [esi]
// 004eb87f  d944241c             fld dword ptr [esp + 0x1c]
// 004eb883  d9c0                 fld st(0)
// 004eb885  deca                 fmulp st(2)
// 004eb887  d9c9                 fxch st(1)
// 004eb889  d91e                 fstp dword ptr [esi]
// 004eb88b  d84e04               fmul dword ptr [esi + 4]
// 004eb88e  d95e04               fstp dword ptr [esi + 4]
// 004eb891  5e                   pop esi
// 004eb892  83c408               add esp, 8

#include <math.h>

struct Vec2 {
    float x;
    float y;
    Vec2() {}
    Vec2 direction() const;   // thiscall, hidden return (call 0x50b010)
    float length() const { return sqrtf(x * x + y * y); }
};

struct CylinderBuilder {
    float field0;
    void compute(Vec2& v, int a2, int a3, const Vec2& size, int a5);
};

static inline float gabs(float x) { return ::fabs(x); }

void CylinderBuilder::compute(Vec2& v, int a2, int a3, const Vec2& size, int a5)
{
    float r;
    if (gabs(v.y) >= gabs(v.x)) {
        if (v.y == 0.0f) {
            r = 0.0f;
        } else {
            float t = gabs(v.y) / v.direction().length();
            r = t * (1.0f - field0 / size.y);
        }
    } else {
        if (v.x == 0.0f) {
            r = 0.0f;
        } else {
            float t = gabs(v.x) / v.direction().length();
            r = t * (1.0f - field0 / size.x);
        }
    }
    v.x = v.x * r;
    v.y = v.y * r;
}
