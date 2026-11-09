// from server: 100% by auto
// roc 2012-06 0062c410  unit: G3D::Sphere  size: 254 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062c410
//
// 0062c410  83ec18               sub esp, 0x18
// 0062c413  8b442420             mov eax, dword ptr [esp + 0x20]
// 0062c417  f30f1000             movss xmm0, dword ptr [eax]
// 0062c41b  f30f105818           movss xmm3, dword ptr [eax + 0x18]
// 0062c420  f30f10600c           movss xmm4, dword ptr [eax + 0xc]
// 0062c425  f30f11442420         movss dword ptr [esp + 0x20], xmm0
// 0062c42b  f30f10401c           movss xmm0, dword ptr [eax + 0x1c]
// 0062c430  f30f11442404         movss dword ptr [esp + 4], xmm0
// 0062c436  f30f104010           movss xmm0, dword ptr [eax + 0x10]
// 0062c43b  f30f11442408         movss dword ptr [esp + 8], xmm0
// 0062c441  f30f104004           movss xmm0, dword ptr [eax + 4]
// 0062c446  f30f110424           movss dword ptr [esp], xmm0
// 0062c44b  f30f104020           movss xmm0, dword ptr [eax + 0x20]
// 0062c450  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 0062c456  f30f104014           movss xmm0, dword ptr [eax + 0x14]
// 0062c45b  f30f11442414         movss dword ptr [esp + 0x14], xmm0
// 0062c461  f30f104008           movss xmm0, dword ptr [eax + 8]
// 0062c466  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0062c46a  56                   push esi
// 0062c46b  f30f11442410         movss dword ptr [esp + 0x10], xmm0
// 0062c471  83c104               add ecx, 4
// 0062c474  8d5008               lea edx, [eax + 8]
// 0062c477  be03000000           mov esi, 3
// 0062c47c  8d642400             lea esp, [esp]
// 0062c480  f30f104904           movss xmm1, dword ptr [ecx + 4]
// 0062c485  f30f1041fc           movss xmm0, dword ptr [ecx - 4]
// 0062c48a  f30f1011             movss xmm2, dword ptr [ecx]
// 0062c48e  0f28e8               movaps xmm5, xmm0
// 0062c491  f30f596c2424         mulss xmm5, dword ptr [esp + 0x24]
// 0062c497  0f28f1               movaps xmm6, xmm1
// 0062c49a  f30f59f3             mulss xmm6, xmm3
// 0062c49e  f30f58ee             addss xmm5, xmm6
// 0062c4a2  0f28f2               movaps xmm6, xmm2
// 0062c4a5  f30f59f4             mulss xmm6, xmm4
// 0062c4a9  f30f58ee             addss xmm5, xmm6
// 0062c4ad  f30f116af8           movss dword ptr [edx - 8], xmm5
// 0062c4b2  0f28e8               movaps xmm5, xmm0
// 0062c4b5  f30f596c2404         mulss xmm5, dword ptr [esp + 4]
// 0062c4bb  f30f59442410         mulss xmm0, dword ptr [esp + 0x10]
// 0062c4c1  0f28f1               movaps xmm6, xmm1
// 0062c4c4  f30f59742408         mulss xmm6, dword ptr [esp + 8]
// 0062c4ca  f30f594c2414         mulss xmm1, dword ptr [esp + 0x14]
// 0062c4d0  f30f58ee             addss xmm5, xmm6
// 0062c4d4  0f28f2               movaps xmm6, xmm2
// 0062c4d7  f30f5974240c         mulss xmm6, dword ptr [esp + 0xc]
// 0062c4dd  f30f59542418         mulss xmm2, dword ptr [esp + 0x18]
// 0062c4e3  f30f58c1             addss xmm0, xmm1
// 0062c4e7  f30f58ee             addss xmm5, xmm6
// 0062c4eb  f30f58c2             addss xmm0, xmm2
// 0062c4ef  f30f116afc           movss dword ptr [edx - 4], xmm5
// 0062c4f4  f30f1102             movss dword ptr [edx], xmm0
// 0062c4f8  83c10c               add ecx, 0xc
// 0062c4fb  83c20c               add edx, 0xc
// 0062c4fe  83ee01               sub esi, 1
// 0062c501  0f8579ffffff         jne 0x62c480
// 0062c507  5e                   pop esi
// 0062c508  83c418               add esp, 0x18
// 0062c50b  c20800               ret 8
// library rbx2016-g3d/Matrix3.cpp (function ??DMatrix3@G3D@@QBE?AV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Matrix3.cpp
