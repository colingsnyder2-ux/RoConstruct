// from server: 100% by auto
// roc 2010-06 00557320  unit: seg_00550000  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00557320
//
// 00557320  b801000000           mov eax, 1
// 00557325  8405989fc000         test byte ptr [0xc09f98], al
// 0055732b  7559                 jne 0x557386
// 0055732d  0f57c0               xorps xmm0, xmm0
// 00557330  f30f100d24f6a100     movss xmm1, dword ptr [0xa1f624]
// 00557338  0905989fc000         or dword ptr [0xc09f98], eax
// 0055733e  f30f110d749fc000     movss dword ptr [0xc09f74], xmm1
// 00557346  f30f1105789fc000     movss dword ptr [0xc09f78], xmm0
// 0055734e  f30f11057c9fc000     movss dword ptr [0xc09f7c], xmm0
// 00557356  f30f1105809fc000     movss dword ptr [0xc09f80], xmm0
// 0055735e  f30f110d849fc000     movss dword ptr [0xc09f84], xmm1
// 00557366  f30f1105889fc000     movss dword ptr [0xc09f88], xmm0
// 0055736e  f30f11058c9fc000     movss dword ptr [0xc09f8c], xmm0
// 00557376  f30f1105909fc000     movss dword ptr [0xc09f90], xmm0
// 0055737e  f30f110d949fc000     movss dword ptr [0xc09f94], xmm1
// 00557386  b8749fc000           mov eax, 0xc09f74
// 0055738b  c3                   ret 
// library rbx2016-g3d/Matrix3.cpp (function ?identity@Matrix3@G3D@@SAABV12@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
