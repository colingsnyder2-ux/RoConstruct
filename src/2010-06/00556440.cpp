// from server: 100% by auto
// roc 2010-06 00556440  unit: seg_00550000  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00556440
//
// 00556440  8b442404             mov eax, dword ptr [esp + 4]
// 00556444  f30f1005c027a100     movss xmm0, dword ptr [0xa127c0]
// 0055644c  56                   push esi
// 0055644d  8bf1                 mov esi, ecx
// 0055644f  57                   push edi
// 00556450  8d5004               lea edx, [eax + 4]
// 00556453  2bf0                 sub esi, eax
// 00556455  bf03000000           mov edi, 3
// 0055645a  8d9b00000000         lea ebx, [ebx]
// 00556460  f30f1009             movss xmm1, dword ptr [ecx]
// 00556464  0f57c8               xorps xmm1, xmm0
// 00556467  f30f114afc           movss dword ptr [edx - 4], xmm1
// 0055646c  f30f100c16           movss xmm1, dword ptr [esi + edx]
// 00556471  0f57c8               xorps xmm1, xmm0
// 00556474  f30f110a             movss dword ptr [edx], xmm1
// 00556478  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 0055647d  0f57c8               xorps xmm1, xmm0
// 00556480  f30f114a04           movss dword ptr [edx + 4], xmm1
// 00556485  83c10c               add ecx, 0xc
// 00556488  83c20c               add edx, 0xc
// 0055648b  83ef01               sub edi, 1
// 0055648e  75d0                 jne 0x556460
// 00556490  5f                   pop edi
// 00556491  5e                   pop esi
// 00556492  c20400               ret 4
// library rbx2016-g3d/Matrix3.cpp (function ??GMatrix3@G3D@@QBE?AV01@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
