// from server: 100% by auto
// roc 2012-06 0056bca0  unit: RBX::RbxRay  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0056bca0
//
// 0056bca0  8b442408             mov eax, dword ptr [esp + 8]
// 0056bca4  f30f104108           movss xmm0, dword ptr [ecx + 8]
// 0056bca9  f30f104808           movss xmm1, dword ptr [eax + 8]
// 0056bcae  0f2fc8               comiss xmm1, xmm0
// 0056bcb1  8b54240c             mov edx, dword ptr [esp + 0xc]
// 0056bcb5  f30f105208           movss xmm2, dword ptr [edx + 8]
// 0056bcba  7205                 jb 0x56bcc1
// 0056bcbc  0f28e1               movaps xmm4, xmm1
// 0056bcbf  eb0d                 jmp 0x56bcce
// 0056bcc1  0f2fc2               comiss xmm0, xmm2
// 0056bcc4  7205                 jb 0x56bccb
// 0056bcc6  0f28e2               movaps xmm4, xmm2
// 0056bcc9  eb03                 jmp 0x56bcce
// 0056bccb  0f28e0               movaps xmm4, xmm0
// 0056bcce  f30f104104           movss xmm0, dword ptr [ecx + 4]
// 0056bcd3  f30f104804           movss xmm1, dword ptr [eax + 4]
// 0056bcd8  0f2fc8               comiss xmm1, xmm0
// 0056bcdb  f30f105204           movss xmm2, dword ptr [edx + 4]
// 0056bce0  7205                 jb 0x56bce7
// 0056bce2  0f28d9               movaps xmm3, xmm1
// 0056bce5  eb0d                 jmp 0x56bcf4
// 0056bce7  0f2fc2               comiss xmm0, xmm2
// 0056bcea  7205                 jb 0x56bcf1
// 0056bcec  0f28da               movaps xmm3, xmm2
// 0056bcef  eb03                 jmp 0x56bcf4
// 0056bcf1  0f28d8               movaps xmm3, xmm0
// 0056bcf4  f30f1001             movss xmm0, dword ptr [ecx]
// 0056bcf8  f30f1008             movss xmm1, dword ptr [eax]
// 0056bcfc  0f2fc8               comiss xmm1, xmm0
// 0056bcff  f30f1012             movss xmm2, dword ptr [edx]
// 0056bd03  7218                 jb 0x56bd1d
// 0056bd05  8b442404             mov eax, dword ptr [esp + 4]
// 0056bd09  0f28c1               movaps xmm0, xmm1
// 0056bd0c  f30f1100             movss dword ptr [eax], xmm0
// 0056bd10  f30f115804           movss dword ptr [eax + 4], xmm3
// 0056bd15  f30f116008           movss dword ptr [eax + 8], xmm4
// 0056bd1a  c20c00               ret 0xc
// 0056bd1d  0f2fc2               comiss xmm0, xmm2
// 0056bd20  7203                 jb 0x56bd25
// 0056bd22  0f28c2               movaps xmm0, xmm2
// 0056bd25  8b442404             mov eax, dword ptr [esp + 4]
// 0056bd29  f30f1100             movss dword ptr [eax], xmm0
// 0056bd2d  f30f115804           movss dword ptr [eax + 4], xmm3
// 0056bd32  f30f116008           movss dword ptr [eax + 8], xmm4
// 0056bd37  c20c00               ret 0xc
// library rbx2016-g3d/AABox.cpp (function ?clamp@Vector3@G3D@@QBE?AV12@ABV12@0@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
