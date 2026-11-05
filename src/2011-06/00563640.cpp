// from server: 100% by auto
// roc 2011-06 00563640  unit: G3D::Random  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00563640
//
// 00563640  83ec0c               sub esp, 0xc
// 00563643  56                   push esi
// 00563644  8bf1                 mov esi, ecx
// 00563646  eb02                 jmp 0x56364a
// 00563648  ddd8                 fstp st(0)
// 0056364a  d9e8                 fld1 
// 0056364c  8b06                 mov eax, dword ptr [esi]
// 0056364e  8b5014               mov edx, dword ptr [eax + 0x14]
// 00563651  83ec08               sub esp, 8
// 00563654  d95c2404             fstp dword ptr [esp + 4]
// 00563658  8bce                 mov ecx, esi
// 0056365a  d90530eca600         fld dword ptr [0xa6ec30]
// 00563660  d91c24               fstp dword ptr [esp]
// 00563663  ffd2                 call edx
// 00563665  8b06                 mov eax, dword ptr [esi]
// 00563667  d95c2408             fstp dword ptr [esp + 8]
// 0056366b  d9e8                 fld1 
// 0056366d  8b5014               mov edx, dword ptr [eax + 0x14]
// 00563670  83ec08               sub esp, 8
// 00563673  d95c2404             fstp dword ptr [esp + 4]
// 00563677  d90530eca600         fld dword ptr [0xa6ec30]
// 0056367d  8bce                 mov ecx, esi
// 0056367f  d91c24               fstp dword ptr [esp]
// 00563682  ffd2                 call edx
// 00563684  d9542404             fst dword ptr [esp + 4]
// 00563688  f30f104c2408         movss xmm1, dword ptr [esp + 8]
// 0056368e  f30f10442404         movss xmm0, dword ptr [esp + 4]
// 00563694  0f28d1               movaps xmm2, xmm1
// 00563697  f30f59c0             mulss xmm0, xmm0
// 0056369b  f30f59d1             mulss xmm2, xmm1
// 0056369f  f30f58c2             addss xmm0, xmm2
// 005636a3  0f2f05143ba600       comiss xmm0, dword ptr [0xa63b14]
// 005636aa  f30f1144240c         movss dword ptr [esp + 0xc], xmm0
// 005636b0  7796                 ja 0x563648
// 005636b2  d944240c             fld dword ptr [esp + 0xc]
// 005636b6  5e                   pop esi
// 005636b7  d9c0                 fld st(0)
// 005636b9  d9ed                 fldln2 
// 005636bb  d9c9                 fxch st(1)
// 005636bd  d9f1                 fyl2x 
// 005636bf  d80da0fba700         fmul dword ptr [0xa7fba0]
// 005636c5  def1                 fdivrp st(1)
// 005636c7  d9fa                 fsqrt 
// 005636c9  dec9                 fmulp st(1)
// 005636cb  d9442414             fld dword ptr [esp + 0x14]
// 005636cf  dcc9                 fmul st(1), st(0)
// 005636d1  dec9                 fmulp st(1)
// 005636d3  d8442410             fadd dword ptr [esp + 0x10]
// 005636d7  83c40c               add esp, 0xc
// 005636da  c20800               ret 8
// library rbx2016-g3d/Random.cpp (function ?gaussian@Random@G3D@@UAEMMM@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Random.cpp
