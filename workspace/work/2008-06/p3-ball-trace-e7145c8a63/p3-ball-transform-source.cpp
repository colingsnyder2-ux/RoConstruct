// Implementation: C:\Users\colin\RoConstruct\src\2008-06\004fabb0.cpp
// Build pointer preserved: C:\Users\colin\RoConstruct\src\2008-06\004fabb0.cpp
// from server: 100% by king_originala
// roc 2008-06 004fabb0  unit: RBX::ViewNew::TorsoBuilder  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004fabb0
//
// 004fabb0  8b442404             mov eax, dword ptr [esp + 4]
// 004fabb4  d94008               fld dword ptr [eax + 8]
// 004fabb7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004fabbb  d94004               fld dword ptr [eax + 4]
// 004fabbe  d900                 fld dword ptr [eax]
// 004fabc0  dcc8                 fmul st(0), st(0)
// 004fabc2  d9c1                 fld st(1)
// 004fabc4  deca                 fmulp st(2)
// 004fabc6  dec1                 faddp st(1)
// 004fabc8  d9c1                 fld st(1)
// 004fabca  deca                 fmulp st(2)
// 004fabcc  dec1                 faddp st(1)
// 004fabce  d9fa                 fsqrt 
// 004fabd0  d9e8                 fld1 
// 004fabd2  def1                 fdivrp st(1)
// 004fabd4  d900                 fld dword ptr [eax]
// 004fabd6  d8c9                 fmul st(1)
// 004fabd8  d9c1                 fld st(1)
// 004fabda  d84804               fmul dword ptr [eax + 4]
// 004fabdd  d9ca                 fxch st(2)
// 004fabdf  d84808               fmul dword ptr [eax + 8]
// 004fabe2  d9c9                 fxch st(1)
// 004fabe4  d911                 fst dword ptr [ecx]
// 004fabe6  d9ca                 fxch st(2)
// 004fabe8  d95104               fst dword ptr [ecx + 4]
// 004fabeb  d9c9                 fxch st(1)
// 004fabed  d95108               fst dword ptr [ecx + 8]
// 004fabf0  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004fabf4  d901                 fld dword ptr [ecx]
// 004fabf6  decb                 fmulp st(3)
// 004fabf8  d94104               fld dword ptr [ecx + 4]
// 004fabfb  deca                 fmulp st(2)
// 004fabfd  d84908               fmul dword ptr [ecx + 8]
// 004fac00  d9ca                 fxch st(2)
// 004fac02  d918                 fstp dword ptr [eax]
// 004fac04  d95804               fstp dword ptr [eax + 4]
// 004fac07  d95808               fstp dword ptr [eax + 8]
// 004fac0a  c3                   ret 

extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)
#pragma float_control(precise, off)

struct Vec3 {
    float x, y, z;
};

void __cdecl normalizeAndScale(Vec3* value, Vec3* unit, void*, const volatile Vec3* scale)
{
    float inverseLength = 1.0f / (float)sqrt(
        value->x * value->x +
        value->y * value->y +
        value->z * value->z);

    float x = value->x * inverseLength;
    float y = value->y * inverseLength;
    float z = value->z * inverseLength;

    unit->x = x;
    unit->y = y;
    unit->z = z;

    float scaledX = x * scale->x;
    float scaledY = y * scale->y;
    float scaledZ = z * scale->z;

    value->x = scaledX;
    value->y = scaledY;
    value->z = scaledZ;
}
