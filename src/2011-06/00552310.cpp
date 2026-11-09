// from server: 100% by auto
// roc 2011-06 00552310  unit: G3D::Sphere  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00552310
//
// 00552310  8b442404             mov eax, dword ptr [esp + 4]
// 00552314  0f57c0               xorps xmm0, xmm0
// 00552317  56                   push esi
// 00552318  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0055231c  33d2                 xor edx, edx
// 0055231e  f30f1100             movss dword ptr [eax], xmm0
// 00552322  f30f114004           movss dword ptr [eax + 4], xmm0
// 00552327  f30f114008           movss dword ptr [eax + 8], xmm0
// 0055232c  f30f11400c           movss dword ptr [eax + 0xc], xmm0
// 00552331  83c108               add ecx, 8
// 00552334  eb0a                 jmp 0x552340
// 00552336  8da42400000000       lea esp, [esp]
// 0055233d  8d4900               lea ecx, [ecx]
// 00552340  f30f1041f8           movss xmm0, dword ptr [ecx - 8]
// 00552345  f30f5906             mulss xmm0, dword ptr [esi]
// 00552349  f30f580490           addss xmm0, dword ptr [eax + edx*4]
// 0055234e  f30f110490           movss dword ptr [eax + edx*4], xmm0
// 00552353  f30f1049fc           movss xmm1, dword ptr [ecx - 4]
// 00552358  f30f594e04           mulss xmm1, dword ptr [esi + 4]
// 0055235d  f30f58c8             addss xmm1, xmm0
// 00552361  f30f110c90           movss dword ptr [eax + edx*4], xmm1
// 00552366  f30f1001             movss xmm0, dword ptr [ecx]
// 0055236a  f30f594608           mulss xmm0, dword ptr [esi + 8]
// 0055236f  f30f58c1             addss xmm0, xmm1
// 00552373  f30f110490           movss dword ptr [eax + edx*4], xmm0
// 00552378  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 0055237d  f30f594e0c           mulss xmm1, dword ptr [esi + 0xc]
// 00552382  f30f58c8             addss xmm1, xmm0
// 00552386  f30f110c90           movss dword ptr [eax + edx*4], xmm1
// 0055238b  42                   inc edx
// 0055238c  83c110               add ecx, 0x10
// 0055238f  83fa04               cmp edx, 4
// 00552392  7cac                 jl 0x552340
// 00552394  5e                   pop esi
// 00552395  c20800               ret 8
// library rbx2016-g3d/Matrix4.cpp (function ??DMatrix4@G3D@@QBE?AVVector4@1@ABV21@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix4.cpp
