// from server: 100% by colin
// roc 2007-08 00628390  unit: RBX::AssemblyStage  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00628390
//
// 00628390  83ec10               sub esp, 0x10
// 00628393  d9410c               fld dword ptr [ecx + 0xc]
// 00628396  8d1424               lea edx, [esp]
// 00628399  d9e1                 fabs 
// 0062839b  d91424               fst dword ptr [esp]
// 0062839e  d94108               fld dword ptr [ecx + 8]
// 006283a1  d9e1                 fabs 
// 006283a3  d9542404             fst dword ptr [esp + 4]
// 006283a7  d94104               fld dword ptr [ecx + 4]
// 006283aa  d9e1                 fabs 
// 006283ac  d9542408             fst dword ptr [esp + 8]
// 006283b0  d901                 fld dword ptr [ecx]
// 006283b2  d9e1                 fabs 
// 006283b4  d954240c             fst dword ptr [esp + 0xc]
// 006283b8  d9ca                 fxch st(2)
// 006283ba  d8db                 fcomp st(3)
// 006283bc  dfe0                 fnstsw ax
// 006283be  ddda                 fstp st(2)
// 006283c0  f6c405               test ah, 5
// 006283c3  7b04                 jnp 0x6283c9
// 006283c5  8d542404             lea edx, [esp + 4]
// 006283c9  ded9                 fcompp 
// 006283cb  8d4c2408             lea ecx, [esp + 8]
// 006283cf  dfe0                 fnstsw ax
// 006283d1  f6c405               test ah, 5
// 006283d4  7b04                 jnp 0x6283da
// 006283d6  8d4c240c             lea ecx, [esp + 0xc]
// 006283da  d902                 fld dword ptr [edx]
// 006283dc  d819                 fcomp dword ptr [ecx]
// 006283de  dfe0                 fnstsw ax
// 006283e0  f6c441               test ah, 0x41
// 006283e3  7506                 jne 0x6283eb
// 006283e5  d902                 fld dword ptr [edx]
// 006283e7  83c410               add esp, 0x10
// 006283ea  c3                   ret 
// 006283eb  d901                 fld dword ptr [ecx]
// 006283ed  83c410               add esp, 0x10
// 006283f0  c3                   ret 
// copied from an identical function in another client (function ?f@S@@QBEMXZ)

// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern "C" double __cdecl fabs(double);
#pragma intrinsic(fabs)

template<class T>
const T& maximum(const T& a, const T& b)
{
    return a < b ? b : a;
}

struct S
{
    float x, y, z, w;
    float f() const;
};

float S::f() const
{
    return maximum(
        maximum((float)fabs(x), (float)fabs(y)),
        maximum((float)fabs(z), (float)fabs(w)));
}