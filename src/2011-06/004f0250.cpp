// from server: 100% by auto
// roc 2011-06 004f0250  unit: RBX::RbxRay  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004f0250
//
// 004f0250  8b442408             mov eax, dword ptr [esp + 8]
// 004f0254  f30f104108           movss xmm0, dword ptr [ecx + 8]
// 004f0259  f30f104808           movss xmm1, dword ptr [eax + 8]
// 004f025e  0f2fc8               comiss xmm1, xmm0
// 004f0261  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004f0265  f30f105208           movss xmm2, dword ptr [edx + 8]
// 004f026a  7205                 jb 0x4f0271
// 004f026c  0f28e1               movaps xmm4, xmm1
// 004f026f  eb0d                 jmp 0x4f027e
// 004f0271  0f2fc2               comiss xmm0, xmm2
// 004f0274  7205                 jb 0x4f027b
// 004f0276  0f28e2               movaps xmm4, xmm2
// 004f0279  eb03                 jmp 0x4f027e
// 004f027b  0f28e0               movaps xmm4, xmm0
// 004f027e  f30f104104           movss xmm0, dword ptr [ecx + 4]
// 004f0283  f30f104804           movss xmm1, dword ptr [eax + 4]
// 004f0288  0f2fc8               comiss xmm1, xmm0
// 004f028b  f30f105204           movss xmm2, dword ptr [edx + 4]
// 004f0290  7205                 jb 0x4f0297
// 004f0292  0f28d9               movaps xmm3, xmm1
// 004f0295  eb0d                 jmp 0x4f02a4
// 004f0297  0f2fc2               comiss xmm0, xmm2
// 004f029a  7205                 jb 0x4f02a1
// 004f029c  0f28da               movaps xmm3, xmm2
// 004f029f  eb03                 jmp 0x4f02a4
// 004f02a1  0f28d8               movaps xmm3, xmm0
// 004f02a4  f30f1001             movss xmm0, dword ptr [ecx]
// 004f02a8  f30f1008             movss xmm1, dword ptr [eax]
// 004f02ac  0f2fc8               comiss xmm1, xmm0
// 004f02af  f30f1012             movss xmm2, dword ptr [edx]
// 004f02b3  7218                 jb 0x4f02cd
// 004f02b5  8b442404             mov eax, dword ptr [esp + 4]
// 004f02b9  0f28c1               movaps xmm0, xmm1
// 004f02bc  f30f1100             movss dword ptr [eax], xmm0
// 004f02c0  f30f115804           movss dword ptr [eax + 4], xmm3
// 004f02c5  f30f116008           movss dword ptr [eax + 8], xmm4
// 004f02ca  c20c00               ret 0xc
// 004f02cd  0f2fc2               comiss xmm0, xmm2
// 004f02d0  7203                 jb 0x4f02d5
// 004f02d2  0f28c2               movaps xmm0, xmm2
// 004f02d5  8b442404             mov eax, dword ptr [esp + 4]
// 004f02d9  f30f1100             movss dword ptr [eax], xmm0
// 004f02dd  f30f115804           movss dword ptr [eax + 4], xmm3
// 004f02e2  f30f116008           movss dword ptr [eax + 8], xmm4
// 004f02e7  c20c00               ret 0xc
// library rbx2016-g3d/AABox.cpp (function ?clamp@Vector3@G3D@@QBE?AV12@ABV12@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
