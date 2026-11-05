// from server: 100% by auto
// roc 2012-06 0062c620  unit: G3D::Sphere  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062c620
//
// 0062c620  8b442404             mov eax, dword ptr [esp + 4]
// 0062c624  f30f10059031b600     movss xmm0, dword ptr [0xb63190]
// 0062c62c  56                   push esi
// 0062c62d  8bf1                 mov esi, ecx
// 0062c62f  57                   push edi
// 0062c630  8d5004               lea edx, [eax + 4]
// 0062c633  2bf0                 sub esi, eax
// 0062c635  bf03000000           mov edi, 3
// 0062c63a  8d9b00000000         lea ebx, [ebx]
// 0062c640  f30f1009             movss xmm1, dword ptr [ecx]
// 0062c644  0f57c8               xorps xmm1, xmm0
// 0062c647  f30f114afc           movss dword ptr [edx - 4], xmm1
// 0062c64c  f30f100c16           movss xmm1, dword ptr [esi + edx]
// 0062c651  0f57c8               xorps xmm1, xmm0
// 0062c654  f30f110a             movss dword ptr [edx], xmm1
// 0062c658  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 0062c65d  0f57c8               xorps xmm1, xmm0
// 0062c660  f30f114a04           movss dword ptr [edx + 4], xmm1
// 0062c665  83c10c               add ecx, 0xc
// 0062c668  83c20c               add edx, 0xc
// 0062c66b  83ef01               sub edi, 1
// 0062c66e  75d0                 jne 0x62c640
// 0062c670  5f                   pop edi
// 0062c671  5e                   pop esi
// 0062c672  c20400               ret 4
// library rbx2016-g3d/Matrix3.cpp (function ??GMatrix3@G3D@@QBE?AV01@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
