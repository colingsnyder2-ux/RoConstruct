// from server: 100% by auto
// roc 2012-06 00634140  unit: G3D::Random  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00634140
//
// 00634140  8b442404             mov eax, dword ptr [esp + 4]
// 00634144  0f57c0               xorps xmm0, xmm0
// 00634147  56                   push esi
// 00634148  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0063414c  33d2                 xor edx, edx
// 0063414e  f30f1100             movss dword ptr [eax], xmm0
// 00634152  f30f114004           movss dword ptr [eax + 4], xmm0
// 00634157  f30f114008           movss dword ptr [eax + 8], xmm0
// 0063415c  f30f11400c           movss dword ptr [eax + 0xc], xmm0
// 00634161  83c108               add ecx, 8
// 00634164  eb0a                 jmp 0x634170
// 00634166  8da42400000000       lea esp, [esp]
// 0063416d  8d4900               lea ecx, [ecx]
// 00634170  f30f1041f8           movss xmm0, dword ptr [ecx - 8]
// 00634175  f30f5906             mulss xmm0, dword ptr [esi]
// 00634179  f30f580490           addss xmm0, dword ptr [eax + edx*4]
// 0063417e  f30f110490           movss dword ptr [eax + edx*4], xmm0
// 00634183  f30f1049fc           movss xmm1, dword ptr [ecx - 4]
// 00634188  f30f594e04           mulss xmm1, dword ptr [esi + 4]
// 0063418d  f30f58c8             addss xmm1, xmm0
// 00634191  f30f110c90           movss dword ptr [eax + edx*4], xmm1
// 00634196  f30f1001             movss xmm0, dword ptr [ecx]
// 0063419a  f30f594608           mulss xmm0, dword ptr [esi + 8]
// 0063419f  f30f58c1             addss xmm0, xmm1
// 006341a3  f30f110490           movss dword ptr [eax + edx*4], xmm0
// 006341a8  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 006341ad  f30f594e0c           mulss xmm1, dword ptr [esi + 0xc]
// 006341b2  f30f58c8             addss xmm1, xmm0
// 006341b6  f30f110c90           movss dword ptr [eax + edx*4], xmm1
// 006341bb  42                   inc edx
// 006341bc  83c110               add ecx, 0x10
// 006341bf  83fa04               cmp edx, 4
// 006341c2  7cac                 jl 0x634170
// 006341c4  5e                   pop esi
// 006341c5  c20800               ret 8
// library rbx2016-g3d/Matrix4.cpp (function ??DMatrix4@G3D@@QBE?AVVector4@1@ABV21@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix4.cpp
