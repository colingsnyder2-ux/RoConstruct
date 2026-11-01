// from server: 100% by colin
// roc 2007-03 00612040  unit: seg_00610000  size: 97 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00612040
//
// 00612040  83ec10               sub esp, 0x10
// 00612043  d9410c               fld dword ptr [ecx + 0xc]
// 00612046  8d1424               lea edx, [esp]
// 00612049  d9e1                 fabs 
// 0061204b  d91424               fst dword ptr [esp]
// 0061204e  d94108               fld dword ptr [ecx + 8]
// 00612051  d9e1                 fabs 
// 00612053  d9542404             fst dword ptr [esp + 4]
// 00612057  d94104               fld dword ptr [ecx + 4]
// 0061205a  d9e1                 fabs 
// 0061205c  d9542408             fst dword ptr [esp + 8]
// 00612060  d901                 fld dword ptr [ecx]
// 00612062  d9e1                 fabs 
// 00612064  d954240c             fst dword ptr [esp + 0xc]
// 00612068  d9ca                 fxch st(2)
// 0061206a  d8db                 fcomp st(3)
// 0061206c  dfe0                 fnstsw ax
// 0061206e  ddda                 fstp st(2)
// 00612070  f6c405               test ah, 5
// 00612073  7b04                 jnp 0x612079
// 00612075  8d542404             lea edx, [esp + 4]
// 00612079  ded9                 fcompp 
// 0061207b  8d4c2408             lea ecx, [esp + 8]
// 0061207f  dfe0                 fnstsw ax
// 00612081  f6c405               test ah, 5
// 00612084  7b04                 jnp 0x61208a
// 00612086  8d4c240c             lea ecx, [esp + 0xc]
// 0061208a  d902                 fld dword ptr [edx]
// 0061208c  d819                 fcomp dword ptr [ecx]
// 0061208e  dfe0                 fnstsw ax
// 00612090  f6c441               test ah, 0x41
// 00612093  7506                 jne 0x61209b
// 00612095  d902                 fld dword ptr [edx]
// 00612097  83c410               add esp, 0x10
// 0061209a  c3                   ret 
// 0061209b  d901                 fld dword ptr [ecx]
// 0061209d  83c410               add esp, 0x10
// 006120a0  c3                   ret 
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