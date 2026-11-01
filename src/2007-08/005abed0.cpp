// from server: 100% by colin
// roc 2007-08 005abed0  unit: RBX::World  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005abed0
//
// 005abed0  d9442410             fld dword ptr [esp + 0x10]
// 005abed4  d9e1                 fabs 
// 005abed6  d9442404             fld dword ptr [esp + 4]
// 005abeda  d9c0                 fld st(0)
// 005abedc  d8c9                 fmul st(1)
// 005abede  d9c0                 fld st(0)
// 005abee0  d8ca                 fmul st(2)
// 005abee2  deca                 fmulp st(2)
// 005abee4  d9442408             fld dword ptr [esp + 8]
// 005abee8  d9c0                 fld st(0)
// 005abeea  d8c9                 fmul st(1)
// 005abeec  d8cc                 fmul st(4)
// 005abeee  d9c2                 fld st(2)
// 005abef0  d84c240c             fmul dword ptr [esp + 0xc]
// 005abef4  dcc0                 fadd st(0), st(0)
// 005abef6  dec1                 faddp st(1)
// 005abef8  d8cc                 fmul st(4)
// 005abefa  deeb                 fsubp st(3)
// 005abefc  d9ee                 fldz 
// 005abefe  d8db                 fcomp st(3)
// 005abf00  dfe0                 fnstsw ax
// 005abf02  f6c401               test ah, 1
// 005abf05  750f                 jne 0x5abf16
// 005abf07  ddda                 fstp st(2)
// 005abf09  ddda                 fstp st(2)
// 005abf0b  ddd9                 fstp st(1)
// 005abf0d  ddd8                 fstp st(0)
// 005abf0f  d90514167b00         fld dword ptr [0x7b1614]
// 005abf15  c3                   ret 
// 005abf16  d9ca                 fxch st(2)
// 005abf18  d9fa                 fsqrt 
// 005abf1a  d9ca                 fxch st(2)
// 005abf1c  decb                 fmulp st(3)
// 005abf1e  d9c0                 fld st(0)
// 005abf20  d8c2                 fadd st(2)
// 005abf22  d8f3                 fdiv st(3)
// 005abf24  d9e8                 fld1 
// 005abf26  d9f3                 fpatan 
// 005abf28  d9542404             fst dword ptr [esp + 4]
// 005abf2c  d9c9                 fxch st(1)
// 005abf2e  dee2                 fsubrp st(2)
// 005abf30  d9c9                 fxch st(1)
// 005abf32  def2                 fdivrp st(2)
// 005abf34  d9e8                 fld1 
// 005abf36  d9c9                 fxch st(1)
// 005abf38  d9ca                 fxch st(2)
// 005abf3a  d9c9                 fxch st(1)
// 005abf3c  d9f3                 fpatan 
// 005abf3e  d9542410             fst dword ptr [esp + 0x10]
// 005abf42  ded9                 fcompp 
// 005abf44  dfe0                 fnstsw ax
// 005abf46  f6c405               test ah, 5
// 005abf49  8d442410             lea eax, [esp + 0x10]
// 005abf4d  7b04                 jnp 0x5abf53
// 005abf4f  8d442404             lea eax, [esp + 4]
// 005abf53  d900                 fld dword ptr [eax]
// 005abf55  c3                   ret 
// copied from an identical function in another client (function ?f@@YAMMMMM@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 91% by EspClaude
#pragma float_control(precise, off)
// roc 2008-06 005ded80  unit: RBX::Message  size: 134 bytes

extern "C" double __cdecl fabs(double);
extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl atan(double);
#pragma intrinsic(fabs, sqrt, atan)

extern const float invalidResult;

float __cdecl f(float speed, float distance, float height, float gravity)
{
    double g = fabs(gravity);
    double disc = speed*speed*speed*speed
        - (distance*distance*g + 2.0*(speed*speed)*height)*g;

    if (disc <= 0.0)
        return invalidResult;

    double root = sqrt(disc);
    double v2 = speed*speed;
    double upper = atan((root + v2) / (distance*g));
    speed = (float)upper;
    double lower = atan((v2 - root) / (g*distance));
    gravity = (float)lower;

    const float* result = lower < upper ? &gravity : &speed;
    return *result;
}