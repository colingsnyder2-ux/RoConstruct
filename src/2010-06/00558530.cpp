// from server: 100% by auto
// roc 2010-06 00558530  unit: seg_00550000  size: 136 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00558530
//
// 00558530  8b442404             mov eax, dword ptr [esp + 4]
// 00558534  0f57c0               xorps xmm0, xmm0
// 00558537  56                   push esi
// 00558538  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0055853c  33d2                 xor edx, edx
// 0055853e  f30f1100             movss dword ptr [eax], xmm0
// 00558542  f30f114004           movss dword ptr [eax + 4], xmm0
// 00558547  f30f114008           movss dword ptr [eax + 8], xmm0
// 0055854c  f30f11400c           movss dword ptr [eax + 0xc], xmm0
// 00558551  83c108               add ecx, 8
// 00558554  eb0a                 jmp 0x558560
// 00558556  8da42400000000       lea esp, [esp]
// 0055855d  8d4900               lea ecx, [ecx]
// 00558560  f30f1041f8           movss xmm0, dword ptr [ecx - 8]
// 00558565  f30f5906             mulss xmm0, dword ptr [esi]
// 00558569  f30f580490           addss xmm0, dword ptr [eax + edx*4]
// 0055856e  f30f110490           movss dword ptr [eax + edx*4], xmm0
// 00558573  f30f1049fc           movss xmm1, dword ptr [ecx - 4]
// 00558578  f30f594e04           mulss xmm1, dword ptr [esi + 4]
// 0055857d  f30f58c8             addss xmm1, xmm0
// 00558581  f30f110c90           movss dword ptr [eax + edx*4], xmm1
// 00558586  f30f1001             movss xmm0, dword ptr [ecx]
// 0055858a  f30f594608           mulss xmm0, dword ptr [esi + 8]
// 0055858f  f30f58c1             addss xmm0, xmm1
// 00558593  f30f110490           movss dword ptr [eax + edx*4], xmm0
// 00558598  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 0055859d  f30f594e0c           mulss xmm1, dword ptr [esi + 0xc]
// 005585a2  f30f58c8             addss xmm1, xmm0
// 005585a6  f30f110c90           movss dword ptr [eax + edx*4], xmm1
// 005585ab  42                   inc edx
// 005585ac  83c110               add ecx, 0x10
// 005585af  83fa04               cmp edx, 4
// 005585b2  7cac                 jl 0x558560
// 005585b4  5e                   pop esi
// 005585b5  c20800               ret 8
// library rbx2016-g3d/Matrix4.cpp (function ??DMatrix4@G3D@@QBE?AVVector4@1@ABV21@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix4.cpp
