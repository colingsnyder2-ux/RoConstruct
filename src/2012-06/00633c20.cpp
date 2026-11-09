// from server: 100% by auto
// roc 2012-06 00633c20  unit: G3D::Random  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00633c20
//
// 00633c20  83ec0c               sub esp, 0xc
// 00633c23  56                   push esi
// 00633c24  8bf1                 mov esi, ecx
// 00633c26  eb02                 jmp 0x633c2a
// 00633c28  ddd8                 fstp st(0)
// 00633c2a  d9e8                 fld1 
// 00633c2c  8b06                 mov eax, dword ptr [esi]
// 00633c2e  8b5014               mov edx, dword ptr [eax + 0x14]
// 00633c31  83ec08               sub esp, 8
// 00633c34  d95c2404             fstp dword ptr [esp + 4]
// 00633c38  8bce                 mov ecx, esi
// 00633c3a  d905b8abb500         fld dword ptr [0xb5abb8]
// 00633c40  d91c24               fstp dword ptr [esp]
// 00633c43  ffd2                 call edx
// 00633c45  8b06                 mov eax, dword ptr [esi]
// 00633c47  d95c2408             fstp dword ptr [esp + 8]
// 00633c4b  d9e8                 fld1 
// 00633c4d  8b5014               mov edx, dword ptr [eax + 0x14]
// 00633c50  83ec08               sub esp, 8
// 00633c53  d95c2404             fstp dword ptr [esp + 4]
// 00633c57  d905b8abb500         fld dword ptr [0xb5abb8]
// 00633c5d  8bce                 mov ecx, esi
// 00633c5f  d91c24               fstp dword ptr [esp]
// 00633c62  ffd2                 call edx
// 00633c64  d9542404             fst dword ptr [esp + 4]
// 00633c68  f30f104c2408         movss xmm1, dword ptr [esp + 8]
// 00633c6e  f30f10442404         movss xmm0, dword ptr [esp + 4]
// 00633c74  0f28d1               movaps xmm2, xmm1
// 00633c77  f30f59c0             mulss xmm0, xmm0
// 00633c7b  f30f59d1             mulss xmm2, xmm1
// 00633c7f  f30f58c2             addss xmm0, xmm2
// 00633c83  0f2f0540c4b400       comiss xmm0, dword ptr [0xb4c440]
// 00633c8a  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 00633c90  7796                 ja 0x633c28
// 00633c92  d944240c             fld dword ptr [esp + 0xc]
// 00633c96  5e                   pop esi
// 00633c97  d9c0                 fld st(0)
// 00633c99  d9ed                 fldln2 
// 00633c9b  d9c9                 fxch st(1)
// 00633c9d  d9f1                 fyl2x 
// 00633c9f  d80dfc98b600         fmul dword ptr [0xb698fc]
// 00633ca5  def1                 fdivrp st(1)
// 00633ca7  d9fa                 fsqrt 
// 00633ca9  dec9                 fmulp st(1)
// 00633cab  d9442414             fld dword ptr [esp + 0x14]
// 00633caf  dcc9                 fmul st(1), st(0)
// 00633cb1  dec9                 fmulp st(1)
// 00633cb3  d8442410             fadd dword ptr [esp + 0x10]
// 00633cb7  83c40c               add esp, 0xc
// 00633cba  c20800               ret 8
// library rbx2016-g3d/Random.cpp (function ?gaussian@Random@G3D@@UAEMMM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Random.cpp
